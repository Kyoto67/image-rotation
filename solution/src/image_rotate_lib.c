//
// Created by kyoto on 25.10.22.
//

#include "image_rotate_lib.h"
#include "bmp_struct_lib.h"

struct pixel get_pixel_for_rotate( const struct image* const image, const size_t index) {
    return image->data[index];
}

void write_rotated_pixel ( struct image** rotated, const struct pixel px, const size_t index) {
    (*rotated)->data[index] = px;
}

void rotate_image(const struct image* const image, struct image* *new_image) {
    *new_image = init_image(image->height, image->width);
    for (size_t w = 0; w < image->width; ++w) {
        for (size_t h = 0; h < image->height; ++h) {
            write_rotated_pixel(new_image, get_pixel_for_rotate(image, w + (image->height - h - 1) * image->width), w * (image->height) + h );
        }
    }
}

