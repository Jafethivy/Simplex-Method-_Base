#include <iostream>
#include "MethodLogic.h"

//Define the new matrix for the simplex method
void redefine_matrix(Matrix m){
	define_z(m);
	fill_slack(m);
	m.print_matrix();
	simplex(m);
}
void define_z(Matrix m){
	for (int j = 0; j < m.vars; j++) {
		m.Z_setter(j, -(m.Z_getter(j)));
	}
	for(int j = m.cols_getter() - m.vars - 1 ; j < m.cols_getter(); j++) {
		m.Z_setter(j, 0);
	}
}
void fill_slack(Matrix m) {
	double** value = m.get_matrix();
	fill_i(m);
}
void fill_j(int i, Matrix m) {
	for (int j = m.vars; j < m.cols_getter() - 1; j++) {
		if(j - m.vars == i - 1) m.values_setter(i, j, 1);
		else m.values_setter(i, j, 0);;
	}
}
void fill_i(Matrix m) {
	for (int i = 1; i < m.rows_getter(); i++) {
		fill_j(i, m);
	}
}

void simplex(Matrix m) {
	double** mat_new = m.get_matrix();
	int col = det_piv_column(mat_new, m);
	int row = det_piv_row(mat_new, m, col);
	std::cout << col << std::endl;
	std::cout << row << std::endl;

	std::cout << mat_new[row][col] << std::endl;
}
int det_piv_column(double** mat_new, Matrix m) {
	double min = mat_new[0][0];
	int b = 0;
	for (int j = 1; j < m.vars; j++) {
		if (mat_new[0][j] < min) {
			min = mat_new[0][j];
			b = j;
		}
	}
	return b;
}

