#pragma once
#include <string>

class Matrix{
private:
	int rest, vars;
	int rows, cols;
	std::string objt;

	double** values;
	double* func_Z;

public:
	std::string size;

	//constructor
	Matrix();

	//user input functions
	int restrictions();
	int varibles();

	//auxiliary functions
	void print_info();
	void print_matrix();

	int get_rows();
	int get_cols(int r);

	void init_matrix();

	//Objetive
	std::string objetive();

	//Objetive function
	void obj_function();

	//Define restrictions
	void define_rest();
};

