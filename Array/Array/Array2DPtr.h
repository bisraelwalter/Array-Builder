#pragma once
#ifndef ARRAY2DPTR_H
#define ARRAY2DPTR_H
#include <iostream>


#endif
using namespace std;

template<class T>
class RowPtr;

template <class T>
class Array2DPtr
{
private:
	T** m_array;
	int m_row;
	int m_col;

public:
	Array2DPtr();
	Array2DPtr(int row, int col);
	Array2DPtr(const Array2DPtr & copy);
	~Array2DPtr();
	Array2DPtr &operator=(const Array2DPtr & rhs);
	RowPtr<T> operator[](int index);
	int getRow() const;
	void setRow(int rows);
	int getColumn() const;
	void setColumn(int columns);
	T & Select(int row, int column);
};

template<class T>
inline Array2DPtr<T>::Array2DPtr()
{
	cout << "Constructor called" << endl;
	this->m_row = 0;
	this->m_col = 0;
	m_array = new T*[this->m_row];
	for (int i = 0; i < this->m_row; i++)
		m_array[i] = new T[this->m_col];
}

template<class T>
inline Array2DPtr<T>::Array2DPtr(int row, int col)
{
	cout << "Parameter Constructor called " << endl;
	this->m_row = row;
	this->m_col = col;
	m_array = new T*[row];
	for (int i = 0; i < row; i++)
		m_array[i] = new T[col];
}

template<class T>
inline Array2DPtr<T>::Array2DPtr(const Array2DPtr & copy)
{
	this->m_row = copy.m_row;
	this->m_col = copy.m_col;

	if (copy.m_array)
	{
		for (int i = 0; i < this->m_row; i++)
		{
			for (int j = 0; j < this->m_col; j++)
				this->m_array[i][j] = copy.m_array[i][j];
		}
	}
}



template<class T>
inline Array2DPtr<T>::~Array2DPtr()
{
	cout << "Deconstructor called" << endl;
	for (int i = 0; i < this->m_row; i++)
		delete[] m_array[i];

	delete[]  m_array;

}

template<class T>
inline Array2DPtr<T>& Array2DPtr<T>::operator=(const Array2DPtr& rhs)
{
	if (this == &rhs)
		return *this;

	for (int i = 0; i < this->m_row; i++)
		delete[] m_array[i];

	delete[]  m_array;

	this->m_row = rhs.m_row;
	this->m_col = rhs.m_col;

	m_array = new T*[this->m_row];
	for (int i = 0; i < this->m_row; i++)
		m_array[i] = new T[this->m_col];

	for (int i = 0; i < this->m_row; i++)
	{
		for (int j = 0; j < this->m_row; j++)
			this->m_array[i][j] = rhs.m_array[i][j];
	}

	return *this;
}

template<class T>
inline RowPtr<T> Array2DPtr<T>::operator[](int index)
{
	if (index < 0)
		throw Exception("cannot be less than zero");
	if (index > this->m_row - 1)
		throw Exception("cannot be greater than the size of the array");

	return RowPtr<T>(*this, index);
}

template<class T>
inline int Array2DPtr<T>::getRow() const
{
	return this->m_row;
}

template<class T>
inline void Array2DPtr<T>::setRow(int rows)
{
	T** Temp = new T*[rows];
	for (int i = 0; i < rows; i++)
		Temp[i] = new T[this->m_col];

	for (int i = 0; i < this->m_row; i++)
		delete[] m_array[i];

	delete[]  m_array;

	m_array = new T*[rows];
	for (int i = 0; i < rows; i++)
		m_array[i] = new T[this->m_col];

	this->m_row = rows;

	for (int i = 0; i < this->m_row; i++)
	{
		for (int j = 0; j < this->m_col; j++)
			this->m_array[i][j] = Temp[i][j];
	}

	for (int i = 0; i < this->m_row; i++)
		delete[] Temp[i];

	delete[] Temp;
}


template<class T>
inline int Array2DPtr<T>::getColumn() const
{
	return this->m_col;
}

template<class T>
inline void Array2DPtr<T>::setColumn(int columns)
{
	T** Temp = new T*[this->m_row];
	for (int i = 0; i < this->m_row; i++)
		Temp[i] = new T[columns];

	for (int i = 0; i < this->m_row; i++)
		delete[] m_array[i];

	delete[]  m_array;

	m_array = new T*[this->m_row];
	for (int i = 0; i < this->m_row; i++)
		m_array[i] = new T[columns];

	this->m_col = columns;

	for (int i = 0; i < this->m_row; i++)
	{
		for (int j = 0; j < this->m_col; j++)
			this->m_array[i][j] = Temp[i][j];
	}

	for (int i = 0; i < this->m_row; i++)
		delete[] Temp[i];

	delete[] Temp;
}

template<class T>
inline T & Array2DPtr<T>::Select(int row, int column)
{

	return m_array[row][column];

}
