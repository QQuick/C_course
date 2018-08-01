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
#include <stdbool.h>

int main () {    
    printf ("Do you like hardware? <y|n>");
    char hardwareAnswer [2];
    scanf ("%s", hardwareAnswer);
    
    printf ("Do you like software? <y|n>");
    char softwareAnswer [2];
    scanf ("%s", softwareAnswer);
    bool likesSoftware = !strcmp (softwareAnswer, "y");
    
    if (!strcmp (hardwareAnswer, "y")) {
        if (likesSoftware) {
            printf ("You'll feel quite at home here!");
        }
        else {
            printf ("Maybe the electronics department suits you better...");
        }
    }
    else {
        if (likesSoftware) {
            printf ("Maybe the informatics department suits you better...");
        }
        else {
            printf ("What are you doing here?");
        }
    }    
}
