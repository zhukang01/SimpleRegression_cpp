//————————————————
//版权声明：本文为CSDN博主「cclplus」的原创文章，遵循 CC 4.0 BY - SA 版权协议，转载请附上原文出处链接及本声明。
//原文链接：https ://blog.csdn.net/m0_37772174/article/details/83018940
#include "pch.h"
#include "Matrix.h"
#include<math.h>

using std::endl;
using std::cout;
using std::istream;
const double EPS = 1e-10;

void Matrix::initialize() //初始化矩阵大小	
{
	//new一个存放double型指针的数组空间，存行数个，指针赋给p
	//p = new double* [rows_num];
	//for (int i = 0; i < rows_num; i++) {
	//	//数组的每个指针，指向new出来的一个大小为列数的数组
	//	p[i] = new double[cols_num];//为p[i]进行动态内存分配，大小为cols	
	//}
	p.resize(rows_num, std::vector<double>(cols_num));
}

//全为0的矩阵
Matrix::Matrix(int a, int b)
{
 	rows_num = a;
	cols_num = b;
	initialize();
	for (int i = 0; i < rows_num; i++) {
		for (int j = 0; j < cols_num; j++) {
			p[i][j] = 0;
		}
	}
}

//值全为value的矩阵
Matrix::Matrix(int a, int b, double value)
{

	rows_num = a;
	cols_num = b;
	initialize();
	for (int i = 0; i < rows_num; i++) {
		for (int j = 0; j < cols_num; j++) {
			p[i][j] = value;
		}
	}
}

//析构函数
Matrix::~Matrix()
{
	//cout << "Desturct this matrix:" << endl;
	//this->Show();
	
	//for (int i = 0; i < rows_num; i++) {
	//	delete[] p[i];
	//}
	//delete p;
}

//矩阵复制
Matrix& Matrix::operator=(const Matrix& m)
{
	//cout << &m;
	if (this == &m) { return *this; }
	if (rows_num != m.rows_num || cols_num != m.cols_num) {
		/*for (int i = 0; i < cols_num; i++) {
			delete[] p[i];
		}
		delete p;*/

		rows_num = m.rows_num;
		cols_num = m.cols_num;
		initialize();
	}

	for (int i = 0; i < rows_num; i++) {
		for (int j = 0; j < cols_num; j++) {
			p[i][j] = m.p[i][j];
		}
	}

	//cout << this << endl;
	return *this;

}

//将数组的值传给matrix（要求矩阵大小已经声明
Matrix& Matrix::operator=(double* a)
{
	for (int i = 0; i < rows_num; i++) {
		for (int j = 0; j < cols_num; j++) {
			p[i][j] = *(a + i * cols_num + j);
		}
	}
	return *this;
}

//+=
Matrix& Matrix::operator+=(const Matrix& m)
{
	for (int i = 0; i < rows_num; i++) {
		for (int j = 0; j < cols_num; j++) {
			p[i][j] += m.p[i][j];
		}
	}
	return *this;
}

//-=
Matrix& Matrix::operator-=(const Matrix& m)
{
	for (int i = 0; i < rows_num; i++) {
		for (int j = 0; j < cols_num; j++) {
			p[i][j] -= m.p[i][j];
		}
	}
	return *this;
}

//*=,点乘
Matrix& Matrix::operator*=(const Matrix& m)
{
	for (int i = 0; i < rows_num; i++) {
		for (int j = 0; j < cols_num; j++) {
			p[i][j] *= m.p[i][j];
		}
	}
	return *this;
}

///=，点除
Matrix& Matrix::operator/=(const Matrix& m)
{
	for (int i = 0; i < rows_num; i++) {
		for (int j = 0; j < cols_num; j++) {
			p[i][j] /= m.p[i][j];
		}
	}
	return *this;
}

Matrix& Matrix::operator/=(const double x)
{
	for (int i = 0; i < rows_num; i++) {
		for (int j = 0; j < cols_num; j++) {
			p[i][j] /= x;
		}
	}
	return *this;
}

//矩阵乘法
Matrix Matrix::operator*(const Matrix& m)const
{
	//cout<<&m;
	Matrix temp(rows_num, m.cols_num, 0.0);
	for (int i = 0; i < rows_num; i++) {
		for (int j = 0; j < m.cols_num; j++) {
			for (int k = 0; k < cols_num; k++) {
				temp.p[i][j] += (p[i][k]) * m.p[k][j];
			}
		}
	}
	//cout << &temp << endl;;
	//temp.Show();
	return temp;
}

//求解线性方程组Ax=b
Matrix Matrix::Solve(const Matrix& A, const Matrix& b)
{
	Matrix theta(A.cols_num, 1);
	int iteration = 300;
	double alpha = 0.005;

	for (int iter = 0; iter < iteration; iter++) {

		Matrix temp = (A*theta - b);
		Matrix tempt = Matrix::T(temp);

		double cost = (tempt * temp).Point(0, 0);
		cost /= (2 * A.rows_num);

		cout << "iter:" << iter << " " << "cost:" << cost << endl;
		cost = 0;

		Matrix xt = Matrix::T(A);
		Matrix diff = xt * temp;

		diff /= (A.rows_num / alpha);
		theta -= diff;

	}
	return theta;
}


//矩阵显示
void Matrix::Show()const
{
	for (int i = 0; i < rows_num; i++) {
		for (int j = 0; j < cols_num; j++) {
			cout << p[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

//行变换,输入从0开始
void Matrix::swapRows(int a, int b)
{
	std::vector<double> temp = p[a];
	p[a] = p[b];
	p[b] = temp;
}

//取某一点值
double Matrix::Point(int a,int b)const
{
	return this->p[a][b];
}

//求逆矩阵
//A前提为方针
Matrix Matrix::inv(Matrix A)
{
	//高斯消元求逆
	const double eps = 1e-6;
	int dim = A.rows_num;
	Matrix temp(2 * dim, 2 * dim);
	for (int i = 0; i < dim; i++) {
		for (int j = 0; j < 2 * dim; j++) {
			if (j < dim)
			{
				temp.p[i][j] = A.p[i][j];
			}
			else
			{
				temp.p[i][j] = j - dim == i ? 1 : 0;
			}
		}
	}

	for (int i = 0; i < dim; i++)
	{
		if (abs(temp.p[i][i]) < eps)//若mat[i,i]为0，则往下找一个不为0的行，加到第i行
		{
			int j;
			for (j = i + 1; j < dim; j++)
			{
				if (abs(temp.p[j][i]) > eps) break;
			}
			//if (j == dim) return temp;
			for (int r = i; r < 2 * dim; r++)
			{
				temp.p[i][r] += temp.p[j][r];
			}
		}
		double ep = temp.p[i][i];
		//将temp[i,i]变为1
		for (int r = i; r < 2 * dim; r++)
		{
			temp.p[i][r] /= ep;
		}

		for (int j = i + 1; j < dim; j++)
		{
			double e = -1 * (temp.p[j][i] / temp.p[i][i]);
			for (int r = i; r < 2 * dim; r++)
			{
				temp.p[j][r] += e * temp.p[i][r];
			}
		}
	}

	for (int i = dim - 1; i >= 0; i--)
	{
		for (int j = i - 1; j >= 0; j--)
		{
			double e = -1 * (temp.p[j][i] / temp.p[i][i]);
			for (int r = i; r < 2 * dim; r++)
			{
				temp.p[j][r] += e * temp.p[i][r];
			}
		}
	}

	Matrix result(dim, dim);
	for (int i = 0; i < dim; i++)
	{
		for (int r = dim; r < 2 * dim; r++)
		{
			result.p[i][r - dim] = temp.p[i][r];
		}
	}
	return result;

}

//单位矩阵
Matrix Matrix::eye(int a)
{
	Matrix temp(a, a, 0.0);
	for (int i = 0; i < temp.rows_num; i++) {
		for (int j = 0; j < temp.cols_num; j++) {
			if (i == j)temp.p[i][j] = 1;
		}
	}
	return temp;
}

//读取行数
int Matrix::row()const
{
	return rows_num;
}

//读取列数
int Matrix::col()const
{
	return cols_num;
}

//矩阵转置
Matrix Matrix::T(const Matrix& m)
{
	int size_x = m.rows_num;
	int size_y = m.cols_num;
	Matrix temp(size_y, size_x);
	for (int i = 0; i < size_y; i++) {
		for (int j = 0; j < size_x; j++) {
			temp.p[i][j] = m.p[j][i];
		}
	}
	return temp;
}


//矩阵的输入
istream& operator>>(std::istream& x, Matrix& m)
{
	for (int i = 0; i < m.rows_num; i++) {
		for (int j = 0; j < m.cols_num; j++) {
			cout << "The matrix's size is " << m.rows_num << "*" << m.cols_num << endl;
			cout << "Please enter the data for [" << i << "]" << "[" << j << "]" << endl;
			x >> m.p[i][j];
		}
	}
	return x;
}

////矩阵乘法
//Matrix operator* (const Matrix& x, const Matrix& y)
//{
//	Matrix temp(x.rows_num, y.cols_num, 0.0);
//	for (int i = 0; i < x.rows_num; i++) {
//		for (int j = 0; j < y.cols_num; j++) {
//			for (int k = 0; k < x.cols_num; k++) {
//				temp.p[i][j] += (x.p[i][k]) * y.p[k][j];
//			}
//		}
//	}
//	cout << &temp;
//	return temp;
//}

//矩阵减法
Matrix operator-(const Matrix& x, const Matrix& y)
{
	Matrix temp(x.rows_num, y.cols_num, 0.0);
	for (int i = 0; i < x.rows_num; i++) {
		for (int j = 0; j < y.cols_num; j++) {
			temp.p[i][j] = x.p[i][j] - y.p[i][j];
		}
	}

	return temp;
}

//清零
void Matrix::clear()
{
	for (int i = 0; i < rows_num; i++) {
		for (int j = 0; j < cols_num; j++) {
			p[i][j] = 0;
		}
	}
}

Matrix Matrix::augmentM(const Matrix& x)
{
	Matrix temp(x.rows_num, x.cols_num + 1);

	return temp;
}












	