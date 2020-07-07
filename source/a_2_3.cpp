#define CATCH_CONFIG_RUNNER
#include "catch.hpp"

#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <list>
#include <algorithm>
#include <stdlib.h>


// 4.2 und 4.3

TEST_CASE("4.2 4.3", "[4.2 4.3]") {
	std::vector<unsigned int> v;
	for (int i = 0; i < 100; ++i) {
		int rand = std::rand() % 101;
		v.push_back(rand);
	}

	std::set<unsigned int> s;

	// 4.2.1.
	int count = 0;
	for (auto const& i : v) {
		auto ins = s.insert(i);
		if (ins.second) {
			++count;
		}
	}
	std::cout << "Anzahl der unterschiedlichen Zufallszahlen: " << count << "\n";

	// 4.2.2.
	std::cout << "nicht enthaltene Zahlen: \n";
	for (int i = 0; i < 100; ++i) {
		if (s.find(i) == s.end()) {
			std::cout << i << " ";
			++count;
		}
	}

	REQUIRE(count == 100);

	// 4.3
	std::map<unsigned int, unsigned int> m;
	for (auto const& i : v) {
		auto ins = m.insert(std::pair<unsigned int, unsigned int>{i, 1});
		if (!ins.second) {
			m[i] += 1;
		}
	}

	std::cout << "\n \n";

	std::cout << "Zahl : Häufigkeit \n";
	for (auto const& i : m) {
		std::cout << i.first << " : " << i.second << "\n";
	}

	count = 0;
	for (auto i : m) {
		count += i.second;
	}

	REQUIRE(count == 100);
}

std::vector<unsigned int> a_2_3(bool print) {
	// 4.2
	std::vector<unsigned int> v;
	for (int i = 0; i < 100; ++i) {
		int rand = std::rand() % 101;
		v.push_back(rand);
	}

	std::set<unsigned int> s;

	// 4.2.1
	int count = 0;
	for (auto const& i : v) {
		auto ins = s.insert(i);
		if (ins.second) {
			++count;
		}
	}
	//std::cout << "Anzahl der unterschiedlichen Zufallszahlen: " << count << "\n";

	// 4.2.2.
	if (print) std::cout << "nicht enthaltene Zahlen: \n";
	for (int i = 0; i < 100; ++i) {
		if (s.find(i) == s.end()) {
			if (print) std::cout << i << " ";
		}
	}

	// 4.3
	std::map<unsigned int, unsigned int> m;
	for (auto const& i : v) {
		auto ins = m.insert(std::pair<unsigned int, unsigned int>{i, 1});
		if (!ins.second) {
			m[i] += 1;
		}
	}

	if (print) {
		std::cout << "\n \n";

		std::cout << "Zahl : Häufigkeit \n";
		for (auto const& i : m) {
			std::cout << i.first << " : " << i.second << "\n";
		}
	}

	// 4.9
	return v;
}

bool a_9(std::vector<unsigned int>& v) {
	bool test_case = true;
	std::list<unsigned int> l(std::cbegin(v), std::cend(v));
	std::cout << l.size() << "\n";
	auto l_front = l.begin();
	std::advance(l_front, 90);
	std::cout << *l_front << " vs " << v[90] << "\n";
	for (int i = 1; i < 10; ++i) {
		std::advance(l_front, 1);
		std::cout << *l_front << " vs " << v.at(90 + i) << "\n";
		if (*l_front != v.at(90 + i)) test_case = false;
	}
	return test_case;
}

TEST_CASE("4.9", "[4.9]") {
	std::vector<unsigned int> v = a_2_3(false);
	bool test_case = a_9(v);
	REQUIRE(test_case == true);
}

int main(int argc, char* argv[]) {
	return Catch::Session().run(argc, argv);
}