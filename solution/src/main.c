#include "file_IO_lib.h"
#include "bmp_struct_lib.h"
#include "image_IO_lib.h"
#include "image_rotate_lib.h"


int main( int argc, char** argv ) {

    if (argc < 3) {
        fprintf(stderr, "Invalid arguments.");
        return -1;
    }


    FILE* read_file = NULL;
    FILE* write_file = NULL;



open_file(&read_file, argv[1], "rb");

open_file(&write_file, argv[2], "wb");

    struct image* image = NULL;
    enum read_status status = from_bmp(read_file, &image);
    if(status != READ_OK){
        fprintf(stderr, "Error: %d", status);
        return status;
    }

    struct image* rotated = NULL;
    rotate_image(image, &rotated);
    free_image(image);

    enum write_status write_status = to_bmp(write_file, rotated);
    if(write_status != WRITE_OK){
        fprintf(stderr, "Error: %d", write_status);
        free_image(rotated);
        return write_status;
    }

    free_image(rotated);

close_file(read_file);

    return 0;
}
