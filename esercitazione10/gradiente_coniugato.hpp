#pragma once
#include <Eigen/Dense>

void gradiente_coniugato(const Eigen::MatrixXd& A, Eigen::VectorXd& x, const Eigen::VectorXd b, const double tol){
    Eigen::VectorXd r = b - A * x;
    Eigen::VectorXd p = r;

    while (r.norm() > tol){
        const double alpha = ((p.transpose() * r)/(p.transpose() * A * p)).value();

        x += alpha * p;
        r = b - A * x;
        
        const double beta = ((p.transpose() * A * r)/(p.transpose() * A * p)).value();

        p = r - beta * p;
    }
}