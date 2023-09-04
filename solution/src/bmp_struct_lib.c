//
// Created by kyoto on 25.10.22.
//

#include "bmp_struct_lib.h"

#define BMP_LITTLEENDIAN_TYPE 0x4D42
#define BMP_RESERVED_BYTES 0
#define BMP_IMAGE_PLANES_CONST 1
#define BITMAPINFOHEADER_SIZE 40
#define BI_RGB_COMPRESSION_CONST 0
#define BMP_TRUECOLOR_VALUE 24
#define PIXEL_PER_METER_NEVERMIND 0
#define WITHOUT_COLOR_TABLE 0

struct bmp_header* init_bmp_header(void) {
    return malloc( sizeof(struct bmp_header) );
}

struct image* init_image( const uint64_t width, const uint64_t height) {
    struct pixel* pixels = malloc( sizeof( struct pixel) * width * height );
    struct image* image = malloc( sizeof(struct image) );
    image->height = height;
    image->width = width;
    image->data = pixels;
    return image;
}

void free_header( struct bmp_header* header) {
    free(header);
}

void free_image( struct image* image ) {
    free(image->data);
    free(image);
}

size_t calc_image_size(const struct image* const image){
    return image->width + padding_calculate(image) * image->height;
}

size_t calc_file_size(const struct image* const image) {
    return image->width * image->height * sizeof(struct pixel) + padding_calculate(image) * image->height + sizeof(struct bmp_header);
}

int64_t padding_calculate(const struct image* const image) {
    int64_t padding = 0;
    if (image->width % 4 != 0) padding = 4 - (int64_t) ((image->width * sizeof(struct pixel)) % 4);
    return padding;
}

struct bmp_header* create_bmp_header_from_img(const struct image* const image) {
    struct bmp_header* header = init_bmp_header();
    header->bfType = BMP_LITTLEENDIAN_TYPE;
    header->bfileSize = calc_file_size(image);
    header->bfReserved = BMP_RESERVED_BYTES;
    header->bOffBits = sizeof(struct bmp_header);
    header->biSize = BITMAPINFOHEADER_SIZE;
    header->biWidth = image->width;
    header->biHeight = image->height;
    header->biPlanes = BMP_IMAGE_PLANES_CONST;
    header->biBitCount = BMP_TRUECOLOR_VALUE;
    header->biCompression = BI_RGB_COMPRESSION_CONST;
    header->biSizeImage = calc_image_size(image);
    header->biXPelsPerMeter = PIXEL_PER_METER_NEVERMIND;
    header->biYPelsPerMeter = PIXEL_PER_METER_NEVERMIND;
    header->biClrUsed = WITHOUT_COLOR_TABLE;
    header->biClrImportant = WITHOUT_COLOR_TABLE;
    return header;
}
