#include <iostream>
#include <map>
#include <set>
#include <string>
#include <queue>
#include <stack>
#include <algorithm> 
#include <cctype>    

void displayInventory(const std::map<std::string, int>& inventory) {
    std::cout << "\n-->  Current Inventory:\n";
    for (const auto& item : inventory) {
        std::cout << item.first << ": " << item.second << " in stock\n";
    }
    std::cout << std::endl;
}

void addProduct(std::map<std::string, int>& inventory) {
    std::string producto;
    int cantidad;

    std::cout << "Ingrese el producto: ";
    std::cin >> producto;
    std::cout << "Ingrese la cantidad: ";
    std::cin >> cantidad;

    if (cantidad < 0) {
        std::cout << "Cantidad no puede ser negativa.\n";
        return;
    }

    inventory[producto] = cantidad;
    displayInventory(inventory);
}

void updateInventory(std::map<std::string, int>& inventory) {
    std::string producto;
    int cantidad;

    std::cout << "Ingrese el producto: ";
    std::cin >> producto;
    if (!inventory.count(producto)) {
        std::cout << producto << " no se encuentra en el inventario." << std::endl;
    } else {
        std::cout << "Ingrese la cantidad: ";
        std::cin >> cantidad;

        if (cantidad < 0) {
            std::cout << "Cantidad no puede ser negativa.\n";
            return;
        }

        inventory[producto] = cantidad;
        displayInventory(inventory);
    }
}

void displayPCategory(const std::set<std::string>& productCategories) {
    std::cout << "Product Categories:\n";
    for (const auto& category : productCategories) {
        std::cout << "- " << category << "\n";
    }
}

void addPCategory(std::set<std::string>& productCategories) {
    std::string category;
    std::cout << "Introduce a new Product Category:\n";
    std::cin >> category;
    productCategories.insert(category);
    displayPCategory(productCategories);
}

void addOrder(std::queue<std::string>& orders) {
    std::string order;
    int numberorder;
    std::cout << "Ingrese el numero de orden: ";
    std::cin >> numberorder;
    std::cout << "Orden: ";
    std::cin >> order;
    std::string x = "Order #" + std::to_string(numberorder) + ": " + order + "\n";
    orders.push(x);
}

void processOrder(std::queue<std::string>& orders) {
    while (!orders.empty()) {
        std::cout << "Processing " << orders.front() << std::endl;
        orders.pop();
    }
}

void addRestok(std::stack<std::pair<std::string, int>>& restocks) {
    std::string product;
    int quantity;
    std::cout << "Ingrese el producto que desea reordenar: ";
    std::cin >> product;
    std::cout << "Ingrese cantidad de restok: ";
    std::cin >> quantity;

    if (quantity < 0) {
        std::cout << "Cantidad no puede ser negativa.\n";
        return;
    }

    restocks.push({product, quantity});
}

void processRestock(std::stack<std::pair<std::string, int>>& restocks, std::map<std::string, int>& inventory) {
    while (!restocks.empty()) {
        auto restock = restocks.top();
        restocks.pop();
        inventory[restock.first] += restock.second;
        std::cout << "Restocked " << restock.second << " units of " << restock.first << std::endl;
    }
    displayInventory(inventory);
}

void addCart(std:: vector <std::pair<std::string, int>>& customerCart){
    std::string product;
    int quantity;
    std::cout << "Ingrese el producto que desea comprar: ";
    std::cin >> product;
    std::cout << "Ingrese cantidad: ";
    std::cin >> quantity;

    if (quantity < 0) {
        std::cout << "Cantidad no puede ser negativa.\n";
        return;
    }
    customerCart.push_back({product, quantity});
}

void displayCart(std:: vector <std::pair<std::string, int>>& customerCart){
    for (const auto& item : customerCart) {
        std::cout << "*" << item.second << "-" << item.first << "\n";
    }
}

int main() {
    std::map<std::string, int> inventory;
    // Adding products
    inventory["Laptop"] = 5;
    inventory["Mouse"] = 20;
    inventory["Keyboard"] = 10;

    std::set<std::string> productCategories;
    // Adding categories
    productCategories.insert("Electronics");
    productCategories.insert("Accessories");
    productCategories.insert("Peripherals");

    std::queue<std::string> orders;
    // Adding orders
    orders.push("Order#1: Laptop");
    orders.push("Order#2: Mouse");
    orders.push("Order#3: Keyboard");

    std::stack<std::pair<std::string, int>> restocks;
    // Adding restock batches
    restocks.push({"Mouse", 10});
    restocks.push({"Laptop", 2});
    restocks.push({"Keyboard", 5});

    std::vector<std::pair<std::string, int>> customerCart;
    // Adding items to cart
    customerCart.push_back({"Laptop", 1});
    customerCart.push_back({"Mouse", 2});
    customerCart.push_back({"Keyboard", 1});

    int answer;
    do {
            std:: cout << "------------>    Welcome to Tech-Store    <-----------------\n"
                       << "Press (1) to access to Inventory management System. \n"
                       << "Press (2) to access to Costumers Purchase\n"
                       << "Press (0) to Exit... \n";
            std::cin >> answer;

            switch (answer)
            {
            case 1:
                do {
                std::cout << "----> Inventory Management System  <----" << std::endl;
                std::cout << "Access to Inventory Management System, what would you like to do? \n"
                  << "(1) Display the inventory \n"
                  << "(2) Add a new product \n"
                  << "(3) Update the quantity of an existing product \n"
                  << "(4) Display the Product Categories \n"
                  << "(5) Add a new category \n"
                  << "(6) Add a new order \n"
                  << "(7) Process an order \n"
                  << "(8) Add a restok batch \n"
                  << "(9) Process a restok batch \n"
                  << "(10)  \n"
                  << "(0) Exit\n"
                  << "Enter your choice: ";
                std::cin >> answer;

            switch (answer) {
                case 1: displayInventory(inventory); break;
                case 2: addProduct(inventory); break;
                case 3: updateInventory(inventory); break;
                case 4: displayPCategory(productCategories); break;
                case 5: addPCategory(productCategories); break;
                case 6: addOrder(orders); break;
                case 7: processOrder(orders); break;
                case 8: addRestok(restocks); break;
                case 9: processRestock(restocks, inventory); break;
                case 0: std::cout << "Exiting.....\n"; break;
                default: std::cout << "Invalid option. Please try again.\n";
            }
            } while (answer != 0); break;
            
            case 2:
                do{
                std::cout << "----> Customer Management System  <----" << std::endl;
                std::cout << "\n(1) Add items to customer's cart\n"
                          << "(2) Display the items in the cart \n"
                          << "(0) Exit...\n";
                std:: cin >>answer;

                switch (answer) {
                    case 1: addCart(customerCart); break;
                    case 2: displayCart(customerCart); break;
                    case 0: std::cout <<"Exiting...\n"; break;
                }
                }while (answer!=0);
            
            case 0:  std::cout << "Exiting.....\n"; break;   
            default: std::cout << "Invalid option. Please try again.\n";
            }

        
    } while (answer!=0);
    return 0;
}
