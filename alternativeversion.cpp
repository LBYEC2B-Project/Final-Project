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

class BasicInfo{
    private:
    char name[20], company[20];
    public:
    BasicInfo(){
        cout<<"Basic User Information\n";
        cout<<"Name of User: ";
        cin>>name;
        cout<<"Company Name: ";
        cin>>company;
    };
};

class Product{
	private:
	string name;
	string classification;
	string id;
	int price;
	int qty;

	public:	
	void Productinfo(string a , string b, string c, int d, int e){
		id = a;
		classification = b;
		name = c;
		price = d;
		qty = e;
	}
};

// returns the contents of file "inventory.txt"
// v=id w=classification x=name y=price z=qty
void readFile(){
	string v, w, x;
	int y, z;
	int i=1;
	Product list[100];
	ifstream file;
    file.open("inventory.txt");
    if (file.is_open())
	{
    	while ( file >> v >> w >> x >> y >> z )
    	{	
			list[i].Productinfo(v, w, x, y, z);//each line has their own object
    	}
		file.close();
		cout << "Successfully scanned inventory list\n";
	}
	else cout << "List is currently empty\n";
};

void addProduct(){
	string id, group, name;
	int price, qty;

	cout <<"Checking Inventory Status...\n";
	readFile();
	
	//TODO: random/increment product id based on unused ids in list
	cout << "Enter Product Group: "; //Electronics, Food, etc
	cin >> group;
	cout << "Enter Product Name: ";
	cin >> name;
	cout << "Enter Product Price: ";
	cin >> price;
	cout << "Enter Product Quantity: ";
	cin >> qty;
};

void rmProduct(){
	
	//return list;
};

// the below ___List(){} functions refer to the data from the file stored in a string "list"
// they (mostly) don't directly change the stuff in the file.
void viewList(){
	
}

void editList(){
	
}

int main(){
    int x, y;
    cout<<"|||Product Inventory System v1.0|||\n\n";
    BasicInfo info;
    do{
    cout<<"\nProgram Functions";
    cout<<"\n1) Add Product(s)\n2) View Current Inventory Listing\n3) Edit Inventory Listing\n4) Exit Program\n\n";
    cout<<"Please Choose Function to be Executed: ";
    cin>>x;
    	switch(x){
        	case 1: //add new entry(ies)
        	{
        		//list = addProduct(list);
				addProduct();
            	break;
        	}
        	case 2: //view list
        	{
				viewList();
            	break;
        	}
        	case 3: //edit entry(ies)
        	{
				editList();
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