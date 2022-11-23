#include "libft.hpp"
#include <catch2/catch_test_macros.hpp>
#include <vector>
#include <string>

using std::vector;
using std::string;

TEST_CASE("ft_split basic example", "[libft]") {
	char** result = ft_split("a b c d", ' ');
	REQUIRE(result != NULL);
	vector<string> v;
	for (int i = 0; result[i] != NULL; i++) {
		v.push_back(result[i]);
	}
	ft_free_split(result);
	REQUIRE(v.size() == 4);
	REQUIRE(v == vector<string> { "a", "b", "c", "d" });
}
