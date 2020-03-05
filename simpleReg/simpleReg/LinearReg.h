#pragma once
#ifndef LINEARREGRESSION_H
#define ML_LINEARREGRESSION_H//则定义宏

#include <iostream>


class LinearReg
{
public:
	//特征
	double* x;
	//预测
	double* y;
	//样本数量
	int m;
	//参数
	double* theta;
	//创建实例
	LinearReg(double x[], double y[], int m);
	//训练
	void train(double alpha, int iterations);
	//预测
	void predict(double x);

	

private:
	static double h(double x, double theta[]);//进行单次预测
	static double compute_cost(double x[], double y[], double theta[], int m);//计算偏差
	static double* calculation_prediction(double x[], double theta[], int m);//预测
	static double* gradient_descent(double x[], double y[], double alpha, int iter, double *J, int m);//梯度下降
};


#endif // !LINEARREGRESSION_H



