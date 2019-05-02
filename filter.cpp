//Class to represent a typical filter object to be used by imageops.
//Filter data is a NxN matrix of values representing the filter.

#include<sstream>
#include<fstream>
#include<string>
#include "Image.h"

using namespace std;
using namespace chtble001;

//constructor
filter::filter(const std::string& inputFile) {
	filter_matrix = new float*[N];
	float num;
	
	//create an input stream to read the file and store data in matrix
	ifstream ifs;
	ifs.open(inputFile);
	ifs >> N;
	
	//loop to populate the float matrix
	for (int i = 0; i < N; ++i) {
		float *row = new float[N];
		filter_matrix[i] = row;
		for (int j = 0; j < N; ++j) {
			ifs >> num;
			row[j] = num;
		}
	}
	ifs.close();
}

//the destructor
filter::~filter() {
	for (int i = 0; i < N; ++i) {
		delete[] filter_matrix[i];
	}
	delete[]filter_matrix;
}
