//structures header file
#include <string>
#include <iostream>

//note: for some reason breaks when price is not int;
struct Product{
	int id;
	std::string name;
	std::string group;
	float price;
	int qty;
	void printProduct(){
		std::cout << "\n" << id << "\t\t" << name << "\t\t" << group << "\t\t" << price << " (USD)\t\t" << qty;
	}
};

struct FileData{
	int size = 0;
	std::string content;
};
