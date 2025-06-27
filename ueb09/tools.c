#include <stdio.h>
#include "tools.h"
#include "escapesequenzen.h"

void clearBuffer() {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}

int askAgain(int Row, int Col) {
    char eingabe;
    POSITION(Row, Col);
    CLEAR_LINE;
    printf("Moechten Sie noch einmal (j/n) ? ");
    do {
        eingabe = getchar();
        clearBuffer();
        eingabe = (eingabe >= 'A' && eingabe <= 'Z') ? eingabe + 32 : eingabe; // Groß -> klein
        if (eingabe != 'j' && eingabe != 'n') {
            POSITION(Row + 1, Col);
            CLEAR_LINE;
            printf("Ungueltige Eingabe. Bitte 'j' oder 'n' eingeben: ");
        }
    } while (eingabe != 'j' && eingabe != 'n');
    return eingabe == 'j';
}
