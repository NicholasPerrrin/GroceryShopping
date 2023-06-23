#include <iostream>

using namespace std;

double MakePurchase();//output the total and ask for confirmation to complete the order
void ListStores();//lists the store to choose from
int ChooseStore();//choose from a list of stores to go to
void LeaveStore();//allows the user to leave the current store
void ListItems();//lists the items in the aisle
void AddItems(string cartItems[]);//adds specified items to the user's cart
void AddPrices(double cartPrices[]);//adds specified prices of items to the user's cart
void PrintReceipt();//outputs the total cost and items purchased upon leaving a store

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
/*
int ChooseStore() {

}*/