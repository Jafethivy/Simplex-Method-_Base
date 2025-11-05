#include "Matrix.h"
#include <iostream>

//constructor
Matrix::Matrix() {
	rest = 3;
	vars = 3;
	rows = Matrix::aux_rows();
	cols = Matrix::aux_cols(rows);

	values = new double* [rows];
	func_Z = new double[vars];

	Matrix::init_matrix();

	size = std::to_string(rows) + "x" + std::to_string(cols);
}

//Getters and Setters
double** Matrix::get_matrix(){ return Matrix::values; }
int Matrix::cols_getter() const { return Matrix::cols; }
int Matrix::rows_getter() const { return Matrix::rows; }
double Matrix::Z_getter(int j) { return Matrix::func_Z[j]; }
double Matrix::get_value(int i, int j) { return Matrix::values[i][j]; }

void Matrix::Z_setter(int j, double value) {
	values[0][j] = value;
}
void Matrix::values_setter(int i, int j, double value) {
	values[i][j] = value;
}


//user input functions
int Matrix::restrictions() {
	int rest;
	std::cout << "Enter the number of restrictions: ";
	std::cin >> rest;
	return rest;
}
int Matrix::varibles() {
	int var;
	std::cout << "Enter the number of varibles: ";
	std::cin >> var;
	return var;
}

//auxiliary functions
void Matrix::print_info() {
	std::cout << "Matrix size: " << Matrix::size << std::endl;
	std::cout << "Objetive: " << Matrix::objt << std::endl;
	std::cout << "Function Z coefficients: ";
	for (int i = 0; i < vars; i++) {
		std::cout << func_Z[i] << "X_" << i+1 << " ";
	}
	std::cout << std::endl;
}
void Matrix::print_matrix() {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			std::cout << "[" << values[i][j] << "]" << " ";
		}
		std::cout << std::endl;
	}
}
int Matrix::aux_rows() const{ return Matrix::rest + 1; }
int Matrix::aux_cols(int r) const{ return Matrix::vars + r; }

void Matrix::init_matrix() {
	for (int i = 0; i < rows; i++) {
		Matrix::values[i] = new double[cols];
	}
}

//Objetive function
void Matrix::obj_function() {
	int n = 1;
	for (int i = 0; i < vars; i++) {
		//std::cout << "Enter the coefficient for x" << i + 1 << ": ";
		//std::cin >> func_Z[i];
		func_Z[i] = n;
		n++;
	}
}

//Define restrictions
void Matrix::define_rest() {
	int n = 0;
	for (int i = 0; i < rest; i++) {
		for (int j = 0; j < vars; j++) {
			values[i+1][j] = n;
			n++;
		}
		values[i+1][cols - 1] = 40;
		
	}
}
