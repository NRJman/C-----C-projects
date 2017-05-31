#define _USE_MATH_DEFINES
#include <fstream>
#include <math.h>
#include <iostream>
#include <iomanip>
using namespace std;

double b = 7;
double a = 0;

double f(double x) {
	return 0.001*exp(x + 5)*cos(3 * x);
}

double* SchemeOneDivision(int N) {
	double tmp_1, tmp_2;
	int i, j, k, l;
	double* res = new double[N];
	double **SLAU = new double*[N];
	for (int i = 0; i < N; i++)
		SLAU[i] = new double[N + 1];

	double h = (b - a) / N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N + 1; j++)
			SLAU[i][j] = 0;

	for (int i = 0; i < N; i++) {
		SLAU[i][i] = 4 * h;
		if (i>0)
			SLAU[i][i - 1] = h;
		if (i < N - 1)
			SLAU[i][i + 1] = h;
		double x_prev = a + h * (i - 1);
		double x_i = a + h * i;
		double x_next = a + h * (i + 1);
		SLAU[i][N] = 6 * (f(x_next) - 2 * f(x_i) + f(x_prev)) / h;
	}

	for (j = 0; j < N; j++) {
		tmp_1 = SLAU[j][j];
		for (i = j; i < N + 1; i++) {
			SLAU[j][i] /= tmp_1;
		}
		for (k = j + 1; k < N; k++) {
			tmp_2 = SLAU[k][j];
			for (l = j; l < N + 1; l++) {
				SLAU[k][l] -= SLAU[j][l] * tmp_2;
			}
		}
	}
	for (j = N - 1; j >= 0; j--) {
		tmp_1 = 0;
		for (i = N - 1; i > j; i--) {
			tmp_1 += SLAU[j][i] * res[i];
		}
		res[j] = SLAU[j][N] - tmp_1;
	}
	return res;
}

void SplInterpol(int N) {
	ofstream fout("results.txt");
	double* A = new double[N];
	double* D = new double[N];
	double* B = new double[N];
	double* C;

	double h = (b - a) / N;
	double x = a;
	for (int i = 0; i < N; ++i) {
		A[i] = f(x);
		x += h;
	}

	C = SchemeOneDivision(N);

	D[0] = C[0];
	for (int i = 1; i < N; ++i)
		D[i] = (C[i] - C[i - 1]) / h;

	B[0] = 0;
	for (int i = 1; i < N; ++i)
		B[i] = (h * C[i] / 2) - (h * h * D[i] / 2) + (f(a + h*i) - f(a + h*(i - 1))) / h;

	int k = (b - a) * 10;
	double step = (b - a) / (double)k;
	double y, xj;
	x = a;

	for (int i = 0; i <= k; i++) {
		int j = 0;
		while (x >= (a + j * h))
			j++;
		j--;
		xj = a + h * j;
		y = A[j] + B[j] * (x - xj) + C[j] * (x - xj) * (x - xj) / 2 + D[j] * (x - xj) * (x - xj) * (x - xj) / 6;
		fout << x;
		fout << " ; ";
		fout << y;
		fout << endl;
		x += step;
	}
	fout.close();
	return;
}


int main() {
	int N = 70;
	printf("Spline with N = %d\n", N);
	SplInterpol(N);
	printf("The results will be shown in 'results.txt' file. \n");

	return 0;
}