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
	//将均方误差（平方误差/二次损失）损失函数作为默认loss function计算梯度
	//w'=w-lr*（J对w的偏导），为参数w的一次梯度下降，J为loss function，衡量误差
	for (int i = 0; i < iter; i++) {
		
	}
}

//进行单次预测
double LinearReg::h(double x, double theta)
{
	
}

//计算偏差
double LinearReg::compute_cost(double x[], double y[], double theta[], int m)
{

}

//预测
double* LinearReg::calculation_prediction(double x[], double theta[], int m)
{

}






