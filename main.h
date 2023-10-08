#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <list>

class Product
{
private:
    std::string _productID;
    std::string _name;
    float _price;

public:
    Product() = default;
    Product(const std::string &productID, const std::string &name, float price)
        : _productID(productID), _name(name), _price(price) {}

    std::string getProductID() const
    {
        return _productID;
    }

    std::string getName() const
    {
        return _name;
    }

    float getPrice() const
    {
        return _price;
    }
};

class Order
{
private:
    std::vector<Product> _orderedProducts;

public:
    void addProduct(const Product &product)
    {
        _orderedProducts.push_back(product);
    }

    const std::vector<Product> &getOrderedProducts() const
    {
        return _orderedProducts;
    }
};

class Customer
{
private:
    std::string _customerID;
    std::string _customerName;
    std::vector<Order> _orders;

public:
    Customer() = default;
    Customer(const std::string &customerID, const std::string &customerName)
        : _customerID(customerID), _customerName(customerName) {}

    void placeOrder(const Order &order)
    {
        _orders.push_back(order);
    }

    std::string getCustomerID() const
    {
        return _customerID;
    }

    std::string getCustomerName() const
    {
        return _customerName;
    }

    const std::vector<Order> &getOrders() const
    {
        return _orders;
    }
};

class RetailStore
{
private:
    std::map<std::string, Product> _inventory;
    std::map<std::string, Customer> _customers;

public:
    void addProductToInventory(const Product &product)
    {
        _inventory[product.getProductID()] = product;
    }

    void addCustomer(const Customer &customer)
    {
        _customers[customer.getCustomerID()] = customer;
    }

    void placeOrderForCustomer(const std::string &customerID, const Order &order)
    {
        if (_customers.find(customerID) != _customers.end())
        {
            _customers[customerID].placeOrder(order);
        }
    }

    std::list<Product> getProductsOrderedByCustomer(const std::string &customerID) const
    {
        std::list<Product> productsOrdered;
        if (_customers.find(customerID) != _customers.end())
        {
            const std::vector<Order> &orders = _customers.at(customerID).getOrders();
            for (const Order &order : orders)
            {
                const std::vector<Product> &orderedProducts = order.getOrderedProducts();
                productsOrdered.insert(productsOrdered.end(), orderedProducts.begin(), orderedProducts.end());
            }
        }
        return productsOrdered;
    }

    float getTotalExpenditureOfCustomer(const std::string &customerID) const
    {
        float totalExpenditure = 0.0;
        if (_customers.find(customerID) != _customers.end())
        {
            const std::vector<Order> &orders = _customers.at(customerID).getOrders();
            for (const Order &order : orders)
            {
                const std::vector<Product> &orderedProducts = order.getOrderedProducts();
                for (const Product &product : orderedProducts)
                {
                    totalExpenditure += product.getPrice();
                }
            }
        }
        return totalExpenditure;
    }

    std::list<std::string> getCustomersWhoPurchasedProduct(const std::string &productID) const
    {
        std::list<std::string> customersWhoPurchased;
        for (const auto &customer : _customers)
        {
            const std::vector<Order> &orders = customer.second.getOrders();
            for (const Order &order : orders)
            {
                const std::vector<Product> &orderedProducts = order.getOrderedProducts();
                for (const Product &product : orderedProducts)
                {
                    if (product.getProductID() == productID)
                    {
                        customersWhoPurchased.push_back(customer.first);
                        break;
                    }
                }
            }
        }
        return customersWhoPurchased;
    }

    const std::map<std::string, Product> &getInventory() const
    {
        return _inventory;
    }

    const std::map<std::string, Customer> &getCustomers() const
    {
        return _customers;
    }
};
