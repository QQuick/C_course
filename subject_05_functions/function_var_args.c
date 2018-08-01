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
#include <stdarg.h>

float average (int nrOfVarArgs, ...) {
    va_list argp;
    va_start (argp, nrOfVarArgs);
    
    float sum = 0;
    for (int varArgIndex = 0; varArgIndex < nrOfVarArgs; varArgIndex++) {
        float arg = va_arg (argp, double);
        printf ("Argument: %.2f\n", arg);
        sum += arg;
    }
    
    va_end (argp);
    return sum / nrOfVarArgs;
}

int main () {    
    printf ("Average is: %.2f\n\n", average (
        3,
        9.5, 20.0, 40.5
    ));
    
    printf ("Average is: %.2f\n\n", average (
        9,
        1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0
    ));
    
    return 0;
}
