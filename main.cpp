// Author: Ahmed Alkaabi
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

const double Normal[3][3] = { { 1.00, 0, 0 }, { 0, 1.00, 0 }, { 0, 1.00, 0 } };
const double Protanopia[3][3] = { { 0.56667, 0.43333, 0 }, { 0.55833, 0.44167, 0 }, { 0, 0.24167, 0.75833 } };
const double Protanomaly[3][3] = { { 0.81667, 0.18333, 0}, { 0.33333, 0.66667, 0 }, { 0, 0.125, 0.875 } };
const double Deuteranopia[3][3] = { { 0.625, 0.375, 0 }, { 0.70, 0.30, 0 }, { 0, 0.30, 0.70 } };
const double Deuteranomaly[3][3] = { { 0.80, 0.20, 0 }, { 0.25833, 0.74167, 0 }, { 0, 0.14167, 0.85833 } };
const double Tritanopia[3][3]  = { { 0.95, 5, 0 }, { 0, 0.43333, 0.56667 }, { 0, 0.475, 0.525 } };
const double Tritanomaly[3][3] = { { 0.96667, 0.03333, 0 }, { 0, 0.73333, 0.26667 }, { 0, 0.18333, 0.81667 } };
const double Achromatopsia[3][3] = { { 0.299, 0.587, 0.114 }, { 0.299, 0.587, 0.114 }, { 0.299, 0.587, 0.114 } };
const double Achromatomaly[3][3] { { 0.618, 0.32, 0.062 }, { 0.163, 0.775, 0.062 }, { 0.163, 0.320, 0.516 } };

using namespace std;

#define COMMON  5
#define TEST(a,b) printf("%-13s   ", b); if (paletteTest(common, a)) printf("%-13s\n", "Passed"); else printf("%-13s\n", "Failed")

class Color {
    public:
        unsigned char r, g, b;
        Color();
        Color(string colorStr);
        Color(const Color& obj);
        ~Color();
        bool operator == (const Color& color) const;
        bool operator < (const Color& color) const;
        string toString() const;  
        int hex() const;  
        Color filter(const double filt[3][3]) const;
};

typedef vector<Color> COLORTABLE;
typedef vector<int> COLORCOUNT;

Color::Color(string colorStr) {
    string str = colorStr;

    if (str.length() < 6) { 
        string cs;
        cs += str[0];
        cs += str[0];
        cs += str[1];
        cs += str[1];
        cs += str[2];
        cs += str[2];
        str = cs;
    }

    r = (unsigned char)stoi(str.substr(0, 2), nullptr, 16);
    g = (unsigned char)stoi(str.substr(2, 2), nullptr, 16);
    b = (unsigned char)stoi(str.substr(4, 2), nullptr, 16);
}

Color::Color() : r(0), g(0), b(0) {
}

Color::Color(const Color& obj) : r(obj.r), g(obj.g), b(obj.b) {
}

Color::~Color() {}

int Color::hex() const {
    return ((int)r << 16) | ((int)g << 8) | ((int)b);
}

bool Color::operator == (const Color& color) const {
    return hex() == color.hex();
}

bool Color::operator < (const Color& color) const {
    return hex() < color.hex();
}

string Color::toString() const {
    char str[256];
    sprintf(str, "%02X%02X%02x", (int)r, (int)g, (int)b);
    return string(str);
}

Color Color::filter(const double filt[3][3]) const {
    double rf, gf, bf;
    rf = filt[0][0] * r + filt[0][1] * g + filt[0][2] * b;
    gf = filt[1][0] * r + filt[1][1] * g + filt[1][2] * b;
    bf = filt[2][0] * r + filt[2][1] * g + filt[2][2] * b;
    
    Color filtered;
    filtered.r = rf;
    filtered.g = gf;
    filtered.b = bf;

    return filtered;
}

bool appendColor(COLORTABLE& table, COLORCOUNT& count, Color& c) {
    for (size_t i = 0; i < table.size(); i++) {
        if (table[i] == c) {
            count[i]++;
            return true;
        }
    }

    table.push_back(c);
    count.push_back(1);

    return false;
}

bool paletteTest(Color palette[COMMON], const double filter[3][3]) {
    for (int i = 0; i < COMMON; i++) {
        for (int j = i + 1; j < COMMON; j++) {
            if (palette[i].filter(filter) == palette[j].filter(filter)) {
                return false;
            }
        }
    }
    return true;
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

    do {
        cout << "Please enter file name to analyze: ";
        getline(cin, fileName);

        file.open(fileName, ifstream::in);

    } while (!file.is_open());

    string color;
    COLORTABLE colorTable; 
    COLORCOUNT colorCnt;

    cout << endl << "The colors in the palette are" << endl;
    cout << "  HEX   USAGE" << endl;

    char ch;
    string keyword;
    Color c;

    while ((ch = file.get()) != EOF) {
        if (ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t') { 
            if (keyword.length() > 0) {
                if (keyword[0] == '#') {  
                    try {
                        c = Color(keyword.substr(1));
                        appendColor(colorTable, colorCnt, c);
                    } catch(const invalid_argument& ia) {}
                } else {
                    for (int i = 0; i < 16; i++) {
                        if (keyword == colorNames[i]) {
                            try {
                                c = Color(colorValues[i]);
                                appendColor(colorTable, colorCnt, c);
                            } catch(const invalid_argument& ia) {}
                            break;
                        }
                    }
                }
                keyword = "";
            }
        } else {
            keyword += ch;
        }
    }

    Color common[COMMON];
    int usage[COMMON] = {0};

    for (size_t i = 0; i < colorTable.size(); i++) {
        cout << colorTable[i].toString() << " " << colorCnt[i] << endl;

        if (colorTable[i].hex() == 0x000000 || colorTable[i].hex() == 0xFFFFFF) 
            continue;

        for (auto i = 0; i < COMMON; i++) {
            if (colorCnt[i] > usage[i]) { 
                usage[i] = colorCnt[i];
                common[i] = colorTable[i];
                break;
            }
        }
    }    

    cout << endl << "Analysis:" << endl;
    cout << "There are " << colorTable.size() << " unique colors." << endl;

    cout << endl << "Commonly Used Colors:" << endl;
    cout << "  HEX   USAGE" << endl;
    for (size_t i = 0; i < COMMON; i++) {
        cout << common[i].toString() << "   " << usage[i] << endl;
    }

    cout << endl << "Color Blindness Test:" << endl;
    cout << "   CONDITION    RESULT" << endl;
    TEST(Protanopia, "Protanopia");
    TEST(Protanomaly, "Protanomaly");
    TEST(Deuteranopia, "Deuteranopia");
    TEST(Deuteranomaly, "Deuteranomaly");
    TEST(Tritanopia, "Tritanopia");
    TEST(Tritanomaly, "Tritanomaly");
    TEST(Achromatopsia, "Achromatopsia");
    TEST(Achromatomaly, "Achromatomaly");

    return 0;
}