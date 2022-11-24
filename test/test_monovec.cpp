#include "libft.hpp"
#include "monovec.h"
#include <algorithm>
#include <vector>
#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators.hpp>
#include <catch2/generators/catch_generators_adapters.hpp>
#include <catch2/generators/catch_generators_random.hpp>
#include <sstream>

using std::vector;

extern "C" {
MONOVEC_DECLARATION(int, VecInt, veci);
MONOVEC_DEFINITIONS(int, VecInt, veci);
}

class RandomIntVecGenerator: public Catch::Generators::IGenerator<vector<int>> {
	std::minstd_rand m_rand;
	std::uniform_int_distribution<> m_dist;
	vector<int> current_table;
	int sz;
public:

	RandomIntVecGenerator(int low, int high, int sz):
		m_rand(std::random_device{}()),
		m_dist(low, high),
		sz(sz)
	{
		current_table.resize(sz);
		static_cast<void>(next());
	}

    const vector<int>& get() const override;
    bool next() override {
		for (int i = 0; i < sz; i++) {
			current_table[i] = m_dist(m_rand);
		}
        return true;
    }
};

const vector<int>& RandomIntVecGenerator::get() const {
	return current_table;
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

TEST_CASE("test strcmp", "[std]") {
	REQUIRE(strcmp("a", "b") < 0);
	REQUIRE(strcmp("a", "a") == 0);
	REQUIRE(strcmp("b", "a") > 0);
}

int compare_ints(int* a, int* b) {
	if (*a < *b) {
		return -1;
	} else if (*a > *b) {
		return 1;
	} else {
		return 0;
	}
}

TEST_CASE("monovec sort", "[monovec]") {
	VecInt* v = veci_construct(0);
	veci_push_back(v, 4);
	veci_push_back(v, 1);
	veci_push_back(v, 5);
	veci_push_back(v, 2);
	veci_sort_unstable_by(v, compare_ints);
	REQUIRE(v->length == 4);
	REQUIRE(std::is_sorted(v->table, v->table + v->length));
	veci_destroy(v);
}

Catch::Generators::GeneratorWrapper<vector<int>> random(int low, int high, int sz) {
    return Catch::Generators::GeneratorWrapper<vector<int>>(
        Catch::Detail::make_unique<RandomIntVecGenerator>(low, high, sz)
    );
}

TEST_CASE("monovec sort property", "[gen]") {
	vector<int> numbers = GENERATE(take(100, random(INT32_MIN, INT32_MAX, 100)));
	VecInt* v = veci_construct(numbers.size());
	for (int i = 0; i < numbers.size(); i++) {
		veci_push_back(v, numbers[i]);
	}
	std::stringstream ss;
	ss << "[ ";
	for (int x : numbers) {
		ss << x << ' ';
	}
	ss << "]";
	SECTION(ss.str()) {
		REQUIRE(v->length == numbers.size());
		veci_sort_unstable_by(v, compare_ints);
		std::sort(numbers.begin(), numbers.end());
		REQUIRE(std::is_sorted(v->table, v->table + v->length));
		REQUIRE(numbers == vector<int> { v->table, v->table + v->length });
	}
}
