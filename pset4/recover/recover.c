#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;
int start_of_jpg(BYTE temp[]);

int main(int argc, char *argv[])
{

    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    FILE *pic;

    int count = 0;
    char name[8];
    BYTE temp[512];

    while (fread(temp, 512, 1, file) == 1)
    {
        if (start_of_jpg(temp) == 1)
        {
            if (count != 0)
            {
                fclose(pic);
            }
            sprintf(name, "%03i.jpg", count);
            pic = fopen(name, "w");
            fwrite(temp, 512, 1, pic);
            count++;
        }
        else if (count > 0)
        {
            fwrite(temp, 512, 1, pic);
        }

    }

    //open memory card
    // repeat until end of card:
    //     read 512 bytes into buffer
    //     If start of new JPEG
    //     If first JPEG
    //         ...
    //     Else
    //         ...
    //     Else
    //         If already found JPEG
    //Close any remaining files

}

int start_of_jpg(BYTE temp[])
{
    if (temp[0] == 0xff && temp[1] == 0xd8 && temp[2] == 0xff && (temp[3] & 0xf0) == 0xe0)
    {
        return 1;
    }
    return 0;
}