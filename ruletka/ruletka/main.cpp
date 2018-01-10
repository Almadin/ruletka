#include <iostream>
#include <cstdlib>
#include <ctime>
#include<locale.h>
#include<string>
#include<sstream>
#include<fstream>
#include <windows.h>

using namespace std;

bool sprawdzenie(int liczba, string  rodzaj, char tabs[])
{
	//konwersja rodzaju, bed¹cego zmienn¹ typu string na zmienn¹ typu int w celu ³atwiejdszego sprawdzenia
	int i;
	istringstream iss(rodzaj);
	iss >> i;
	//operatory if sprawdzaj¹ce czy gracz wygra³
	if (rodzaj == "k1" || rodzaj == "k2" || rodzaj == "k3") {
		if (rodzaj == "k1") {
			if (liczba % 3 == 1)
				return true;
		}
		else if (rodzaj == "k2") {
			if (liczba % 3 == 2)
				return true;
		}
		else if (rodzaj == "k3") {
			if (liczba != 0 && liczba % 3 == 0)
				return true;
		}
	}
	else if (rodzaj == "p") {
		if (liczba != 0 && liczba % 2 == 0)
			return true;
	}
	else if (rodzaj == "n") {
		if (liczba % 2 != 0)
			return true;
	}
	else if (rodzaj == "w1" || rodzaj == "w2" || rodzaj == "w3" || rodzaj == "w4" || rodzaj == "w5" || rodzaj == "w6" || rodzaj == "w7" || rodzaj == "w8" || rodzaj == "w9" || rodzaj == "w10" || rodzaj == "w11" || rodzaj == "w12") {
		if (rodzaj == "w1") {
			if (liczba >= 1 && liczba <= 3)
				return true;
		}
		else if (rodzaj == "w2") {
			if (liczba >= 4 && liczba <= 6)
				return true;
		}
		else if (rodzaj == "w3") {
			if (liczba >= 7 && liczba <= 9)
				return true;
		}
		else if (rodzaj == "w4") {
			if (liczba >= 10 && liczba <= 12)
				return true;
		}
		else if (rodzaj == "w5") {
			if (liczba >= 13 && liczba <= 15)
				return true;
		}
		else if (rodzaj == "w6") {
			if (liczba >= 16 && liczba <= 18)
				return true;
		}
		else if (rodzaj == "w7") {
			if (liczba >= 19 && liczba <= 21)
				return true;
		}
		else if (rodzaj == "w8") {
			if (liczba >= 22 && liczba <= 24)
				return true;
		}
		else if (rodzaj == "w9") {
			if (liczba >= 25 && liczba <= 27)
				return true;
		}
		else if (rodzaj == "w10") {
			if (liczba >= 28 && liczba <= 30)
				return true;
		}
		else if (rodzaj == "w11") {
			if (liczba >= 31 && liczba <= 33)
				return true;
		}
		else if (rodzaj == "w12") {
			if (liczba >= 34 && liczba <= 36)
				return true;
		}
	}
	else if (rodzaj == "g") {
		if (liczba != 0 && liczba <= 18)
			return true;
	}
	else if (rodzaj == "d") {
		if (liczba > 18)
			return true;
	}
	else if (rodzaj == "b") {
		if (tabs[liczba] == 'b')
			return true;
	}
	else if (rodzaj == "r") {
		if (tabs[liczba] == 'r')
			return true;
	}
	else if (i == liczba) {
		return true;
	}
	else return false;
}

int wylosuj()
{
	return (rand() % 37);
}

int fwygrana(int liczba, string rodzaj)
{
	int wygrana;
	if (rodzaj == "p" || rodzaj == "n" || rodzaj == "r" || rodzaj == "b" || rodzaj == "g" || rodzaj == "d")
		wygrana = liczba;
	else if (rodzaj == "k1" || rodzaj == "k2" || rodzaj == "k3")
		wygrana = liczba * 2;
	else if (rodzaj == "w1" || rodzaj == "w2" || rodzaj == "w3" || rodzaj == "w4" || rodzaj == "w5" || rodzaj == "w6" || rodzaj == "w7" || rodzaj == "w8" || rodzaj == "w9" || rodzaj == "w10" || rodzaj == "w11" || rodzaj == "w12")
		wygrana = liczba * 11;
	else wygrana = liczba * 35;

	return wygrana;
}

int wylosowano0(int liczba, string rodzaj)
{
	int strata;
	if (rodzaj == "p" || rodzaj == "n" || rodzaj == "r" || rodzaj == "b" || rodzaj == "g" || rodzaj == "d")
		strata = liczba / 2;
	else
		strata = liczba;
	return strata;
}

int main()
{
	setlocale(LC_ALL, "polish");
	int kasa = 1000, zaklad, wygrana, strata;
	string rodzakladu;
	char decyzja;
	ofstream plik;
	plik.open("wyniki.txt");
	srand(time(NULL));
	char tab[37] = { 0, 'r', 'b', 'r', 'b', 'r', 'b', 'r', 'b', 'r', 'b', 'b', 'r', 'b', 'r', 'b', 'r', 'b', 'r', 'r', 'b', 'r', 'b', 'r', 'b', 'r', 'b', 'r','b', 'b', 'r', 'b', 'r', 'b', 'r', 'b', 'r' };
	int wylos;

	do {
		do {
			cout << "Masz " << kasa << "pln. Jak¹ kwote obstawiasz?" << endl;
			cin >> zaklad;
			if (zaklad > kasa)
				cout << "Nie masz tyle pieniêdzy. Podaj jeszcze raz:" << endl;
		} while (zaklad > kasa);

		cout << "Co obstawiasz? (tylko opcje zgodne)" << endl;
		cout << "p - parzyste" << endl;
		cout << "n - nieparzyste" << endl;
		cout << "p - parzyste" << endl;
		cout << "r - czerwone(red)" << endl;
		cout << "b - czarna(black)" << endl;
		cout << "g - górna polowa" << endl;
		cout << "d - dolna polowa" << endl;
		cout << "k1, k2, k3 - kolumna 1, kolumna 2, kolumna 3" << endl;
		cout << "w1, w2, ..., w12 - wiersz trzech numerów" << endl;
		cout << "0 - 36 - pojedyncze pole o odpowiednim numerze" << endl;
		cin >> rodzakladu;
		/*int i;
		istringstream iss(rodzakladu);
		iss >> i;*/
		wylos = wylosuj();
		Sleep(2500);
		cout << "Wylosowano numer: " << wylos << endl;
		if (sprawdzenie(wylos, rodzakladu, tab) == true) {
			cout << "Obstawi³eœ poprawnie. Zyskujesz ";
			wygrana = fwygrana(zaklad, rodzakladu);
			cout << wygrana << endl;
			kasa = kasa + wygrana;
		}
		else {
			if (rodzakladu == "0") {
				strata = wylosowano0(zaklad, rodzakladu);
				kasa = kasa - strata;
			}
			else {
				cout << "Niestety nie trafi³eœ" << endl;
				kasa = kasa - zaklad;
			}
		}
		cout << kasa << endl;
		plik << kasa << endl;
		if (kasa == 0)
		{
			cout << "Jesteœ Bankrutem" << endl;
			decyzja = 'n';
		}
		else {
			do {
				cout << "czy chcesz kontyunowaæ grê?(t-tak, n-nie)" << endl;
				cin >> decyzja;
				if (decyzja != 't' && decyzja != 'n')
					cout << "Nieprawid³owy wybór" << endl;
			} while (decyzja != 't' && decyzja != 'n');
		}
	} while (decyzja == 't');
	plik.close();
	system("PAUSE");
	return 0;
}