/*
Copyright 2018 Jacques de Hooge, GEATEC engineering, www.geatec.com

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

  http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#include <stdio.h>

int main () {
    
    /*
    Binary files are very suitable for storage and access of large blocks of numbers:
    
    - They are much smaller than text files holding the same data
    - Access to them is much faster because they don't require any conversion
    - It's relatively easy to access their elements or subblocks of elements in random order
    
    One drawback is that they aren't human readable, which can make debugging harder.
    
    Make sure you thoroughly understand the difference between text files and binary files.
    Also make sure you understand the difference between sequential access and random access.
    */
    
    // ======== Open file
    
    char fileName [] = "test.bin";
    FILE *binFile = fopen (fileName, "w+b");                  // Create or clear binary file for reading as well as writing
    
    // ======== Write a one dimensional block of numbers
    
    int const sideLength = 5;
    int const nrOfElements = sideLength * sideLength;
    
    int pattern1dim [] = {
        0, 0, 1, 0, 0,
        0, 1, 2, 1, 0,
        1, 2, 3, 2, 1,
        0, 1, 2, 1, 0,
        0, 0, 1, 0, 0
    };
    
    fseek (binFile, 0, SEEK_SET);
    fwrite (pattern1dim, sizeof (int), nrOfElements, binFile);
    
    // ======== Read block of numbers back into a two dimensional variable
    
    int pattern2dim [sideLength][sideLength];
    
    fseek (binFile, 0, SEEK_SET);
    fread (pattern2dim, sizeof (int), nrOfElements, binFile);
    
    // ======== Show contents of this two dimensional variable
    
    printf ("\n");
    for (int rowIndex = 0; rowIndex < sideLength; rowIndex++) {
        for (int columnIndex = 0; columnIndex < sideLength; columnIndex++) {
            printf ("%i ", pattern2dim [rowIndex][columnIndex]);
        }
        printf ("\n");
    }
    printf ("\n\n");
    
    // ======== Write three variables of different types and sizes in opposite order, just to show that it's possible
    
    int anInt = 3;
    float aFloat = 3.14;
    double aDouble = 3.141592653588;
    
    fseek (binFile, sizeof (int) + sizeof (float), SEEK_SET);   // Seeking beyond end of file will expand file size
    fwrite (&aDouble, sizeof (double), 1, binFile);
    
    fseek (binFile, sizeof (int), SEEK_SET);
    fwrite (&aFloat, sizeof (float), 1, binFile);
    
    fseek (binFile, 0, SEEK_SET);
    fwrite (&anInt, sizeof (int), 1, binFile);
    
    // ======== Read the data into three other variables in natural order
    
    int anIntToo;
    float aFloatToo;
    double aDoubleToo;
    
    fseek (binFile, 0, SEEK_SET);                               // Offset 0 bytes from the beginning
    fread (&anIntToo, sizeof (int), 1, binFile);                // No subsequent fseek's needed, position advances at reading (as it would at writing)
    fread (&aFloatToo, sizeof (float), 1, binFile);
    fread (&aDoubleToo, sizeof (double), 1, binFile);
    
    // ======== Show contents of these other variables
    
    printf ("File \"%s\" now contains: %i %f %f\n", fileName, anIntToo, aFloatToo, aDoubleToo);
    printf ("Try to load it in a text editor\n");
    printf ("It's not human readable. WHY exactly?\n\n");
    
    // ======== Close file
    
    fclose (binFile);
    return 0;
}
