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

// 4.6
TEST_CASE("sort circles 4.6", "[sort 4.6]") {
	std::list<Kreis> sorted_circles;
	sorted_circles.push_back({ 1 });
	sorted_circles.push_back({ 3 });
	sorted_circles.push_back({ 5 });
	sorted_circles.push_back({ 2 });
	sorted_circles.push_back({ 2 });
	auto sorting_lambda = [](Kreis const& a, Kreis const& b) {return a.radius() < b.radius(); };
	sorted_circles.sort(sorting_lambda);
	REQUIRE(std::is_sorted(sorted_circles.begin(), sorted_circles.end()));
}

// 4.7
TEST_CASE("sort circles 4.7", "[sort 4.7]") {
	std::set<Kreis, lessKreis> s({ {1}, {3}, {5}, {2}, {2} }, lessKreis{});
	//s.insert({ 1 });
	//s.insert({ 3 });
	//s.insert({ 5 });
	//s.insert({ 2 });
	//s.insert({ 2 });
	REQUIRE(std::is_sorted(s.begin(), s.end()));
}

int main(){
return 0;
}