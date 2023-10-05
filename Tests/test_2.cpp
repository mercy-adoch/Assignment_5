#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "../main.h"

double value_t1 = 1789895.61;
double value_t2 = 1234.56;

TEST_CASE( "Tests_1", "Tests" ) {
    REQUIRE( extract_decimal(value_t1) == 61);
}

TEST_CASE( "Tests_2", "Tests" ) {
    REQUIRE( extract_decimal(value_t2) == 56);
}
