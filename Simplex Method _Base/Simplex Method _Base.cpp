#include <iostream>
#include "Matrix.h"
#include "Maximize.h"


int main() {
    int n_vars, n_rest;
    std::string obj;

    std::cout << "Enter variables: ";
    std::cin >> n_vars;
    std::cout << "Enter restrictions: ";
    std::cin >> n_rest;
    std::cout << "Enter objetive (max/min): ";
    std::cin >> obj;

    Matrix m(n_vars, n_rest, obj);

    // Cargar función objetivo
    std::cout << "\nEnter objective coefficients:\n";
    std::vector<double> coefs_obj(n_vars);
    for (int i = 0; i < n_vars; ++i) {
        std::cout << "x" << i + 1 << ": ";
        std::cin >> coefs_obj[i];
    }
    m.set_objetive_function(coefs_obj);

    // Cargar restricciones
    std::cout << "\nEnter restrictions:\n";
    for (int i = 0; i < n_rest; ++i) {
        std::cout << "Restriction " << i + 1 << ":\n";
        std::vector<double> coefs_rest(n_vars);
        for (int j = 0; j < n_vars; ++j) {
            std::cout << "x" << j + 1 << ": ";
            std::cin >> coefs_rest[j];
        }
        double resultado;
        std::cout << "Result: ";
        std::cin >> resultado;
        m.set_restrictions(i, coefs_rest, resultado);
    }

	start_maximization(m);
    /*
    m.set_objetive_function({ 3, 2, 5 });
    m.set_restrictions(0, { 2, 1, 1 }, 430);
    m.set_restrictions(1, { 1, 2, 1 }, 460);
    m.set_restrictions(2, { 1, 1, 3 }, 420);
    start_maximization(m);
    return 0;
    */
}
