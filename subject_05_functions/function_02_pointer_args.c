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

void swap (float *a, float *b) {
    float temp = *a;
    *a = *b;
    *b = temp;
}

int main () {
    float a = 2.72;
    float b = 3.14;
    
    printf ("original: %.2f, %.2f\n", a, b);
    swap (&a, &b);
    printf ("swapped : %.2f, %.2f\n", a, b); 
}
