#include <cstdlib> //std::rand()
#include <vector> 
#include <list>
#include <iostream>
#include <iterator> //std::ostream_iterator<>
#include <algorithm> //std::reverse, std::generate

int main() {
	//erstellt Vektor der Größe 10
	std::vector<int> v_0(10); 

	//fügt v_0 10 immer die gleichen "Zufalls"zahlen hinzu
	for (auto& v : v_0) {
		v = std::rand();
	}

	//Elemente von v_0 werden in den ostream kopiert und ausgegeben
	std::cout << "Ausgabe 1 \n";
	std::copy(std::cbegin(v_0), std::cend(v_0),
		std::ostream_iterator<int>(std::cout, "\n"));
	
	std::cout << "Ausgabe 2 \n";
	//Liste mit Elementen des Vektors wird erstellt
	std::list<int> l_0(std::cbegin(v_0), std::cend(v_0));
	//Liste mit Elementen von l_0 wird erstellt
	std::list<int> l_1(std::cbegin(l_0), std::cend(l_0));
	//Reihenfolge von l_1 wird umgedreht
	std::reverse(std::begin(l_1), std::end(l_1));
	//Elemente von l_1 werden in den ostream kopiert und ausgegeben
	std::copy(std::cbegin(l_1), std::cend(l_1),
		std::ostream_iterator<int>(std::cout, "\n"));

	std::cout << "Ausgabe 3 \n";
	//l_1 wird sortiert: kleinstes Element zuerst
	l_1.sort();
	//Elemente von l_1 werden in den ostream kopiert und ausgegeben
	std::copy(l_1.cbegin(), l_1.cend(),
		std::ostream_iterator<int>(std::cout, "\n"));

	std::cout << "Ausgabe 4 \n";
	//v_0 beinhaltet nun 10 andere, nicht zufällige "Zufallszahlen"
	std::generate(std::begin(v_0), std::end(v_0), std::rand);
	//Elemente von v_0 werden in den ostream kopiert und ausgegeben
	std::copy(v_0.crbegin(), v_0.crend(),
		std::ostream_iterator<int>(std::cout, "\n"));

	return 0;
}