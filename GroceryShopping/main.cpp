#include <iostream>

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

double MakePurchase();//output the total and ask for confirmation to complete the order
void ListStores(shopper customer);//lists the store to choose from
string ChooseStore(int i);//choose from a list of stores to go to
void LeaveStore();//allows the user to leave the current store
void ListItems();//lists the items in the aisle
void addItems(string item, int quantity, shopper customer);
void PrintReceipt();//outputs the total cost and items purchased upon leaving a store
void displayCart(shopper& customer);
void Store(string storeName, shopper customer);
shopper Customer(shopper customer);

// JLS: added this to make sure adding items worked but can leave it in to allow users to see cart before checkout
void displayCart(shopper& customer) {
    if (customer.cart[0] == "") {
        cout << "Cart is empty" << endl;
    }
    else {
        for (int i = 0; i < CART_SIZE; i++) {
            cout << customer.cart[i];
        }
    }
}

// JLS: gave additems funcallity to test isles you can change it if needed tho its basic just to make sure items are added
// it dosent have prices yet but will implement them later
void additems(string item, int quantity, shopper& customer) {
    for (int i = 0; i < quantity; i++) {
        customer.cart[index] = item;
        index++;
    }
}

//JLS: aisles for Meijer all labeled with M
void MgroceryAisle(shopper customer) {
    cout << "You are in the Grocery aisle." << endl;

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
            int quantity;
            cin >> quantity;
            additems("Milk", quantity, customer);
        }
        else if (item_choice == "2" || item_choice == "eggs") {
            cout << "You have chosen: Eggs" << endl;
            cout << "Enter the quantity you want: ";
            int quantity;
            cin >> quantity;
            additems("Eggs", quantity, customer);
        }
        else if (item_choice == "3" || item_choice == "chicken") {
            cout << "You have chosen: Chicken" << endl;
            cout << "Enter the quantity you want: ";
            int quantity;
            cin >> quantity;
            additems("Chicken", quantity, customer);
        }
        else if (item_choice == "4" || item_choice == "cereal") {
            cout << "You have chosen: Cereal" << endl;
            cout << "Enter the quantity you want: ";
            int quantity;
            cin >> quantity;
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
void MclothingAisle(shopper customer) {
    cout << "You are in the Clothing aisle." << endl;

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
                    int quantity;
                    cin >> quantity;
                    additems("Men's T-Shirt", quantity, customer);
                }
                else if (item_choice == "2" || item_choice == "jeans") {
                    cout << "You have chosen: Men's Jeans" << endl;
                    cout << "Enter the quantity you want: ";
                    int quantity;
                    cin >> quantity;
                    additems("Men's Jeans", quantity, customer);
                }
                else if (item_choice == "3" || item_choice == "jacket") {
                    cout << "You have chosen: Men's Jacket" << endl;
                    cout << "Enter the quantity you want: ";
                    int quantity;
                    cin >> quantity;
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

void MelectronicsAisle(shopper customer) {
    cout << "You are in the Electronics aisle." << endl;

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
            int quantity;
            cin >> quantity;
            additems("Laptop", quantity, customer);
        }
        else if (item_choice == "2" || item_choice == "smartphone") {
            cout << "You have chosen: Smartphone" << endl;
            cout << "Enter the quantity you want: ";
            int quantity;
            cin >> quantity;
            additems("Smartphone", quantity, customer);
        }
        else if (item_choice == "3" || item_choice == "headphones") {
            cout << "You have chosen: Headphones" << endl;
            cout << "Enter the quantity you want: ";
            int quantity;
            cin >> quantity;
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
void Store(string storeName, shopper customer) {
    cout << "Welcome to " << storeName << "!" << endl;

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
            cout << "Thank you for shopping with us. Goodbye!" << endl;
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

    ListStores(customer);
    
    //get input from user to choose store
    cin >> i;
    //select store that the user has entered
    string storeName = ChooseStore(i);

    Store(storeName, customer);

}
void ListStores(shopper customer) {
    cout << "Hello, " << customer.firstName << " " << customer.LastName << endl;
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