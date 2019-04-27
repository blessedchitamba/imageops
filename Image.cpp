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
Image::Image(unique_ptr<u_char[]> image, int width, int height) : width(width), height(height) {
	data = move(image);
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

Image::iterator::iterator(u_char *p) : ptr(p) {}
Image::iterator::iterator( const iterator & rhs) : ptr(rhs.ptr) {}
iterator & operator=(const iterator & rhs) {
	if (this != rhs) {
		delete ptr;
		ptr = rhs.ptr;
	}
}

//Overloaded operators

//prefix ++
const Image::iterator& operator++ () {
	 ++ptr;
}

//prefix --
void Image::iterator::iterator operator--() {
	 --ptr;
}

//returns the pointer to the currently pointed image sub array
Image::iterator::iterator operator*() {
	return ptr;
}

//------------begin and end methods--------------
iterator Image::begin(void) {
	return iterator(data.get());	//data is a pointer to the first item in the image array
}

iterator Image::end(void) {
	//this should return a pointer to the end of the image array
	u_char *end_ptr = data.get()+(width*height);
	return iterator(end_ptr);
}
