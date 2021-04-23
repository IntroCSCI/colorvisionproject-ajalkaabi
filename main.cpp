// Author: Ahmed Alkaabi
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Class declaration of color
class Color {
    public:
        unsigned char r, g, b;
        Color(string colorStr);
        ~Color();
        bool operator == (const Color& color);
        string toString();  
    private:
        string str;
};

// Class definition of colors
Color::Color(string colorStr) {
    this->str = colorStr;

    if (this->str.length() < 6) { // check if three digit
        string cs;
        cs += this->str[0];
        cs += this->str[0];
        cs += this->str[1];
        cs += this->str[1];
        cs += this->str[2];
        cs += this->str[2];
        this->str = cs;
    }

    this->r = (unsigned char)stoi(this->str.substr(0, 2), nullptr, 16);
    this->g = (unsigned char)stoi(this->str.substr(2, 2), nullptr, 16);
    this->b = (unsigned char)stoi(this->str.substr(4, 2), nullptr, 16);

    this->str = this->str.substr(0, 6);
}

Color::~Color() {}

bool Color::operator == (const Color& color) {
    return this->r == color.r && this->g == color.g && this->b == color.b;
}

string Color::toString() {
    return this->str;
}

bool appendUnique(vector<Color>& table, Color* c) {
    int count = 0;

    for (size_t i = 0; i < table.size(); i++) {
        if (*c == table[i]) {
            count++;
            break; 
        }
    }

    if (!count) {
        table.push_back(*c);
        return true;
    } else {
        return false;
    }
}

const char* colorNames[] = {
    "black",
    "silver",
    "gray",
    "white",
    "maroon",
    "red",
    "purple",
    "fuchsia",
    "green",
    "lime",
    "olive",
    "yellow",
    "navy",
    "blue",
    "teal",
    "aqua"
};

const char* colorValues[] = {
    "000000",
    "C0C0C0",
    "808080",
    "FFFFFF",
    "800000",
    "FF0000",
    "800080",
    "FF00FF",
    "008000",
    "00FF00",
    "808000",
    "FFFF00",
    "000080",
    "0000FF",
    "008080",
    "00FFFF"
};

int main() {

    string fileName;
    ifstream file;

    // Repeatedly ask the user for a file until it opens sucessfully
    do {
        cout << "Please enter file name to analyze: ";
        getline(cin, fileName);

        file.open(fileName, ifstream::in);

    } while (!file.is_open());


    // Read the colors in the file
    string color;
    vector<Color> colorTable;

    cout << endl << "The colors in the palette are: " << endl;

    char ch;
    string keyword;
    Color* c;

    while ((ch = file.get()) != EOF) {
        if (ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t') { // end of word
            if (keyword.length() > 0) {
                if (keyword[0] == '#') { // This is a color hex  
                    try {
                        c = new Color(keyword.substr(1));
                        if (!appendUnique(colorTable, c)) {
                            delete c;
                        } else 
                            cout << c->toString() << endl;
                    } catch(const invalid_argument& ia) {}
                } else { // check color names
                    for (int i = 0; i < 16; i++) {
                        if (keyword == colorNames[i]) {
                            try {
                                c = new Color(colorValues[i]);
                                if (!appendUnique(colorTable, c)) {
                                    delete c;
                                } else
                                    cout << c->toString() << endl;
                            } catch(const invalid_argument& ia) {}
                            break; // stop the loop once found
                        }
                    }
                }

                keyword = "";
            }
        } else {
            keyword += ch;
        }
    }

    cout << endl << "Analysis:" << endl;
    cout << "There are " << colorTable.size() << " unique colors." << endl;
    
    return 0;
}