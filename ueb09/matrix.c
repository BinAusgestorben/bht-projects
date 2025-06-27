#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matrix.h"
#include "escapesequenzen.h"
#include "tools.h"

int const MaxRows = 8;
int const MaxColumns = 8;

// Prüft, ob der Benutzer nur ENTER gedrückt hat
static int ersteEingabePruefen(void) {
    char zeichen = getchar();
    if (zeichen == '\n') return 0;
    ungetc(zeichen, stdin);
    return 1;
}

int getNumberOfRows(int Row, int Col, int MatrixNo) {
    int value;
    do {
        POSITION(Row, Col);
        CLEAR_LINE;
        printf("Geben Sie bitte die Zeilenanzahl der %d. Matrix ein (1..%d): ", MatrixNo, MaxRows);
        if (!ersteEingabePruefen()) continue;
        if (scanf("%d", &value) != 1) clearBuffer();
    } while (value < 1 || value > MaxRows);
    clearBuffer();
    return value;
}

int getNumberOfColumns(int Row, int Col, int MatrixNo) {
    int value;
    do {
        POSITION(Row, Col);
        CLEAR_LINE;
        printf("Geben Sie bitte die Spaltenanzahl der %d. Matrix ein (1..%d): ", MatrixNo, MaxColumns);
        if (!ersteEingabePruefen()) continue;
        if (scanf("%d", &value) != 1) clearBuffer();
    } while (value < 1 || value > MaxColumns);
    clearBuffer();
    return value;
}

static void printEmptyMatrix(int RowCount, int ColCount, int Row, int Col) {
    for (int i = 0; i < RowCount; i++) {
        POSITION(Row + i, Col);
        printf("|");
        for (int j = 0; j < ColCount; j++) {
            printf(" ____");
        }
        printf(" |");
    }
}

void getMatrix(int Row, int Col, int RowCount, int ColCount, int Matrix[MaxRows][MaxColumns]) {
    printEmptyMatrix(RowCount, ColCount, Row, Col);
    for (int i = 0; i < RowCount; i++) {
        for (int j = 0; j < ColCount; j++) {
            int xpos = Col + 2 + j * 5;
            int ypos = Row + i;
            char input[10];
            int zahl;
            while (1) {
                POSITION(ypos, xpos);
                printf("____");
                POSITION(ypos, xpos);
                if (!ersteEingabePruefen()) continue;

                fgets(input, sizeof(input), stdin);
                if (strlen(input) > 5) input[5] = '\0'; // max 5 Zeichen (inkl. \n)

                char gekuerzt[5];
                strncpy(gekuerzt, input, 4);
                gekuerzt[4] = '\0';

                char *endptr;
                zahl = (int)strtol(input, &endptr, 10);
                if (endptr != input) {
                    if (zahl >= -999 && zahl <= 9999) {
                        Matrix[i][j] = zahl;
                        POSITION(ypos, xpos);
                        printf("%4d", Matrix[i][j]);
                        if (strlen(input) > 4) {
                            POSITION(ypos, xpos + 4);
                            printf(" ");
                        }
                        break;
                    }
                }
                POSITION(ypos, xpos);
                printf("____");
            }
        }
    }
}

void calcMatrix(int RowCount1, int ColCount1, int ColCount2,
                int M1[MaxRows][MaxColumns], int M2[MaxRows][MaxColumns], int MErg[MaxRows][MaxColumns]) {
    for (int i = 0; i < RowCount1; i++) {
        for (int j = 0; j < ColCount2; j++) {
            MErg[i][j] = 0;
            for (int k = 0; k < ColCount1; k++) {
                MErg[i][j] += M1[i][k] * M2[k][j];
            }
        }
    }
}

int anzahlZiffern(int zahl) {
    if (zahl == 0) return 1;
    if (zahl < 0) zahl = -zahl;
    int count = 0;
    while (zahl > 0) {
        zahl /= 10;
        count++;
    }
    return count;
}

void printMatrix(int Row, int Col, int RowCount, int ColCount, int Matrix[MaxRows][MaxColumns]) {
    int maxWidth = 4;
    for (int i = 0; i < RowCount; i++) {
        for (int j = 0; j < ColCount; j++) {
            int len = anzahlZiffern(Matrix[i][j]);
            if (Matrix[i][j] < 0) len++; // Platz für Minuszeichen
            if (len > maxWidth) maxWidth = len;
        }
    }
    for (int i = 0; i < RowCount; i++) {
        POSITION(Row + i, Col);
        printf("|");
        for (int j = 0; j < ColCount; j++) {
            printf(" %*d", maxWidth, Matrix[i][j]);
        }
        printf(" |");
    }
}
