#ifndef TOOLS_H
#define TOOLS_H

/***************************************************************************
 *  clearBuffer
 *  Leert den Eingabepuffer, um Eingabereste zu entfernen.
 *  Parameter: keine
 *  Ergebnis : nichts
 ***************************************************************************/
void clearBuffer();

/***************************************************************************
 *  askAgain
 *  Fragt den Benutzer, ob das Programm erneut ausgefuehrt werden soll
 *  Parameter: Row, Col: Zeile und Spalte, an der die Benutzerabfrage beginnt
 *  Ergebnis : Gibt 1 zurueck, wenn erneut ausgefuehrt werden soll, sonst 0
 ***************************************************************************/
int askAgain(int Row, int Col);

#endif // TOOLS_H
