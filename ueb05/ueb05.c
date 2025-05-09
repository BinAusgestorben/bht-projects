#include <stdio.h>

int main() {

// Variable um das Ende des Programmes zu bestimmen
int ender = 0;

	do {

		// Variablen zum löschen des Eingabepuffers und zum erkennen einer Enter eingabe
		char Dummy, Fortfahren;
		// Die vom User eingegebene ganze Zahl
		double Zahl = 1;
		// Rückgabewert von scanf
		int Anz;

		printf("\nGeben Sie bitte eine ganze Zahl ein: ");
		
		// Erstes Zeichen aus Eingabepuffer holen
		int first = getchar();

		// Erkennen ob die erste Eingabe ein Enter war 
		if (first == '\n') {
			printf("Sie haben keine Zahl eingegeben.\n\n");
		} else {
	
			// Erstes Zeichen wieder in den Eingabepuffer zurücklegen
			ungetc(first, stdin);

			// Eingabe in variable Zahl speichern und Rückgabewert von scanf in Anz speichern
			Anz = scanf("%lf", &Zahl);

			// Eingabepuffer leeren
			while ((Dummy = getchar()) != '\n' && Dummy != EOF);

			if (Anz == 0) {
				printf("Sie haben keine Zahl eingegeben.\n\n");
			} else {
				printf("Sie haben die ganze Zahl %.0f eingegeben.\n\n", Zahl);
			}
		}

		// Variable um das Ende der 'Möchten Sie noch einmal' Abfrage zu bestimmen
		int nochmal = 0;

		do {
			printf("Möchten Sie noch einmal (j/n)? ");
			scanf("%c", &Fortfahren);
	
			// Überprüfen ob die erste Eingabe ein Enter ist
			if (Fortfahren == '\n') {
				printf("Falsche Eingabe! Bitte 'j' oder 'n' eingeben!\n\n");
				continue;
			}

			// Eingabpuffer leeren
			while ((Dummy = getchar()) != '\n' && Dummy != EOF);

			if (Fortfahren == 'j' || Fortfahren == 'J') {
				ender = 0;
				nochmal = 1;
			} else if (Fortfahren == 'n' || Fortfahren == 'N') {
				ender = 1;
				nochmal = 1;
			} else {
				printf("Falsche Eingabe! Bitte 'j' oder 'n' eingeben!\n\n");
			}
		} while (!nochmal);

	} while (!ender);

return 0;
}
