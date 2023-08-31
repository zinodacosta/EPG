#include<stdio.h>

//Terminrechner


// Aufgabe 1, Strukturtyp TMyDateTime mit folgende Variablen:
struct TMyDateTime
{
	int Tag;
	int Monat;
	int Jahr;
	int Stunde;
	int Minute;
} T;



// Aufgabe 2, Funktion isLeapYear, return 1 falls ein Schaltjahr bevorsteht, sonst return 0;
int isLeapYear(int year)
{
	if ((year % 100 == 0 && year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
	{
		return 1;
	}
	else return 0;
}



// Aufgabe 3, Eingabe etliche Werte
void writeDateTime(struct TMyDateTime T)
{
	printf_s("Der Datum lautet: ");
	printf_s("%.2i.%.2i.%.4i %.2i:%.2i\n", T.Tag, T.Monat, T.Jahr, T.Stunde, T.Minute);
}



// Aufgabe 4, überprüfen der eingegebenen werte
void readDateTime(struct TMyDateTime *T)
{

	int day, month, year, hour, minute;

	printf_s("Geben Sie folgende Werte ein:\nDas Jahr "); //Eingabe Jahr
	scanf_s("%i", &year);
	T->Jahr = year;

	printf_s("Das Jahr lautet: %i\nDer Monat (zwischen 1 bis 12): ", year); //Eingabe Monat

do                                             //überprüft ob eingegeben Monat zwischen 1 und 12 liegen;
{
	scanf_s("%i", &month);
} while (month < 1 || month > 12);

int x = 0;
printf_s("Das Jahr lautet %i der Monat %i, geben Sie nun einen Tag an ", year, month); //Eingabe Tag
do                                             //uberprüft ob tag zum monat passt und ob >0 & <31;
{
	scanf_s("%i", &day);
	switch (month)
	{
	case 1: x = 31;
		break;

	case 2: x = 28 + isLeapYear(year);
		break;

	case 3: x = 31;
		break;

	case 4: x = 30;
		break;

	case 5: x = 31;
		break;

	case 6: x = 30;
		break;

	case 7: x = 31;
		break;

	case 8: x = 31;
		break;

	case 9: x = 30;
		break;

	case 10: x = 31;
		break;

	case 11: x = 30;
		break;

	case 12: x = 31;
		break;

	default:
		printf_s("Nochmal lesen ! ! !");
		break;
	}
} while (day < 1 || day > x++);

printf_s("Das Datum lautet: %i.%i.%i. Und nun die Stunde: ", day, month, year);
do
{
	scanf_s("%i", &hour);
} while (hour < 0 || hour > 23);

printf_s("Das Datum lautet: %i.%i.%i. Zeit:%i Und nun die Minuten: ", day, month, year, hour);
do
{
	scanf_s("%i", &minute);
} while (minute < 0 || minute > 59);

printf_s("\nKontorlle: %.2i.%.2i.%.4i %.2i:%.2i\n", day, month, year, hour, minute);


T->Jahr = year;				//Werte werden T übergeben
T->Monat = month;
T->Tag = day;
T->Stunde = hour;
T->Minute = minute;


/*strcpy(*T->Tag, "day");
strcpy(*T->Monat, "month");
strcpy(*T->Jahr, "year");

strcpy(*T->Stunde, "hour");
strcpy(*T->Minute, "minute");*/

}



// Aufgabe 5,
void calcDateTime(struct TMyDateTime *T, int hours)
{

	T->Stunde = T->Stunde + hours;

	while (T->Stunde > 23)
	{
		T->Tag++;
		T->Stunde = T->Stunde - 24;
	}

	int A5tage, status = 0, tempMonat = T->Monat, tempJahr = T->Jahr;
	do                    //uberprüft ob tag zum monat passt und ob >0 & <31;
	{
		A5tage = checkTage(tempMonat, tempJahr);
		if (T->Tag > A5tage)
		{
			T->Monat++;
			T->Tag = T->Tag - A5tage;

			tempMonat++;
			if (tempMonat > 12)
			{
				tempMonat = tempMonat - 12;
				tempJahr++;
			}
		}
		else (status = 1);

	} while (status != 1);

	while (T->Monat > 12)
	{
		T->Jahr++;
		T->Monat = T->Monat - 12;
	}
}



// für Aufgabe5, Prüfung: Tage pro aktuelle Monat
int checkTage(A5monat, A5jahr)
{
	int x = 0;

	switch (A5monat)
	{
	case 1: x = 31;
		break;

	case 2: x = 28 + isLeapYear(A5jahr);
		break;

	case 3: x = 31;
		break;

	case 4: x = 30;
		break;

	case 5: x = 31;
		break;

	case 6: x = 30;
		break;

	case 7: x = 31;
		break;

	case 8: x = 31;
		break;

	case 9: x = 30;
		break;

	case 10: x = 31;
		break;

	case 11: x = 30;
		break;

	case 12: x = 31;
		break;

	default:
		printf_s("Nochmal lesen ! ! !");
		break;
	}
	return x;
}  //checkt nochmal ob die monate 28, 29, 30 oder 31 tage hat




// main:
int main()
{
	struct TMyDateTime T;
	int hhours = 0;
	int abfrage = 0;

	readDateTime(&T);
	writeDateTime(T);

	do
	{
		printf_s("\n\nWie viele Stunden sollen dazugerechnet werden?\n");
		scanf_s("%i", &hhours);

		calcDateTime(&T, hhours);
		writeDateTime(T);

		printf_s("\n\nWeitere Stunden addieren? (1=Ja, 0=Nein)\n");
		scanf_s("%i", &abfrage);

	} while (abfrage == 1);
}
