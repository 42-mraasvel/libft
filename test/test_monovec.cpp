#include "libft.hpp"
#include <catch2/catch_test_macros.hpp>

extern "C" {
MONOVEC_DECLARATION(int, VecInt, veci);
MONOVEC_DEFINITIONS(int, VecInt, veci);
}

/*
Testcases
monovec construct: on/off-point
- cap = 0
- cap = 1
*/

TEST_CASE("monovec construct empty", "[monovec]") {
	VecInt* v = veci_construct(0);
	REQUIRE(v != nullptr);
	REQUIRE(v->length == 0);
	REQUIRE(v->capacity == 0);
	REQUIRE(v->table == nullptr);
	veci_destroy(v);
}

TEST_CASE("monovec construct with cap", "[monovec]") {
	VecInt* v = veci_construct(1);
	REQUIRE(v != nullptr);
	REQUIRE(v->length == 0);
	REQUIRE(v->capacity == 1);
	REQUIRE(v->table != nullptr);
	veci_destroy(v);
}

TEST_CASE("monovec pushback with no capacity", "[monovec]") {
	VecInt* v = veci_construct(0);
	REQUIRE(v != nullptr);
	REQUIRE(veci_push_back(v, 42) == 0);
	REQUIRE(v->length == 1);
	REQUIRE(v->capacity == 1);
	REQUIRE(v->table != nullptr);
	REQUIRE(v->table[0] == 42);
	for (int i = 0; i < 5; i++) {
		REQUIRE(veci_push_back(v, i) == 0);
	}
	// cap = 2^3 (8), length = 5
	REQUIRE(v->length == 6);
	REQUIRE(v->capacity == 8);
	veci_destroy(v);
}

TEST_CASE("monovec pushback with capacity", "[monovec]") {
	VecInt* v = veci_construct(1000);
	for (int i = 0; i < 1000; i++) {
		veci_push_back(v, i);
	}
	REQUIRE(v->length == 1000);
	REQUIRE(v->capacity == 1000);
	REQUIRE(v->table[999] == 999);
	veci_push_back(v, 42);
	REQUIRE(v->capacity == 2000);
	REQUIRE(v->length == 1001);
	veci_destroy(v);
}
