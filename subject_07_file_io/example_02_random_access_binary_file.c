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
    
    FILE *binFile = fopen ("test.bin", "w+b");                  // Create or clear binary file for reading as well as writing
    
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
    
    // ======== Close file
    
    fclose (binFile);
    
    // ======== Show results
    
    printf ("%i %f %f\n", anIntToo, aFloatToo, aDoubleToo);
    printf ("Try to load the resulting file in a text editor\n");
    printf ("It's not human readable. WHY exactly?\n");
    
    return 0;
}
