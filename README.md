# Anti-Colorblind

## Description

My program asks for a file name, reads the file, and prints out all the six characters color values that are there in the file. The color values are represented in hex format. Then the program prints out how many unique colors are in the file.

### v0.2 Updates

The program can now print out how many unique color are in the file. I also fixed a bug from the previous version of the program, which was sometimes the program prints out some values that are not color values.

### v1.0 Updates

*Coming soon*


## Developer

Ahmed Alkaabi

## Example

To run the program, give the following commands:

```
Enter the file name that you want to analyze.
```

Here is an example of the program running:

```
Please enter file name to analyze: test2.css

The colors in the palette are: 
00bfff
ffffff

Analysis:
There are 2 unique colors.
```

## C++ Guide

### Variables and Data Types

I used multiple strings such as (filaName), which stores the name of the file the user inputs. And (line) which stores each line with a color value in it after opening the file. I used one char variable which is (colorValue), and this variable stores each hex character. I aslo used one int (colorValues), and it's used to represent the position of color values' charcacters. Finally, I used (reader) from ifstream, which represents the variable that reads the opened files.

### Console Input and Output

I used multiple console outputs. The first is to ask the user for the name of the file they want to open. The second one is to create a space (endl) between the user's input and the output of the program. And the third one to print out the color values that are found in the file. I also used two console inputs, the first one to store the file name. And the second one to store each line in the opened filewith a color value.

### Decisions

I used two decisions in my program, and both of them are from the same type (if). The point of the first (if) decision in my program is to check if the entered file name exists and can be opened, and if it's true it proceeds, if not, the program breaks. The second (if) decision in my program is used to check if the hash # sign exists, and proceeds if it's true, if not, it does not do anything.

### Iteration

I have two examples of iteration in my program. The first one is (while loop), and this loop helps printing out the color values as long as the program didn't reach the end of the opened file, and that's because of the condition of this (while loop) which is (!reader.eof). The second example of iteration in my program is the (for loop), and it's useful for me because it made the program read print out only the characters that are within the hexadecimal range.

### File Input and Output

I used file input, to open the file and read from it only, without editing it. File Input helped read the file and get me to my goal, which is reading the color values from the opened file.

### Arrays/Vectors

I used vectors to store the colors read from the file. I used arrays to list the common color names used in css and their corresponding color values in hex.

### Functions

I used a function to check if a color is existing in the color table and include that color if it is not in the color table. (A) It created a unique function to hanlde the insertion of new colors in the table.
(B) The parameters passed by objection reference is the color table vector and passed by pointer is the color. With passing by reference, you can modify the object/class from the function itself. It is also much faster since the computer doesnt have to duplicate the object.
(C) This function returns a bool type to signify that the new color is unique.

### Classes

I created the Color class to store information of the color and implement methods to do conversion from string to Color, conversion from Color to string, and defining of equal operator to see if two colors are equal.