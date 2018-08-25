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

int const dimension = 10;

int const cruiserLength = 4;
int const destroyerLength = 3;
int const zephyrLength = 2;

void addWater (char sea [][dimension]) {
    for (int rowIndex = 0; rowIndex < dimension; rowIndex++) {
        for (int columnIndex = 0; columnIndex < dimension; columnIndex++) {
            sea [rowIndex][columnIndex] = '.';
        }
    }
}

void addShip (char sea [][dimension], int rowIndex, int columnIndex, int shipLength, bool vertical) {
    // Habit: if outside loop for better performance
    if (vertical) {
        for (int offset = 0; offset < shipLength; offset++) {
            sea [rowIndex + offset][columnIndex] = 'X';
        }
    }
    else {
        for (int offset = 0; offset < shipLength; offset++) {
            sea [rowIndex][columnIndex + offset] = 'X';
        }
    }
}

void showAll (char sea [][dimension]) {
    for (int rowIndex = 0; rowIndex < dimension; rowIndex++) {
        for (int columnIndex = 0; columnIndex < dimension; columnIndex++) {
            printf ("%c ", sea [rowIndex][columnIndex]);
        }
        printf ("\n");
    }
    printf ("\n");
}

int main () {
    char sea [dimension][dimension];    
    // A field is of type char
    // So a row is of type char *
    // So the whole sea is of type char **

    addWater (sea);
    
    addShip (sea, 2, 3, cruiserLength, false);
    addShip (sea, 4, 5, destroyerLength, true);
    addShip (sea, 8, 2, zephyrLength, false);
    
    showAll (sea);

    return 0;
}
