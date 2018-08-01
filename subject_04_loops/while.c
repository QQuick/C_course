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
    // Almost anything in C (and C++) is an expression!
    // This allows even a naive compiler to keep things in CPU registers.
    // It's one of the things that made C (and C++) code fast right from the start.
    // Not everyone likes this coding style, but then again not everyone likes C...
    
    printf ("Exponential growth, however modest, eventually wins from linear growth!\n\n");
    
    float linear, exponential;
    linear = exponential = 1;

    printf ("  lin    exp\n");
    printf (" =====  =====\n");
    while (++linear > (exponential *= 1.1)) {
        printf ("%6.2f %6.2f\n", linear, exponential);
    }
}
