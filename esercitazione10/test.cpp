#include "gradiente_coniugato.hpp"
#include <iostream>
#include <Eigen/Dense>

int main(){
    const double tol = 1.0e-15;
    unsigned int n = 10;

    Eigen::MatrixXd B = Eigen::MatrixXd::Random(n, n);

    if (abs(B.determinant()) < tol)
        return -1;

    Eigen::MatrixXd A = B.transpose() * B;
    Eigen::VectorXd x_ex = Eigen::VectorXd::Ones(n);

    Eigen::VectorXd b = A * x_ex;

    Eigen::VectorXd x = Eigen::VectorXd::Zero(n);

    gradiente_coniugato(A, x, b, tol);

    std::cout << x << "\n";

    return EXIT_SUCCESS;
}