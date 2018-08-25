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
#include <string.h>

int main () {
    // Zero terminated char arrays are called C strings
    char dogName [64] = {'C', 'u', 'j', 'o', 0};  // Leave space for longer names!
    printf ("Dog: %s\n", dogName);

    // The name of an array is a pointer to its first element
    // The following line just copies the pointer, not the array itself
    char *dogNameToo = dogName;
    printf ("Same dog: %s\n\n", dogNameToo);
  
    // You can use a string literal as source array
    strcpy (dogName, "Hector"); // Wasting space of two chars
    printf ("Other dog: %s\n", dogName);
    printf ("Same other dog (WHY?): %s\n\n", dogNameToo);

    // You can also create C strings as follows
    // The string will then be const and possibly in ROM
    char const *catName = "Thomas";
    printf ("Cat: %s\n", catName);

    // You can copy the pointer
    char const *catNameToo = catName;
    printf ("Same cat: %s\n\n", catNameToo);

    // But you can't overwrite the const array
    /*
    strcpy (catName, "Lady");   // Won't work, up to date compilers flag this as an error
    */
    
    // Pointer arithmetic is intelligent (and 0 means false)
    char charArray [] = "0123";         // Determine size automagically
    printf ("Size of one char: %i bytes\n", sizeof (char));
    printf ("%c\n", *(charArray + 2));    // Advance 2 * sizeof (char) bytes
    for (char *charPointer = charArray; *charPointer; charPointer++) {
        printf ("%c", *charPointer);
        printf (" ");
    }
    printf ("\n\n");
        
    float floatArray [] = {0.0, 1.0, 2.0, 3.0, -1.0};
    printf ("Size of one float: %i bytes\n", sizeof (float));
    printf ("%f (WHY?)\n", *(floatArray + 2));   // Advance 2 * sizeof (float) bytes
    for (float *floatPointer = floatArray; *floatPointer >= 0; floatPointer++) {
        printf ("%f", *floatPointer);
        printf (" ");
    }
    printf ("\n\n");
    
    return 0;
}
