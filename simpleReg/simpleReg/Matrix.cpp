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
	//p = new double* [rows_num];
	//for (int i = 0; i < rows_num; i++) {
	//	//�����ÿ��ָ�룬ָ��new������һ����СΪ����������
	//	p[i] = new double[cols_num];//Ϊp[i]���ж�̬�ڴ���䣬��СΪcols	
	//}
	p.resize(rows_num, std::vector<double>(cols_num));
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
	//cout << "Desturct this matrix:" << endl;
	//this->Show();
	
	//for (int i = 0; i < rows_num; i++) {
	//	delete[] p[i];
	//}
	//delete p;
}

//������
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

Matrix& Matrix::operator/=(const double x)
{
	for (int i = 0; i < rows_num; i++) {
		for (int j = 0; j < cols_num; j++) {
			p[i][j] /= x;
		}
	}
	return *this;
}

//����˷�
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

//������Է�����
//�ݲ�����
//Matrix Matrix::Solve(const Matrix& A, const Matrix& b)
//{
//	//��˹��ȥ��ʵ��Ax=b�ķ������	
//	for (int i = 0; i < A.rows_num; i++) {		
//		if (A.p[i][i] == 0) { 			
//			cout << "����������" << endl;		
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
//	// �������	
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
	std::vector<double> temp = p[a];
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
			cout << "The matrix's size is " << m.rows_num << "*" << m.cols_num << endl;
			cout << "Please enter the data for [" << i << "]" << "[" << j << "]" << endl;
			x >> m.p[i][j];
		}
	}
	return x;
}

////����˷�
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

//�������
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

//����
void Matrix::clear()
{
	for (int i = 0; i < rows_num; i++) {
		for (int j = 0; j < cols_num; j++) {
			p[i][j] = 0;
		}
	}
}












	