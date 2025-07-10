#include <stdio.h>
#include "tools.h"
#include "escapesequenzen.h"



/*******************************************************************************************
 * Was macht die Funktion:
 *   Prüft, ob der Benutzer bei der Texteingabe eine leere Eingabe (nur Enter) gemacht hat.
 *
 * Was gibt sie zurück:
 *   1, wenn ein Zeichen eingegeben wurde, 0 bei Leereingabe.
*******************************************************************************************/
static int ersteEingabePruefen(void) {
	char zeichen = getchar();
	if (zeichen == '\n') return 0;
	ungetc(zeichen, stdin);
	return 1;
}


void clearBuffer() {
	int ch;
	while ((ch = getchar()) != '\n' && ch != EOF);
}


int askAgain() {
	char eingabe;

	while (1) {
		CLEAR_LINE;
		printf("Moechten Sie noch einmal (j/n) ? ");

		if (!ersteEingabePruefen()) {
			// Leere Eingabe -> Frage wiederholen
			continue;
		}

		eingabe = getchar();
		clearBuffer();

		// Großbuchstaben in Kleinbuchstaben umwandeln
		if (eingabe >= 'A' && eingabe <= 'Z') {
			eingabe += 32;
		}

		if (eingabe == 'j' || eingabe == 'n') {
			return eingabe == 'j';
		}

		CLEAR_LINE;
		printf("Ungueltige Eingabe. Bitte 'j' oder 'n' eingeben:\n");
	}
}