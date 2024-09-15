#pragma once
#include <iostream>
#include <fstream> 
#include <map>
#include <list>
#include <vector>
using namespace std;

/**
* @brief
*
*Zmienna realizujaca algorytm przeszukania w glab (DFS, ang.Depth First Search).  
*Metoda badania grafu oparta na algorytmie DFS polega na badaniu wszystkich krawedzi wychodzacych z podanego wierzcholka. W tym przypadku zawsze zaczynamy od wierzcholka 0. 
*Po zbadaniu wszystkich krawedzi wychodzacych z danego wierzcholka algorytm powraca do wierzcholka, z ktorego dany wierzcholek zostal odwiedzony. Algorytm DFS jest algorytmem rekurencyjnym.
*
* @param graf Mapa list zawierajaca zadany graf.
* @param visited Mapa zawierajaca informacje czy konkretny wierzcholek zostal juz odwiedzony. Jako klucz przyjmuje wartosci typu 'int', ktore okreslaja wierzcholki zas jako wartosci przechowywane pod danym kluczem zmienne typu bool.
* @param color Mapa przechowujaca informacje o kolorze jak zostal przydzielony kazdemu wierzcholkowi. 
* @param isBipartite Zmienna logiczna przechowujaca informacje czy zadany graf nieskierowany jest grafem dwudzielnym.
* @param a Wierzcholek
* @return Zwraca true w zmiennej isBipartite jezeli graf jest dwudzielny. W przeciwnym razie zwraca wartosc false.
* 
*/
void DFS(int a, map<int, int>& color, map<int, list<int>>& graf, map<int, bool>& visited, bool& isBipartite);

/**
* @brief
* Funkcja ma zapisac do pliku wyjsciowego informacje ze graf jest dwudzielny, wypisac liste sasiedztwa dla grafu oraz do ktorych zbiorow naleza konkretne wierzcholki.
*
* @param color Mapa przechowujaca informacje o kolorze jak zostal przydzielony kazdemu wierzcholkowi podczas dzialania algorytmu DFS.
* @param out Zmienna typu string zawierajaca nazwe pliku wyjsciowego.
* @param graf Mapa list zawierajaca zadany graf.
*/
void printBipartiteGroups(map<int, int>& color, string& out, map<int, list<int>>& graf);

/**
* @brief
* Funkcja ma za zadanie zapisac do pliku wyjsciowego informacje ze gra nieskierowany nie jest grafem dwudzielnym.
*
* @param out Zmienna typu string zawierajaca nazwe pliku wyjsciowego.
* 
*/
void printNOBipartiteGroups(map<int, int>& color, string& out, map<int, list<int>>& graf);

/**
* @brief
		
* Funkcja wywoluje funkcje DFS() oraz funkcje printBipartiteGroups() i printNOBipartiteGroups().
* W funkcji tworzone sa dwie istotne mapy:
* 1. map<int, int>color - przechowuje informacje o kolorze jak zostal przydzielony kazdemu wierzcholkowi podczas dzialania algorytmu DFS.
* 2. map<int, bool>visited - zawiera informacje czy konkretny wierzcholek zostal juz odwiedzony. Jako klucz przyjmuje wartosci typu 'int', ktore okreslaja wierzcholki zas jako wartosci przechowywane pod danym kluczem zmienne typu bool.
* 
* @param graf Mapa list zawierajaca i przechowujaca zadany graf.
* @param isBipartite Zmienna logiczna przechowujaca informacje czy zadany graf nieskierowany jest grafem dwudzielnym.
* @param out Zmienna zawierajaca nazwe pliku do ktorego trzeba zapisac wynik koncowy
*/
void wyp(map<int, list<int>>& graf, bool& isBipartite, string& out);

/**
* @brief 
*Funkcja dodaje wierzcholki z pliku wejsciowego do mapy list o nazwie "graf"
*
* @param a Pierwszy wierzcholek z linii
* @param b Drugi wierzcholek z linii 
*  @param graf Mapa list zawierajaca zadany graf. Zmienna jest dalej przekazywana.
*/
void addedge(int a, int b, map<int,list<int>>& graf);

/**
* @brief Funkcja otwiera plik, sprawdza poprawnosc argumentow
*
* @param txt Zmienna zawierajaca nazwe pliku ktory trzeba otworzyc
* @param out Zmienna zawierajaca nazwe pliku do ktorego trzeba zapisac wynik koncowy
*/
void read(string txt,string out);
