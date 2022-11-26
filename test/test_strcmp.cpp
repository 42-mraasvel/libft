#include "libft.hpp"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("case insensitive strcmp", "[libft]") {
	REQUIRE(ft_strcmp_ignore_case("A", "a") == 0);
	REQUIRE(ft_strcmp_ignore_case("Aa", "aa") == 0);
	REQUIRE(ft_strcmp_ignore_case("Aa", "aaB") < 0);
	REQUIRE(ft_strcmp_ignore_case("AaZ", "aaB") > 0);
	REQUIRE(ft_strcmp_ignore_case("AaZ", "aaB") == ft_strcmp_ignore_case("aaz", "aaB"));
}
