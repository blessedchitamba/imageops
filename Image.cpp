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

//Default constructor
Image::Image(): width(0), height(0),data(nullptr){}

//Constructor
Image::Image(unsigned char *image, int width, int height) : data(image), width(width), height(height) {
	cout << "Unique pointer created in constructor" << endl;
}

//Destructor
Image::~Image() {
	//do the deletion of the image array
}

//Copy constructor
Image::Image(const Image & rhs) : width(rhs.width), height(rhs.height), data(new unsigned char[width*height]) {
	//Implement using the iterator begin() and end()
	cout << "Copy constructor called " << endl;
	
	//create the iterators
	Image::iterator beg = this->begin(), end = this->end();
	Image::iterator rbeg = rhs.begin(), rend = rhs.end();
	
	//copy array
	while (beg != end) {
		*beg = *rbeg;
		++beg;
		++rend;
	}
	
	//return *this;
}

//Copy Assignment
//Image& operator=(const Image & rhs){
	//Implement using the iterator begin() and end()
//}

//Move Constructor
Image::Image(Image && rhs) : width(move(rhs.width)), height(move(rhs.height)), data(move(rhs.data)) {
	//Implement using the iterator begin and end
	cout << "Move constructor called " << endl;
	rhs.data.reset(nullptr);
}

//getData
unsigned char* Image::getData() {
	return data.get();
}

int Image::getWidth() {
	return width;
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

//!= operator
bool Image::iterator::operator!=(const iterator &rhs) const {
	return this->ptr != rhs.ptr;
}

//iterator begin and end methods to construct iterator object
Image::iterator Image::begin(void) const {
        return iterator(data.get());
 }
                                                                                                         
Image::iterator Image::end(void) const {
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



//---------------------Iterator operator overload methods--------------------------

//add operator
Image Image::operator+(const Image &rhs) {
	//first check if the two images are the same size
	if( (this->width == rhs.width) && (this->height == rhs.height) ) {
		//create the iterators
		cout << "Dimensions equal..." << endl;
		Image::iterator beg = this->begin(), end = this->end();
		Image::iterator rbeg = rhs.begin(), rend = rhs.end();
		
		//a few variables
		result_data = new unsigned char[rhs.width*rhs.height];
		int count = 0;
		unsigned char val;
		cout << rhs.width*rhs.height << endl;
		cout << this->width << endl;
		
		//do the add
		while(beg != end) {
			val = *beg + *rbeg;
			val = (val > 255) ? 255 : val;   //to ensure value is less than 255
			result_data[count] = val;
			//cout << result_data[count];
			++beg;
			++rbeg;
			count++;
		}
		cout << '\n';
		cout << "count is " << count << endl;
		cout << "result_data[378] is " << result_data[378] << endl;
		//return pointer to new object
		Image result(result_data, rhs.width, rhs.height);
		cout << "result width is " << result.getWidth() << endl;
		return result;
	}
}
