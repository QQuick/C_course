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
#include <math.h>

int main () {
    char action [] = "p";
    
    for (int base = 0; base < 4; base++) {
        for (int exponent = 0; exponent < 4; exponent++) {  // Nested "for"s are commonplace and useful
            if (!strcmp (action, "g")) {
                goto exit;                                  // Use "goto" ONLY to jump out of inner loop (there are alternatives)
            }
            else if (!strcmp (action, "c")) {
                strcpy (action, "p");
                continue;                                   // Use of "continue" is rare, in this case it's better to put the loop tail inside an "else" block
            }
            
            printf ("%d ^ %d = %f, proceed, continue after next, goto exit <p/c/g>? ", base, exponent, pow (base, exponent));
            scanf ("%s", action);
        }  
    }
    
    exit: return 0;
}
