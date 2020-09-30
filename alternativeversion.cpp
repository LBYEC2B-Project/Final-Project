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
	private:	
	string name;
	string classification;
	string id;
	int price, qty, count;
	public:
	void Productinfo(string a , string b, string c, int d, int e){
		id = a;
		classification = b;
		name = c;
		price = d;
		qty = e;
	}
	void Displayinfo(){
		cout << id << " " << classification << " " << name << " " << price << " " << qty << endl;
	}
};

class Count{
	private:
	int count;
	public:
	void setCount(int x){
		count = x;
	}
	int getCount(){
		return count;
	}
};

void readFile(){
	string v, w, x;
	int i=1, y, z;
	Product list[100];
	Count cnt;
	ifstream file;
    file.open("inventory.txt");
    if (file.is_open())
	{
    	while ( file >> v >> w >> x >> y >> z )
    	{	
			list[i].Productinfo(v, w, x, y, z);//each line has their own object
			i++;
    	}
		file.close();
		cout << "Successfully scanned inventory list\n";
		cnt.setCount(i);
	}
	else cout << "List is currently empty\n";
};

string GenerateID(string group){
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
	string id, group, name, y;
	Product list[100];
	Count cnt;
	int price, qty;
	int x=1;
	cout <<"Checking Inventory Status...\n";
	readFile();
	int c = cnt.getCount();
	do{
	cout << "Enter Product Group: "; //Electronics, Food, etc
	cin >> group;
	id = GenerateID(group);
	cout << "Enter Product Name: ";
	cin >> name;
	cout << "Enter Product Price: ";
	cin >> price;
	cout << "Enter Product Quantity: ";
	cin >> qty;
	list[c].Productinfo(id, group, name, price, qty);
	cout << "Add another product: ";
	cin >> y;
	if(y == "yes"){
		c++;
		cnt.setCount(c);
	}
	else if(y == "no"){
		x--;
	}
	}while(x!=0);
};

void rmProduct(){
	
	//return list;
};

void viewList(){
	Product list[100];
	Count cnt;

	for(int i=0; i<=cnt.getCount(); i++){
		list[i].Displayinfo();
	}
};

void editList(){
	
};

int main(){
    int x, y;
	cout<<"\n===================================\n";
    cout<<"|||Product Inventory System v1.0|||";
	cout<<"\n===================================\n";
    BasicInfo info;
	Count cnt;
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
				cnt.setCount(0);
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