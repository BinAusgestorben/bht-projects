#ifndef TOOLS_H
#define TOOLS_H


/*******************************************************************************************
 * Was macht die Funktion:
 *   Fragt den Benutzer, ob er das Programm erneut ausführen möchte (j/n).
 *   Ungültige oder leere Eingaben werden wiederholt.
 *
 * Was gibt sie zurück:
 *   1 bei Eingabe von 'j', 0 bei Eingabe von 'n'.
*******************************************************************************************/
int askAgain();


/*******************************************************************************************
 * Was macht die Funktion:
 *   Entfernt alle restlichen Zeichen aus dem Eingabepuffer bis zum nächsten Zeilenumbruch.
*******************************************************************************************/
void clearBuffer();


#endif // TOOLS_H