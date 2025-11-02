#include "Matrix.h"
#include <iostream>

//constructor
Matrix::Matrix() {
	rest = Matrix::restrictions();
	vars = Matrix::varibles();
	objt = Matrix::objetive();
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

//Objetive: En este punto se define si la funcion es de maximizar o minimizar, pero como el metodo simplex 
//solo trabaja con maximizar, se puede implementar el metodo de la gran M para convertir las funciones de 
//minimizacion en funciones de maximización.
std::string Matrix::objetive() {
	int aux_obj;
	std::cout << "Objetive [1] Max or [2] Min (Using Big M Method): ";
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
