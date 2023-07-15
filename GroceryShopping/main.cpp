#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

//global variables
string storeName;
int index = 0;
const int CART_SIZE = 100;

struct shopper {
    string firstName;
    string LastName;
    string cart[CART_SIZE];
};

void ListStores(shopper customer);//lists the store to choose from
string ChooseStore(int i);//choose from a list of stores to go to
void displayCart(shopper& customer);
void Store(string storeName, shopper& customer);
double GetItemPrice(string item);
void SaveReceipt(shopper customer, double total);
double CalculateTotal(shopper customer);
void ReadShoppingList(shopper& customer);

shopper Customer(shopper customer);

// JLS: added this to make sure adding items worked but can leave it in to allow users to see cart before checkout
void displayCart(shopper& customer) {
    cout << setfill('.');
    if (customer.cart[0] == "") {
        cout << "Cart is empty" << endl;
    }
    else {
        cout << "Your cart" << endl;
        for (int i = 0; i < CART_SIZE; i++) {
            if (customer.cart[i] != "") {
                cout << i + 1 << ": " << setw(15) << customer.cart[i] << endl;
            }
            else {
                continue;
            }
        }
    }
}

// JLS: gave additems funcallity to test isles you can change it if needed tho its basic just to make sure items are added
// it dosent have prices yet but will implement them later
void additems(string item, int quantity, shopper& customer) {
    for (int i = 0; i < quantity; i++) {
        index;
        customer.cart[index] = item;
        index++;
    }
}

//JLS: aisles for Meijer all labeled with M
void MgroceryAisle(shopper& customer) {
    int quantity;
    cout << endl << "You are in the Grocery aisle." << endl;

    while (true) {
        cout << "Items available in Grocery:" << endl;
        cout << "1. Milk" << endl;
        cout << "2. Eggs" << endl;
        cout << "3. Chicken" << endl;
        cout << "4. Cereal" << endl;
        cout << "Enter the number of the item you want (1-4), 'list' to view items again, 'leave' to exit the aisle, or 'cart' to view your cart: ";

        string item_choice;
        cin >> item_choice;

        if (item_choice == "1" || item_choice == "milk") {
            cout << "You have chosen: Milk" << endl;
            cout << "Enter the quantity you want: ";
            cin >> quantity;
            cout << endl;
            additems("Milk", quantity, customer);
        }
        else if (item_choice == "2" || item_choice == "eggs") {
            cout << "You have chosen: Eggs" << endl;
            cout << "Enter the quantity you want: ";
            cin >> quantity;
            cout << endl;
            additems("Eggs", quantity, customer);
        }
        else if (item_choice == "3" || item_choice == "chicken") {
            cout << "You have chosen: Chicken" << endl;
            cout << "Enter the quantity you want: ";
            cin >> quantity;
            cout << endl;
            additems("Chicken", quantity, customer);
        }
        else if (item_choice == "4" || item_choice == "cereal") {
            cout << "You have chosen: Cereal" << endl;
            cout << "Enter the quantity you want: ";
            cin >> quantity;
            cout << endl;
            additems("Cereal", quantity, customer);
        }
        else if (item_choice == "list") {
            continue;
        }
        else if (item_choice == "leave") {
            cout << "Exiting the Grocery aisle." << endl;
            break;
        }
        else if (item_choice == "cart") {
            displayCart(customer);
        }
        else {
            cout << "Invalid choice. Please select a valid item or option." << endl;
        }
    }
    cout << endl;
}

//JLS: clothing aisle has a nested loop to select women or men clothing to meet project requirments
void MclothingAisle(shopper& customer) {
    int quantity;
    cout << endl << "You are in the Clothing aisle." << endl;

    while (true) {
        cout << "Please select a clothing section:" << endl;
        cout << "1. Men's Clothing" << endl;
        cout << "2. Women's Clothing" << endl;
        cout << "Enter the number of the section you want (1-2), 'list' to view sections again, 'leave' to exit the aisle, or 'cart' to view your cart: ";

        string section_choice;
        cin >> section_choice;

        if (section_choice == "1" || section_choice == "men" || section_choice == "mens") {
            cout << endl;
            cout << "You are in the Men's Clothing section." << endl;

            while (true) {
                cout << "Items available in Men's Clothing:" << endl;
                cout << "1. T-Shirt" << endl;
                cout << "2. Jeans" << endl;
                cout << "3. Jacket" << endl;
                cout << "Enter the number of the item you want (1-3), 'list' to view items again, 'leave' to exit the section, or 'cart' to view your cart: ";

                string item_choice;
                cin >> item_choice;

                if (item_choice == "1" || item_choice == "t-shirt") {
                    cout << "You have chosen: Men's T-Shirt" << endl;
                    cout << "Enter the quantity you want: ";
                    cin >> quantity;
                    cout << endl;
                    additems("Men's T-Shirt", quantity, customer);
                }
                else if (item_choice == "2" || item_choice == "jeans") {
                    cout << "You have chosen: Men's Jeans" << endl;
                    cout << "Enter the quantity you want: ";
                    cin >> quantity;
                    cout << endl;
                    additems("Men's Jeans", quantity, customer);
                }
                else if (item_choice == "3" || item_choice == "jacket") {
                    cout << "You have chosen: Men's Jacket" << endl;
                    cout << "Enter the quantity you want: ";
                    cin >> quantity;
                    cout << endl;
                    additems("Men's Jacket", quantity, customer);
                }
                else if (item_choice == "list") {
                    continue;
                }
                else if (item_choice == "leave") {
                    cout << "Exiting the Men's Clothing section." << endl;
                    break;
                }
                else if (item_choice == "cart") {
                    displayCart(customer);
                }
                else {
                    cout << "Invalid choice. Please select a valid item or option." << endl;
                }
            }
            cout << endl;
        }
        else if (section_choice == "2" || section_choice == "women" || section_choice == "womens") {
            cout << endl;
            cout << "You are in the Women's Clothing section." << endl;

            while (true) {
                cout << "Items available in Women's Clothing:" << endl;
                cout << "1. T-Shirt" << endl;
                cout << "2. Jeans" << endl;
                cout << "3. Jacket" << endl;
                cout << "Enter the number of the item you want (1-3), 'list' to view items again, 'leave' to exit the section, or 'cart' to view your cart: ";

                string item_choice;
                cin >> item_choice;

                if (item_choice == "1" || item_choice == "t-shirt") {
                    cout << "You have chosen: Women's T-Shirt" << endl;
                    cout << "Enter the quantity you want: ";
                    int quantity;
                    cin >> quantity;
                    additems("Women's T-Shirt", quantity, customer);
                }
                else if (item_choice == "2" || item_choice == "jeans") {
                    cout << "You have chosen: Women's Jeans" << endl;
                    cout << "Enter the quantity you want: ";
                    int quantity;
                    cin >> quantity;
                    additems("Women's Jeans", quantity, customer);
                }
                else if (item_choice == "3" || item_choice == "jacket") {
                    cout << "You have chosen: Women's Jacket" << endl;
                    cout << "Enter the quantity you want: ";
                    int quantity;
                    cin >> quantity;
                    additems("Women's Jacket", quantity, customer);
                }
                else if (item_choice == "list") {
                    continue;
                }
                else if (item_choice == "leave") {
                    cout << "Exiting the Women's Clothing section." << endl;
                    break;
                }
                else if (item_choice == "cart") {
                    displayCart(customer);
                }
                else {
                    cout << "Invalid choice. Please select a valid item or option." << endl;
                }
            }
            cout << endl;
        }
        else if (section_choice == "list") {
            continue;
        }
        else if (section_choice == "leave") {
            cout << "Exiting the Clothing aisle." << endl;
            break;
        }
        else if (section_choice == "cart") {
            //displayCart();
        }
        else {
            cout << "Invalid choice. Please select a valid section or option." << endl;
        }
    }
    cout << endl;
}

void MelectronicsAisle(shopper& customer) {
    int quantity;
    cout << endl << "You are in the Electronics aisle." << endl;

    while (true) {
        cout << "Items available in Electronics:" << endl;
        cout << "1. Laptop" << endl;
        cout << "2. Smartphone" << endl;
        cout << "3. Headphones" << endl;
        cout << "Enter the number of the item you want (1-3), 'list' to view items again, 'leave' to exit the aisle, or 'cart' to view your cart: ";

        string item_choice;
        cin >> item_choice;

        if (item_choice == "1" || item_choice == "laptop") {
            cout << "You have chosen: Laptop" << endl;
            cout << "Enter the quantity you want: ";
            cin >> quantity;
            cout << endl;
            additems("Laptop", quantity, customer);
        }
        else if (item_choice == "2" || item_choice == "smartphone") {
            cout << "You have chosen: Smartphone" << endl;
            cout << "Enter the quantity you want: ";
            cin >> quantity;
            cout << endl;
            additems("Smartphone", quantity, customer);
        }
        else if (item_choice == "3" || item_choice == "headphones") {
            cout << "You have chosen: Headphones" << endl;
            cout << "Enter the quantity you want: ";
            cin >> quantity;
            cout << endl;
            additems("Headphones", quantity, customer);
        }
        else if (item_choice == "list") {
            continue;
        }
        else if (item_choice == "leave") {
            cout << "Exiting the Electronics aisle." << endl;
            break;
        }
        else if (item_choice == "cart") {
            displayCart(customer);
        }
        else {
            cout << "Invalid choice. Please select a valid item or option." << endl;
        }
    }
    cout << endl;
}

//JLS: mejier store to select the aisles ill add the other stores based off of this as the base
void Store(string storeName, shopper& customer) {
    cout << endl << "Welcome to " << storeName << "!" << endl;

    while (true) {
        cout << "Please select an aisle:" << endl;
        cout << "1. Grocery" << endl;
        cout << "2. Clothing" << endl;
        cout << "3. Electronics" << endl;
        cout << "Enter the number of the aisle you want (1-3), 'cart' to view your cart, or 'exit' to exit the supermarket: ";

        string aisle_choice;
        cin >> aisle_choice;

        if (aisle_choice == "1" || aisle_choice == "grocery") {
            MgroceryAisle(customer);
        }
        else if (aisle_choice == "2" || aisle_choice == "clothing") {
            MclothingAisle(customer);
        }
        else if (aisle_choice == "3" || aisle_choice == "electronics") {
            MelectronicsAisle(customer);
        }
        else if (aisle_choice == "cart") {
            displayCart(customer);
        }
        else if (aisle_choice == "exit") {
            cout << endl << "Thank you for shopping with us. Goodbye!" << endl;
            double total = CalculateTotal(customer);
            SaveReceipt(customer, total);
            break;
        }
        else {
            cout << "Invalid choice. Please select a valid aisle or option." << endl;
        }
    }
}

int main() {
    //variables
    int i;//this integer will represent which store the user is in

    //shopper structure
    shopper customer;

    //initialize customer
    customer = Customer(customer);

    //call ReadShoppingList
    ReadShoppingList(customer);
    //call ListStores
    ListStores(customer);
    
    //get input from user to choose store
    cin >> i;
    //select store that the user has entered
    string storeName = ChooseStore(i);
    //call Store
    Store(storeName, customer);

}
void ListStores(shopper customer) {
    cout << "Hello, " << customer.firstName << " " << customer.LastName << endl << endl;
    cout << "Available stores to choose from: " << endl;
    cout << "Meijer (press 1)" << endl;
    cout << "Wallmart (press 2)" << endl;
    cout << "Target (press 3)" << endl;
    cout << "Type any Store to enter: ";
}

string ChooseStore(int i) {
    switch (i) {
    case 1:
        storeName = "Meijer";
        break;
    case 2:
        storeName = "Wallmart";
        break;
    case 3:
        storeName = "Target";
    }
    return storeName;
}

shopper Customer(shopper customer) {
    cout << "Please enter your name: ";
    cin >> customer.firstName >> customer.LastName;

    return customer;
}

//JLS: function to read from file shoppinglist.txt and add the items in the txt file to cart
void ReadShoppingList(shopper& customer) {
    ifstream inputFile("shoppinglist.txt");
    if (inputFile.is_open()) {
        string item;
        int quantity;
        while (inputFile >> item >> quantity) {
            additems(item, quantity, customer);
        }
        inputFile.close();
        cout << endl << "Items from shoppinglist.txt added to the cart." << endl << endl;
    }
    else {
        cout << "Error opening shoppinglist.txt file!" << endl;
    }
}

// Function to save the receipt to a file
void SaveReceipt(shopper customer, double total) {
    ofstream receiptFile;
    receiptFile.open("receipt.txt");
    if (receiptFile.is_open()) {
        receiptFile << "Receipt" << endl;
        receiptFile << "----------------------" << endl;
        for (int i = 0; i < 100; i++) {
            if (!customer.cart[i].empty()) {
                receiptFile << customer.cart[i] << ": $" << fixed << setprecision(2) << GetItemPrice(customer.cart[i]) << endl;
            }
        }
        receiptFile << "----------------------" << endl;
        receiptFile << "Total: $" << fixed << setprecision(2) << total << endl;
        receiptFile.close();
        cout << "Receipt saved to receipt.txt" << endl;
    }
    else {
        cout << "Error saving receipt to file!" << endl;
    }
}
// Function to get the price of an item
double GetItemPrice(string item) {
    if (item == "Milk") {
        return 2.99;
    }
    else if (item == "Eggs") {
        return 1.99;
    }
    else if (item == "Chicken") {
        return 5.99;
    }
    else if (item == "Cereal") {
        return 3.49;
    }
    else if (item == "T-Shirt") {
        return 9.99;
    }
    else if (item == "Jeans") {
        return 19.99;
    }
    else if (item == "Jacket") {
        return 29.99;
    }
    else if (item == "Laptop") {
        return 599.99;
    }
    else if (item == "Smartphone") {
        return 399.99;
    }
    else if (item == "Headphones") {
        return 49.99;
    }
    return 0.0;
}
// Function to calculate the total cost of the items in the cart
// JLS:added nested loop to meet projects requirements
double CalculateTotal(shopper customer) {
    double total = 0.0;
    for (int i = 0; i < CART_SIZE; i++) {
                total += GetItemPrice(customer.cart[i]);
    }
    return total;
}