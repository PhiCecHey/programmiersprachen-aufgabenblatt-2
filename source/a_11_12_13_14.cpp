#include "rechteck.hpp"
#include "kreis.hpp"

//#include "window.hpp"
//#include <GLFW/glfw3.h>
//#include <utility>
#include <cmath>

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
#include <functional>

// 4.11
TEST_CASE("4.11", "[4.11]") {
	std::vector <int> v_1{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	std::vector <int> v_2{ 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	std::vector <int> v_3(9);
	std::transform(v_1.begin(), v_1.end(), v_2.begin(), v_3.begin(),
		[](int x1, int x2) {return(x1 + x2); });

	REQUIRE(std::all_of(v_3.begin(), v_3.end(), [](int x) {return x == 10; }));
}

// 4.12
bool is_even(int n) { return n % 2 == 0; }

template<typename T>
std::vector<T> filter(std::vector<T> v1, std::function<bool(T t)> f) {
	std::vector<T> v2;
	for (auto i : v1) {
		if (f(i)) {
			v2.push_back(i);
		}
	}
	return v2;
}

// 4.13
TEST_CASE("4.13", "[4.13]") {
	std::vector<Kreis> circles{ {5.0f}, {3.0f}, {8.0f}, {1.0f}, {5.0f} };
	std::vector<Kreis> v;
	std::copy_if(circles.begin(), circles.end(), std::back_inserter(v), [](Kreis x) {return x.radius() > 4.0f; });

	REQUIRE(std::all_of(v.begin(), v.end(), [](Kreis x) {return x.radius() > 4.0f; }));
}

// 4.14
void a_14() {
	Kreis a{ {0.0f, 0.0f}, {1.0f}, {0.5f, 0.5f, 0.5f}, {"a"} };
	a.print();
	Kreis b{ {-1.0f, -1.0f}, {2.0f}, {0.5f, 0.5f, 0.5f}, {"b"} };
	b.print();
	Kreis c{ {1.0f, 2.0f}, {3.0f}, {0.5f, 0.5f, 0.5f}, {"c"} };
	b.print();
}

TEST_CASE("4.14", "[4.14]") {
	a_14();
}


int main(int argc, char* argv[]) {
	return Catch::Session().run(argc, argv);
}