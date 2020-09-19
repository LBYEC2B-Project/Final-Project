#include <iostream>
#include <fstream>

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
    };
};
class ProductInfo{
    private: 
    char name[20], classification[20];
    int quantity;
    float price;
    public:
    void productdetails(){
        cout<<"Product Details\n";
        cout<<"Classification: ";
        cin>>classification;
        cout<<"Name: ";
        cin>>name;
        cout<<"Price: ";
        cin>>price;
        cout<<"Quantity: ";
        cin>>quantity;
    };
};

class AddNewProducts{
    private: 
//code for adding products
    public: 
};

class ViewCurrentList{ 
    private: 
    
    public: 
//code for reading txt file
};

class EditList{
    private: 
// code for editing list
    public: 
};

int main(){
    int x, y;
    cout<<"|||Product Inventory System v1.0|||\n\n";
    BasicInfo info;
    Options:
    cout<<"\nProgram Functions";
    cout<<"\n1) Add Product(s)\n2) View Current Inventory Listing\n3) Edit Inventory Listing\n4) Exit Program\n\n";
    cout<<"Please Choose Function to be Executed: ";
    cin>>x;
    switch(x){
        case 1: //addnewproducts
        {
            break;
        }
        case 2: //viewlist
        {
            break;
        }
        case 3: //edit list
        {
            break;
        }
        case 4:
        {
            cout<<"\nThank you!\n";
            return 0;
        }
        default:
        {
        cout<<"ERROR: Please choose from options 1, 2, or 3. Try again\n\n";
        goto Options;
        };
    //code for writing to txt file, could be at main or in a class
    };
    goto Options;
    return 0;
};