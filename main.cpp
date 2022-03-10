#include<bits/stdc++.h>
using namespace std;
class Pairs{
	string name;
	int price;
	public:
	 Pairs(string name,int price){
	 	this->name = name;
	 	this->price = price;
	 }
	 int getPrice(){
	 	return price;
	 }
	 string getName(int price){
	 	return name;
	 }
	 int getPrice(string name){
	 	return price;
	 }
};
int main(){
	int k = 0;
	ifstream inFile;
	//opening the input txt file
	inFile.open("sample_input.txt");
	// this condition is used to handle when we type wrong filename or in-case 0f any corrupted files
	if(inFile.fail()){
		cerr << "Error Opening The File" << endl;
		exit(1);
	}
	string emps;
	int count = 0;
	while(count!=5){ // checking for the no.of employees 
		inFile >> emps;
		count++; // as the sentence in the input has 5 words we will increment upto 5 and take the number
	} 
	string no_of_emps = emps;
	for(int i=0;i<no_of_emps.size();i++){ // in case our number is greater than 9 we need this loop to convert string to int
		k = (k*10) + (int)(no_of_emps[i] - '0');
	}
	string temp;
	count = 0;
	while(count!=4){
		inFile >> temp;
		count++;
	}
	string goods;
	string str = "";
	int num = 0;
	vector<int> nums;
	vector<Pairs> storage;
	while(!inFile.eof()){ // using .eof() and running loop until the end of input file
		inFile >> goods; // taking each and every element into the input file object
		if(goods[0]>=48 && goods[0]<=57){
			// as we have numbers that are the prices of goods we need to
			// typecast them the ascii range of numbers is 48-57
			for(int i=0;i<goods.size();i++){
				 num = (num*10) + (int)(goods[i]-'0');
			}
			nums.push_back(num);
			Pairs p(str,num); // making pair of name,price using my own class
			storage.push_back(p); // storing every value in a vector
			str = ""; // making str empty again to store the second input
			num = 0; // likewise making num = 0 
		}
		else{
			str = str + goods; // storing the non-numeric data i.e. name of given goods
		}
	}
	int ele,it;
	// using insertion sort to sort all the elements in ascending order
    for(int i=1;i<nums.size();i++){
    	ele = nums[i];
    	it = i - 1;
    	while(it>=0 && nums[it]>ele){
    		nums[it+1] = nums[it];
    		it = it -1;
		}
		nums[it + 1] = ele;
	}
	int min = INT_MAX,start = 0,end = 0;
	// as the elements required will like in the range of i - i+k-1 
	// we will consider the partions of the array and take the min difference
	for(int i=0;i+k-1<nums.size();i++){
		int diff = nums[i+k-1] - nums[i];
	    if(diff < min){
	    	min = diff;
	    	start = i;
	    	end = i + k - 1;
		}
	}
	ofstream outFile;
	outFile.open("sample_output.txt");
	outFile << "The goodies selected for distribution are:" << endl;
	for(int i=start;i<=end;i++){
		for(int j=0;j<storage.size();j++){
			if(storage[j].getPrice() == nums[i]){
				outFile << storage[j].getName(nums[i]) << " " << nums[i];
				break;
			}
		}
		outFile << endl;
	}
	outFile << "And the difference between the chosen goodle with highest price and the lowest price is " << min;
	return 0;
}
