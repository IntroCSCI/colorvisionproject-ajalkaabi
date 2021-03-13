# !!!Replace with your unique project name!!!

## Description

My program asks for a file name, reads the file, and prints out  all the color values that are there in the file. The color values are represented in hex format.

### v0.2 Updates

*Coming soon*

### v1.0 Updates

*Coming soon*


## Developer

Ahmed Alkaabi

## Example

To run the program, give the following commands:

```
g++ --std=c++11 *.cpp -o cvp
./cvp
enter the name of the file that you want to get color values from.
```

Here is an example of the program running:

```
Please enter the name of the file to be opened:
purple.css
#785EF0
#DC267F
#FE6100
#FFB000
#FF0
```

## C++ Guide

### Variables and Data Types

I used multiple strings such as (filaName), which stores the name of the file the user inputs. And (line) which stores each line with a color value in it after opening the file. I used one char variable which is (colorValue), and this variable stores each hex character. Finally, I used (reader) from ifstream, which represents the variable that reads the opened files.

### Console Input and Output



### Decisions

I used two decisions in my program, and both of them are from the same type (if). The point of the first (if) decision in my program is to check if the entered file name exists and can be opened, and if it's true it proceeds, if not, the program breaks. The second (if) decision in my program is used to check if the hash # sign exists, and proceeds if it's true, if not, it does not do anything.

### Iteration

I have two examples of iteration in my program. The first one is (while loop), and this loop helps printing out the color values as long as the program didn't reach the end of the opened file, and that's because of the condition of this (while loop) which is (!reader.eof). The second example of iteration in my program is the (for loop), and it's useful for me because it made the program read print out only the characters that are within the hexadecimal range.

### File Input and Output

I used file input, to open the file and read from it only, without editing it. File Input helped read the file and get me to my goal, which is reading the color values from the opened file.

### Arrays/Vectors

*Coming in version 0.2*

### Functions

*Coming in version 0.2*

### Classes

*Coming in version 1.0*
