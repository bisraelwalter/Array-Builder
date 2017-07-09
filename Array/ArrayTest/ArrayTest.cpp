//****Brandon Walter*****
#define _CRTDBG_MAP_ALLOC
#include <Array.h>
#include <iostream>
#include <stdlib.h>
#include <crtdbg.h>
#include <iomanip>
#include <Array2D.h>
#include <Row.h>
#include <Array2DPtr.h>
#include <RowPtr.h>

using namespace std;

void Array2DPtrOutOfBoundsTester();
void Array2DPtrOverloadEqualsTester();
void Array2DPtrSetColumnTester();
void Array2DPtrSetRowTester();
void Array2DPtrTester();
void Array2dOutOfBoundsTester();
void Array2DoverloadEqualsTester();
void Array2DsetColumnTester();
void Array2DsetRowTester();
void Array2DTester();
void ArrayOutOfBoundsTester();
void ArrayOverloadEqualTester();
void ArraySetStartIndexToDifferentNumberTester();
void ResizeArrayTester();
void LoadIntData(Array<int> & data, int start);
void PrintIntData(Array<int> & data);
void LoadIntData(Array2D<int> & data);
void PrintIntData(Array2D<int> & data);
void LoadIntData(Array2DPtr<int> & data);
void PrintIntData(Array2DPtr<int> & data);

int main()
{
	
	try
	{
		//Array2DPtrOutOfBoundsTester();
		//Array2DPtrOverloadEqualsTester();
		//Array2DPtrSetColumnTester();
		//Array2DPtrSetRowTester();
		//Array2DPtrTester();
		//Array2dOutOfBoundsTester();
		//Array2DoverloadEqualsTester();
		//Array2DsetColumnTester();
		//Array2DsetRowTester();
		//Array2DTester();
		//ArrayOutOfBoundsTester();
		//ArrayOverloadEqualTester();
		//ArraySetStartIndexToDifferentNumberTester();
		//ResizeArrayTester();
	}
	catch(Exception &ex)
	{
		cerr << "Exception thrown: Error - " << ex.getMessage() << endl;
	}

	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDOUT);
	_CrtDumpMemoryLeaks();

	return 0;
}

void Array2DPtrOutOfBoundsTester()
{
	cout << "Array2D double pointer set up test" << endl;
	cout << "Array2D with double pointer" << endl;
	Array2DPtr<int> arrptr(2, 2);
	LoadIntData(arrptr);
	cout << "Trying to access out of bounds" << endl;
	arrptr[1][-3];
}

void Array2DPtrOverloadEqualsTester()
{
	cout << "Array2D overload= test" << endl;
	cout << "2D Array" << endl;
	Array2DPtr<int> twoDarray(3, 3);
	LoadIntData(twoDarray);
	PrintIntData(twoDarray);
	cout << "Second 2D Array" << endl;
	Array2DPtr<int> twoDarray2(5, 5);
	LoadIntData(twoDarray2);
	PrintIntData(twoDarray2);
	cout << "Second 2D Array copied into the first 2D Array" << endl;
	twoDarray = twoDarray2;
	PrintIntData(twoDarray);
}

void Array2DPtrSetColumnTester()
{
	cout << "Array2D double pointer reset column size test" << endl;
	cout << "Array2D with double pointer" << endl;
	Array2DPtr<int> arrptr(5, 5);
	LoadIntData(arrptr);
	PrintIntData(arrptr);
	arrptr.setColumn(2);
	cout << "Array2D with double pointer, column size is reset" << endl;
	LoadIntData(arrptr);
	PrintIntData(arrptr);
}

void Array2DPtrSetRowTester()
{
	cout << "Array2D double pointer reset row size test" << endl;
	cout << "Array 2D with double pointer" << endl;
	Array2DPtr<int> arrptr(5, 5);
	LoadIntData(arrptr);
	PrintIntData(arrptr);
	arrptr.setRow(8);
	cout << "Array2D with double pointer, row size is reset" << endl;
	LoadIntData(arrptr);
	PrintIntData(arrptr);
}

void Array2DPtrTester()
{
	cout << "Array2D double pointer set up test" << endl;
	cout << "Array2D with double pointer" << endl;
	Array2DPtr<int> arrptr(4, 6);
	LoadIntData(arrptr);
	PrintIntData(arrptr);
}

void Array2dOutOfBoundsTester()
{
	cout << "Array2D out of bounds test" << endl;
	cout << "2D Array" << endl;
	Array2D<int> twoDarray(3, 3);
	LoadIntData(twoDarray);
	cout << "Trying to access out of bounds" << endl;
	twoDarray[4][3];
}

void Array2DoverloadEqualsTester()
{
	cout << "Array2D overload= test" << endl;
	cout << "2D Array" << endl;
	Array2D<int> twoDarray(3, 3);
	LoadIntData(twoDarray);
	PrintIntData(twoDarray);
	cout << "Second 2D Array" << endl;
	Array2D<int> twoDarray2(5, 5);
	LoadIntData(twoDarray2);
	PrintIntData(twoDarray2);
	cout << "Second 2D Array copied into the first 2D Array" << endl;
	twoDarray = twoDarray2;
	PrintIntData(twoDarray);
}

void Array2DsetColumnTester()
{
	cout << "Array2D reset column size test" << endl;
	cout << "2D Array" << endl;
	Array2D<int> twoDarray(3, 3);
	LoadIntData(twoDarray);
	PrintIntData(twoDarray);
	cout << "Resized column of 2D array" << endl;
	twoDarray.setColumn(8);
	LoadIntData(twoDarray);
	PrintIntData(twoDarray);
}

void Array2DsetRowTester()
{
	cout << "Array2D reset row size test" << endl;
	cout << "2D Array" << endl;
	Array2D<int> twoDarray(3, 3);
	LoadIntData(twoDarray);
	PrintIntData(twoDarray);
	cout << "Resized row of 2D Array" << endl;
	twoDarray.setRow(8);
	LoadIntData(twoDarray);
	PrintIntData(twoDarray);
}

void Array2DTester()
{
	cout << "Array2D set up test" << endl;
	cout << "2D Array" << endl;
	Array2D<int> twoDarray(3, 3);
	LoadIntData(twoDarray);
	PrintIntData(twoDarray);
}

void ArrayOutOfBoundsTester()
{
	cout << "Array out of bounds test" << endl;
	cout << "Instantiating and filling and Array with 10 numbers" << endl;
	Array<int> firstArray(10);
	LoadIntData(firstArray, 1);
	cout << "Trying to access out of bounds" << endl;
	cout << firstArray[-2];
}

void ArrayOverloadEqualTester()
{
	cout << "Overload= Test" << endl;
	cout << "First Array" << endl;
	Array<int> firstArray(10);
	LoadIntData(firstArray, 1);
	PrintIntData(firstArray);
	cout << "Second Array" << endl;
	Array<int> secondArray(8);
	LoadIntData(secondArray, 4);
	PrintIntData(secondArray);
	cout << "Copied second array into the first array" << endl;
	firstArray = secondArray;
	PrintIntData(firstArray);

}

void ArraySetStartIndexToDifferentNumberTester()
{
	cout << "Setting array to a different starting index" << endl;
	cout << "Instantiating and filling and Array with 10 numbers" << endl;
	Array<int> firstArray(10);
	LoadIntData(firstArray, 1);
	PrintIntData(firstArray);
	firstArray.setStartIndex(6);
	cout << "Array with different starting index" << endl;
	PrintIntData(firstArray);

}

void ResizeArrayTester()
{
	cout << "Array resizing test" << endl;
	cout << "Instantiating and filling and Array with 10 numbers" << endl;
	Array<int> firstArray(10);
	LoadIntData(firstArray, 1);
	PrintIntData(firstArray);
	cout << "Resized array" << endl;
	firstArray.setLength(15);
	PrintIntData(firstArray);
}

void LoadIntData(Array<int>& data, int start)
{
	for (int i = 0; i < data.getLength(); i++)
		data[i] = start + i;
}

void PrintIntData(Array<int>& data)
{
	for (int i = 0; i < data.getLength(); i++)
		cout << "[" << data.getStartIndex() + i << "]" << data[i] << endl;
}

void LoadIntData(Array2D<int>& data)
{
	for (int i = 0; i < data.getRow(); i++)
	{
		for (int j = 0; j < data.getColumn(); j++)
			data[i][j] = (i * j) + i + j;
	}
}

void PrintIntData(Array2D<int>& data)
{
	for (int i = 0; i < data.getRow(); i++)
	{
		for (int j = 0; j < data.getColumn(); j++)
			cout << setw(4) << data[i][j];
		cout << endl;
	}
}

void LoadIntData(Array2DPtr<int>& data)
{
	for (int i = 0; i < data.getRow(); i++)
	{
		for (int j = 0; j < data.getColumn(); j++)
			data[i][j] = (i * j) + i + j;
	}
}

void PrintIntData(Array2DPtr<int>& data)
{
	for (int i = 0; i < data.getRow(); i++)
	{
		for (int j = 0; j < data.getColumn(); j++)
			cout << setw(4) << data[i][j];
		cout << endl;
	}
}









