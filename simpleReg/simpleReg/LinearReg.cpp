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
	//��������ƽ�����/������ʧ����ʧ������ΪĬ��loss function�����ݶ�
	//w'=w-lr*��J��w��ƫ������Ϊ����w��һ���ݶ��½���JΪloss function���������
	for (int i = 0; i < iter; i++) {
		
	}
}

//���е���Ԥ��
double LinearReg::h(double x, double theta)
{
	
}

//����ƫ��
double LinearReg::compute_cost(double x[], double y[], double theta[], int m)
{

}

//Ԥ��
double* LinearReg::calculation_prediction(double x[], double theta[], int m)
{

}






