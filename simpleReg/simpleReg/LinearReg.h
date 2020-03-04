#pragma once
#ifndef LINEARREGRESSION_H
#define ML_LINEARREGRESSION_H//�����

class LinearReg
{
public:
	double* x;
	double* y;
	int m;
	double* theta;
	//����ʵ��
	LinearReg(double x[], double y[], int m);
	//ѵ��
	void train(double alpha, int iterations);
	//Ԥ��
	void predict(double x);

private:
	static double h(double x, double theta);
	static double compute_cost(double x[], double y[], double theta[], int m);
	static double* calculation_prediction(double x[], double theta[], int m);
	static double* gradient_descent(double x[], double y[], double alpha, int iter, double *J, int m);
};

#endif // !LINEARREGRESSION_H



