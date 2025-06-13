#include <stdio.h>
#include <stdlib.h>
#include "escapesequenzen.h"

// Funktionsdeklarationen
void rahmenAusgeben();
short zahlEinlesen(int zeile);
void zahlAusgeben(int zeile, short wert);
char operatorEinlesen();
void operatorAusgeben(char op);
short ergebnisBerechnen(short z1, short z2, char op);
void binaerAusgeben(short wert);
void ergebnisTabelleAusgeben(int zeile, short wert);
void operatorTabelleAusgeben(char op);
int nochmalFragen();
void eingabepufferLeeren();
int ersteEingabePruefen(void);
void eingabezeileLeeren(int zeile);
void fehlermeldung(const char* meldung);




int main() {
    do {
        short operand1, operand2, ergebnis;
        char operator;

        rahmenAusgeben();

        operand1 = zahlEinlesen(4);
        zahlAusgeben(4, operand1);

        operator = operatorEinlesen();
        operatorAusgeben(operator);

        operand2 = zahlEinlesen(6);
        zahlAusgeben(6, operand2);

        ergebnis = ergebnisBerechnen(operand1, operand2, operator);

        ergebnisTabelleAusgeben(11, operand1);
        operatorTabelleAusgeben(operator);
        ergebnisTabelleAusgeben(13, operand2);
        ergebnisTabelleAusgeben(15, ergebnis);

    } while (nochmalFragen());

    return 0;
}



/**
 * Was macht die Funktion:
 *   Prüft, ob der Benutzer eine Eingabe gemacht hat oder nur Enter gedrückt wurde.
 *
 * Was gibt sie zurück:
 *   1 → Eingabe vorhanden  
 *   0 → Eingabe war leer (nur Enter gedrückt)
 */
int ersteEingabePruefen(void) {
    char zeichen = getchar();
    if (zeichen == '\n') {
        return 0; // Leere Eingabe
    }
    ungetc(zeichen, stdin);  // zurück in den Eingabestrom
    return 1;
}



/**
 * Was macht die Funktion:
 *   Löscht die Eingabezeile an einer gegebenen Bildschirmzeile und positioniert den Cursor neu.
 *
 * Beschreibung der Parameter:
 *   Die Bildschirmzeile, in der die Eingabezeile geleert und der Cursor positioniert wird.
 */
void eingabezeileLeeren(int zeile) {
    POSITION(zeile, 20);
    printf("                ");
    POSITION(zeile, 20);
}



/**
 * Was macht die Funktion:
 *   Entfernt alle restlichen Zeichen aus dem Eingabepuffer bis zum nächsten Zeilenumbruch.
 */
void eingabepufferLeeren() {
    while (getchar() != '\n');
}



/**
 * Was macht die Funktion:
 *   Gibt den kompletten Rahmen aus.
 */
void rahmenAusgeben() {
    CLEAR;
    HOME;
    printf("|----------------------------------------------------------|\n");
    printf("| Bitoperatoren-Rechner                                    |\n");
    printf("|                                                          |\n");
    printf("| Eingabe Zahl 1:                                          |\n");
    printf("| Operator:                                                |\n");
    printf("| Eingabe Zahl 2:                                          |\n");
    printf("|                                                          |\n");
    printf("|----------------------------------------------------------|\n");
    printf("|                                                          |\n");
    printf("|          |  dez.  |  okt.   |  hex.  | Binaerdarstellung |\n");
    printf("| Zahl 1   |        |         |        |                   |\n");
    printf("| Operator |        |         |        |                   |\n");
    printf("| Zahl 2   |        |         |        |                   |\n");
    printf("| -------------------------------------------------------- |\n");
    printf("| Ergebnis |        |         |        |                   |\n");
    printf("|                                                          |\n");
    printf("|----------------------------------------------------------|\n");
}



/**
 * Was macht die Funktion:
 *   Liest eine gültige Ganzzahl vom Benutzer ein und prüft auf Eingabe- und Formatfehler.
 *
 * Beschreibung der Parameter:
 *   Die Bildschirmzeile, in der der Benutzer die Zahl eingeben soll.
 *
 * Was gibt sie zurück:
 *   Der korrekt eingelesene Zahlenwert.
 */
short zahlEinlesen(int zeile) {
    short zahl;
    int status;

    while (1) {
        eingabezeileLeeren(zeile);
        printf(">> ");


	if (!ersteEingabePruefen()) {
            POSITION(6, 20);
            printf("                ");
            fehlermeldung("Eingabe darf nicht leer sein.");
            POSITION(5, 20);
            continue;
        }


        status = scanf("%hd", &zahl);

        if (status == 1) {
            eingabepufferLeeren();
            POSITION(18, 1);
            CLEAR_LINE;
            return zahl;
        } else {
            eingabepufferLeeren();
            POSITION(zeile, 20);
            printf("                ");
            fehlermeldung("Ungültige Eingabe! Bitte mit einer Zahl beginnen.");
            POSITION(zeile, 20);
        }
    }
}



/**
 * Was macht die Funktion:
 *   Gibt einen short-Wert an einer bestimmten Bildschirmzeile aus.
 *
 * Beschreibung der Parameter:
 *   Zeile zur Positionierung der Ausgabe.  
 *   Der auszugebende Wert.
 */
void zahlAusgeben(int zeile, short wert) {
    eingabezeileLeeren(zeile);
    printf("%hd", wert);
}



/**
 * Was macht die Funktion:
 *   Liest einen gültigen Operator vom Benutzer ein und prüft ihn auf Zulässigkeit.
 *
 * Was gibt sie zurück:
 *   Den eingelesenen gültigen Operator.
 */
char operatorEinlesen() {
    char op;
    while (1) {
        eingabezeileLeeren(5);
        printf(">> ");

	if (!ersteEingabePruefen()) {
            POSITION(5, 20);
            printf("                ");
            fehlermeldung("Eingabe darf nicht leer sein.");
            POSITION(5, 20);
            continue;
        }


        scanf(" %c", &op);
        eingabepufferLeeren();

        if (op == '&' || op == '|' || op == '^' || op == '<' || op == '>' ||
            op == '+' || op == '-' || op == '*' || op == '/' || op == '%') {
            POSITION(18, 1);
            CLEAR_LINE;
            return op;
        }

        POSITION(5, 20);
        printf("                ");
        fehlermeldung("Ungültiger Operator! Erlaubt: & | ^ < > + - * / %%");
        POSITION(5, 20);
    }
}



/**
 * Was macht die Funktion:
 *   Gibt einen Operator in die vorgesehene Bildschirmposition aus.
 *
 * Beschreibung der Parameter:
 *   Der darzustellende Operator.
 */
void operatorAusgeben(char op) {
    eingabezeileLeeren(5);
    printf("%c", op);
}



/**
 * Was macht die Funktion:
 *   Führt eine Rechenoperation zweier Ganzzahlen mit dem übergebenen Operator durch.
 *
 * Beschreibung der Parameter:
 *   z1   Erster Operand.  
 *   z2   Zweiter Operand.  
 *   op   Der zu verwendende Operator.
 *
 * Was gibt sie zurück:
 *   Das Ergebnis der Operation.  
 *   Bei Division durch 0 → Rückgabe ist 0.
 */
short ergebnisBerechnen(short z1, short z2, char op) {
    switch (op) {
        case '&': return z1 & z2;
        case '|': return z1 | z2;
        case '^': return z1 ^ z2;
        case '<': return z1 << z2;
        case '>': return z1 >> z2;
        case '+': return z1 + z2;
        case '-': return z1 - z2;
        case '*': return z1 * z2;
        case '/': if (z2 == 0) {
        	      fehlermeldung("Division durch 0 nicht erlaubt!");
                      return 0;
                  }
                  return z1 / z2;
        case '%': if (z2 == 0) {
        	      fehlermeldung("Division durch 0 nicht erlaubt!");
                      return 0;
                  }
                  return z1 % z2;
        default:  return 0;
    }
}



/**
 * Was macht die Funktion:
 *   Gibt die binäre Darstellung eines Wertes aus.
 *
 * Beschreibung der Parameter:
 *   Der Wert, der binär dargestellt werden soll.
 */
void binaerAusgeben(short wert) {
    for (int i = 15; i >= 0; i--) {
        printf("%d", (wert >> i) & 1);
    }
}



/**
 * Was macht die Funktion:
 *   Gibt eine Ergebniszeile aus, bestehend aus dezimaler, oktaler, hexadezimaler und binärer Darstellung eines Wertes.
 *
 * Beschreibung der Parameter:
 *   Bildschirmzeile, in der die Werte ausgegeben werden.  
 *   Der darzustellende Wert.
 */
void ergebnisTabelleAusgeben(int zeile, short wert) {
    char oktal[10];
    char hex[10];

    // Oktal- und Hexadezimal-Wert vorbereiten
    sprintf(oktal, "0%o", (unsigned short)wert);
    sprintf(hex, "0x%x", (unsigned short)wert);

    POSITION(zeile, 12);
    printf("| %6d", wert);
    POSITION(zeile, 21);
    printf("| %7s", oktal);
    POSITION(zeile, 31);
    printf("| %7s", hex);
    POSITION(zeile, 43);
    binaerAusgeben(wert);
}



/**
 * Was macht die Funktion:
 *   Gibt den verwendeten Operator in allen vier Spalten der Ergebnistabelle aus.
 *
 * Beschreibung der Parameter:
 *   Der Operator, der dargestellt werden soll.
 */
void operatorTabelleAusgeben(char op) {
    const char* symbol;

    switch (op) {
        case '<': symbol = "<<"; break;
        case '>': symbol = ">>"; break;
        case '&': symbol = "&"; break;
        case '|': symbol = "|"; break;
        case '^': symbol = "^"; break;
        case '+': symbol = "+"; break;
        case '-': symbol = "-"; break;
        case '*': symbol = "*"; break;
        case '/': symbol = "/"; break;
        case '%': symbol = "%"; break;
        default:  symbol = "?"; break;
    }

    POSITION(12, 12);
    printf("| %7s", symbol);
    POSITION(12, 21);
    printf("| %7s", symbol);
    POSITION(12, 31);
    printf("| %7s", symbol);
    POSITION(12, 43);
    printf("%16s", symbol);
}



/**
 * Was macht die Funktion:
 *   Fragt den Benutzer, ob das Programm erneut ausgeführt werden soll.
 *   Nur 'j'/'J' oder 'n'/'N' sind gültig.
 *
 * Was gibt sie zurück:
 *   1  Benutzer möchte das Programm erneut ausführen.  
 *   0  Benutzer möchte beenden.
 */
int nochmalFragen() {
    char eingabe;
    while (1) {
        POSITION(19, 1);
        CLEAR_LINE;
        printf("Möchten Sie noch einmal (j/n)? ");

	if (!ersteEingabePruefen()) {
            POSITION(18, 20);
            printf("                ");
            fehlermeldung("Eingabe darf nicht leer sein.");
            POSITION(17, 20);
            continue;
        }

        scanf(" %c", &eingabe);
        eingabepufferLeeren();

        if (eingabe == 'j' || eingabe == 'J') return 1;
        if (eingabe == 'n' || eingabe == 'N') return 0;

        POSITION(19, 1);
        CLEAR_LINE;
        printf("Bitte geben Sie nur j oder n ein.");
    }
}



/**
 * Was macht die Funktion:
 *   Gibt eine Fehlermeldung im unteren Bereich des Terminals aus.
 *
 * Beschreibung der Parameter:
 *   Der Text, der als Fehlermeldung angezeigt werden soll.
 */
void fehlermeldung(const char* meldung) {
    POSITION(18, 1);
    CLEAR_LINE;
    printf("%s", meldung);
}
