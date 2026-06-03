//Natnael Teklu
// This program is a simple simulation of cache memory using basic data structures in C++.
#include <fstream>
#include<string>
#include "LRUCache.h"
int main() {
	LRUCache lruCache(3);
	ifstream file;
	bool contFlag = true;


		//Using file.open(fName, ios::in) to open file
		file.open("C:\\test\\trace.txt", ios::in);
		//Use file.fail() to test if file opening failed
		if (file.fail()) {

			cout << "Error: Could not open file . Please try again." << endl;
			file.clear(); // Use file.clear() to clear error flags

		}
		else {
				contFlag = false;
				string address;
				while (getline(file, address)) {
					// convert address string to int
					int iAddress = stoi(address, nullptr, 16);
					lruCache.access(iAddress); 		// call access()
				}
				// print stats
				lruCache.printStats(); //call printstats
              }

	

}


