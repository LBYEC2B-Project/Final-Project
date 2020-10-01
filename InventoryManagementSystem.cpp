/*
Note:
Unsure why there sometimes are stoi() (converts strings to int, from <string>) type errors
when the only values input to stoi() strings, and the only values set "list[example].price = stoi(string)" are ints 
**/
#include "InventoryManagementSystem.h"
#include <sstream>
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
using namespace std;

//saves list to txt file "inventory.txt"
void saveList(Product * list, int *size){
	string filename = "inventory.txt";
	ofstream file(filename);
	
	//format of the txt file (every \t is important)
	for (int n=0; n<*size; n++){
		//adds data to file
		file << list[n].id << "\t" << list[n].name << "\t" << list[n].group << "\t" << list[n].price << "\t" << list[n].qty << "\t\n";
	};
}

void addProduct(Product * list, int *size, string *content){
	string pName,pGroup;
	int pPrice, pQty;
	
//	cout << "Size = " << *size << endl;
	
   	list[*size-1].id = *size;
   	*content += (*size + "\t");
   	
	cout << "Enter the Name of the Product: ";
	cin >> pName;
	list[*size-1].name = pName;
	*content += (pName + "\t");
	
	cout << "Enter the Group of the Product: ";
	cin >> pGroup;        	
   	list[*size-1].group = pGroup;
	*content += (pGroup+ "\t");

	cout << "Enter the Price of the Product: ";
	cin >> pPrice;
   	list[*size-1].price = pPrice;
	*content += (pPrice+ "\t");

   	cout << "Enter the Quantity of the Product: ";
   	cin >> pQty;
   	list[*size-1].qty = pQty;
	*content += (pQty + "\t\n");
}

void printList(Product *list, int *size){
	for (int n = 0; n < *size; n++){
		cout << "ID:\t\t" <<list[n].id << endl
			<< "NAME:\t\t" <<list[n].name << endl
			<< "GROUP:\t\t" <<list[n].group << endl
			<< "PRICE:\t\t" <<list[n].price << endl
			<< "QUANTITY:\t" <<list[n].qty << endl << endl;
	}
}

void renderMenu(Product * list, int *size){
	int counter = 0;
	cout<<"|||Product Inventory System v1.0|||\n";
	if(*size== 0)
	{
		cout << "\nYour List is Empty!\n";
	}
	else
	{
		cout << "\nThe list currently contains " << *size << " unique item(s)\n";
		
		for (int n = 0; n<*size; n++){
			if (list[n].qty <= 0){
				counter++;
			}
		}
		if (counter > 0){
			cout << "\n\n" << counter << " of these items, " << "are currently out of stock.\n";
		}
		else
		{
			cout << "All items are currently in stock.\n";
		}
	}
	cout<<"\nProgram Functions";
	cout<<"\n1) Add Product(s)\n2) View Current Inventory Listing\n3) Edit Inventory Listing\n4) Search for a Product\n5) Exit Program\n\n";
	cout<<"Please Choose Function to be Executed: ";
};

 void loadFileData(Product *list, int *size, string *content) {
	fstream file;
	string filename = "inventory.txt";
	string line;
	int count;
	
    file.open(filename);
    if (file.is_open())
	{	

		//reads file line by line
    	while ( getline (file,line) )
    	{
    		*content += line;
    		count++;
    	}
		file.close();
		*size = count;
	}
	else {
		cout << "No List Available. Creating New List. . .\n\n";
		ofstream file(filename);
		
		//prints blank file
		file << "";
		
		//test values
		file << "1\tBrandless_Phone\tElectronics\t50\t40\t\n"
			<< "2\tBrandless_TV\tElectronics\t100\t74\t\n"
			<< "3\tBrandless_Banana\tFood\t99\t1\t\n"
			<< "4\tBrandless_Painting\tHome_Decor\t50\t40\t\n";
		*size = 4;
		
		cout << "Done!\n\n";
		file.close();
	}
}

//unused
//resizes the Product * list array
void oldReallocateMemory(Product * list, int *size){
	Product * tmp = NULL;
	tmp = new Product[*size];
	
	//copy list to tmp (working)
	for (int n = 0; n < *size; n++){
		tmp[n].id = list[n].id;
		tmp[n].name = list[n].name;
		tmp[n].group = list[n].group;
		tmp[n].price = list[n].price;
		tmp[n].qty = list[n].qty;
	}
	
	//delete and remake list
	delete[] list;
	list = NULL;
	list = new Product[*size];
	
	//copy list back from tmp
	for (int n = 0; n < *size; n++){
		list[n].id = tmp[n].id;
		list[n].name = tmp[n].name;
		list[n].group = tmp[n].group;
		list[n].price = tmp[n].price;
		list[n].qty = tmp[n].qty;
	}
	
	//delete tmp list
	delete[] tmp;
	tmp = NULL;
	
//	cout << "Memory Reallocated";
}	

void reallocateMemory(Product * list, int *size, string *content){
	stringstream ss(*content);
	string word;
	
//	cout << "Size: " << *size << endl;
	
	//delete and remake list with new size
	delete[] list;
	list = NULL;
	list = new Product[*size];
	
	//copy list back from content, leaving one index for new product
	for (int n = 0; n < *size-1; n++){
		
		// stoi(word) converts string into int		
		ss >> word;
		list[n].id = stoi(word);
		
		ss >> word;
		list[n].name = word;
			
		ss >> word;
		list[n].group = word;
		
		// stof(word) : converts string into float
		ss >> word;
		list[n].price = stof(word);
		
		// stoi(word) converts string into int		
		ss >> word;
		list[n].qty = stoi(word);
	}	
}	

// updates the list stored in struct Product
void updateList(Product * list, int *size, string *content){
	stringstream ss(*content);
	string word;

	for (int n = 0; n < *size; n++){
		// stoi(word) converts string into int		
		ss >> word;
		list[n].id = stoi(word);

		ss >> word;
		list[n].name = word;
			
		ss >> word;
		list[n].group = word;
		
		// stof(word) : converts string into float
		ss >> word;
		list[n].price = stof(word);
		
		// stoi(word) converts string into int		
		ss >> word;
		list[n].qty = stoi(word);
	}
}

int main(){
	int x, y, z, idInput, tempIndex;
	string strInput;	
	int size = 1;
	string content;
	
	//Initialize ptr		
	Product * list = NULL;
	list = new Product[1];

	//cout << "Size: " << size << endl;

	//gets size of list, and the contents of the file (string)
	loadFileData(list, &size, &content);
	
	//remake (empty) list with more memory determined by size
	delete[] list;
	list = NULL;
	list = new Product[size];
	
	//initialize with content data
	updateList(list, &size, &content);
	
	//run menu
	do{
		renderMenu(list, &size);
		cin>>x;
	    switch(x){
	        case 1: //add new entry
	        {
	        	size++;
				reallocateMemory(list, &size, &content);
				addProduct(list, &size, &content);
				saveList(list, &size);
	            break;
	        }
	        case 2: //view list
	        {
			//cout << "\nCurrent Inventory:\n" << list << "\n";
				cout << "\n\n---------------- CURRENT INVENTORY ------------------\n";
				printList(list, &size);
				cout << "-----------------------------------------------------\n\n";
				break;
	        }
	        case 3: //edit entry
	        {
	        	cout<<"\nEnter the Product ID\n";
	        	cin>>idInput;
	        	do{
	        		for (int n=0; n<size; n++){
	        			if (list[n].id == idInput){
							cout << "\n\n" << list[n].id << "\t" << list[n].name << "\t" << list[n].group << "\t" << list[n].price << " (USD)\t" << list[n].qty;
							tempIndex = n;							
							n = size;
						};
					};
	        		
		        	cout<<"\n\nHow will you edit this product? \n1) Edit\n2) Remove\n3) Go Back\n";
		        	cin>>x;
		        	switch(x){
		        		case 1:
		        			cout << "Which will you edit?\n1)Name\n2)Group\n3)Price\n4)Qty\n";
		        				cin>>y;
								switch(y){
		        					case 1:
		        						cout << "Please enter the new Name:\n";
		        						cin>>strInput;
		        						list[tempIndex].name = strInput;
		        						saveList(list, &size);
		        						break;
		        					case 2:
		        						cout << "Please enter the new Group:\n";
		        						cin>>strInput;
		        						list[tempIndex].group = strInput;
		        						saveList(list, &size);		        						
										break;
		        					case 3:
		        						cout << "Please enter the new Price:\n";
		        						cin>>z;
		        						list[tempIndex].price = z;
		        						saveList(list, &size);
		        						break;
		        					case 4:
		        						cout << "Please enter the new Quantity:\n";
		        						cin>>z;
		        						list[tempIndex].qty = z;
		        						saveList(list, &size);
										break;
								}
		        			break;
		        		case 2:
		        			cout << "--- Future Implementation ---";
		        			break;
		        		case 3:
		        			break;
		        		default:
							cout << "ERROR: Please choose from options 1, 2, 3, or 4. Try again\n\n";
		        			break;
					}
				}while((x < 1)||(x > 3));
	        	x = 0;
	            break;
	        }
	        case 4:
	        	cout << "How would you like to search?\n1) By Name\n2) By Id\n3) Go Back\n";
	        	cin >> y;
	        	switch(y){
	        		case 1:
	        			cout << "\nPlease enter the name of your Product:\n";
	        			cin >> strInput;
	        			for (int n = 0; n < size; n++){
	        				if(list[n].name == strInput){
								cout << "\nID:\t\t" <<list[n].id << endl
									<< "NAME:\t\t" <<list[n].name << endl
									<< "GROUP:\t\t" <<list[n].group << endl
									<< "PRICE:\t\t" <<list[n].price << endl
									<< "QUANTITY:\t" <<list[n].qty << endl << endl;							
							}
						}
	        			break;
	        		case 2:
	        			cout << "\nPlease enter the Id of your Product\n";
	        			cin >> idInput;
	        			for (int n = 0; n < size; n++){
	        				if(list[n].id == idInput){
								cout << "\nID:\t\t" <<list[n].id << endl
									<< "NAME:\t\t" <<list[n].name << endl
									<< "GROUP:\t\t" <<list[n].group << endl
									<< "PRICE:\t\t" <<list[n].price << endl
									<< "QUANTITY:\t" <<list[n].qty << endl << endl;							
							}
						}
	        			break;
	        		case 3: 
	        			break;
					default:
						cout << "ERROR: Please choose from options 1, 2, or 3 Try again\n\n";
						break;
				}
	        	break;
	        case 5:
	        {
	            cout<<"\nThank you!\n";
	      		break;
	        }
	        default:
	        {
	        	cout<<"ERROR: Please choose from options 1, 2, or 3. Try again\n\n";
	    	}
	    };
    }while(x != 5);
	
	//clear memory before exit
	cout << "Clearing Memory\n\n"; 
	delete[] list;
	list = NULL;
	
	cout << "Exiting Program\n";
	return 0;
}
