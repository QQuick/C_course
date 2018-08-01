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
#include <time.h>
#include <stdlib.h>

int main (void) {
    srand (time (NULL));
    
    int factor1 = rand () % 11;
    int factor2 = rand () % 11;
    
    int product;
    printf ("How much is %d x %d?", factor1, factor2);
    scanf ("%d", &product);
    
    if (product < factor1 * factor2 ) {
        printf ("No, that's too small");
    }
    else if (product > factor1 * factor2) {
        printf ("No, that's too large");
    }
    else {
        printf ("Yes, that's correct");
    }
}
