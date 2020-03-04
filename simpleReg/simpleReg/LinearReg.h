#pragma once
#ifndef LINEARREGRESSION_H
#define ML_LINEARREGRESSION_H//�����

class LinearReg
{
public:
	//����
	double* x;
	//Ԥ��
	double* y;
	//��������
	int m;
	//����
	double* theta;
	//����ʵ��
	LinearReg(double x[], double y[], int m);
	//ѵ��
	void train(double alpha, int iterations);
	//Ԥ��
	void predict(double x);

private:
	double h(double x, double theta);//���е���Ԥ��
	double compute_cost(double x[], double y[], double theta[], int m);//����ƫ��
	double* calculation_prediction(double x[], double theta[], int m);//Ԥ��
	double* gradient_descent(double x[], double y[], double alpha, int iter, double *J, int m);//�ݶ��½�
};

#endif // !LINEARREGRESSION_H



