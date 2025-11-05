#pragma once
#include <string>

class Matrix{
private:
	int rows, cols;
	std::string objt;

	double** values;
	double* func_Z;

public:
	int rest, vars;
	std::string size;

	//constructor
	Matrix();

	//Getters and Setters
	double** get_matrix();
	int cols_getter() const;
	int rows_getter() const;
	double Z_getter(int j);
	double get_value(int i, int j);

	void Z_setter(int j, double value);
	void values_setter(int i, int j, double value);
	
	//user input functions
	int restrictions();
	int variables();

	//auxiliary functions
	void print_info();
	void print_matrix();

	int aux_rows() const;
	int aux_cols(int r) const;

	void init_matrix();

	//Objetive
	std::string objetive();

	//Objetive function
	void obj_function();

	//Define restrictions
	void define_rest();
};

