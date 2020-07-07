#include "kreis.hpp"

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


// 4.5
TEST_CASE("sort circles 4.5", "[sort 4.5]") {
	std::list<Kreis> sorted_circles;
	sorted_circles.push_back({ 1 });
	sorted_circles.push_back({ 3 });
	sorted_circles.push_back({ 5 });
	sorted_circles.push_back({ 2 });
	sorted_circles.push_back({ 2 });
	sorted_circles.sort();
	REQUIRE(std::is_sorted(sorted_circles.begin(), sorted_circles.end()));
}

int main(){
return 0;
}