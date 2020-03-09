////First try.Ranable,but not cpp-like,and isnt standard.
//
//
//#include <iostream>
//#include <vector>
//#include <math.h>
//
//using namespace std;
//
//class Mat
//{
//private:
//	vector<vector<double>> matrix;
//	int row;
//	int col;
//
//public:
//	Mat(int a) :row(a) {};
//	Mat(int a, int b) { row = a; col = b; }
//	int getRow() { return row; }
//	int getCol() { return col; }
//	void setEle(vector<vector<double>> x);
//	vector<vector<double>> getEle(){return matrix; }
//};
//
//void Mat::setEle(vector<vector<double>> x)
//{
//	row = x.size(); col = x[0].size();
//	for (int i = 0; i < x.size(); i++) {
//		for (int j = 0; j < x[0].size(); j++) {
//			matrix[i][j] = x[i][j];
//		}
//	}
//}
//
//
//vector<double> predict(vector<double> theta, vector<vector<double>> x)
//{
//	int s = x.size();
//	vector<double> p;
//	for (int i = 0; i < s; i++) {
//		p.emplace_back(theta[0] * x[i][0]);
//	}
//	cout << p.size();
//	return p;
//}
//
//vector<vector<double>> transpose(vector<vector<double>> x)
//{
//	vector<vector<double>> temp;
//	temp.reserve(5);
//	temp.resize(1, vector<double>(5));
//	for (int i = 0; i < x.size(); i++) {
//		for (int j = 0; j < x[0].size(); j++) {
//			temp[j][i] = x[i][j];
//		}
//	}
//	return temp;
//}
//
//vector<double> matminus(vector<double> x, vector<double> y)
//{
//	vector<double> temp;
//	for (int i = 0; i < x.size(); i++) {
//		temp.emplace_back((x.at(i) - y.at(i)));
//	}
//	return temp;
//}
//
//
//
//int main()
//{
//	vector<vector<double>> x{ {1},{2},{3},{4},{5} };
//	vector<double> y{ 2, 4, 6, 8, 10 };
//	vector<double> theta{ 1 };
//	int iteration = 50;
//	double res = 0;
//	double alpha = 0.05;
//
//	for (int iter = 0; iter < iteration; iter++) {
//		vector<double> temp;
//		temp = matminus(predict(theta, x), y);
//		
//		for (int i = 0; i < temp.size(); i++) {
//			res += (temp.at(i) * temp.at(i));
//		}
//		
//		double cost = res / (2*x.size());
//		cout << "iter:" << iter << " " << "cost:" << cost << endl;
//		res = 0;
//		
//		vector<double> diff_temp{ 0 };
//		vector<double> xt{1,2,3,4,5};
//		
//		for (int i = 0; i < xt.size(); i++) {
//			diff_temp[0] += xt[i] * temp[i];
//		}
//
//		//cout << diff_temp[0];
//		
//		//cout << " "<<diff_temp.size()<<endl;
//		for (int i = 0; i < diff_temp.size(); i++) {
//			diff_temp.at(i) *= alpha;
//			diff_temp.at(i) /= x.size();
//			theta.at(i) -= diff_temp.at(i);
//			//cout << theta.at(i);
//		}	
//	}
//
//	for (auto c : theta) {
//		cout << c << endl;
//	}
//	system("pause");
//}


//Version 2.0 with Matrix class

#include <iostream>
#include <vector>
#include <math.h>
#include "Matrix.h"

using namespace std;

//class Complex
//{
//public:
//	Complex() { real = 0; imag = 0; }
//	Complex(double r, double i) { real = r; imag = i; }
//	virtual ~Complex();
//	Complex operator+(Complex &c2); //声明重载运算符“+”的函数
//	void display();
//private:
//	double real;
//	double imag;
//};
//
//Complex::~Complex()
//{
//	cout << "des" << real << "+" << imag <<endl;
//}
//
//Complex Complex::operator+(Complex &c2) //定义重载运算符“+”的函数，返回类型是Complex，复数
//{
//	Complex c;
//	c.real = real + c2.real;
//	c.imag = imag + c2.imag;
//	return c;
//}
////可以一起写成：
////{return Complex(real+c2.real,imag+c2.imag);}
////这里建立了一个临时对象，没有对象名。
//
//void Complex::display()
//{
//	cout << "(" << real << "," << imag << "i)" << endl;
//}

int main()
{
	//求解线性方程AX=y
	//通过梯度下降
	/*int samp_num = 5;
	int fea_num = 1;
	int iteration = 50;
	double res = 0;
	double alpha = 0.05;
	
	Matrix x(samp_num, fea_num);
	Matrix y(samp_num, 1);
	//Matrix theta(fea_num, 1, 1);

	cin >> x;
	cin >> y;

	Matrix theta = Matrix::Solve(x, y);
	theta.Show();*/
	


	//最小二乘拟合多项式
	//过原点的一次式
	/*int samp_num = 5;
	int fea_num = 1;
	double res = 0;
	
	Matrix x(samp_num, fea_num);
	Matrix y(samp_num, 1);
	
	cin >> x;
	cin >> y;
	
	Matrix theta = Matrix::inv(Matrix::T(x)*x)*Matrix::T(x)*y;
	theta.Show();*/


	//加bias
	int samp_num = 5;
	int fea_num = 1;
	double res = 0;

	Matrix x(samp_num, fea_num + 1);
	Matrix y(samp_num, 1);

	cin >> x;
	cin >> y;
	Matrix theta = Matrix::inv(Matrix::T(x)*x)*Matrix::T(x)*y;
	theta.Show();


	return 0;
}












