#include <iostream>
#include "Matrix.h"


int main() {
	Matrix m;
	m.obj_function();
	m.define_rest();
	m.print_info();
	m.print_matrix();
}
