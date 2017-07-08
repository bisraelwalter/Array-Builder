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

void Array2DPtrSetColumn();
void Array2DPtrSetRow();
void Array2DPtrTester();
void Array2DsetColumnTester();
void Array2DsetRowTester();
void Array2DTester();
void overloadEqualTest();
void setStartIndexToDifferentNumberTest();
void ResizeArrayTest();
void LoadIntData(Array2D<int> & data);
void PrintIntData(Array2D<int> & data);
void LoadIntData(Array2DPtr<int> & data);
void PrintIntData(Array2DPtr<int> & data);

int main()
{
	
	try
	{
		Array2DPtrSetColumn();
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

void Array2DPtrSetColumn()
{
	Array2DPtr<int> arrptr(5, 5);
	arrptr.setColumn(2);
	LoadIntData(arrptr);
	PrintIntData(arrptr);
}

void Array2DPtrSetRow()
{
	Array2DPtr<int> arrptr(2, 2);
	arrptr.setRow(8);
	LoadIntData(arrptr);
	PrintIntData(arrptr);
}

void Array2DPtrTester()
{
	Array2DPtr<int> arrptr(2, 2);
	LoadIntData(arrptr);
	PrintIntData(arrptr);
}

void Array2DsetColumnTester()
{
	cout << "2D Array" << endl;
	Array2D<int> twoDarray(3, 3);
	twoDarray.setColumn(8);
	LoadIntData(twoDarray);
	PrintIntData(twoDarray);
}

void Array2DsetRowTester()
{
	cout << "2D Array" << endl;
	Array2D<int> twoDarray(3, 3);
	twoDarray.setRow(8);
	LoadIntData(twoDarray);
	PrintIntData(twoDarray);
}

void Array2DTester()
{
	cout << "2D Array" << endl;
	Array2D<int> twoDarray(3, 3);
	LoadIntData(twoDarray);
	PrintIntData(twoDarray);
}

void overloadEqualTest()
{
	cout << "First Array" << endl;
	Array<int> firstArray(10);
	firstArray.loadintData(1);
	for (int i = 0; i < firstArray.getLength(); i++)
		cout << "[" << i << "]" << firstArray.firstPointer(i) << endl;

	cout << "Second Array" << endl;
	Array<int> secondArray(8);
	secondArray.loadintData(5);
	for (int i = 0; i < secondArray.getLength(); i++)
		cout << "[" << i << "]" << secondArray.firstPointer(i) << endl;

	firstArray = secondArray;
	cout << "Second Array copied to First Array" << endl;
	for (int i = 0; i < firstArray.getLength(); i++)
		cout << "[" << i << "]" << firstArray.firstPointer(i) << endl;
}

void setStartIndexToDifferentNumberTest()
{
	cout << "Instantiating and filling and Array with 10 numbers" << endl;
	Array<int> firstArray(10);
	firstArray.loadintData(4);
	for (int i = 0; i < firstArray.getLength(); i++)
		cout << "[" << i << "]" << firstArray.firstPointer(i) << endl;
	firstArray.setStartIndex(-4);
	cout << "Start of changed index" << endl;
	for (int i = firstArray.getStartIndex(); i < firstArray.getLength() + firstArray.getStartIndex(); i++)
		cout << "[" << i << "]" << firstArray.firstPointer(i - firstArray.getStartIndex()) << endl;
}

void ResizeArrayTest()
{
	cout << "Instantiating and filling and Array with 10 numbers" << endl;
	Array<int> firstArray(10);
	firstArray.loadintData(1);
	cout << "Length: " << firstArray.getLength() << endl;
	for (int i = 0; i < firstArray.getLength(); i++)
		cout << "[" << i << "]" << firstArray.firstPointer(i) << endl;
	firstArray.setLength(15);
	cout << "Length: " << firstArray.getLength() << endl;
	for (int i = 0; i < firstArray.getLength(); i++)
		cout << "[" << i << "]" << firstArray.firstPointer(i) << endl;
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









