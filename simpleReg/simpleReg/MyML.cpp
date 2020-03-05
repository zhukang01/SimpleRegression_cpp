#include <iostream>
#include <vector>

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
		p.emplace_back(theta[0] * x[i][0] + theta[1] * x[i][1] + theta[2] * x[i][2]);
	}

	return p;
}

vector<vector<double>> transpose(vector<vector<double>> x)
{
	vector<vector<double>> temp;
	temp.reserve(15);
	temp.resize(3, vector<double>(5));
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
		temp.emplace_back(x.at(i) - y.at(i));
	}
	return temp;
}


int main()
{
	vector<vector<double>> x{ {0.5,1,1.5},{2,2.5,3},{3.5,4,4.5},{5,5.5,6},{6.5,7,7.5} };
	vector<double> y{ 1, 2, 3, 4, 5 };
	vector<double> theta{ 1,1,1 };
	int iteration = 10;
	int res = 0;
	double alpha = 0.0005;

	for (int iter = 0; iter < iteration; iter++) {
		vector<double> temp = matminus(predict(theta, x), y);
		for (int i = 0; i < temp.size(); i++) {
			res += temp.at(i) * temp.at(i);
		}
		double cost = res / 10;
		cout << "iter:" << iter << " " << "cost:" << cost << endl;

		vector<double> diff_temp = predict(temp, transpose(x));
		for (int i = 0; i < diff_temp.size(); i++) {
			diff_temp.at(i) *= alpha;
			theta.at(i) -= diff_temp.at(i);
		}	
	}

	for (auto c : theta) {
		cout << c << endl;
	}
	system("pause");
}

