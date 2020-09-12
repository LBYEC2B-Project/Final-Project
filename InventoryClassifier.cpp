#include <iostream>

using namespace std;

class BasicInfo{
    private:
    char name[20], company[20];
    public:
    BasicInfo(){
        cout<<"Please Enter Basic Information\n";
        cout<<"Name of User: ";
        cin>>name;
        cout<<"Company Name: ";
        cin>>company;
    };
};

class AddNewProducts{
    private: 
    char name[20], classification[20];
    int quantity, price;
    public: 

};

class ViewCurrentList{

};

class EditList{

};

int main(){
    int x, y;
    cout<<"|||Product Inventory System v1.0|||\n\n";
    BasicInfo info1;
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
    };
    Options2:
    cout<<"Would you like to return to the menu?\n";
    cout<<"1) Yes\n2) No\n";
    cout<<"Input Option: ";
    cin>>x;
    switch(y){
        case 1:
        {
            goto Options;
            break;
        }
        case 2:
        {
            cout<<"\nThank you!\n";
            return 0;
        }
        default:
        {
        cout<<"ERROR: Please choose from options 1 or 2. Try again\n\n";
        goto Options2;
        };
    };
    return 0;
};

