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
#include <ctype.h>

int const maxLineLength = 256;
int const maxNrOfLines = 64;
int const maxNrOfChars = maxNrOfLines * maxLineLength;

int main () {
    printf ("\nLook at the contents of the input file and both output files.\nWhat exactly are the differences and WHY?\n\n");
    
    // Note that {} blocks are used to create different scopes and prevent name clashes
    // The alternative is using different names for the file variables
    
    {   // ======== Text I/O per line ========
        
        char lineBuffer [maxNrOfLines][maxLineLength];
        char lineIndex = 0;
            
        FILE *inputFile = fopen ("test_in.txt", "r");
        while (lineIndex < maxNrOfLines && fgets (lineBuffer [lineIndex], maxLineLength, inputFile)) {
            lineIndex++;    // Should be conditional, so inside loop, not in loop head
        }
        fclose (inputFile);
     
        FILE *outputFile = fopen ("test_out_lines.txt", "w");
        while (--lineIndex >= 0) {
            fputs (lineBuffer [lineIndex], outputFile);
        }
        fclose (outputFile);
    }

    {   // ======== Text I/O per char ========
        
        char charBuffer [maxNrOfChars];
        char charIndex = 0;
        
        FILE *inputFile = fopen ("test_in.txt", "r");
        char inputChar;
        while (charIndex < maxNrOfChars && (inputChar = getc (inputFile)) != EOF) {
            charBuffer [charIndex++] = inputChar;
        }
        fclose (inputFile);
        
        FILE *outputFile = fopen ("test_out_chars.txt", "w");
        while (--charIndex >= 0) {
            putc (charBuffer [charIndex], outputFile);
        }
        fclose (outputFile);
    }
    
    return 0;
}