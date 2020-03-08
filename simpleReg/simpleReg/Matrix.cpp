//————————————————
//版权声明：本文为CSDN博主「cclplus」的原创文章，遵循 CC 4.0 BY - SA 版权协议，转载请附上原文出处链接及本声明。
//原文链接：https ://blog.csdn.net/m0_37772174/article/details/83018940
#include "pch.h"
#include "Matrix.h"

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

//求解线性方程组
//暂不定义
//Matrix Matrix::Solve(const Matrix& A, const Matrix& b)
//{
//	//高斯消去法实现Ax=b的方程求解	
//	for (int i = 0; i < A.rows_num; i++) {		
//		if (A.p[i][i] == 0) { 			
//			cout << "请重新输入" << endl;		
//		}		
//		for (int j = i + 1; j < A.rows_num; j++) {			
//			for (int k = i + 1; k < A.cols_num; k++) {				
//				A.p[j][k] -= A.p[i][k] * (A.p[j][i] / A.p[i][i]);				
//				if (abs(A.p[j][k]) < EPS)
//					A.p[j][k] = 0;
//			}			
//			b.p[j][0] -= b.p[i][0] * (A.p[j][i] / A.p[i][i]);			
//			if (abs(A.p[j][0]) < EPS)
//				A.p[j][0] = 0;			
//			A.p[j][i] = 0;		
//		}	
//	} 	
//	// 反向代换	
//	Matrix x(b.rows_num, 1);	
//	x.p[x.rows_num - 1][0] = b.p[x.rows_num - 1][0] / A.p[x.rows_num - 1][x.rows_num - 1];	
//	if (abs(x.p[x.rows_num - 1][0]) < EPS)		
//		x.p[x.rows_num - 1][0] = 0;	
//	for (int i = x.rows_num - 2; i >= 0; i--) {		
//		double sum = 0;		
//		for (int j = i + 1; j < x.rows_num; j++) {			
//			sum += A.p[i][j] * x.p[j][0];		
//		}		
//		x.p[i][0] = (b.p[i][0] - sum) / A.p[i][i];		
//		if (abs(x.p[i][0]) < EPS)			
//			x.p[i][0] = 0;	
//	} 	
//	return x;
//}


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

//求行列式
//暂不定义
/*double Matrix::det()
{

}*/

//取某一点值
double Matrix::Point(int a,int b)const
{
	return this->p[a][b];
}

//求逆矩阵
//暂不定义
/*Matrix Matrix::inv(Matrix A)
{

}*/

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


//高斯消元
//暂不定义
/*
Matrix Matrix::gaussianEliminate()
{
	
}
*/

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












	