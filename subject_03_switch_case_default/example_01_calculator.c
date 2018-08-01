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
    float a;
    float b;
    char operator [2];
    
    printf ("First operand: ");
    scanf ("%f", &a);
    
    printf ("Second operand: ");
    scanf ("%f", &b);
    
    printf ("Operator <+|-|*|/>: ");
    scanf ("%s", operator);
    
    float result;
    switch (operator [0]) {
        case '+': {
            result = a + b;
            break;
        }
        case '-': {
            result = a - b;
            break;
        }
        case '*': {
            result = a * b;
            break;
        }
        case '/': {
            result = a / b;
            break;
        }
        default: {
            result = 0;
            break;
        }
    }
    printf ("%f %s %f = %f", a, operator, b, result);
}
