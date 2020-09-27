#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

// TODO: in main() make array of objects using this class:
/**
 * Ex.
 int main(){
 	Product listArray[?]	
 }
 
 then, read and convert data from file into Product objects, and add them to the array.
**/
class Product{
	string id;
	string group;
	string name;
	int price;
	int qty;
		
	Product(string a , string b, string c, int d, int e){
		id = a;
		group = b;
		name = c;
		price = d;
		qty = e;
	}
};

string addProduct(){
	string id, group, name;
	int price, qty;
	
	
	//TODO: random/increment product id based on unused ids in list
	cout << "Enter the Product id";
	//cin
	cout << "Enter the Product Group"; //Electronics, Food, etc
	cin >> group;
	cout << "Enter the Product Name";
	cin >> name;
	cout << "Enter the Product Price";
	cin >> price;
	cout << "Enter the Product Quantity";
	cin >> qty;
	
	//replace next line with object array of Products somehow
	//Product productName(id, group, name, price, qty)
	
	//return list;
}

string rmProduct(){
	
	//return list;
}

// returns the contents of file "inventory.txt"
string readFile(){
	string line;
	string content;
	ifstream file;
    file.open("inventory.txt");
    if (file.is_open())
	{
    	while ( getline (file,line) )
    	{	
    		content += line;
    	}
		file.close();
		
		return content;
	}
	else cout << "unable to open file";
}

// the below ___List(){} functions refer to the data from the file stored in a string "list"
// they (mostly) don't directly change the stuff in the file.
void viewList(){
	
}

void editList(){
	
}

//exception: this saves the string "list", overwriting "inventory.txt", not adding to it.
void saveList(string list){
	string fileText;
	
	ofstream file;
	file.open("inventory.txt");
	file << list;
	file.close();
}

int main(){
    int x, y;
    string list;
    
    list = readFile();
    
    
    
    cout<<"|||Product Inventory System v1.0|||\n\n";
    do{
    cout<<"\nProgram Functions";
    cout<<"\n1) Add Product(s)\n2) View Current Inventory Listing\n3) Edit Inventory Listing\n4) Exit Program\n\n";
    cout<<"Please Choose Function to be Executed: ";
    cin>>x;
    	switch(x){
        	case 1: //add new entry(ies)
        	{
        		//list = addProduct(list);
        		saveList(list);
            	break;
        	}
        	case 2: //view list
        	{
       	    	cout << "\nCurrent Inventory:\n" << list << "\n";
            	break;
        	}
        	case 3: //edit entry(ies)
        	{
        		saveList(list);
            	break;
        	}
        	case 4:
        	{
            	cout<<"\nThank you!\n";
     			break;
        	}
        	default:
        	{
        		cout<<"ERROR: Please choose from options 1, 2, or 3. Try again\n\n";
    		}
    	};
    }while(x != 4);
    
    return 0;
};
