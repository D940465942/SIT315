#include <iostream>
#include <random>
#include <time.h>
#include <fstream>
#include <string>
using namespace std;

#define DIM 1000

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

void sequential(int array_1[DIM][DIM], int array_2[DIM][DIM], int array_out[DIM][DIM])
{
	int value;
	for (int i = 0; i < DIM; i++)
	{
		for (int j = 0; j < DIM; j++)
		{
			value = 0;
			for (int k = 0; k < DIM; k++)
			{
				value += array_1[i][k] * array_2[k][j];
			}
			array_out[i][j] = value;

		}
	}
}

int main()
{
	clock_t start, stop;
	for (int i = 0; i < 5; i++)
	{
		init_array(input_array_1);	// random initial input array 1
		init_array(input_array_2);	// random initial input array 2

		int start_s = clock();
		sequential(input_array_1, input_array_2, output_array);
		int stop_s = clock();

		output_arrays_to_file(i, input_array_1, input_array_2, output_array);

		cout << "Running time is: " << (stop_s - start_s) / double(CLOCKS_PER_SEC) * 1000 << "ms" << endl;
	}
}
