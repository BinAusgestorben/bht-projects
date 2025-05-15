#include <stdio.h>
#include <stdlib.h>
#include "escapesequenzen.h"

int main() {
	double Op1, Op2, Erg;
	int menuAuswahl, eingabeGueltig;
	int pufferZeichen;

	do {
		CLEAR;
		HOME;

		// Grundmenü anzeigen
		printf("Einfacher Taschenrechner\n");
		printf("========================\n");
		printf("1. Addition\n");
		printf("2. Subtraktion\n");
		printf("3. Multiplikation\n");
		printf("4. Division\n");
		printf("9. Programmende\n");
		printf("Ihre Wahl: ");

		// Benutzereingabe verarbeiten
		eingabeGueltig = 1;
		if(scanf("%d", &menuAuswahl) != 1) {
			eingabeGueltig = 0;
			while((pufferZeichen = getchar()) != '\n' && pufferZeichen != EOF);
			printf("Numerische Eingabe erforderlich\n");
		}

		// Menüvalidierung
		if(eingabeGueltig) {
			switch(menuAuswahl) {
				case 1:	printf("\nAddition\n--------\n"); break;
				case 2:	printf("\nSubtraktion\n-----------\n"); break;
				case 3:	printf("\nMultiplikation\n--------------\n"); break;
				case 4:	printf("\nDivision\n--------\n"); break;
				case 9:	break;
				default:
					eingabeGueltig = 0;
					printf("Ungültige Menüoption\n");
			}
		}

		// Operandenverarbeitung
		if(eingabeGueltig && menuAuswahl != 9) {
			// Erster Operand
			do {
				printf("Geben Sie bitte den ersten Operanden ein: ");
				if(scanf("%lf", &Op1) != 1) {
					while((pufferZeichen = getchar()) != '\n' && pufferZeichen != EOF);
					printf("Zahl erwartet\n");
					continue;
				}
				break;
			} while(1);

			// Zweiter Operand
			do {
				printf("Geben Sie bitte den zweiten Operanden ein: ");
				if(scanf("%lf", &Op2) != 1) {
					while((pufferZeichen = getchar()) != '\n' && pufferZeichen != EOF);
					printf("Zahl erwartet\n");
					continue;
				}

				// Division durch Null verhindern
				if(menuAuswahl == 4 && Op2 == 0.0) {
					printf("Division durch Null\n");
					continue;
				}
				break;
			} while(1);

			// Arithmetische Operation
			switch(menuAuswahl) {
				case 1:
					Erg = Op1 + Op2;
					printf("\n%.2f + %.2f = %.2f\n", Op1, Op2, Erg);
					break;
				case 2:
					Erg = Op1 - Op2;
					printf("\n%.2f - %.2f = %.2f\n", Op1, Op2, Erg);
					break;
				case 3:
					Erg = Op1 * Op2;
					printf("\n%.2f * %.2f = %.2f\n", Op1, Op2, Erg);
					break;
				case 4:
					Erg = Op1 / Op2;
					printf("\n%.2f / %.2f = %.2f\n", Op1, Op2, Erg);
					break;
			}

			// Programmfortsetzung
			printf("\nEnter zum Fortfahren...");
			while((pufferZeichen = getchar()) != '\n' && pufferZeichen != EOF);
			getchar();
		}

	} while(menuAuswahl != 9);

	// Programmabschluss
	printf("Enter zum Beenden...");
	while((pufferZeichen = getchar()) != '\n' && pufferZeichen != EOF);
	getchar();
	printf("\nProgramm beendet\n");

	return 0;
}
