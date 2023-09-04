//
// Created by kyoto on 24.10.22.
//

#ifndef ASSIGNMENT_3_IMAGE_ROTATION_IMGIO_H
#define ASSIGNMENT_3_IMAGE_ROTATION_IMGIO_H

#include "bmp_struct_lib.h"
#include <stdbool.h>
#include <stdio.h>

/*  deserializer   */
enum read_status  {
    READ_OK = 0,
    READ_INVALID_SIGNATURE,
    READ_INVALID_BITS,
    READ_INVALID_HEADER,
    READ_ERROR
};

enum read_status from_bmp( FILE* in, struct image** img );

/*  serializer   */
enum  write_status  {
    WRITE_OK = 0,
    WRITE_ERROR
};

enum write_status to_bmp( FILE* out, struct image const* img );


#endif //ASSIGNMENT_3_IMAGE_ROTATION_IMGIO_H
