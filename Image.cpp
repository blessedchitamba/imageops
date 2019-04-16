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


class Image 
{  
	private:    
		int width, height;    
		std::unique_ptr<unsigned char[]> data;  
	public:  
		class iterator   
		{     
		private: 
			unsigned char *ptr;
			// construct only via Image class (begin/end)
			iterator(u_char *p) : ptr(p) {} 
		public:
			//copy construct is public 
			iterator( const iterator & rhs) : ptr(rhs.ptr) {} 
			// define overloaded ops: *, ++, --, = 
			iterator & operator=(const iterator & rhs) {...}
			// other methods for iterator
		}; 

   // define begin()/end() to get iterator to start and    
   // "one-past" end.
    iterator begin(void) { return iterator(data.get())} 
    // etc 
};