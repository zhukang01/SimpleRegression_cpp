#pragma once
#ifndef LINEARREGRESSION_H
#define ML_LINEARREGRESSION_H//则定义宏

class LinearReg
{
public:
	double* x;
	double* y;
	int m;
	double* theta;
	//创建实例
	LinearReg(double x[], double y[], int m);
	//训练
	void train(double alpha, int iterations);
	//预测
	void predict(double x);

private:
	static double h(double x, double theta);
	static double compute_cost(double x[], double y[], double theta[], int m);
	static double* calculation_prediction(double x[], double theta[], int m);
	static double* gradient_descent(double x[], double y[], double alpha, int iter, double *J, int m);
};

#endif // !LINEARREGRESSION_H



