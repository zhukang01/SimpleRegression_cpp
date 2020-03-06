#pragma once

#include "pch.h"

class Matrix
{
private:
	int rows_num, cols_num;
	double** p;
	void initialize();

public:
	Matrix(int, int);	
	Matrix(int, int, double);//Ԥ��ֿռ�	
	virtual ~Matrix();//��������Ӧ�����麯�������Ǵ��಻��������	
	Matrix& operator=(const Matrix&);//����ĸ���	
	Matrix& operator=(double *);//�������ֵ��������	
	Matrix& operator+=(const Matrix&);//�����+=����	
	Matrix& operator-=(const Matrix&);// -=	
	Matrix& operator*=(const Matrix&);// *=	
	Matrix& operator/=(const Matrix&);// /=
	Matrix operator*(const Matrix & m)const;	
	static Matrix Solve(const Matrix&, const Matrix&);//������Է�����Ax=b	
	void Show() const;//������ʾ	
	void swapRows(int, int);//�б任	
	double det();//����������ʽ	
	double Point(int i, int j) const;	
	static Matrix inv(Matrix);//�����������	
	static Matrix eye(int );//����һ����λ����	
	int row() const;	
	int col() const;	
	static Matrix T(const Matrix & m);//����ת�õ�ʵ��,�Ҳ��ı����	
	Matrix gaussianEliminate();//��˹��Ԫ��	
	friend std::istream& operator>>(std::istream&, Matrix&);//ʵ�־��������

};


