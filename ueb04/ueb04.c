#include <stdio.h>

//Einbinden der Header-Datei math.h um Zugriff auf die sqrt und pow Funktionen zu erhalten
#include <math.h>

int main() {
	
	double p, q;
	
	//Deklarieren der Variablen Ergebnis1 und Ergebnis2 die die Werte von x1 und x2 erhalten werden
	double Ergebnis1, Ergebnis2; 

	
	printf("\n \n \n|-------------------------------------------------------------------|\n");
	printf("| Dieses Programm loest eine quadratische Gleichung zweiten Grades: |\n");
	printf("| x^2 + p * x + p = 0                                               |\n");
	printf("|                                                                   |\n");
	printf("| Geben Sie bitte die Faktoren p und q ein:                         |\n");
	printf("|-------------------------------------------------------------------|\n");
	

	//Hier wird der Userinput abgefragt und in den Variablen p und q gespeichert
	//Es fehlt noch eine Funktion zum überprüfen der Inputabfragen um falschen Input wie Text abzulehnen
	printf("p = ");
	scanf("%lf", &p);

	printf("q = ");	
	scanf("%lf", &q);	
	
	//Berechung der Werte für x1 und x2 mithilfe der sqrt (Wurzel) und pow (Potenz)
	Ergebnis1 = -(p / 2) + sqrt(pow(p / 2, 2) - q);
	Ergebnis2 = -(p / 2) - sqrt(pow(p / 2, 2) - q);
	
	printf("|-------------------------------------------------------------------|\n");
	printf("| Es wird nun die quadratische Gleichung zweiten Grades             |\n");
	printf("| x^2 + %8.2f * x + %8.2f = 0                                 |\n", p, q);	
	printf("| geloest.                                                          |\n");
	printf("|                                _____________________________      |\n");
	printf("|           1             +     /  %8.2f ^ 2               \\     |\n", p);
	printf("| x    = - --- * %8.2f - \\  /  ------------- - %-8.2f          |\n", p, q);
	printf("|  1,2      2                \\/         2                           |\n");
	printf("|                                                                   |\n");
	printf("| x1 = %-8.2f                                                     |\n", Ergebnis1);
	printf("| x2 = %-8.2f                                                     |\n", Ergebnis2);
	printf("|-------------------------------------------------------------------|\n");
	

	return 0;
}
