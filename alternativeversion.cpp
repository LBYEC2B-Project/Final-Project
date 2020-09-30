#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

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
    }
};

class Product{
	protected:	
	string name[100];
	string classification[100];
	string id[100];
	int price[100], qty[100];
	int cnt = 0;

	public:
	int count = 0;
	void Productinfo(string a , string b, string c, int d, int e, int i){
		id[i] = a;
		classification[i] = b;
		name[i] = c;
		price[i] = d;
		qty[i] = e;
		count = count + 1;
		cnt = count;
	}
	};

class NewProducts: protected Product{
	public:
	void Productsadded(string a , string b, string c, int d, int e){ 
		int i = 1;
		i = i + cnt;
		id[i] = a;
		classification[i] = b;
		name[i] = c;
		price[i] = d;
		qty[i] = e;
		cnt = cnt + 1;
	}
};

class Display: public NewProducts{ //Problem: outputs garbage values
	public:
	void Displayinfo(){
		for(int i=1; i<=cnt; i++){
		cout << id[i] << " " << classification[i] << " " << name[i] << " " << price[i] << " " << qty[i] << endl;
	}
	}
};

void readFile(){
	string v, w, x;
	int i=0, y, z;
	Product list;
	ifstream file;
	cout <<"Checking Inventory Status...\n";
    file.open("inventory.txt");
    if (file.is_open())
	{
    	while ( file >> v >> w >> x >> y >> z ) //input info on every line to variables supposedly
    	{	
			list.Productinfo(v, w, x, y, z, i);//copies info to product class
			i++;
    	}
		file.close();
		cout << "Successfully scanned inventory list\n";
	}
	else cout << "List is currently empty\n";
};

string GenerateID(string group){ //product id, somehow make it more specific
		if(group == "Electronics"){
				group = "E";
			}
		else if(group == "Clothing"){
				group = "C";
			}
		else if(group == "Food"){
				group = "F";
			}
		return group;
};

void addProduct(){
	NewProducts add; //add new product class
	string id, group, name, y;
	int price, qty;
	int x = 1;
	readFile();
	do{
	cout << "Enter Product Group: ";
	cin >> group;
	id = GenerateID(group);
	cout << "Enter Product Name: ";
	cin >> name;
	cout << "Enter Product Price: ";
	cin >> price;
	cout << "Enter Product Quantity: ";
	cin >> qty;
	add.Productsadded(id , group, name, price, qty); //will copy inputs to addproducts class
	cout << "Add another product: ";
	cin >> y;
	if((y == "yes")||(y == "Yes")){
	}
	else if((y == "no")||(y == "No")){
		x--;
	}
	}while(x!=0);
};

void rmProduct(){
	//return list;
};

void viewList(){
	Display show;
	show.Displayinfo();
};

void editList(){
	
};

int main(){
    int x, y;
	cout<<"\n===================================\n";
    cout<<"|||Product Inventory System v1.0|||";
	cout<<"\n===================================\n";
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