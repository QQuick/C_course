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

#include "hello.h"
#include "goodbye.h"

/*
A .c file and the correspondng .h file together constitute a module.
The .h file specifies the interface of this module, the .c file its implementation.
To inventorize what a module has to offer, look at the header, that should be self explanatory, by explicit coding style and/or comments.
Look up the notion of "Literate programming" on the Internet.
There's only one module that doesn't have a .h file, namely the module containing the "main" function.

Modules should form a hierarchy that can be divided into layers, in this case:

- Top layer:    "main" module
- Middle layer: "hello" module and "goodbye" module
- Bottom layer: "base" module

Design guidelines:

1. .h files contain only declarations
2. .c files contain definitions
3. Modules from higher layers can use modules from lower layers, hence can #include their headers
4. Modules from lower layers should NOT use modules from higher layers
5. Don't declare variables in headers, only functions and datatypes (and, once you stepped up to C++: classes)
*/

// Definition
int main () {
    char name [] = "Peter Pan";
    
    printf ("\n");
    sayHello (name);
    printf ("I never want to grow up...\n");
    sayGoodbye (name);
    printf ("\n");
    
    return 0;
}