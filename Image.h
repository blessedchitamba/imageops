// Header file for Image.cpp class.

#ifndef IMAGE_H
#define IMAGE_H

#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <memory>
#include <iostream>

typedef unsigned char u_char;
//using my own student number as namespace
namespace chtble001 {
	class Image {
		/*
		  Methods in this class should be:
		  1) Appropriate constructors and destructors
		  2) Move/Copy semantics
		  3) Load/Save methods
		  4) Operator overloading (the core of the assignment)
		  5) Image iterator inner class
		  6) 
		*/
		private:
			int width, height;    //width and height of the 2D array representing the image
			std::unique_ptr<u_char[]> data;	//pointer to a 1D array representing the image. will be referenced as a 2D
			u_char *result_data;	//the char array to hold the result of any operation between two images
		public:
			class iterator;
			friend class iterator;

			//Inner iterator class to use as the main means to access data in my overloaded methods
			class iterator   
			{     
			private: 
				u_char *ptr;
				// construct only via Image class (begin/end)
				iterator(u_char *p) : ptr(p) {} 
				friend class Image;
			public:
				//copy construct is public 
				iterator( const iterator & rhs);

				//overloaded ++ and -- and *
				iterator& operator++ ();
				iterator& operator--();
				unsigned char& operator*();
				iterator & operator=(const iterator & rhs){}
				bool operator!=(const iterator& rhs) const;
				
				
			};  
			//-------------End of iterator--------------

			//------------Image class methods------------
			//Constructor which takes in a pointer to an unsigned char array
			Image();	//Default constructor
			Image(unsigned char *image, int width, int height);	//Argument constructor
			~Image();	//Destructor

			//Copy constructor
			Image(const Image & rhs);

			//Copy Assignment operator
			Image& operator=(const Image & rhs){
				std::cout << "Copy assignment called " << std::endl;
				this->width = rhs.width;
				this->height = rhs.height;
				this->data.reset(new unsigned char[this->width*this->height]);
				
				//copy the array
				Image::iterator beg = this->begin(), end = this->end();
				Image::iterator rbeg = rhs.begin(), rend = rhs.end();
				while (beg != end) {
					*beg = *rbeg;
					++beg;
					++rbeg;
				}
				
				return *this;
			}

			//Move constructor
			Image(Image && rhs);

			//Move assignment
			Image& operator=(Image && rhs){
				std::cout << "Move assignment called " << std::endl;
				this->width = std::move(rhs.width);
				this->height = std::move(rhs.height);
				this->data = std::move(rhs.data);
				rhs.data.reset(nullptr);
				return *this;
			}
			
			//Image test method to test begin and end
			void testMeth();
			
			//getData method to return raw pointer to array
			unsigned char* getData();
			int getWidth();
			int get_index(int row, int col)const;
			
			//iterator begin and end methods
			iterator begin(void) const;
			iterator end(void) const;

			//----------Operator Overloading Methods-----------
			Image operator+ (const Image & rhs);
			Image operator- (const Image & rhs);
			Image& operator! ();
			Image& operator/ (Image & rhs);
			Image& operator* (const int& f);
			Image operator%(Filter& temp);
			friend std::ostream &operator<< ( std::ostream &output, const Image & rhs);
			friend std::istream &operator>> ( std::istream &input, const Image & lhs);

			//Load and save methods
			void load();
			void save();
	};
	
	
	//filter class
	class filter {
	public:
		int N;	//the dimension of the filter matrix
		float **filter_matrix;
		filter() {}	//constructors
		filter(const std::string& inputFile);
		~filter();	//destructpr
		
		//function to convert to fraction
		float fraction_convert(std::string item);
	};

}

#endif
