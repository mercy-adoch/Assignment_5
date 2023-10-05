#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "../main.h"

double value_t1 = 1;
double value_t2 = 5;

TEST_CASE( "Tests_1", "Tests" ) {
    REQUIRE( add_digits(value_t1,value_t2) == 6);
}

// TEST_CASE( "Tests_2", "Tests" ) {
//     REQUIRE( is_valid(value_t2) == 1);
// }
