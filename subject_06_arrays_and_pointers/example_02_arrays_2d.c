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
