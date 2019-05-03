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

//get index method
int Image::get_index(int column, int row) const {

	/*If both are less than zero*/
	if (column < 0 && row < 0) {
		row = -(row)-1;
		column = -(column)-1;
	}

	/*column is now greater or equal to zero and row is less than zero*/
	if (column >= 0 && row < 0) {
		row = -(row)-1;
	}

	/*if column is less than 0 and row is greater or equal to zero*/
	if (column < 0 && row >= 0) {
		column = -(column)-1;
	}
	
	/*If col is greater than the index and row is fine*/
	if (column >= width && row < height) {
		column = (2 * width) - column - 1;
	}

	/*If row is now greater than height*/
	if (column < width && row >= height) {
		//2*width-col-1
		row = (2 * height) - row - 1;
	}

	/*if they are both out of bounds*/
	if (column >= width && row >= height) {
		row = (2 * height) - row - 1;
		column = (2 * width) - column - 1;
	}

	int result = (row * width) + column;
	return result;
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

//overloadd + operator that adds and int and an iterator
Image::iterator& chtble001::Image::iterator::operator+(const int& rhs) {
	this->ptr += rhs;
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
		//cout << rhs.width*rhs.height << endl;
		//cout << this->width << endl;
		
		//do the add
		while(beg != end) {
			if((int)*beg + (int)*rbeg > 255) {
				val = 255;
			}
			else if((int)*beg + (int)*rbeg < 0) {
				val = 0;
			}
			else {
				val = *beg + *rbeg;
			}
			result_data[count] = val;
			//cout << result_data[count];
			++beg;
			++rbeg;
			count++;
		}
		/*cout << '\n';
		cout << "count is " << count << endl;
		cout << "result_data[378] is " << result_data[378] << endl;*/
		//return pointer to new object
		Image result(result_data, rhs.width, rhs.height);
		//cout << "result width is " << result.getWidth() << endl;
		return result;
	}
}


//subtract operator
Image Image::operator-(const Image &rhs) {
	//first check if the two images are the same size
	if( (this->width == rhs.width) && (this->height == rhs.height) ) {
		//create the iterators
		cout << "Dimensions equal..." << endl;
		cout << "Subtract operator called " << endl;
		Image::iterator beg = this->begin(), end = this->end();
		Image::iterator rbeg = rhs.begin(), rend = rhs.end();
		
		//a few variables
		result_data = new unsigned char[rhs.width*rhs.height];
		int count = 0;
		unsigned char val;
		//cout << rhs.width*rhs.height << endl;
		//cout << this->width << endl;
		
		//do the subtract
		while(beg != end) {
			if((int)*beg - (int)*rbeg > 255) {
				val = 255;
			}
			else if((int)*beg - (int)*rbeg < 0) {
				val = 0;
			}
			else {
				val = *beg - *rbeg;
			}
			result_data[count] = val;
			//cout << result_data[count];
			++beg;
			++rbeg;
			count++;
		}
		/*cout << '\n';
		cout << "count is " << count << endl;
		cout << "result_data[378] is " << result_data[378] << endl;*/
		//return pointer to new object
		Image result(result_data, rhs.width, rhs.height);
		//cout << "result width is " << result.getWidth() << endl;
		return result;
	}
}

//Invert ! operator
Image& Image::operator!() {
	//create an iterator
	Image::iterator beg = this->begin(), end = this->end();
	while (beg != end) {
		*beg = 255 - *beg;
		++beg;
	}
	cout << "Image inverted!" << endl;
	return *this;
}

//threshold * operator
Image& Image::operator*(const int& f) {
	//iterators
	Image::iterator beg = this->begin(), end = this->end();
	while (beg != end) {
		if (*beg > f) {
			*beg = 255;
			++beg;
		}
		else {
			*beg = 0;
			++beg; 
		}
	}
	cout << "Threshold applied" << endl;
	return *this;
}

//mask / operator
Image& Image::operator/(Image& rhs) {
	//check if the images are equal size
	if( (this->width == rhs.width) && (this->height == rhs.height) ) {
		//create the iterators
		cout << "Dimensions equal..." << endl;
		cout << "Mask operator called " << endl;
		Image::iterator beg = this->begin(), end = this->end();
		Image::iterator rbeg = rhs.begin(), rend = rhs.end();

		//do the masking
		while (beg != end) {
			if (*rbeg == 255) {
				*rbeg = *beg;
			}
			++beg;
			++rbeg;
		}
		cout << "Mask applied" << endl;
		return rhs;
	}
}

//filter operator for extra credit
Image Image::operator%(filter& fil) {
	
	//empty data array
	unsigned char *array = new unsigned char[width*height];
	//create image to hold the result
	Image final_im(array, width, height);

	//some stuff
	int num = (fil.N - 1) / 2;
	int k = 0, m = 0;

	//loop through in a nested way to apply filter
	for (int y = 0; y < height; ++y) {
		for (int x = 0; x < width; ++x) {
			float temp = 0;
			k = x - num, m = y - num;
			for (int i = 0; i < fil.N; ++i) {
				for (int j = 0; j < fil.N; ++j) {
					temp += data.get()[get_index(k++, m)] * fil.filter_matrix[i][j];
				}
				// reinit column and add +1 to the row to go to the next level
				k = x - num;
				++m;
			}
			int index = final_im.get_index(x, y);
			iterator resit = final_im.begin() + index;
			*resit = (unsigned char)temp;
		}
	}
	return final_im;
}
