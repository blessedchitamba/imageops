//Image class to hold image data for assignment 4
//Blessed Chitamba
//April 2019

#include "Image.h"
#include <fstream>  // Needed for file stream objects
#include <iostream> // Needed for console stream objects
#include <sstream>  // Needed for string stream objects
#include <string>   // Needed for strings
#include <iterator>  //Needed for the iterator
#include <cstdlib>
#include <math.h>
#include <memory>
#include <vector>
#include <bitset>
#include <queue>

using namespace std;
using namespace chtble001;

//Constructor
Image::Image(unsigned char *image, int width, int height) : data(image), width(width), height(height) {
	cout << "Unique pointer created in constructor" << endl;
}

//Destructor
Image::~Image() {
	//do the deletion of the image array
}

//Copy constructor
Image::Image(const Image & rhs){
	//Implement using the iterator begin() and end()
}

//Copy Assignment
//Image& operator=(const Image & rhs){
	//Implement using the iterator begin() and end()
//}

//Move Constructor
Image::Image(Image && rhs) {
	//Implement using the iterator begin and end
}

//Move Assignment
//Image::Image& operator=(Image && rhs) {
	//Implement using the iterator begin and end methods
//}

//----------Iterator methods--------------

Image::iterator::iterator( const iterator & rhs) : ptr(rhs.ptr) {}

//Overloaded operators

//prefix ++
Image::iterator& chtble001::Image::iterator::operator++ () {
	 ++this->ptr;
	 return *this;
}

//prefix --
Image::iterator& chtble001::Image::iterator::operator--() {
	 --this->ptr;
	 return *this;
}

//returns the pointer to the currently pointed image sub array
unsigned char& Image::iterator::operator*() {
	return *(this->ptr);
}

//iterator begin and end methods to construct iterator object
Image::iterator Image::begin(void){
        return iterator(data.get());
 }
                                                                                                         
Image::iterator Image::end(void){
        //this should return a pointer to the end of the image array
        u_char *end_ptr = data.get()+(width*height)-1;
        return iterator(end_ptr);
}

//test method
void Image::testMeth() {
	//create a begin and end iterator and print out the values they point to
	Image::iterator beg = this->begin(), end = this->end();
	cout << "Value of beg is " << *beg << endl;
	cout << "Value of end is " << *end << endl;
}
