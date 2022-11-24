#include "monoquicksort.h"
#include <catch2/catch_test_macros.hpp>
#include <algorithm>
#include <vector>
#include <string>

using std::vector;
using std::string;

extern "C" {
	MONO_QUICKSORT_DEFINITION(int, int);
	MONO_QUICKSORT_DEFINITION(const char*, string);
}

TEST_CASE("monoquicksort int basic", "[quicksort]") {
	int table[] = { 4, 1, 5, 2 };
	int sz = sizeof(table) / sizeof(int);
	int_quicksort_by(table, table + sz, [](int* a, int* b) {
		if (*a < *b) {
			return -1;
		} else if (*a > *b) {
			return 1;
		} else {
			return 0;
		}
	});
	REQUIRE(std::is_sorted(table, table + sz));
}

TEST_CASE("monoquicksort string basic", "[quicksort]") {
	const char* table[] = { "a", "z", "b", "d", "A", "-Asdiuh" };
	int sz = (int)(sizeof(table) / sizeof(char*));
	string_quicksort_by(table, table + sz, [](const char** a, const char** b) {
		return(strcmp(*a, *b)); }
	);
	vector<string> v { table, table + sz };
	REQUIRE(std::is_sorted(v.begin(), v.end()));
}
