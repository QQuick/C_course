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

float average (float numbers [], int length) {
    float sum = 0;
    for (int index = 0; index < length; index++) {
        sum += numbers [index];
    }
    return sum / length;
}

int main () {
    float array1 [] = {10, 1.75, 7.25, 7.5, 8.5}; 
    printf ("The average of the elements of array1 is: %.2f\n", average (array1, sizeof (array1) / sizeof (float)));
    
    float array2 [] = {1, 1.5, 2}; 
    printf ("The average of the elements of array2 is: %.2f\n", average (array2, sizeof (array2) / sizeof (float)));    
}
