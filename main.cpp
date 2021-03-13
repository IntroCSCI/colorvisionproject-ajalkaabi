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

	
    cout << "Please enter the name of the file that you want to get color values from:\n";
	 getline(cin, fileName); 
	reader.open(fileName, ios::in);
  
	if (reader.is_open()) {

   cout << endl;   
		while (!reader.eof()) {
			getline(reader, line);
			position = line.find("#");
      
			if (line[position]) {
        
       
				for (int colorValue = position+=1; (line[colorValue] >= '0' && line[colorValue] <= '9') || ((line[colorValue] >= 'A' && line[colorValue] <= 'F')) || (line[colorValue] >= 'a' && line[colorValue] <= 'f'); colorValue+=6) {
        
          
          string i = line.substr(position, 6);
          if(i.size()==6)
          {cout << '#' << i << endl;}
          else
          {break;}


				}
			}
		}
	}
	return 0;
}
