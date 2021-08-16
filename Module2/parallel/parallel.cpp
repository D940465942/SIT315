#include "pch.h"
#include <iostream>
#include <random>
#include <time.h>
#include <windows.h>
#include <string>
#include <fstream>
using namespace std;

#define DIM 1500
#define NUM_OF_THREADS 3

int input_array_1[DIM][DIM];
int input_array_2[DIM][DIM];
int output_array[DIM][DIM];

void init_array(int array[DIM][DIM])
{
	for (int i = 0; i < DIM; i++)
	{
		for (int j = 0; j < DIM; j++)
		{
			array[i][j] = rand() % ((100 - 1) + 1) + 1;
		}
	}
}

void output_arrays_to_file(int index, int array_1[DIM][DIM], int array_2[DIM][DIM], int array_out[DIM][DIM])
{
	ofstream file_out(to_string(index) + ".txt");

	file_out << "Input Array 1" << endl << "[";

	for (int i = 0; i < DIM; i++) {
		file_out << "[";
		for (int j = 0; j < DIM; j++) {
			file_out << array_1[i][j];
			file_out << " ";
		}
		file_out << "]" << endl;
	}
	file_out << "]" << endl;

	file_out << "Input Array 2" << endl << "[";

	for (int i = 0; i < DIM; i++) {
		file_out << "[";
		for (int j = 0; j < DIM; j++) {
			file_out << array_2[i][j];
			file_out << " ";
		}
		file_out << "]" << endl;
	}
	file_out << "]" << endl;

	file_out << "Output Array " << endl << "[";

	for (int i = 0; i < DIM; i++)
	{
		file_out << "[";
		for (int j = 0; j < DIM; j++) {
			file_out << array_out[i][j];
			file_out << " ";
		}
		file_out << "]" << endl;
	}
	file_out << "]" << endl;
	file_out.close();
}

int calculate(int i, int j, int array1[DIM][DIM], int array2[DIM][DIM])
{
	int value = 0;
	for (int k = 0; k < DIM; k++)
	{
		value += array1[i][k] * array2[k][j];
	}
	return value;
}

DWORD WINAPI one_thread(LPVOID lpParamter)
{
	for (int i = 0; i < DIM; i++)
	{
		for (int j = 0; j < DIM; j++)
		{
			output_array[i][j] = calculate(i, j, input_array_1, input_array_2);
		}
	}
	return 0L;
}

int main()
{
	clock_t start, stop;
	cout << DIM << " rows and " << DIM << " columns: " << endl;

	for (int i = 0; i < NUM_OF_THREADS; i++)
	{
		cout << i << "th of " << NUM_OF_THREADS << " threads" << endl;
		init_array(input_array_1);	// random initial input array 1
		init_array(input_array_2);	// random initial input array 2

		int start_s = clock(); 
		HANDLE hThread = CreateThread(NULL, 0, one_thread, NULL, 0, NULL);
		CloseHandle(hThread);
		int stop_s = clock();
		//output_arrays_to_file(i, input_array_1, input_array_2, output_array);
		cout << "Running time is: " << (stop_s - start_s) / double(CLOCKS_PER_SEC) * 1000 << "ms" << endl;
	}
}
