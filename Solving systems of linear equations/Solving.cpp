#include <iostream>
#include <math.h>

using namespace std;
#define N 4

void lets_print_it(double a[N][N+1]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= N; j++) {
			cout << a[i][j] << " ";
		}
		cout << "\n";
	}
}

void Gauss_Gordan_method(double a[N][N + 1]) {
	for (int m = 0; m < N; m++) {

		for (int j = m + 1; j <= N; j++) {
			a[m][j] /= a[m][m];
		}a[m][m] = 1;

		for (int i = 0; i < N; i++) {
			for (int j = m + 1; j <= N; j++) {
				if (i != m) {
					a[i][j] -= a[m][j] * a[i][m];
				}
				else { break; }
			} if (i != m) { a[i][m] = 0; }
		}

	}
	lets_print_it(a);
}

double* simple_iteration(double matrix[N][N+1], double eps) {
	double *res, *help_res, max, q, m_norma_x;
	int i, j, k;
	res = (double *)malloc(N * sizeof(double));
	help_res = (double *)malloc(N * sizeof(double));

	for (i = 0; i < N; i++) {
		max = matrix[i][i];
		for (j = 0; j < N+1; j++)
			matrix[i][j] = matrix[i][j] / max;
	}

	q = 0;
	for (i = 0; i < N; i++) {
		max = 0;
		for (j = 0; j < N; j++)
			if (i != j)
				max += fabs(matrix[i][j]);
		if (max > q)
			q = max;
	}

	for (i = 0; i < N; i++)
		help_res[i] = matrix[i][N];

	for (i = 0; i < N; i++) {
		res[i] = matrix[i][N];
		for (j = 0; j < N; j++)
			if (i != j)
				res[i] -= matrix[i][j] * help_res[j];
	}

	for (i = 0; i < N; i++)
		help_res[i] = res[i];

	k = 2;
	do {
		for (i = 0; i < N; i++) {
			res[i] = matrix[i][N];
			for (j = 0; j < N; j++)
				if (i != j)
					res[i] -= matrix[i][j] * help_res[j];
		}

		for (i = 0; i < N; i++)
			help_res[i] = res[i] - help_res[i];

		m_norma_x = fabs(help_res[0]);
		for (i = 1; i < N; i++)
			if (fabs(help_res[i])>m_norma_x)
				m_norma_x = fabs(help_res[i]);

		for (i = 0; i < N; i++)
			help_res[i] = res[i];

		k++;
	} while (m_norma_x > eps*((1 - q) / q));

	printf("Number of iterations= %d\n", k);

	return res;
}



int main() {

	double a[N][N + 1] = {
		{ 2, 13, 16, 9, 96 },
		{ 4, 31, 18, 8, 125 },
		{ 18, 9, 36, 8, 213 },
		{ 20, 8, 7, 7, 130 }
	};

	double modern_a[N][N+1]= {
		{ 56, -7, 3, 13, 265 },
		{ 4, 31, 18, 8, 125 },
		{ 18, 9, 36, 8, 213 },
		{ 26, 4, 7, 44, 261 }
	};

	double eps = 1e-4;

	cout << "\t\tGauss-Gordan method:\n" << endl;
	Gauss_Gordan_method(a);

	cout<< "\t\tSimple iteration method:\n" << endl;
	cout << "Epsilon=" << eps << endl;
	double* res = (double *)malloc(N * sizeof(double));
	res = simple_iteration(modern_a, eps);

	for (int i = 0; i < N; i++) {
		cout << res[i] << endl;
	}


	system("PAUSE");
	return 0;
}