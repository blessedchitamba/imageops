//Image class to hold image data for assignment 4
//Blessed Chitamba
//April 2016

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
Image::Image(*u_char[][] image, int width, int height) : width(width), height(height) {
	shared_ptr<u_char[][]> image(image);
}

//Destructor
Image::~Image() {
	//do the deletion of the image 2D matrix
}

//Copy constructor
Image::Image(const Image & rhs){
	//Implement using the iterator begin() and end()
}

//Copy Assignment
Image::Image & operator=(const Image & rhs){
	//Implement using the iterator begin() and end()
}

//Move Constructor
Image::Image(Image && rhs) {
	//Implement using the iterator begin and end
}

//Move Assignment
Image::Image & operator=(Image && rhs) {
	//Implement using the iterator begin and end methods
}

//----------Iterator methods--------------

Image::iterator::iterator(u_char[] *p) : ptr(p) {}
Image::iterator::iterator( const iterator & rhs) : ptr(rhs.ptr) {}
Image::iterator::iterator & operator=(const iterator & rhs) {
	if (this != rhs) {
		delete[] ptr;
		ptr = rhs.ptr;
	}
}

//Overloaded operators

//prefix ++
Image::iterator::iterator operator++ () {
	return ++ptr;
}

//prefix --
Image::iterator::iterator operator--() {
	return --ptr;
}

//returns the pointer to the currently pointed image sub array
Image::iterator::iterator operator*() {
	return ptr;
}

//------------begin and end methods--------------
Image::begin(void) {
	u_char[][] *pointer = image.get();
	return iterator(pointer[0]);
}

Image::end(void) {
	u_char[][] *pointer = image.get();
	return iterator(pointer[height]);
}

class Image 
{  
	private:    
		int width, height;    
		std::unique_ptr<u_char[][]> data;  
	public:  
		class iterator   
		{     
		private: 
			u_char *ptr;
			// construct only via Image class (begin/end)
			iterator(u_char *p) : ptr(p) {} 
		public:
			//copy construct is public 
			iterator( const iterator & rhs) : ptr(rhs.ptr) {} 
			// define overloaded ops: *, ++, --, = 
			iterator & operator=(const iterator & rhs) {
				if (this != rhs) {
					delete[] ptr;
					ptr = rhs.ptr;
				}
			}
			// other methods for iterator
		}; 

   // define begin()/end() to get iterator to start and    
   // "one-past" end.
    iterator begin(void) { return iterator(data.get())} 
    // etc 
};