//��������������������������������
//��Ȩ����������ΪCSDN������cclplus����ԭ�����£���ѭ CC 4.0 BY - SA ��ȨЭ�飬ת���븽��ԭ�ĳ������Ӽ���������
//ԭ�����ӣ�https ://blog.csdn.net/m0_37772174/article/details/83018940
#include "pch.h"
#include "Matrix.h"

using std::endl;
using std::cout;
using std::istream;
const double EPS = 1e-10;

void Matrix::initialize() //��ʼ�������С	
{
	//newһ�����double��ָ�������ռ䣬����������ָ�븳��p
	p = new double*[rows_num];
	for (int i = 0; i < rows_num; ++i) {
		//�����ÿ��ָ�룬ָ��new������һ����СΪ����������
		p[i] = new double[cols_num];//Ϊp[i]���ж�̬�ڴ���䣬��СΪcols	
	}
}

//ȫΪ0�ľ���
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

//ֵȫΪvalue�ľ���
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

//��������
Matrix::~Matrix()
{
	for (int i = 0; i < rows_num; i++) {
		delete[] p[i];
	}
	delete p;
}

//������
Matrix& Matrix::operator=(const Matrix& m)
{
	if (this == &m) { return *this; }
	if (rows_num != m.rows_num || cols_num != m.cols_num) {
		for (int i = 0; i < cols_num; i++) {
			delete[] p[i];
		}
		delete p;

		rows_num = m.rows_num;
		cols_num = m.cols_num;
		initialize();
	}

	for (int i = 0; i < rows_num; i++) {
		for (int j = 0; j < cols_num; j++) {
			p[i][j] = m.p[i][j];
		}
	}

	return *this;

}

//�������ֵ����matrix��Ҫ������С�Ѿ�����
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

//*=,���
Matrix& Matrix::operator*=(const Matrix& m)
{
	for (int i = 0; i < rows_num; i++) {
		for (int j = 0; j < cols_num; j++) {
			p[i][j] *= m.p[i][j];
		}
	}
	return *this;
}

///=�����
Matrix& Matrix::operator/=(const Matrix& m)
{
	for (int i = 0; i < rows_num; i++) {
		for (int j = 0; j < cols_num; j++) {
			p[i][j] /= m.p[i][j];
		}
	}
	return *this;
}

//����˷�
Matrix Matrix::operator*(const Matrix & m)const
{
	Matrix temp(rows_num, m.cols_num, 0.0);
	for (int i = 0; i < rows_num; i++) {
		for (int j = 0; j < m.cols_num; j++) {
			for (int k = 0; k < cols_num; k++) {
				temp.p[i][j] += (p[i][k]) * m.p[k][j];
			}
		}
	}
	return temp;
}

//������Է�����
//�ݲ�����
/*Matrix Matrix::Solve(const Matrix& a, const Matrix& b)
{
	return a;
}*/


//������ʾ
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

//�б任,�����0��ʼ
void Matrix::swapRows(int a, int b)
{
	double* temp = p[a];
	p[a] = p[b];
	p[b] = temp;
}

//������ʽ
//�ݲ�����
/*double Matrix::det()
{

}*/

//ȡĳһ��ֵ
double Matrix::Point(int a,int b)const
{
	return this->p[a][b];
}

//�������
//�ݲ�����
/*Matrix Matrix::inv(Matrix A)
{

}*/

//��λ����
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

//��ȡ����
int Matrix::row()const
{
	return rows_num;
}

//��ȡ����
int Matrix::col()const
{
	return cols_num;
}

//����ת��
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

//��˹��Ԫ
//�ݲ�����
/*
Matrix Matrix::gaussianEliminate()
{
	
}
*/

//���������
istream& operator>>(std::istream& x, Matrix& m)
{
	for (int i = 0; i < m.rows_num; i++) {
		for (int j = 0; j < m.cols_num; j++) {
			x >> m.p[i][j];
		}
	}
	return x;
}














	