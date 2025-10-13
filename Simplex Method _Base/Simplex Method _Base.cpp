#include <iostream>
#include "Matrix.h"
#include "MethodLogic.h"


int main() {
	Matrix m;
	m.obj_function();
	m.define_rest();
	redefine_matrix(m);
}
