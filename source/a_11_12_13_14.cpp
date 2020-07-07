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

// 4.11
TEST_CASE("4.11", "[4.11]") {
	std::vector <int> v_1{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	std::vector <int> v_2{ 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	std::vector <int> v_3(9);
	std::transform(v_1.begin(), v_1.end(), v_2.begin(), v_3.begin(),
		[](int x1, int x2) {return(x1 + x2); });

	REQUIRE(std::all_of(v_3.begin(), v_3.end(), [](int x) {return x == 10; }));
}


int main(int argc, char* argv[]) {
	return Catch::Session().run(argc, argv);
}