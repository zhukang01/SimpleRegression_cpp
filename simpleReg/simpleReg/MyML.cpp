#include <iostream>
#include <vector>
#include <math.h>

using namespace std;
//const int max_r = 500;
//const int max_c = 500;

//class Matrix
//{
//private:
//	int row;
//	int col;
//	double ele[max_r][max_c];
//
//public:
//	Matrix(int x,int y):row(x),col(y){}
//	Matrix(int x, int y, double a[max_r]) {
//		row = x;
//		col = y;
//		for (int i = 0; i < row; i++) {
//
//		}
//	}
//	int GetRow() { return row; }
//	int GetCol() { return col; }
//	void setElement(int i, int j, double x) { ele[i][j] = x; };
//	double getElement(const int& i, const int& j){ return ele[i][j]; }
//		
//
//	friend Matrix operator + (Matrix& m1, Matrix& m2);
//	friend Matrix operator - (Matrix& m1, Matrix& m2);
//	friend Matrix operator * (Matrix& m1, Matrix& m2);
//	friend Matrix operator / (Matrix& m1, Matrix& m2);
//
//
//};
//
//
//Matrix operator + (Matrix& m1, Matrix& m2)
//{
//	int m1_row = m1.GetRow(), m1_col = m1.GetCol();
//	int m2_row = m2.GetRow(), m2_col = m2.GetCol();
//	if (m1_col != m2_col || m1_row != m2_row) {
//		cout << "Matrix size isn't match!" << endl;
//	}
//	else {
//		Matrix temp(m1_row,m1_col);
//		for (int i = 0; i < m1_row; i++) {
//			for (int j = 0; j < m1.col; j++) {
//				double x = m1.getElement(i, j) + m2.getElement(i, j);
//				temp.setElement(i, j, x);
//			}
//		}
//	}
//	return temp;
//
//}
//
//Matrix operator - (Matrix& m1, Matrix& m2)
//{
//
//}
//
//Matrix operator * (Matrix& m1, Matrix& m2)
//{
//
//}
//
//Matrix operator / (Matrix& m1, Matrix& m2)
//{
//
//}





vector<double> predict(vector<double> theta, vector<vector<double>> x)
{
	int s = x.size();
	vector<double> p;
	for (int i = 0; i < s; i++) {
		p.emplace_back(theta[0] * x[i][0]);
	}
	//cout << p.size();
	return p;
}

vector<vector<double>> transpose(vector<vector<double>> x)
{
	vector<vector<double>> temp;
	temp.reserve(5);
	temp.resize(1, vector<double>(5));
	for (int i = 0; i < x.size(); i++) {
		for (int j = 0; j < x[0].size(); j++) {
			temp[j][i] = x[i][j];
		}
	}
	return temp;
}

vector<double> matminus(vector<double> x, vector<double> y)
{
	vector<double> temp;
	for (int i = 0; i < x.size(); i++) {
		temp.emplace_back((x.at(i) - y.at(i)));
	}
	return temp;
}



int main()
{
	vector<vector<double>> x{ {1},{2},{3},{4},{5} };
	vector<double> y{ 2, 4, 6, 8, 10 };
	vector<double> theta{ 1};
	int iteration = 100;
	double res = 0;
	double alpha = 0.005;

	for (int iter = 0; iter < iteration; iter++) {
		vector<double> temp;
		temp = matminus(predict(theta, x), y);
		
		for (int i = 0; i < temp.size(); i++) {
			res += (temp.at(i) * temp.at(i));
		}
		
		double cost = res / (2*x.size());
		cout << "iter:" << iter << " " << "cost:" << cost << endl;
		res = 0;
		
		vector<double> diff_temp{ 0 };
		vector<double> xt{1,2,3,4,5};
		
		for (int i = 0; i < xt.size(); i++) {
			diff_temp[0] += xt[i] * temp[i];
		}

		//cout << diff_temp[0];
		
		//cout << " "<<diff_temp.size()<<endl;
		for (int i = 0; i < diff_temp.size(); i++) {
			diff_temp.at(i) *= alpha;
			diff_temp.at(i) /= x.size();
			theta.at(i) -= diff_temp.at(i);
			//cout << theta.at(i);
		}	
	}

	for (auto c : theta) {
		cout << c << endl;
	}
	system("pause");
}

