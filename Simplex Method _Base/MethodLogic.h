#pragma once
#include "Matrix.h"

void redefine_matrix(Matrix m);
void define_z(Matrix m);
void fill_slack(Matrix m);

void fill_i(Matrix m);
void fill_j(int i, Matrix m);

void simplex(Matrix m);
int det_piv_column(double** mat_new,Matrix m);
int det_piv_row(double** mat_new, Matrix m, int piv_col);
