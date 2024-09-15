#include "header.h"

void DFS(int a, map<int,int>& color, map<int, list<int>>& graf, map<int, bool>& visited, bool& isBipartite) {
	visited[a] = true;
	
	for (int b : graf[a]) {
		if (!visited[b]) {
			color[b] = 1 - color[a];

			DFS(b, color, graf, visited, isBipartite);
		
			if (!isBipartite)
				return;
		}
		else if (color[b] == color[a]) {
			isBipartite = false;
			return;
		}
	}
}
void printBipartiteGroups(map<int, int>& color,string& out, map<int, list<int>>& graf) {
	ofstream plik_out(out);
	plik_out << "\nGraf jest dwudzielny!" << endl;
	plik_out << "\nZbior A : ";
	for (auto& it : color) {
		if (it.second == 0)
			plik_out << it.first << " ";
		
	}
	plik_out << endl;
	plik_out << "\nZbior B : ";
	for (auto& it : color) {
		if (it.second == 1)
			plik_out << it.first << " ";
	}
	plik_out << endl;
	//wypisanie listy sasiedztwa dla grafu dwudzielnego
	plik_out << "\nLista sasiedztwa: " << endl;
	for (auto& it : graf) {
		plik_out << it.first << ": ";
		for (int w : it.second) {
			plik_out << "-> " << w << " ";
		}
		plik_out << endl;
	}
	plik_out.close();
}
void printNOBipartiteGroups(string& out){ 
	ofstream plik_out(out);
	plik_out << "\nGraf nie jest dwudzielny!" << endl;
	plik_out.close();
}

void wyp(map<int, list<int>>& graf, bool& isBipartite,string& out) {
	map<int, int>color;
	for (auto& v : graf) {
		map<int, bool>visited;
		
		if (!visited[v.first]) {
			DFS(v.first, color, graf, visited, isBipartite);
			if (!isBipartite)
				break;
		}
	}
	
	if (isBipartite) {
		printBipartiteGroups(color, out,graf);
	}
	else {
		printNOBipartiteGroups(out);
	}
	
}


/**
* @brief
* Linia kodu: graf[b].push_back(a); jest obowiazkowa w przypadku grafow nieskierowanych.
*/
void addedge(int a, int b, map<int, list<int>>& graf) {
	graf[a].push_back(b);
	graf[b].push_back(a);
}



void read(string txt,string out){
	ifstream plik;
	plik.open(txt);
	if (!plik.good() == true) {
		cout << "Nie mozna otworzyc pliku!" << endl << "Sprawdz poprawnosc argumentow i sprobuj ponownie" << endl;
		return;
	}
	int a, b;
	map<int, list<int>>graf;
	
	bool isBipartite = true; // flaga okreœlaj¹ca, czy graf jest dwudzielny

	while (plik >> a >> b) {
		addedge(a, b, graf);//dodanie wiercho³ków do grafu
	}
	wyp(graf, isBipartite,out);
	plik.close();
}
