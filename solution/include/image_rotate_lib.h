//
// Created by kyoto on 25.10.22.
//

#ifndef ASSIGNMENT_3_IMAGE_ROTATION_IMAGE_ROTATE_LIB_H
#define ASSIGNMENT_3_IMAGE_ROTATION_IMAGE_ROTATE_LIB_H
#include "bmp_struct_lib.h"

struct pixel get_rotated_pixel( const struct image* const image, size_t index);

void write_new_pixel (const struct image** const rotated, const struct pixel px, size_t index);

void rotate_image(const struct image* const image, struct image* *new_image);

#endif //ASSIGNMENT_3_IMAGE_ROTATION_IMAGE_ROTATE_LIB_H
