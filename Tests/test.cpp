#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "../main.h"

// double value_t1 = 1;
// double value_t2 = 5;

// TEST_CASE( "Tests_1", "Tests" ) {
//     REQUIRE( add_digits(value_t1,value_t2) == 6);
// }

// Define test cases using the TEST_CASE macro from Catch2.
TEST_CASE("Test retail store functionality") {
    RetailStore store;

    Product mathBook("P01", "Math Book", 50.0);
    Product physicsBook("P02", "Physics Book", 60.0);
    Product chemistryBook("P03", "Chemistry Book", 55.0);

    store.addProductToInventory(mathBook);
    store.addProductToInventory(physicsBook);
    store.addProductToInventory(chemistryBook);

    Customer alice("C01", "Alice");
    Customer bob("C02", "Bob");

    store.addCustomer(alice);
    store.addCustomer(bob);

    Order order1;
    order1.addProduct(mathBook);
    order1.addProduct(chemistryBook);

    Order order2;
    order2.addProduct(physicsBook);

    store.placeOrderForCustomer("C01", order1);
    store.placeOrderForCustomer("C02", order2);

    // Test cases to check the functionality of your retail store methods.
    SECTION("Test getTotalExpenditureOfCustomer") {
        REQUIRE(store.getTotalExpenditureOfCustomer("C01") == Approx(105.0)); // Alice
        REQUIRE(store.getTotalExpenditureOfCustomer("C02") == Approx(60.0));  // Bob
    }

    SECTION("Test getCustomersWhoPurchasedProduct") {
        std::list<std::string> customersWhoBoughtMath = store.getCustomersWhoPurchasedProduct("P01");
        REQUIRE(customersWhoBoughtMath.size() == 1);
        REQUIRE(customersWhoBoughtMath.front() == "C01"); // Alice bought the Math Book

        std::list<std::string> customersWhoBoughtPhysics = store.getCustomersWhoPurchasedProduct("P02");
        REQUIRE(customersWhoBoughtPhysics.size() == 1);
        REQUIRE(customersWhoBoughtPhysics.front() == "C02"); // Bob bought the Physics Book
    }

    // Add more test cases as needed to cover your code's functionality.
}

