#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "escapesequenzen.h"
#include "tools.h"

void resetArray(int *Anzahl);
void printTitle();
void getText(char *T);
void countChar(char *T, int *A);
void setUpper2Lower(int *A);
void printTable(int *A);



int main()
{
	do
	{
		CLEAR;
		HOME;
		char Text[151];
		int Anzahl[256];

		resetArray(Anzahl);
		printTitle();
		getText(Text);
		countChar(Text, Anzahl);
		setUpper2Lower(Anzahl);
		printTable(Anzahl);
	} while (askAgain());
	CLEAR;
	HOME;
	printf("Programm wurde beendet!\n\n");
	return 0;
}



/*******************************************************************************************
 * Was macht die Funktion:
 *   Gibt den Titel und eine kurze Anleitung zur Eingabe auf dem Bildschirm aus.
*******************************************************************************************/
void printTitle(){
	printf("========================\n");
	printf("||                    ||\n");
	printf("||   Zeichenzaehler   ||\n");
	printf("||                    ||\n");
	printf("========================\n\n");
	printf("Geben Sie bitte den Text ein (mind. 1 Zeichen / max. 150 Zeichen),\n");
	printf("dessen Zeichen gezaehlt werden sollen:\n");
}



/*******************************************************************************************
 * Was macht die Funktion:
 *   Liest eine Texteingabe vom Benutzer ein (max. 150 Zeichen).
 *   Leere Eingaben werden abgefangen, bis eine gültige Eingabe erfolgt.
 *
 * Beschreibung der Parameter:
 *   Text:  Ein Zeichenarray, in das der eingegebene Text geschrieben wird.
*******************************************************************************************/
void getText(char *Text) {
	while (1) {
		*Text = '\0';
		scanf("%150[^\n]", Text);
		clearBuffer();

		if (*Text == '\0') {
			POSITION(9, 0);
			printf("                ");
			POSITION(9, 0);
			continue;
		} else {
			break;  // Text wurde erfolgreich eingegeben
		}
	}
}



/*******************************************************************************************
 * Was macht die Funktion:
 *   Zählt die Häufigkeit aller Zeichen im übergebenen Text.
 *
 * Beschreibung der Parameter:
 *   Text:  Der eingegebene Text.
 *   Anzahl:  Array, in dem die Häufigkeit der Zeichen gespeichert wird.
*******************************************************************************************/
void countChar(char *Text, int *Anzahl){

	char *ptrText = Text;

	while ( *ptrText )
	{
		Anzahl[(unsigned char)*ptrText]++;
		ptrText++;
	}
}



/*******************************************************************************************
 * Was macht die Funktion:
 *   Addiert die Häufigkeiten von Großbuchstaben auf die entsprechenden Kleinbuchstaben
 *   und setzt die Werte der Großbuchstaben auf 0.
 *
 * Beschreibung der Parameter:
 *   Anzahl:  Zeichenhäufigkeiten, die angepasst werden.
*******************************************************************************************/
void setUpper2Lower(int *Anzahl){
	int i = 0;
	for (i = 'a'; i <= 'z'; i++)
	{
		*(Anzahl + i) += *(Anzahl + i -32);
		*(Anzahl + i -32) = 0;
	}
}



/*******************************************************************************************
 * Was macht die Funktion:
 *   Setzt alle Werte im übergebenen Array auf 0 zurück.
 *
 * Beschreibung der Parameter:
 *   Anzahl:  Ein Array mit 256 Elementen zur Speicherung von Zeichenhäufigkeiten.
*******************************************************************************************/
void resetArray(int *Anzahl){
	int i = 0;
	for (i = 0; i < 256; i++) {
		Anzahl[i] = 0;
	}
}



/*******************************************************************************************
 * Was macht die Funktion:
 *   Gibt eine formatierte Übersicht aller gezählten Zeichen und deren Häufigkeit aus.
 *
 * Beschreibung der Parameter:
 *   Anzahl:  Das Array mit den gezählten Zeichenhäufigkeiten.
*******************************************************************************************/
void printTable(int *Anzahl) {
	printf("\nAnzahl der Zeichen:\n");
	printf("---------------------------------------------------------------------\n");
	int count = 0;
	int i = 0;
	for (i = 0; i < 256; i++) {
		if (Anzahl[i] > 0) {
			// Nur druckbare Zeichen zwischen ASCII 32 und 126
			char ch = (i >= 32 && i <= 126) ? (char)i : ' ';

			printf("| %2c (0x%02x): %3d ", ch, i, Anzahl[i]);
			count++;

			// Nach 4 Einträgen Zeilenumbruch
			if (count % 4 == 0) {
				printf("|\n");
			}
		}
	}
	if (count % 4 != 0) {
		int rest = 4 - (count % 4);
		int i = 0;
		for (i = 0; i < rest; i++) {
			printf("|                ");
		}
		printf("|\n");
	}
	printf("---------------------------------------------------------------------\n");
}