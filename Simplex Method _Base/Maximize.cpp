#include <iostream>
#include "Maximize.h"

void start_maximization(Matrix& m) {
	define_z(m);
	fill_slack(m);
	m.print_matrix();
	pivoting(m);
	std::cout << "\nAfter pivoting:\n";
	m.print_matrix();
	pivoting(m);
	std::cout << "\nAfter pivoting:\n";
	m.print_matrix();
}

void pivoting(Matrix& m) {
	int piv_col = det_piv_column(m);
	int piv_row = det_piv_row(m, piv_col);
	row_pivot_iterate(m, piv_row, piv_col);
	col_iterate(m, piv_row, piv_col);
	std::cout << "\nPivot Column: " << piv_col << ", Pivot Row: " << piv_row << "\n";
}

void define_z(Matrix& m){ // funciona
	for (int j = 0; j < m.vars_getter(); j++) {
		m.Z_setter(j, -m.Z_getter(j));
	}
}
void fill_slack(Matrix& m) { // funciona
	fill_i(m);
}
void fill_j(int i, Matrix& m) {
	for (int j = m.vars_getter(); j < m.cols_getter() - 1; j++) {
		if(j - m.vars_getter() == i - 1) m.values_setter(i, j, 1);
		else m.values_setter(i, j, 0);;
	}
}
void fill_i(Matrix& m) {
	for (int i = 1; i < m.rows_getter(); i++) {
		fill_j(i, m);
	}
}

int det_piv_column(Matrix& m) {
	int piv_col = -1;
	double most_neg = 0;
	for (int j = 0; j < m.cols_getter() - 1; j++) {
		if (m.get_value(0, j) < most_neg) {
			most_neg = m.get_value(0, j);
			piv_col = j;
		}
	}
	return piv_col;
}
int det_piv_row(Matrix& m, int piv_col) {
	int piv_row = -1;
	double val_min = m.get_value(1,6) / m.get_value(1,piv_col);
	for (int i = 1; i < m.rows_getter(); i++) {
		double denom = m.get_value(i, piv_col);
		if (denom <= 0) continue;

		if (m.get_value(i,6) / m.get_value(i,piv_col) < val_min && m.get_value(i, piv_col) > 0) {
			std::cout << "Row " << i << " - Value: " << m.get_value(i,6) / m.get_value(i, piv_col) << "\n";
			val_min = m.get_value(i,6) / m.get_value(i,piv_col);
			piv_row = i;
		}
	}
	return piv_row;
}

void row_pivot_iterate(Matrix& m, int piv_row, int piv_col) {
	double piv_value = m.get_value(piv_row, piv_col);
	for (int j = 0; j < m.cols_getter(); j++) {
		m.values_setter(piv_row, j, m.get_value(piv_row, j) / piv_value);
	}

}
void col_iterate(Matrix& m, int piv_row, int piv_col) {
	for (int i = 0; i <= m.rest_getter(); i++) {
		double multiplier = m.get_value(i, piv_col);
		if (i == piv_row) { continue; }
		for (int j = 0; j < m.cols_getter(); j++) {
			double pivoted_value = m.get_value(piv_row, j);
			double new_value = m.get_value(i, j) - (multiplier * pivoted_value);
			m.values_setter(i, j, new_value);
		}
	}
}

bool optimal_solution(Matrix& m) {
	for (int j = 0; j < m.cols_getter(); j++) {
		if (m.get_value(0, j) < 0) {
			return false;
		}
	}
	return true;
}
