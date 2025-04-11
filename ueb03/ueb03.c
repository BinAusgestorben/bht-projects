#include <stdio.h>

int main() {

	//Deklaration und Initiierung der Widerstandswerte in Ohm
	double R1 = 1000.0, R2 = 400.0, R3 = 600.0;
	
	//Deklaration und Initiierung der Ergebnisvariablen mit 0.0
	double Ergebnis_Reihenschaltung = 0.0;
	double Ergebnis_Para_Kehrwerte = 0.0;
	double Ergebnis_Para_Gesamt = 0.0;
	double Ergebnis_Messbruecke = 0.0;

	//Berechnung des Gesamtwiderstands bei Reihenschaltung
	Ergebnis_Reihenschaltung = R1 + R2 + R3;
	
	//Berechnnen und addieren der Kehrwerte
	Ergebnis_Para_Kehrwerte = (1.0 / R1) + (1.0 / R2) + (1.0 / R3);
	//Kehrwert der addierten Kehrwerte berechnen
	Ergebnis_Para_Gesamt = 1.0/Ergebnis_Para_Kehrwerte;

	//Berechnen des unbekannten Widerstands mit einer Wheatstoneschen Messbruecke
	Ergebnis_Messbruecke = R3 * (R1 / R2);

	
	//Ausgabe
	printf("Reihenschaltung:\n");
	printf("%f Ohm + %f Ohm + %f Ohm = %f Ohm\n", R1, R2, R3, Ergebnis_Reihenschaltung);

	printf("Parallelschaltung:\n");
	printf("1 / %f Ohm + 1 / %f Ohm +1 / %f Ohm = 1 / %f Ohm\n", R1, R2, R3, Ergebnis_Para_Gesamt);

	printf("Wheatstonesche Messbruecke:\n");
	printf("%f Ohm * %f Ohm / %f Ohm = %f Ohm\n", R3, R1, R2, Ergebnis_Messbruecke);


	return 0;
}



