extern "C" {
#include "ft_string.h"
}
#include <catch2/catch_test_macros.hpp>

TEST_CASE("test_string", "[string]") {
	String* s = string_format("%s/%s", "parent", "child");
	REQUIRE(s != nullptr);
	std::string expected { "parent/child" };
	REQUIRE(expected == s->chars->table);
	string_destroy(s);
}
