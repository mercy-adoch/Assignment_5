#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "../main.h"

double value_t1 = extract_decimal(1789895.61);
double value_t2 = extract_decimal(1234.56);

TEST_CASE("Tests_1", "Tests" ) {
    REQUIRE(sum_of_digits(value_t1) == 7);
}

TEST_CASE("Tests_2", "Tests" ) {
    REQUIRE(sum_of_digits(value_t2) == 11);
}
