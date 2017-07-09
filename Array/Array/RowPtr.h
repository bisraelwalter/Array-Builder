//****Brandon Walter*****
#ifndef ROWPTR_H
#define ROWPTR_H
#include "Exception.h"


template <class T>
class Array2DPtr;

template <class T>
class RowPtr
{
private:
	Array2DPtr<T> &m_array;
	int m_row;

public:
	RowPtr(Array2DPtr<T> &array, int row);
	T &operator[](int column);
};


#endif

template<class T>
inline RowPtr<T>::RowPtr(Array2DPtr<T>& array, int row) : m_array(array), m_row(row) {}


template<class T>
inline T & RowPtr<T>::operator[](int column)
{
	if (column < 0)
		throw Exception("Column cannot be less than zero");
	if (column > m_array.getColumn() - 1)
		throw Exception("Cannot be greater than size of array");

	return this->m_array.Select(m_row, column);
}
