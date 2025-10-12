#include "Matrix.h"
#include <iostream>

//constructor
Matrix::Matrix() {
	rest = Matrix::restrictions();
	vars = Matrix::varibles();
	objt = Matrix::objetive();
	rows = Matrix::get_rows();
	cols = Matrix::get_cols(rows);

	values = new double* [rows];
	func_Z = new double[vars];

	Matrix::init_matrix();

	size = std::to_string(rows) + "x" + std::to_string(cols);
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
int Matrix::get_rows() {
	return Matrix::rest + 1;
}
int Matrix::get_cols(int r) {
	return Matrix::vars + r;
}

void Matrix::init_matrix() {
	for (int i = 0; i < rows; i++) {
		Matrix::values[i] = new double[cols];
	}
}

//Objetive
std::string Matrix::objetive() {
	int aux_obj;
	std::cout << "Objetive [1] Max or [2] Min: ";
	std::cin >> aux_obj;
	std::string objt = (aux_obj == 1) ? "Max" : "Min";
	return objt;
}

//Objetive function
void Matrix::obj_function() {
	for (int i = 0; i < vars; i++) {
		std::cout << "Enter the coefficient for x" << i + 1 << ": ";
		std::cin >> func_Z[i];
	}
}

//Define restrictions
void Matrix::define_rest() {
	std::cout << "Define the restrictions:" << std::endl;
	for (int i = 0; i < rest; i++) {
		std::cout << "Restriction " << i + 1 << ":" << std::endl;
		for (int j = 0; j < vars; j++) {
			std::cout << "Enter the coefficient for x" << j + 1 << ": ";
			std::cin >> values[i+1][j];
		}
		std::cout << "Enter the result value: ";
		std::cin >> values[i+1][cols - 1];
	}
}
