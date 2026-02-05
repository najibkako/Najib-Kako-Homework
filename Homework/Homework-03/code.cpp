// Hi Professor, you will see a LOT of notes in this code file. This is because I've been struggling to keep up so
// as im learning how to code im trying to be able to *EXPLAIN* how it works so it can stick in my brain. 

#include <iostream>
// This allows us to use inputs and outputs (stands for Input Output Stream)

#include <string>
// This allows us to use the strings (a line of characters)

#include <bitset>
// This allows us to use bitset, which is what we use to show binary values

#include <cstdint>
// This allows us to use fixed width integer types

#include <cstring>
// This allows us to use functions for manipulating C-style strings and arrays

using namespace std;
// This allows us to use the standard library without having to type "std::" before every command 



// THESE NOTES ARE ABOUT TO GET EXTREMELLLLLLY REPETITIVE AND CONVOLUTED
// Im sorry in advance, this is cuz im a dummy who needs to learn like a dummy to learn it correctly
// enjoy these dumb notes srry my brotha :C 

string intToBinary(int number) {
      return bitset<32>(number).to_string();
}

// This will turn text to 32 bit binary 
// intToBinary is the name of the function
// bitset<32> is so we can see it in 32 bits
// (number) is the input we are changing to binary
// .to_string() is so that the bitset turns into text

string floatToBinary(float number) {
      uint32_t bits;
      memcpy(&bits, &number, sizeof(number));
      return bitset<32>(bits).to_string();
}

// the function recieves one float
// uint32_t bits; is creating a box named bits that will hold a 32 bit unsigned integer
// memcpy is a command that copies data from one location to another
// bitset<32>(bits).to_string(); is turning the bits into 32 bit binary text
// return sends it back

int main() { 

// "int" is so we get a integer as our end product
// "main" is the starting point of the code
// () is to show its a function
// { is where the function starts and } is where it ends 

char letter; 

// Char letter; means create a box named letter that will hold one character
// the Char aspect is the one that can hold one character
// letter is simply the name of the box
// we put a semicolon at the end of each line because a semicolon in code is like a period

cout << "type a letter habibi: ";

// cout means "console output" so that in the terminal we get text outputted
// << is to send the text after INTO the command cout
// the text after is just the text we want outputted

cin >> letter;

// cin means "console input"  
// >> letter the next console input will be put into the box letter
// im beginning to realize how dumb these notes look to you lmao

// note that because we are using Char it will only do one character
// it will not do a string and as of now idk how to write code that is diff than that
// will learn as i go and learn how to do that

cout << "you inputted: " << letter << "\n";

//the cout is to output to terminal
// "you inputted: " is being outputted as text
// we put << "\n" so that the next output will be on a new line

cout << "ASCII value in 8 bits is: " 
     << bitset<8>(static_cast<unsigned char>(letter)) 
     << "\n";

// << "ASCII value in 8 bits is: " = outputting text in terminal

// << bitset<8>(static_cast<unsigned char>(letter)) Ill explain this very in depth in these next few notes
      // bitset          | bitset is a command that shows a number as binary (bitset = binary display machine)
      // <8>             | <8> is so we can see it in 8 bits (8 numbers) (because a char is 1 byte and 8 bits is a byte) 
      // ( )             | ( ) is so that anything within the parentheses gets turned into the bitset<8>
      // static_cast     | static_cast in plain terms is just how you tell C++ to change something from one type to another (in this case char to unsigned char) 
      // <unsigned char> | <unsigned char> is what we are changing it TO (changing letter from char to unsigned char) (this means the char will only be positive)
      // (letter)        | (letter) is what we are changing (the box named letter that holds the character inputted by user)

int number;
cout << "type an integer: ";
cin >> number;
cout << "you inputted: " << number << "\n";
cout << "binary value is: " << intToBinary(number) << "\n";

// same as above but number instead of letter

float f; 
cout << "type a float: ";
cin >> f; 
cout << "you inputted: " << f << "\n";
cout << "binary value is: " << floatToBinary(f) << "\n";

      
// same as above but its a float (2.5 , 3.14 , etc)

return 0;
// return 0; is to end the main function and return a value of 0 to the operating system

}



