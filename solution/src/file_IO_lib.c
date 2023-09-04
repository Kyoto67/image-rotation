//
// Created by kyoto on 25.10.22.
//

#include "file_IO_lib.h"



bool open_file(FILE** file, const char* const filename, const char* const open_mode) {
    *file = fopen(filename, open_mode);
    return (*file != NULL);
}

bool close_file(FILE* file) {
    return fclose(file) == 0;
}
