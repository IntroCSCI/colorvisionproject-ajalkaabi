// Author: Ahmed Alkaabi
#include <fstream>
#include <iostream>
using namespace std;

int main() {
	string line = "";
	size_t position;
  string fileName;
	ifstream reader;
  string color;

	
    cout << "Please name the file to be opened:\n";
	 getline(cin, fileName); 
	reader.open(fileName, ios::in);
  
	if (reader.is_open()) {

    
		while (!reader.eof()) {
			getline(reader, line);
			position = line.find("#");

			if (line[position]) {
        cout << '#';
				for (char colorValue = position += 1; (line[colorValue] >= '0' && line[colorValue] <= '9') || (line[colorValue] >= 'A' && line[colorValue] <= 'F'); colorValue++) {
          
          
					cout << line[colorValue];
				}
        
			}
			cout << endl;
		}
	}
	return 0;
}
