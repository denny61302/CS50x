#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
    // check if the namefile was specified
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover image\n");
        return 1;
    }

    // check if memory card is successfully opened
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        fprintf(stderr, "Could not open file %s.\n", argv[1]);
        return 1;
    }

    FILE *img;
    char filename[7];
    unsigned char bf[512];
    int counter = 0;
    bool jpeg_header = false;
    bool found_jpeg = false;
    size_t read_bytes = 1;

    // If the end of the file is reached, fread returns 0
    while (read_bytes != 0)
    {
        // the number of items read
        read_bytes = fread(bf, sizeof(unsigned char), 512, file);
        // found a new jpg file
        if (bf[0] == 0xff && bf[1] == 0xd8 && bf[2] == 0xff && (bf[3] & 0xf0) == 0xe0)
        {
            found_jpeg = true;
            // find the first JPEG header
            if (!jpeg_header)
            {
                jpeg_header = true;
            }
            else
            {
                // close the previous image file
                fclose(img);
            }
            sprintf(filename, "%03d.jpg", counter);
            // open new image file
            img = fopen(filename, "w");
            fwrite(bf, sizeof(unsigned char), read_bytes, img);
            counter++;
        }
        //writes buffer data into the currently opened image
        else
        {
            if (found_jpeg)
            {
                fwrite(bf, sizeof(unsigned char), read_bytes, img);
            }
        }
    }

    //frees memory and closes files
    fclose(img);
    fclose(file);

    return 0;
}