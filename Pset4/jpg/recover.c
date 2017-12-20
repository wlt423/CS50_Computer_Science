/**
 * recover.c
 * Walter Thornton
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(void)
{
    bool jpg_open = false;
    BYTE buffer[512];
    char title[8];
    FILE* file = fopen("card.raw", "r");
    FILE* img;
    int pic = 0;
    
    // repeat until end of file
    while (fread(buffer, sizeof(BYTE), 512, file) == 512)
    {
        // check for jpg signature
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff) 
        {
            // check if jpg is already open
            if (jpg_open == true)
            {
                fclose(img);
            }
           
        // create new jpg    
            sprintf(title, "%.3d.jpg", pic);
            img = fopen(title, "w");
            pic++;
            jpg_open = true;
        }
        
        // write data to jpg
        if (jpg_open == true)
        {
            fwrite(buffer, sizeof(buffer), 1, img);
        }
    }    
    
    // close files
    fclose(img);
    fclose(file);
    return 0;
}
