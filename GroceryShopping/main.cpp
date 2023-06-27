#include <iostream>

using namespace std;

double MakePurchase();//output the total and ask for confirmation to complete the order
void ListStores();//lists the store to choose from
int ChooseStore();//choose from a list of stores to go to
void LeaveStore();//allows the user to leave the current store
void ListItems();//lists the items in the aisle
void AddPrices(double cartPrices[]);//adds specified prices of items to the user's cart
void PrintReceipt();//outputs the total cost and items purchased upon leaving a store

// JLS: added this to make sure adding items worked but can leave it in to allow users to see cart before checkout
void displayCart() {
    cout << endl << "Your cart contains:" << endl;
    if (cart.empty()) {
        cout << "Cart is empty." << endl;
    }
    else {
        for (const auto& pair : cart) {
            cout << pair.first << ": " << pair.second << endl;
        }
    }
    cout << endl;
}

// JLS: gave additems funcallity to test isles you can change it if needed tho its basic just to make sure items are added
// it dosent have prices yet but will implement them later
void additems(const string& item, int quantity) {
    if (quantity > 0) {
        cart[item] += quantity;
        cout << "Item added to cart." << endl;
    }
    else {
        cout << "Item was not added to cart." << endl;
    }
}

//JLS: isles for Meijer all labeled with M
void MgroceryAisle() {
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
            additems("Milk", quantity);
        }
        else if (item_choice == "2" || item_choice == "eggs") {
            cout << "You have chosen: Eggs" << endl;
            cout << "Enter the quantity you want: ";
            int quantity;
            cin >> quantity;
            additems("Eggs", quantity);
        }
        else if (item_choice == "3" || item_choice == "chicken") {
            cout << "You have chosen: Chicken" << endl;
            cout << "Enter the quantity you want: ";
            int quantity;
            cin >> quantity;
            additems("Chicken", quantity);
        }
        else if (item_choice == "4" || item_choice == "cereal") {
            cout << "You have chosen: Cereal" << endl;
            cout << "Enter the quantity you want: ";
            int quantity;
            cin >> quantity;
            additems("Cereal", quantity);
        }
        else if (item_choice == "list") {
            continue;
        }
        else if (item_choice == "leave") {
            cout << "Exiting the Grocery aisle." << endl;
            break;
        }
        else if (item_choice == "cart") {
            displayCart();
        }
        else {
            cout << "Invalid choice. Please select a valid item or option." << endl;
        }
    }
    cout << endl;
}

//JLS: clothing aisle has a nested loop to select women or men clothing to meet project requirments
void MclothingAisle() {
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
                    additems("Men's T-Shirt", quantity);
                }
                else if (item_choice == "2" || item_choice == "jeans") {
                    cout << "You have chosen: Men's Jeans" << endl;
                    cout << "Enter the quantity you want: ";
                    int quantity;
                    cin >> quantity;
                    additems("Men's Jeans", quantity);
                }
                else if (item_choice == "3" || item_choice == "jacket") {
                    cout << "You have chosen: Men's Jacket" << endl;
                    cout << "Enter the quantity you want: ";
                    int quantity;
                    cin >> quantity;
                    additems("Men's Jacket", quantity);
                }
                else if (item_choice == "list") {
                    continue;
                }
                else if (item_choice == "leave") {
                    cout << "Exiting the Men's Clothing section." << endl;
                    break;
                }
                else if (item_choice == "cart") {
                    displayCart();
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
                    additems("Women's T-Shirt", quantity);
                }
                else if (item_choice == "2" || item_choice == "jeans") {
                    cout << "You have chosen: Women's Jeans" << endl;
                    cout << "Enter the quantity you want: ";
                    int quantity;
                    cin >> quantity;
                    additems("Women's Jeans", quantity);
                }
                else if (item_choice == "3" || item_choice == "jacket") {
                    cout << "You have chosen: Women's Jacket" << endl;
                    cout << "Enter the quantity you want: ";
                    int quantity;
                    cin >> quantity;
                    additems("Women's Jacket", quantity);
                }
                else if (item_choice == "list") {
                    continue;
                }
                else if (item_choice == "leave") {
                    cout << "Exiting the Women's Clothing section." << endl;
                    break;
                }
                else if (item_choice == "cart") {
                    displayCart();
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
            displayCart();
        }
        else {
            cout << "Invalid choice. Please select a valid section or option." << endl;
        }
    }
    cout << endl;
}

void MelectronicsAisle() {
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
            additems("Laptop", quantity);
        }
        else if (item_choice == "2" || item_choice == "smartphone") {
            cout << "You have chosen: Smartphone" << endl;
            cout << "Enter the quantity you want: ";
            int quantity;
            cin >> quantity;
            additems("Smartphone", quantity);
        }
        else if (item_choice == "3" || item_choice == "headphones") {
            cout << "You have chosen: Headphones" << endl;
            cout << "Enter the quantity you want: ";
            int quantity;
            cin >> quantity;
            additems("Headphones", quantity);
        }
        else if (item_choice == "list") {
            continue;
        }
        else if (item_choice == "leave") {
            cout << "Exiting the Electronics aisle." << endl;
            break;
        }
        else if (item_choice == "cart") {
            displayCart();
        }
        else {
            cout << "Invalid choice. Please select a valid item or option." << endl;
        }
    }
    cout << endl;
}

//JLS: mejier store to select the aisles ill add the other stores based off of this as the base
void mejier() {
    cout << "Welcome to the Supermarket!" << endl;

    while (true) {
        cout << "Please select an aisle:" << endl;
        cout << "1. Grocery" << endl;
        cout << "2. Clothing" << endl;
        cout << "3. Electronics" << endl;
        cout << "Enter the number of the aisle you want (1-3), 'cart' to view your cart, or 'exit' to exit the supermarket: ";

        string aisle_choice;
        cin >> aisle_choice;

        if (aisle_choice == "1" || aisle_choice == "grocery") {
            MgroceryAisle();
        }
        else if (aisle_choice == "2" || aisle_choice == "clothing") {
            MclothingAisle();
        }
        else if (aisle_choice == "3" || aisle_choice == "electronics") {
            MelectronicsAisle();
        }
        else if (aisle_choice == "cart") {
            displayCart();
        }
        else if (aisle_choice == "exit") {
            cout << "Thank you for shopping with us. Goodbye!" << endl;
            break;
        }
        else {
            cout << "Invalid choice. Please select a valid aisle or option." << endl;
        }
    }

    return 0;
}

int main() {
    //variables
    int i;//this integer will represent which store the user is in

    ListStores();

}
void ListStores() {
    cout << "Available stores to choose from: " << endl;
    cout << "Meijer" << endl;
    cout << "Wallmart" << endl;
    cout << "Target" << endl;
    cout << "Type any Store to enter: ";
}
// this 
int ChooseStore() {

}