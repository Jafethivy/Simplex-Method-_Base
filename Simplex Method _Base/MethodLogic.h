#pragma once
#include "Matrix.h"

void redefine_matrix(Matrix m);
void simplex(Matrix m);
void pivoting(Matrix m);

void define_z(Matrix m);
void fill_slack(Matrix m);
void fill_i(Matrix m);
void fill_j(int i, Matrix m);

int det_piv_column(Matrix m);
int det_piv_row(Matrix m, int piv_col);

void row_pivot_iterate(Matrix m, int piv_row, int piv_col);
void col_iterate(Matrix m, int piv_row, int piv_col);

bool optimal_solution(Matrix m);