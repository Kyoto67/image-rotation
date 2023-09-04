//
// Created by kyoto on 25.10.22.
//

#ifndef ASSIGNMENT_3_IMAGE_ROTATION_FILE_IO_LIB_H
#define ASSIGNMENT_3_IMAGE_ROTATION_FILE_IO_LIB_H

#include <stdbool.h>
#include <stdio.h>

bool open_file(FILE** file, const char* const filename, const char* const open_mode);
bool close_file(FILE* file);

#endif //ASSIGNMENT_3_IMAGE_ROTATION_FILE_IO_LIB_H
