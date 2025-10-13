#pragma once
#include "Matrix.h"

void redefine_matrix(Matrix m);
void define_z(Matrix m);
void fill_slack(Matrix m);

void fill_i(Matrix m);
void fill_j(int i, Matrix m);