//
// Created by kyoto on 21.10.22.
//



#ifndef ASSIGNMENT_3_IMAGE_ROTATION_BMP_HEADER_H
#define ASSIGNMENT_3_IMAGE_ROTATION_BMP_HEADER_H

#include <inttypes.h>
#include <malloc.h>
#include <stdint.h>

struct __attribute__((packed)) bmp_header
{
    uint16_t bfType;
    uint32_t bfileSize;
    uint32_t bfReserved;
    uint32_t bOffBits;
    uint32_t biSize;
    uint32_t biWidth;
    uint32_t biHeight;
    uint16_t biPlanes;
    uint16_t biBitCount;
    uint32_t biCompression;
    uint32_t biSizeImage;
    uint32_t biXPelsPerMeter;
    uint32_t biYPelsPerMeter;
    uint32_t biClrUsed;
    uint32_t biClrImportant;
};


struct __attribute__((packed)) pixel { uint8_t b, g, r; };

struct image {
    uint64_t width, height;
    struct pixel* data;
};

struct bmp_header* init_bmp_header(void);

struct image* init_image( const uint64_t width, const uint64_t height);

void free_header( struct bmp_header* header);

void free_image( struct image* image );

int64_t padding_calculate(const struct image* const image);

struct bmp_header* create_bmp_header_from_img(const struct image* const image);

#endif //ASSIGNMENT_3_IMAGE_ROTATION_BMP_HEADER_H

