#include <stdio.h>
#include<stdlib.h>

int eingabe_zaehler();
int eingabe_nenner();
void ausgabe_bruch(int Nenner, int Zaehler);
void kuerzen(int Nenner, int Zaehler, int GGT, int *ZurueckN, int *ZurueckZ);
int ggT(int a, int b);

int main()
{
	int Z, N, gekuerzt, Teiler;
	int returnN = 0, returnZ = 0;

	Z = eingabe_zaehler();
	N = eingabe_nenner();
	ausgabe_bruch(N, Z);

	Teiler = ggT(N, Z);
	printf("ggT ist %i\n", Teiler);

	kuerzen(N, Z, Teiler, &returnN, &returnZ);
	ausgabe_bruch(returnN, returnZ);


	return 0;
}


int eingabe_zaehler()
{
	int zaehler;
	printf("Zaehler eingeben: \n");
	scanf("%i", &zaehler);

	return zaehler;
}


int eingabe_nenner()
{
	int nenner;

	do
	{
		printf("Nenner eingeben: \n");
		scanf("%i", &nenner);
	} while (nenner == 0);

	return nenner;

}


void ausgabe_bruch(int Nenner, int Zaehler)
{
	printf("Bruch: %i/%i\n", Zaehler, Nenner);
}



int ggT(int a, int b)
{

    int tmp = 0;
    while(b != 0)
    {
        tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}

void kuerzen(int Nenner, int Zaehler, int GGT, int *ZurueckN, int *ZurueckZ)
{

	double Nenner1, Zaehler1, z;
	z = GGT * 1.0;
	Nenner1 = Nenner;
	Zaehler1 = Zaehler;
	*ZurueckN = Nenner1 / z;
	*ZurueckZ = Zaehler1 / z;




}

