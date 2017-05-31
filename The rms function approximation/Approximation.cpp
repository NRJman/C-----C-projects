#define _USE_MATH_DEFINES
#include <math.h>
#include <iomanip>
#include <iostream>
#include <fstream>
using namespace std;

double f(double x) {
	return 0.001*exp(x + 5)*cos(3 * x);
}

double Chebyshev(int n, double x) {
	double Tn_next, Tn = x, Tn_prev = 1;

	if (n == 0) return Tn_prev;
	int i = 1;

	while (i < n) {
		Tn_next = 2 * x * Tn - Tn_prev;
		Tn_prev = Tn;
		Tn = Tn_next;
		++i;
	}
	return Tn;
}

double* scheme_selection_main_element(double **matrix, int N) {
	int i, j, line_num, row_num, k, line_new = 0;
	double tmp, max, *M_tmp = new double[N];
	double *res_vect = new double[N];
	double ** change_matrix = new double*[N];
	for (int i = 0; i < N + 1; i++)
		change_matrix[i] = new double[N + 1];

	for (k = 0; k < N - 1; k++) {

		max = 0;
		for (i = 0; i < N; i++)
			for (j = 0; j < N; j++)
				if (fabs(matrix[i][j]) > max) {
					max = fabs(matrix[i][j]);
					line_num = i;
					row_num = j;
				}

		for (j = 0; j < N + 1; j++)
			change_matrix[line_new][j] = matrix[line_num][j];
		line_new++;

		for (i = 0; i < N; i++)
			M_tmp[i] = -(matrix[i][row_num] / max);

		for (i = 0; i < N; i++)
			for (j = 0; j < N + 1; j++)
				if (i != line_num)
					matrix[i][j] += matrix[line_num][j] * M_tmp[i];

		for (j = 0; j < N + 1; j++)
			matrix[line_num][j] = 0;

		for (i = 0; i < N; i++)
			matrix[i][row_num] = 0;
	}

	for (i = 0; i < N; i++)
		if (matrix[i][N] != 0)
			line_num = i;

	for (j = 0; j < N + 1; j++)
		change_matrix[line_new][j] = matrix[line_num][j];

	for (j = 0; j < N; j++)
		res_vect[j] = 0;

	for (i = N - 1; i >= 0; i--) {
		tmp = change_matrix[i][N];
		for (j = 0; j < N; j++)
			if ((change_matrix[i][j] != 0) && (res_vect[j] != 0))
				tmp -= change_matrix[i][j] * res_vect[j];
		for (j = 0; j < N; j++)
			if ((change_matrix[i][j] != 0) && (res_vect[j] == 0))
				res_vect[j] = tmp / change_matrix[i][j];
	}

	return res_vect;
}


double change_func(int N, double x, int k1, int k2, double a, double b) {
	double t = (2 * x - a - b) / (b - a);
	if (k2 == N)
		return  f(x)*Chebyshev(k1, t);
	else
		return  Chebyshev(k1, t)*Chebyshev(k2, t);
}

double trapetion(int k1, int k2, double a, double b, int integrate_n, int N) {
	double h, x, integral = 0;
	h = (b - a) / integrate_n;
	for (x = a; x < b; x += h) {
		integral += h*(change_func(N, x, k1, k2, a, b) + change_func(N, x + h, k1, k2, a, b)) / 2;
	}
	return integral;
}

double two_count(int k1, int k2, double a, double b, int N) {
	double r, In, I2n;
	double eps = 1e-8;
	int integrate_n = (int)ceil((b - a) / sqrt(sqrt(eps)));

	In = trapetion(k1, k2, a, b, integrate_n, N);
	I2n = trapetion(k1, k2, a, b, 2 * integrate_n, N);
	r = fabs(In - I2n) / 3;

	while (r > eps) {
		In = I2n;
		integrate_n *= 2;
		I2n = trapetion(k1, k2, a, b, integrate_n, N);
		r = fabs(In - I2n) / 3;
	}
	return I2n;
}

double ** make_polinom_matrix(double a, double b, int N) {
	int i, j;
	double *result = new double[N];
	double ** Polinom_matrix = new double*[N];
	for (int i = 0; i < N + 1; i++)
		Polinom_matrix[i] = new double[N + 1];

	for (i = 0; i < N; i++) {
		for (j = 0; j < N + 1; j++) {
			Polinom_matrix[i][j] = Polinom_matrix[j][i] = two_count(i, j, a, b, N);
		}
		Polinom_matrix[i][N] = two_count(i, N, a, b, N);
	}

	return Polinom_matrix;
}

double Polinom(double x, double a, double b, int n) {
	double **Polinom_matrix = make_polinom_matrix(a, b, n);
	double *res_matrix = scheme_selection_main_element(Polinom_matrix, n);
	double  t = (2 * x - b - a) / (b - a);
	double res = 0;
	for (int j = 0; j < n; ++j)
		res += res_matrix[j] * Chebyshev(j, t);
	return res;
}

int main() {

	double eps = 0.1;
	double a = 0, b = 7;
	int k = (int)(b - a) * 10;
	double y, x, step = (b - a) / k;
	int n = 13;
	double SKV = eps + 1;

	while (SKV > eps) {
		n += 1;
		SKV = 0;
		x = a;
		for (int i = 0; i <= k; ++i) {
			y = f(x) - Polinom(x, a, b, n);
			SKV += y*y;
			x += step;
		}
		SKV = sqrt(SKV / (k + 1));
		cout << "SKV [" << n << "] = " << SKV << endl;
	}

	cout << "N = " << n << endl << endl;
	ofstream fout("lab.txt");
	for (double x = a; x <= b; x += step) {
		double result = Polinom(x, a, b, n);
		fout << x << ";" << result << endl;
	}
	cout << "Results in file lab.txt" << endl;
	fout.close();
	return 0;
}