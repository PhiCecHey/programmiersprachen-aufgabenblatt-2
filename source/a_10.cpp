#define CATCH_CONFIG_RUNNER

#include "catch.hpp"
#include <cmath>
#include <algorithm>
#include <iostream>
#include <vector>

bool is_multiple_of_3(int i) {
	return i % 3 == 0;
}

bool is_not_multiple_of_3(int i) {
	return !is_multiple_of_3(i);
}

TEST_CASE("filter alle Vielfache von drei", "[erase]") {

	std::vector<int> v;

	std::cout << "\n ---------- \n";

	int rand;
	for (int i = 0; i < 10; ++i) {
		rand = std::rand() % 101;
		v.push_back(rand);
	}

	std::cout << "size: " << v.size() << "\n";

	for (int i = 0; i < 10; ++i) {
		std::cout << v.at(i) << "\n";
	}

	std::cout << "\n ---------- \n";

	//v.erase(std::remove_if(v.begin(), v.end(), [](int x) {return x % 3 != 0; }), v.end());
	v.erase(std::remove_if(v.begin(), v.end(), is_not_multiple_of_3), v.end());

	std::cout << "size: " << v.size() << "\n";

	for (int i = 0; i < v.size(); ++i) {
		std::cout << v.at(i) << "\n";
	}

	//REQUIRE(std::all_of(v.begin(), v.end(), [](int x) {return x % 3 == 0; }));
	REQUIRE(std::all_of(v.begin(), v.end(), is_multiple_of_3));
}

int main(int argc, char* argv[]) {

	return Catch::Session().run(argc, argv);
}