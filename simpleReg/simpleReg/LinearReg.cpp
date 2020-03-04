#include "LinearReg.h"
#include <iostream>
#


LinearReg::LinearReg(double x[], double y[], int m)
{
	this->x = x;
	this->y = y;
	this->m = m;

}

double* LinearReg::gradient_descent(double x[], double y[], double alpha, int iter, double *J, int m)
{

}