//Author: Ahmed Alkaabi
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
string line ="";
size_t position;
int colorValue;
string fileName="";
ifstream reader;

cout <<"Please enter the file to get color values from\n";
getline(cin, fileName);
reader.open(fileName, ios::in);

if(reader.is_open())
{
  
  while(!reader.eof())
  {
    getline(reader, line);
    position = line.find("#");

    if(line[position])
    {
      for (char colorValue = position +=1; colorValue++ ;)
      {
        cout << line[colorValue];
      }
    }
    cout << endl;
  }
}
  return 0;
}
