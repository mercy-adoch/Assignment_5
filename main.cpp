#include <iostream>
#include "main.h"
#include<cmath>


int main()
{
    RetailStore store;

    store.addProductToInventory(Product("P1", "Product 1", 10.99));
    store.addProductToInventory(Product("P2", "Product 2", 19.99));
    store.addProductToInventory(Product("P3", "Product 3", 5.99));

    Customer customer1("C1", "Customer 1");
    Customer customer2("C2", "Customer 2");

    store.addCustomer(customer1);
    store.addCustomer(customer2);

    Order order1;
    auto it1 = store.getInventory().find("P1");
    if (it1 != store.getInventory().end())
    {
        order1.addProduct(it1->second);
    }
    customer1.placeOrder(order1);

    Order order2;
    auto it2 = store.getInventory().find("P2");
    if (it2 != store.getInventory().end())
    {
        order2.addProduct(it2->second);
    }
    customer2.placeOrder(order2);

    Order order3;
    auto it3 = store.getInventory().find("P3");
    if (it3 != store.getInventory().end())
    {
        order3.addProduct(it3->second);
    }
    customer1.placeOrder(order3);

    store.placeOrderForCustomer(customer1.getCustomerID(), order1);
    store.placeOrderForCustomer(customer2.getCustomerID(), order2);
    store.placeOrderForCustomer(customer1.getCustomerID(), order3);

    const std::list<Product> &productsOrderedByCustomer1AfterOrders = store.getProductsOrderedByCustomer("C1");
    const std::list<Product> &productsOrderedByCustomer2AfterOrders = store.getProductsOrderedByCustomer("C2");

    float totalExpenditure1 = store.getTotalExpenditureOfCustomer("C1");
    float totalExpenditure2 = store.getTotalExpenditureOfCustomer("C2");

    const std::list<std::string> &customersWhoPurchasedP2 = store.getCustomersWhoPurchasedProduct("P2");

    std::cout << "Products ordered by Customer 1:" << std::endl;
    for (const Product &product : productsOrderedByCustomer1AfterOrders)
    {
        std::cout << product.getName() << std::endl;
    }

    std::cout << "Products ordered by Customer 2:" << std::endl;
    for (const Product &product : productsOrderedByCustomer2AfterOrders)
    {
        std::cout << product.getName() << std::endl;
    }

    std::cout << "Total expenditure of Customer 1: $" << totalExpenditure1 << std::endl;
    std::cout << "Total expenditure of Customer 2: $" << totalExpenditure2 << std::endl;

    std::cout << "Customers who purchased Product 2:" << std::endl;
    for (const std::string &customerID : customersWhoPurchasedP2)
    {
        std::cout << customerID << std::endl;
    }

    return 0;
}
