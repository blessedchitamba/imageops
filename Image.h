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
				
				
			};  
			//-------------End of iterator--------------

			//Image class methods
			//Constructor which takes in a pointer to an unsigned char array
			Image(std::unique_ptr<u_char[]> image, int width, int height);	//Default constructor
			~Image();	//Destructor

			//Copy constructor
			Image(const Image & rhs);

			//Copy Assignment operator
			Image& operator=(const Image & rhs){}

			//Move constructor
			Image(Image && rhs);

			//Move assignment
			Image& operator=(Image && rhs){}
			
			//iterator begin and end methods
			iterator begin(void);
			iterator end(void);

			//----------Operator Overloading Methods-----------
			Image operator+ (const Image & rhs);
			Image operator- (const Image & rhs);
			Image operator! ();
			Image operator/ (const Image & rhs);
			Image operator* (int f);
			friend std::ostream &operator<< ( std::ostream &output, const Image & rhs);
			friend std::istream &operator>> ( std::istream &input, const Image & lhs);

			//Load and save methods
			void load();
			void save();
	};

}

#endif
