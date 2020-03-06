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

int main()
{
	Matrix A = Matrix(3, 3);
	std::cin >> A;
	Matrix b = Matrix(3, 1);
	std::cin >> b;
	Matrix c = Matrix(1, 3, 1);
	A.Show();
	b.Show();
	c.Show();

	return 0;
}












