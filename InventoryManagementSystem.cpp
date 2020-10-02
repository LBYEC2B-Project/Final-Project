/* Notes:
Obscure Bugs:
	1:addProduct works, but for some crashes when ran twice in one session. on opening the program again, addProduct will work again until ran a second time.
		-narrowed down the problem to be in either reallocateMemory() or addProduct()
		-if in reallocate Memory you change "*size-1" to "*size-2", you can run addProduct twice before crash, but
		one of the proucts loses its name and group.
		-*size-2 seems correct, but the associated data deletion bug is a worse result, therefore *size-1 is kept until a fix is made.
	

	2:The list can be any size if provided a manually editted text file and everything will run (except addProduct() will error as described above),
	but if addProduct() is used add an entry the program will error when trying
	to add a Product after the list is _x_ entries long (_x_ is different on each computer we test this on, most commonly _x_ == 7).

Future Considerations:
-forgot to add error handling to handle wrong type inputs, but it would be an improvement to add in the future/given more time.
**/
#include "InventoryManagementSystem.h"
#include <sstream>
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
using namespace std;

//saves list to txt file "inventory.txt"
void saveList(Product * list, int *size, string filename){
	ofstream file(filename);
	
	//format of the txt file (every , is important)
	for (int n=0; n<*size; n++){
		//adds data to file
		file << list[n].id << ","<< list[n].name << "," << list[n].group << "," << list[n].price << "," << list[n].qty << ",\n";
	};
}

void addProduct(Product * list, int *size, string *content){
	string input;
	string pName, pGroup;
	int pPrice, pQty;
	
   	list[*size-1].id = *size;
   	*content += (*size + ",");
   	
   	//removes leading whitespace that breaks getline(cin, ___)
	cin.get();

	cout << "Enter the Name of the Product: ";
	getline(cin, input);
	list[*size-1].name = input;
	*content += (input + ",");
	
	cout << "Enter the Group of the Product: ";
	getline(cin, input);
   	list[*size-1].group = input;
	*content += (input+ ",");
	
	cout << "Enter the Price of the Product: ";
	getline(cin, input);
   	list[*size-1].price = stof(input);
	*content += (input + ",");

   	cout << "Enter the Quantity of the Product: ";
	getline(cin, input);
   	list[*size-1].qty = stoi(input);
	*content += (input + ",\n");
}

void printList(Product *list, int *size){
	for (int n = 0; n < *size; n++){
		cout << "ID:\t\t" <<list[n].id << "\n"
			<< "NAME:\t\t" <<list[n].name << "\n"
			<< "GROUP:\t\t" <<list[n].group << "\n"
			<< "PRICE:\t\t" <<list[n].price << "\n"
			<< "QUANTITY:\t" <<list[n].qty << "\n\n";
	}
}

void renderMenu(Product * list, int *size){
	int counter = 0;
	int total = 0;
	cout<<"\n|||Product Inventory System v1.0|||\n";
	if(*size== 0)
	{
		cout << "\nYour List is Empty!\n";
	}
	else
	{
		cout << "\nThe list currently contains:\n\n\t" << *size << " individual item(s)\n";
		
		for (int n = 0; n<*size; n++){
			total += list[n].qty;
		}
		
		cout << "\t" << total << " total units\n";
				
		for (int n = 0; n<*size; n++){
			if (list[n].qty <= 0){
				counter++;
			}
		}
		
		if (counter > 0){
			cout << "\n\t" << counter << " of these items " << "are currently out of stock.\n";
		}
		else
		{
			cout << "\n\tAll " << *size << " items are currently in stock.\n";
		}
	}
	cout<<"\nProgram Functions";
	cout<<"\n1) Add Product(s)\n2) View Current Inventory Listing\n3) View Out of Stock Items\n4) Edit Inventory Listing\n5) Search for a Product\n6) Exit Program\n\n";
	cout<<"Please Choose Function to be Executed: ";
};

// creates new list
void createFile(string filename){
		ofstream file(filename);
		
		cout << "No List Available. Creating New List. . .\n\n";
		//prints blank file
		file << "";
		
		//test values
		file << "1,Brandless Phone,Electronics,50,0,\n"
			<< "2,Brandless TV,Electronics,100,74,\n"
			<< "3,Abstract Painting,Home Decor,200,0,\n";
		
		cout << "Done!\n\n";
}

 void loadFileData(Product *list, int *size, string *content, string filename) {
	fstream file;
	string line;
	int count;
	
    file.open(filename);
    
    if (!file.is_open()){
		createFile(filename);
		file.open(filename);
	}
	
   	while ( getline (file, line) )
   	{
   		*content += line;
   		count++;
   	}
	file.close();
	*size = count;
}


//(Unused function) resizes the Product * list array
/*
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
*/

// remakes Product * list array with new size
void reallocateMemory(Product * list, int *size, string *content){
	stringstream ss(*content);
	string word;
		
	//delete and remake list with new size
	delete[] list;
	list = NULL;
	list = new Product[*size];
	
	//copy list back from content, leaving one index for new product
	for (int n = 0; n < *size-1	; n++){

		// stoi(word) converts string into int		
		getline(ss, word, ',');
		list[n].id = stoi(word);
		
		getline(ss, word, ',');
		list[n].name = word;

		getline(ss, word, ',');
		list[n].group = word;
		
		// stof(word) : converts string into float
		getline(ss, word, ',');
		list[n].price = stof(word);

		// stoi(word) converts string into int		
		getline(ss, word, ',');
		list[n].qty = stoi(word);
	}
}	

// updates the list stored in struct Product
void updateList(Product * list, int *size, string *content){
	stringstream ss(*content);
	string word;

	for (int n = 0; n<*size; n++){
		// stoi(word) converts string into int		
		getline(ss, word, ',');
		list[n].id = stoi(word);
		
		getline(ss, word, ',');
		list[n].name = word;

		getline(ss, word, ',');
		list[n].group = word;
		
		// stof(word) : converts string into float
		getline(ss, word, ',');
		list[n].price = stof(word);

		// stoi(word) converts string into int		
		getline(ss, word, ',');
		list[n].qty = stoi(word);
	}	
}

int main(){
	string filename = "inventory.txt";
	int x, y, z, idInput;
	int tempIndex = 0;
	string strInput;	
	int size = 1;
	string content;
	
	//Initialize ptr		
	Product * list = NULL;
	list = new Product[1];

	//gets size of list, and the contents of the file (string)
	loadFileData(list, &size, &content, filename);
	
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
	           	size++;  	
				reallocateMemory(list, &size, &content);
	       		addProduct(list, &size, &content);
				saveList(list, &size, filename);
	            break;
	        
	        case 2: //view list
	        
			//cout << "\nCurrent Inventory:\n" << list << "\n";
				cout << "\n\n---------------- CURRENT INVENTORY ------------------\n";
				printList(list, &size);
				cout << "-----------------------------------------------------\n\n";
				system("PAUSE");
				break;
	        
	        case 3: //view out of stock
				cout << "The following items are Out of Stock:\n\n";
				for (int n = 0; n < size; n++){
					if (list[n].qty == 0){
					cout << "ID:\t\t" <<list[n].id << "\n"
					<< "NAME:\t\t" <<list[n].name << "\n"
					<< "GROUP:\t\t" <<list[n].group << "\n"
					<< "PRICE:\t\t" <<list[n].price << "\n"
					<< "QUANTITY:\t" <<list[n].qty << "\n\n";
					}	
				}
				system("PAUSE");
	        	break;

	        case 4: //edit entry
	        	cout<<"\nEnter the Product ID\n";
	        	cin>>idInput;
	        	do{
	        		for (int n=0; n<size; n++){
	        			if (list[n].id == idInput){
							cout << "\nID:\t\t" <<list[n].id << "\n"
								<< "NAME:\t\t" <<list[n].name << "\n"
								<< "GROUP:\t\t" <<list[n].group << "\n"
								<< "PRICE:\t\t" <<list[n].price << "\n"
								<< "QUANTITY:\t" <<list[n].qty << "\n";
							tempIndex = n;							
							n = size;
						};
					};
					if (tempIndex == 0){
						cout << "\n There is no product of ID #" << idInput << "\n\n";
						x = 2;
						system("PAUSE");
						break;
					} else {
	        			cout<<"\n\nIs this the correct product? \n1) Edit\n2) Go Back\n";
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
		        						saveList(list, &size, filename);
		        						break;
		        					case 2:
		        						cout << "Please enter the new Group:\n";
		        						cin>>strInput;
		        						list[tempIndex].group = strInput;
		        						saveList(list, &size, filename);		        						
										break;
		        					case 3:
		        						cout << "Please enter the new Price:\n";
		        						cin>>z;
		        						list[tempIndex].price = z;
		        						saveList(list, &size, filename);
		        						break;
		        					case 4:
		        						cout << "Please enter the new Quantity:\n";
		        						cin>>z;
		        						list[tempIndex].qty = z;
		        						saveList(list, &size, filename);
										break;
								}
								tempIndex = 0;
		        				break;
		        			case 2:
		        				break;
		        			default:
								cout << "ERROR: Please choose from options 1, or 2. Try again\n\n";
		        				break;
						}	
					}
				}while((x < 1)||(x > 2));
	        	x = 0;
	            break;
	        
	        case 5:
	        	cout << "How would you like to search?\n1) View by Name\n2) View by ID\n3) Go Back\n";
	        	cin >> y;
	        	switch(y){
	        		case 1:
	        			cout << "\nPlease enter the name of your Product: (Case Sensitive)\n";
	        			cin >> strInput;
	        			for (int n = 0; n < size; n++){
	        				if(list[n].name == strInput){
								cout << "\nID:\t\t" <<list[n].id << "\n"
									<< "NAME:\t\t" <<list[n].name << "\n"
									<< "GROUP:\t\t" <<list[n].group << "\n"
									<< "PRICE:\t\t" <<list[n].price << "\n"
									<< "QUANTITY:\t" <<list[n].qty << "\n\n";
								tempIndex  = n;							
							}
						}
						if (tempIndex == 0){
							cout << "\n There is no product named " << strInput << "\n";
						}
						tempIndex = 0;
	        			break;
	        		case 2:
	        			cout << "\nPlease enter the id of your Product\n";
	        			cin >> idInput;
	        			for (int n = 0; n < size; n++){
	        				if(list[n].id == idInput){
								cout << "\nID:\t\t" <<list[n].id << "\n"
									<< "NAME:\t\t" <<list[n].name << "\n"
									<< "GROUP:\t\t" <<list[n].group << "\n"
									<< "PRICE:\t\t" <<list[n].price << "\n"
									<< "QUANTITY:\t" <<list[n].qty << "\n\n";							
							}
						}
	        			break;
	        		case 3: 
	        			break;
					default:
						cout << "ERROR: Please choose from options 1, 2, or 3 Try again\n\n";
						break;
				}
				system("PAUSE");
	        	break;
	        case 6:
	            cout<<"\nThank you!\n\n";
	      		break;
	        
	        default:
	        	cout<<"\n\n\n\n\n\n\n\n\n\nERROR: Please choose from options 1-6. Try again\n\n";
	        	break;
	    };
    }while(x != 6);
	
	//clear memory before exit
	cout << "Clearing Memory...\n\n"; 
	delete[] list;
	list = NULL;
	cout << "Done.\n\n";
	
	cout << "Exiting Program\n";
	return 0;
}
