//
// Created by kyoto on 24.10.22.
//
#include "image_IO_lib.h"
#include "bmp_struct_lib.h"


bool skip_padding_in_image( FILE* in, const struct image* const image) {
    int64_t padding = padding_calculate(image);
        if ( fseek(in, padding, SEEK_CUR) ) return false;
    return true;
}

bool read_header( FILE* f, struct bmp_header *header ) {
    return fread( header, sizeof( struct bmp_header ), 1, f );
}

bool read_image( FILE* in,  const struct image* const image ) {
    for (size_t h=0; h < image->height; h++) {
        for (size_t w=0; w < image->width; w++ ) {
            if (!fread( ( image->data + (h*(image->width) + w) ) , sizeof(struct pixel), 1, in)) return false;
        }
        if (!skip_padding_in_image(in, image)) return false;
    }
    return true;
}



/*  deserializer   */
enum read_status from_bmp( FILE* in, struct image** img ) {

    struct bmp_header header = {0};
    if (!read_header(in, &header)) return READ_INVALID_HEADER;
    *img = init_image(header.biWidth, header.biHeight);
        if (!read_image(in, *img)) {
        free_image(*img);
        return READ_INVALID_BITS;
    }
    return READ_OK;
}

bool write_header( FILE* out, const struct bmp_header* const header) {
    return fwrite(header, sizeof(struct bmp_header), 1, out) ;
}

bool write_padding( FILE* out, const struct image* const image) {
    if (padding_calculate(image) == 0) return true;
    uint8_t padding[3] = {0,0,0};
    return fwrite( &padding , sizeof(uint8_t), padding_calculate(image), out );
}

bool write_image( FILE* out, const struct image* const image) {
    for (size_t h=0; h<image->height; h++) {
        for (size_t w=0; w<image->width; w++) {
            if (!fwrite( ( image->data + h * (image->width) + w ), sizeof(struct pixel), 1, out)) return false;
        }
        if ( !write_padding( out, image ) ) return false;
    }
    return true;
}


//serializer
enum write_status to_bmp(  FILE* out, const struct image* const img ) {
    struct bmp_header* header = create_bmp_header_from_img(img);
    if ( !write_header(out, header) ) {
        free_header(header);
        return WRITE_ERROR;
    }
    if ( !write_image(out,img) ) {
        free_header(header);
        return WRITE_ERROR;
    }
    free_header(header);
    return WRITE_OK;
}

