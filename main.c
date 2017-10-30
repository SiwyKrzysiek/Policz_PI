#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

double Losowa(void);
void PoliczPI(int liczbaLosowan);

int main(void)
{
    printf("Krzysztof Dabrowski gr. 1I1\nProjekt obliczajacy liczbe PI metoda \"orzel-reszka\"\n-----------------------------------------------------\n\n");

    srand(time(NULL)); //Ustawienie zarodka losowania od aktualnego czasu

    printf("Podaj liczbe losowan: ");

    int liczbaLosowan;
    if (scanf("%d", &liczbaLosowan) != 1 || liczbaLosowan==INT_MAX) //Wczytanie liczby losowan i sprawdzenie jej poprawnosci
    {
        printf("\nNieprawidlowo wprowadzona liczba liczba\n");
        return 1;
    }
    if(liczbaLosowan < 10) //W przeciwnym wypadku nie da sie wypisywac wynikow co 10%
    {
        printf("\nMinimalna liczba losowan to 10\n");
        return 1;
    }
    printf("\n");

    PoliczPI(liczbaLosowan);

    return 0;
}

double Losowa(void) //Losowa liczba z przedzialu [0, 1]
{
    return (double)rand() / RAND_MAX ;
}

void PoliczPI(int liczbaLosowan)
{
    int wKole=0;
    int dziesiecPr = liczbaLosowan/10;
    double PI = 0;

    for (int i=1; i<=liczbaLosowan; ++i)
    {
        double x, y; //Wylosowanie punktu z kwadrata
        x = Losowa();
        y = Losowa();

        if(x*x + y*y <= 1) //Sprawdznie czy wylosowany punkt jest w kole
            wKole++;
        PI = 4.0*((double)wKole / i);

        if(i % dziesiecPr == 0) //Co dziesiec procent
        {
            printf("%d%% - %d losowan PI = %f\n", i/dziesiecPr*10, i, PI); //Wypisywanie wynikow
        }
    }
}
