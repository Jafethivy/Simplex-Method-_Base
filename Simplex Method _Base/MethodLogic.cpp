#include <iostream>
#include "MethodLogic.h"

//Define the new matrix for the simplex method
void redefine_matrix(Matrix m){
	define_z(m);
	fill_slack(m);
	m.print_matrix();
	simplex(m);
	std::cout << "After pivoting: " << std::endl;
	m.print_matrix();
}
void simplex(Matrix m) {
	pivoting(m);
}
void pivoting(Matrix m) {
	int piv_col = det_piv_column(m);
	int piv_row = det_piv_row(m, piv_col);
	row_pivot_iterate(m, piv_row, piv_col);
	col_iterate(m, piv_row, piv_col);
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

int det_piv_column(Matrix m) {
	double min = m.get_value(0,0);
	int b = 0;
	for (int j = 1; j < m.cols_getter(); j++) {
		if (m.get_value(0, j) < min) {
			min = m.get_value(0, j);
			b = j;
		}
	}
	return b;
}
int det_piv_row(Matrix m, int piv_col) {
	double row_min = m.get_value(1,piv_col);
	double res_min = m.get_value(1,m.cols_getter() - 1);
	double val_min = res_min / row_min;
	int a = 1;
	for (int i = 2; i <= m.rest; i++) {
		double row_min_t = m.get_value(i, piv_col);
		double res_min_t = m.get_value(i, m.cols_getter() - 1);
		double val_min_t = res_min_t / row_min_t;
		if (val_min_t < val_min) {
			val_min = val_min_t;
			a = i;
		}
	}
	return a;
}

void row_pivot_iterate(Matrix m, int piv_row, int piv_col) {
	double piv_value = m.get_value(piv_row, piv_col);
	for (int j = 0; j < m.cols_getter(); j++) {
		double new_value = m.get_value(piv_row, j) / piv_value;
		m.values_setter(piv_row, j, new_value);
	}
}
void col_iterate(Matrix m, int piv_row, int piv_col) {
	for (int i = 1; i <= m.rest; i++) {
		double multiplier = m.get_value(i, piv_col);
		if (i == piv_row ) { continue; }
		for (int j = 0; j < m.cols_getter(); j++) {
			double pivoted_value = m.get_value(piv_row, j);
			double new_value = m.get_value(i, j) - (multiplier * pivoted_value);
			m.values_setter(i, j, new_value);
		}
	}
}

bool optimal_solution(Matrix m) {
	for (int j = 0; j < m.cols_getter() - 1; j++) {
		if (m.get_value(0, j) < 0) {
			return false;
		}
	}
	return true;
}