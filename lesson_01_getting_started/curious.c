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

int main (void) {
    printf ("What's your name? ");
    char name [256];
    scanf ("%s", name);
    
    printf ("How old are you? ");
    int age;
    scanf ("%d", &age);
    
    printf ("How much money is on your banking account? ");
    float amount;
    scanf ("%f", &amount);
    
    printf ("Well hello %s, so nice to meet you.\n", name);
    printf ("Not to be impolite, %s, but %.2f is a lot of money for someone of only %d years old.\n", name, amount, age);
    printf ("You'd better give me some of it, to guard it for you...\n");
    
    return 0;
}
