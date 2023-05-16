// Jeremiasz Zolnierek-Kielczewski
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

#define N int(150) // Rozmiar tablicy student, MAX 134217727, jednak nie polecam, zajmuje dosyc dlugo.
#define M int(11) // Rozmiar tablicy ocena, odpowiada ocenom od 0 do 10

void tablica_bazowa(int student[]);
void oblicz_srednia(int student[]);
void sortuj_i_wypisz(int student[]);
void liczenie_oraz_najwieksza_ocena(int student[], int ocena[]);
void histogram(int ocena[]);

int student[N]; // deklarowanie tablicy student
int ocena[M]; // deklarowanie tablicy ocena

int main ()
{
    tablica_bazowa(student);
    oblicz_srednia(student);
    sortuj_i_wypisz(student);
    liczenie_oraz_najwieksza_ocena(student, ocena);
    histogram(ocena); // wywołanie wszystkich funkcji
    std::cout << "Prosze nacisnac ENTER aby zakonczyc program" << std::endl;
    std::cin.get();
    return 0;
}
void tablica_bazowa(int student[])
{
    srand(time(NULL)); // utworzenie seeda dla wylosowania na podstawie obecnego czasu. nie jest to najlepsza metoda losowosci, jednak jest ona wystarczajaca dla zastosowan, ktore nie sa zabezpieczeniami.
    for (int i = 0; i < N; i++) // petla iterujaca na podstawie zdefiniowanej wartosci N
    {
        student[i] = rand() % 11; // generator losowej oceny uzywajacy wczesniej wspomnianego seeda
    }
    std::cout << "Tablica ocen to: " << std::endl;
    for (int i = 0; i < N; i++)
    {
        std::cout << student[i] << ", ";
    } // petla wypisujaca oceny z tablicy
    std::cout << std::endl;
}
void oblicz_srednia(int student[])
{
    int suma = 0; // zdefiniowanie zmiennej "suma" wewnątrz funkcji
    for(int i = 0; i < N; i++)
    {
        suma += student[i];
    } // petla dodajaca wszystkie wartosci w tablicy student
    double srednia = static_cast<double>(suma) / N; // obliczenie samej sredniej, static_cast zostal uzyty, aby miec pewnosc, ze srenia bedzie w float
    std::cout << "Srednia ocen to: " << std::endl <<  srednia << std::endl;
}
void sortuj_i_wypisz(int student[]) // funckja jednoczesnie sortuje tablice, wypisuje ja oraz oblicza i wypisuje mediane
{
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < N - i - 1; j++)
        {
            if (student[j] > student[j+1])
            {
                int temp = student[j];
                student[j] = student[j+1];
                student[j+1] = temp;
            }
        }
    } // standardowy bubblesort, ktory porownuje 2 sasiadujace liczby w tabeli, i ustawia je w kolejnosci rosnacej jezeli juz nie sa w takiej kolejnosci, oraz powtarza to az do momentu, kiedy nie musi wykonac zadnych zmian
    std::cout << "Posortowana tablica: " << std::endl;
    for (int i = 0; i < N; i++)
    {
        std::cout << student[i] << ", ";
    } // petla wypisuje posortowana tablice
    std::cout << std::endl;
    double mediana; // zdefiniowanie mediany wewnatrz funkcji, float poniewaz jezeli N jest parzyste, mediana bedzie srednia dwoch liczb ktora moze byc liczba niecalkowita
    if (N % 2 == 0)
    {
        mediana = (static_cast<double>(student[N/2-1]) + static_cast<double>(student[N/2])) / 2;
    } // static_cast ponownie uzyty dla zapewnienia double
    else
    {
        mediana = static_cast<double>(student[N/2]);
    } // static_cast ponownie uzyty dla zapewnienia double
    std::cout << "Mediana: " << std::endl << mediana << std::endl;
}
void liczenie_oraz_najwieksza_ocena(int student[], int ocena[])
{
    int max = 0; // zdefiniowanie zmiennej aby uzyc jej dlaej jako przechowanie najwiekszej dotychczasowej liczby ocen
    std::cout << "Liczba wystapien poszczegolnych ocen:" << std::endl;
    for (int i = 0; i < N; i++)
    {
        ocena[student[i]]++;
        if (ocena[student[i]] > max)
        {
            max = ocena[student[i]];
        } // petla zamieniajaca zmienna max jezeli liczba tej konkretnej oceny jest wieksza niz dotychczasowa
    } // petla liczaca ilosc poszczegolnych ocen
    for (int i = 0; i < M; i++)
    {
        std::cout << i << ": " << ocena[i] << " razy" << std::endl;
    } // petla wypisujaca ile razy dana ocena zostala wystawiona
    std::cout << "Najczestsza ocena: " << std::endl;
    for (int i = 0; i < M; i++)
    {
        if (ocena[i] == max)
        {
            std::cout << i << " (" << max << " razy)" << std::endl;
        } //petla wypisujaca ktora ocena (lub oceny) byla wystawiana najwieksza ilosc razy
    }
}
void histogram(int ocena[])
{
    std::cout << "Histogram ocen:" << std::endl;
    for (int i = 0; i < M; i++)
    {
        std::cout << std::setw(2) << i << ": "; // setw(2) dla wyrównania cyfr
        for (int j = 0; j < ocena[i]; j++)
        {
            std::cout << "*";
        } // wypisanie odpowiedniej ilosci znakow dla danej oceny
        std::cout << std::endl;
    }
}
