# Homework 5: Implementing the List Data Structure<br>
*Due Date: Monday 9th of October, end of day*<br>
In this homework, you are tasked to design and implement a system for an online retail store. Given the description and requirements below, you have to decide the appropriate containers to use among std::vector, std::set, and std::map.<br>
The retail store offers a variety of products. Each product has a unique product ID, a name, and a price. Customers can place orders, with each order containing one or more products. Each customer has a unique customer ID and a name.<br>
## A Brief about std::pair
When you’re working with maps, you’re often dealing with pairs. A pair is a simple data structure provided by the C++ Standard Library to store two heterogeneous objects as a single unit. A map in C++ is essentially a collection of such pairs where the first item of the pair (accessible via .first) acts as the key and the second item (accessible via .second) as the associated value.<br>
For example, if you have a std::map<std::string, float> products, each element in this map is a pair. The .first attribute would give the product name (a string), and the .second attribute would give its price (a float).<br>
*Hint: When iterating through a map using a range-based for loop, each element will be a pair. This can be useful when you want both the key and the value during the iteration.*<br>
# Tasks<br>

1. Design and implement a Product class. This class should store details about a product. Add private members:<br>
• std::string _productID<br>
• std::string _name<br>
• float _price<br>

2. Design and implement an Order class. This class should store the products that make up an order. Suggested private member:<br>
• A container (your choice) named _orderedProducts to store products.<br>

3. Design and implement a Customer class. Add the following private members:<br>
• std::string _customerID<br>
• std::string _customerName<br>
• A container (your choice) named _orders to store the customer’s orders.<br>

4. Design a system that allows:<br>
• void addProductToInventory(const Product& product): Adding new products to the store’s inventory.<br>
• void placeOrderForCustomer(const std::string& customerID, const Order& order): Placing an order for a customer.<br>
• std::list<Product> getProductsOrderedByCustomer(const std::string& customerID) const: Retrieving a list of all products ordered by a specific customer.<br>
• float getTotalExpenditureOfCustomer(const std::string& customerID) const: Retrieving the total expenditure of a customer.<br>
• std::list<std::string> getCustomersWhoPurchasedProduct(const std::string& productID) const: Listing all customers who purchased a particular product.<br>

5. Implement the system and create a main function to showcase its functionality. Add at least three products, two customers, and place at least three orders in total.<br>
