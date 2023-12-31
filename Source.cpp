#include <iostream>
#include "headers/h_clock/HiTime.h"

double round_up(double value, int decimal_places)
{
	const double multiplier = std::pow(10.0, decimal_places);
	return std::ceil(value * multiplier) / multiplier;
}

int main()
{
	int n;
	bool divergeFlag;
	std::cout << "Enter the Number of unkowns: ";
	std::cin >> n;
	std::cout << "\n";
	double* C = new double[n];
	double** A = new double* [n];
	for (int mi = 0; mi < n; mi++) {

		// Declare a memory block
		// of size n
		A[mi] = new double[n];
	}
	int convergePT = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cout << "a"<<i<<j<<"= ";
			// Assign values to the
			// memory blocks created
			std::cin >> A[i][j] ;
		}
		std::cout << "\nc" << i << "= ";
		std::cin >> C[i];
		std::cout << "\n";

	}


	double* X = new double[n];
	std::fill(X, X+n, 0);

	/*
	for (int mi = 0; mi < n; mi++) {

		// Declare a memory block
		// of size n
		std::cout << X[mi]  << "\n";
	}
	*/

	double* _X = new double[n];

	double* dX = new double[n];

	for (int i = 0; i < n; i++)
	{
		dX[i] = 1;
	}

	int itr = 0;
	h_clock::startTimer();
	do
	{

	


		for (int i = 0; i < n; i++)
		{
			_X[i] = X[i];
		}

		for (int i = 0; i < n; i++)
		{
			double sum = 0;
			for (int j = 0; j < n; j++)
			{
				if (j != i)
				{
					sum += (A[i][j] * X[j]);
				}
				X[i] = (C[i]-sum) / A[i][i];
			}
			
		}

	
		std::cout << itr ;
		
		for (int i = 0; i < n; i++)
		{
			std::cout << " " <<  X[i];
		}

		
		convergePT = 0;
		for (int i = 0; i < n; i++)
		{
			dX[i] = X[i] - _X[i];
			if (dX[i] >= 0.0001) convergePT++;
		}
		//std::cout <<" " << convergePT;
		std::cout << "\n";
		itr++;
		if (itr >= 1500)
		{
			divergeFlag = true;
			break;
		}
	} while (convergePT != 0);

	int time = h_clock::clock_milli();
	if (divergeFlag)
	{
		for (int c = 0; c <= 30; c++) std::cout << (char)220;
		std::cout << "\nSOLUTION DIVERGES after " << itr << " iterations in " << time << " ms\n";
		for (int c = 0; c <= 30; c++) std::cout << (char)220;
		
	}
	else
	{

		double* Sol_X = new double[n];

		for (int i = 0; i < n; i++)
		{
			Sol_X[i] = round_up(X[i], 2);
		}

		for (int c = 0; c <= 30; c++) std::cout << (char)220;
		std::cout << "\nSOLUTION CONVERGED in " << itr << " iterations in " << time << " ms\n";
		for (int c = 0; c <= 30; c++) std::cout << (char)220;
		std::cout << "\nRESULTS: \nX = [";

		for (int i = 0; i < n; i++)
		{
			std::cout << " " << Sol_X[i];
		}

		std::cout << " ]\n";

	}

	return 0;
}