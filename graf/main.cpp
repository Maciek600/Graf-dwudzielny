#include <iostream>
#include <fstream> 
#include <stdio.h>
#include <string> 
#include <vector>
#include <list>
#include <map>
#include <unordered_set>
#include "header.h"
using namespace std;
/*! \mainpage Graf dwudzielny
 *
 * 
 * \section intro_sec Wstep
 * Program sprawdza czy graf nieskierowany jest grafem dwudzielnym.
 * \section test_sec Pliki testowe
 * W zalaczonych plikach znajduja sie dwa pliki tekstowe:
 * 1. good.txt - plik z grafem nieskierowanym ktory jest dwudzielny. ~ 400 krawedzi
 * 2. bad.txt - plik z grafem nieskeirowanyk ktory nie jest dwudzielny. ~ 400 krawedzi 
 * 3. smallBipartite.txt - mniejszy plik z grafem ktory jest dwudzielny
 * 4. smallNOBipartite.txt- mniejszy plik z grafem nie dwudzielnym
 * 
 * 
 * Plik z grafem ma nastepujaca postac:
 *	- Kazda krawedz jest podana w osobnej lini; podane sa dwa wierzcholki ktore laczy krawedz.
 *	- W pliku moga wystapic puste linie.
 *	- W linii moga wystapic nadmiarowe znaki biale.
 * 
 * \section instr_sec Instrukcja
 * Aby prawidlowo uzyc programu, podczas uruchamiania z linni polecen powinno uzyc sie nastepujacych przelacznikow:
 * 1. -i plik wejsciowy z krawedziami grafu
 * 2. -o plik wyjsciowy z wynikami
 * 
 * Przyklad: -i good.txt -o output.txt
 * 
 *\author Maciej Fajlhauer
 *
 */



/**
* @brief
* Funkcja main() przyjmuje lacznie 4 argumenty (dwa przelaczniki wraz z ich wartosciami) wpisane podczas uruchamiania programu z linii polecen. Najpierw nastepuje odczyt wyzej wymienionych przelacznikow oraz ich wartosci, a nastepnie sprawdzana jest porpawnosc ich wprowadzenia.
* W przypadku bledu, funkcja wypisuje na ekranie instrukcje dla uzytkownika wraz z przykladem porpawnego uzycia przelacznikow. Jezeli wszystko zostalo poprawnie wpisane, funkcja main() wywoluje funkcje read().
*/
int main(int argc, char* argv[]) {
	vector<string>opcja;
	//obs³uga argumentów podczas uruchamiania programu z konsoli
	for (int i = 0; i < argc; i++) {
		string arg = argv[i];
		opcja.push_back(arg);

	}
	if (opcja[1] != "-l" && opcja[3]!="-o") {
		cout << "Podano nieprawid³owe argumenty" << endl;
		cout << "Instrukcja poprawnego uzycia argumentow: " << endl;
		cout << "-l <nazwa_pliku_wejsciowego.txt>" << endl;
		cout << "-o <nazwa_pliku_wyjsciowego.txt>" << endl;
		cout << "Przyklad: -l wejscie.txt -o wyjscie.txt" << endl;
	}else{
		//czytamy argumenty wejœciowe
		//cout << endl << "Opcja 1:" << opcja[0] << endl; // adres katalogu C:\User\...
		cout << endl << "Opcja 2:" << opcja[1] << endl;//pierwszy argument np -l
		cout << endl << "Opcja 3:" << opcja[2] << endl;//wartosc tego argumentu np test.txt
		cout << endl << "Opcja 4:" << opcja[3] << endl;//argument zapisu do pliku
		cout << endl << "Opcja 5:" << opcja[4] << endl;//nazwa pliku do ktorego nalezy zapisac wynik
	
		string txt = opcja[2]; 
		string out = opcja[4];
		read(txt,out);//wczytywanie grafu z pliku
	}
			
	return 0;
}