#include <iostream>
#include "Matrix.h"
#include "Maximize.h"


int main() {
    Matrix m(3, 3, "max");

    /*std::cout << "\nEnter objective coefficients:\n";
    std::vector<double> coefs_obj(3);
    for (int i = 0; i < 3; ++i) {
        std::cout << "x" << i + 1 << ": ";
        std::cin >> coefs_obj[i];
    }
    m.set_objetive_function(coefs_obj);

    std::cout << "\nEnter restrictions:\n";
    for (int i = 0; i < 3; ++i) {
        std::cout << "Restriction " << i + 1 << ":\n";
        std::vector<double> coefs_rest(3);
        for (int j = 0; j < 3; ++j) {
            std::cout << "x" << j + 1 << ": ";
            std::cin >> coefs_rest[j];
        }
        double resultado;
        std::cout << "Result: ";
        std::cin >> resultado;
        m.set_restrictions(i, coefs_rest, resultado);
    }
    */
	//todo lo anterior es solo testeo de carga de datos
    m.set_objetive_function({3, 2, 5});
    m.set_restrictions(0, {2, 1, 1}, 430);
    m.set_restrictions(1, {1, 2, 1}, 460);
    m.set_restrictions(2, {1, 1, 3}, 420);
    start_maximization(m);
	return 0;
}
