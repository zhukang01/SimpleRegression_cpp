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

	//��������ƽ�����/������ʧ����ʧ������ΪĬ��loss function�����ݶ�
	//w'=w-lr*��J��w��ƫ������Ϊ����w��һ���ݶ��½���JΪloss function���������
	for (int i = 0; i < iter; i++) {
		
	}
}

//���е���Ԥ��
double LinearReg::h(double x, double theta[])
{
	return theta[0] + theta[1] * x;
}

//����ƫ��
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

//Ԥ��
double* LinearReg::calculation_prediction(double x[], double theta[], int m)
{
	double* predictions = new double[m];
	for (int i = 0; i < m; i++) {
		predictions[i] = h(x[i], theta);
	}
	return predictions;
}

//ѵ��
void LinearReg::train(double alpha, int iterations)
{

}

//Ԥ��
void LinearReg::predict(double x)
{

}

