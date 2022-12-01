extern "C" {
#include "ft_string.h"
}
#include <catch2/catch_test_macros.hpp>
#include <sstream>

TEST_CASE("test_string", "[string]") {
	String* s = string_format("%s/%s", "parent", "child");
	REQUIRE(s != nullptr);
	std::string expected { "parent/child" };
	REQUIRE(expected == s->chars->table);
	string_destroy(s);
}

TEST_CASE("string int conversion", "[string]") {
	String* s = string_format("%d %d %d %d %d", 1, -1, 0, INT_MAX,  INT_MIN);
	REQUIRE(s != nullptr);
	std::stringstream ss;
	ss << 1 << ' ' << -1 << ' ' << 0 << ' ' << INT_MAX << ' ' << INT_MIN;
	REQUIRE(ss.str() == s->chars->table);
	string_destroy(s);
}

TEST_CASE("string char conversion", "[string]") {
	String* s = string_format("%c%c %c", 'a', 'b', 32);
	std::string expected { "ab  " };
	REQUIRE(expected == s->chars->table);
	REQUIRE(string_length(s) == expected.size());
	string_destroy(s);
}

TEST_CASE("string precision", "[string]") {
	String* s = string_format("%.2s", "abcde");
	std::string expected("ab");
	REQUIRE(expected == s->chars->table);
	REQUIRE(expected.size() == string_length(s));
	string_destroy(s);
}
