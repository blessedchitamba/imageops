// Header file for Image.cpp class.

#ifndef IMAGE_H
#define IMAGE_H

#include <vector>
#include <string>
#include <unordered_map>
#include <queue>

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
			std::unique_ptr<u_char[][]> data;	//pointer to a 2D array representing the image
		public:
			class iterator;
			friend class iterator;

			//Inner iterator class to use as the main means to access data in my overloaded methods
			class iterator   
			{     
			private: 
				u_char[] *ptr;
				// construct only via Image class (begin/end)
				iterator(u_char[] *p); 
			public:
				//copy construct is public 
				iterator( const iterator & rhs);

				//overloaded ++ and -- and *
				iterator operator++ ();
				iterator operator--();
				iterator operator*();
				iterator & operator=(const iterator & rhs);
			};  
			//-------------End of iterator--------------

			//iterator begin and end methods
			iterator begin(void);
			iterator end(void);

			//Image class methods
			//Constructor which takes in a pointer to an unsigned char matrix
			Image(*u_char[][] image, int width, int height);	//Default constructor
			~Image();	//Destructor

			//Copy constructor
			Image(const Image & rhs);

			//Copy Assignment operator
			Image & operator=(const Image & rhs);

			//Move constructor
			Image(Image && rhs);

			//Move assignment
			Image & operator=(Image && rhs);

			//----------Operator Overloading Methods-----------
			Image operator+ (const Image & rhs);
			Image operator- (const Image & rhs);
			Image operator! ();
			Image operator/ (const Image & rhs);
			Image operator* (int f);
			friend ostream &operator<< ( ostream &output, const Image & rhs);
			friend istream &operator>> ( istream &input, const Image & lhs);

			//Load and save methods
			void load();
			void save();
	}

}

#endif