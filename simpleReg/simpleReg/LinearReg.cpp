#include "LinearReg.h"
#include <iostream>
#include <math.h>


LinearReg::LinearReg(double x[], double y[], int m)
{
	this->x = x;
	this->y = y;
	this->m = m;
	
}

double* LinearReg::gradient_descent(double x[], double y[], double lr, int iter, double *J, int m)
{
	double* theta = new double[2];
	theta[0] = 1;
	theta[1] = 1;

	//将均方误差（平方误差/二次损失）损失函数作为默认loss function计算梯度
	//w'=w-lr*（J对w的偏导），为参数w的一次梯度下降，J为loss function，衡量误差
	for (int i = 0; i < iter; i++) {
		
	}
}

//进行单次预测
double LinearReg::h(double x, double theta[])
{
	return theta[0] + theta[1] * x;
}

//计算偏差
double LinearReg::compute_cost(double x[], double y[], double theta[], int m)
{
	double* predictions = calculation_prediction(x, theta, m);
	double temp = 0;
	for (int i = 0; i < m; i++) {
		temp += pow(predictions[i] - y[i], 2);
	}
	double cost = temp / (2 * m);
	return cost;

}

//预测
double* LinearReg::calculation_prediction(double x[], double theta[], int m)
{
	double* predictions = new double[m];
	for (int i = 0; i < m; i++) {
		predictions[i] = h(x[i], theta);
	}
	return predictions;
}

//训练
void LinearReg::train(double alpha, int iterations)
{

}

//预测
void LinearReg::predict(double x)
{

}

