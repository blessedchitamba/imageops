/*the driver file for the imageops application
  It will do the reading of image file, loading of the image array,
  as well as taking user input for image processing options
*/

#include <fstream>  // Needed for file stream objects
#include <iostream> // Needed for console stream objects
#include <sstream>  // Needed for string stream objects
#include <string>   // Needed for strings
#include <vector>   // Needed for the vector container
#include "Image.h"  // the file containing the functions

using namespace std;
using namespace chtble001;

unsigned char* loadImage(string inputFile);
bool saveOutput(const unsigned char *array, string outputFile, int width, int height);
int Nrows, Ncols;

int main(int argc, char * argv[])
{
	//process user options
	//-a, -s, and -l have image1 and image2. -i only has image. -t has image and int f
	string option = argv[1];
	
	//pointers to unsigned char arrays that holds image data
	unsigned char *data1;
	unsigned char *data2;
	
	//if statement
	if (option == "-i") {
		//implement invert
		cout << "Invert option selected.." << endl;
		string imageFile = argv[2];
		string outputFile = argv[3];
		
		//load data array
		data1 = loadImage(imageFile);
		
		//to test, write that same array to outputfile
		saveOutput(data1, outputFile, Nrows, Ncols);
		
		//create the Image object
		
	}
	else if (option == "-t") {
		//threshhold operation. 
		cout << "Threshhold option selected.." << endl;
		string imageFile = argv[2];
		string threshInt = argv[3];
		string outputFile = argv[4];
		
		//load data array
		data1 = loadImage(imageFile);
		
		//create Image object
		
		//call the appropriate method
	}
	else {		//else the rest have two image arguments
		string image1 = argv[2];
		string image2 = argv[3];
		string outputFile = argv[4];
		
		//load arrays
		data1 = loadImage(image1);
		data2 = loadImage(image2);
		
		//create Image object
		
		if (option == "-a") {
			//call appropriate method
			cout << "Option called is " << option << endl;
		}
		else if (option == "-s") {
			//call appropriate method
			cout << "Option called is " << option << endl;
		}
		else if (option == "-l") {
			//call approptiate method
			cout << "Option called is " << option << endl;
		}
		else {
			cout << "Invalid option!!" << endl;
		}
	}
}

//loadImage definition
unsigned char* loadImage(string inputFile) {
	//implement here
	cout << "Beginning loadImage.." << endl;
	unsigned char *imageData;
	
	//read from file line by line. Discard header by looping
	string line;
	string data;
	ifstream theFile(inputFile, ios::binary);
	
	if(theFile.is_open()) {
		//first line with P5
		getline(theFile, line);
		
		//loop through comments till the next line that doesnt start with #
		getline(theFile, line);
		while(line[0] == '#') {
			getline(theFile, line);
		}
		
		//current line now is the one that has Nrows and Ncols
		istringstream iss;
		iss.str(line);
		string x, y;
		iss >> x >> y;
		Nrows = stoi(x);
		Ncols = stoi(y);
		cout << "Nrows is " << Nrows << "and Ncols is " << Ncols << endl;
		
		//skip the 255 line
		getline(theFile, line);
		
		//now read the image data
		imageData = new unsigned char[Nrows*Ncols];
		theFile.read((char*)imageData, Nrows*Ncols);
		cout << "Image read successfully." << endl;
	}
	return imageData;
}

//saveOutput definition. takes in a ref to unsigned char array and string filename
bool saveOutput(const unsigned char *array, string outputFile, int width, int height) {
	//write the contents of array into the output file as binary
	
	ofstream outfile(outputFile, ios::binary);
	
	//write header first
	outfile << "P5" << '\n' << "#output file" << '\n' <<
		width << height << '\n' << 255 << endl;
	
	//now write the array
	outfile.write((char*)array, width*height);
	
	outfile.close();
	
	cout << "File with output image created" << endl;
}
