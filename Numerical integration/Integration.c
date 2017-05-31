#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double y(double x) {
	return (-exp(x)*(sin(x) + cos(x))) / 64;
}

double F(double x) {
	return (-exp(x)*sin(x)) / 64;

}

double Simpson(double n, double a, double b,double *h) {
	int i;
	//double h; //step
	double sig1 = 0.0; //even sum
	double sig2 = 0.0; //odd sum

	n = 2 * ceil(n / 2);
	*h = (b - a) / n;
	for (i = 1; i < n; i++) {
		if (i % 2 == 0)
			sig2 += y(a + i**h);
		else
			sig1 += y(a + i**h);
	}
	return *h / 3 * (y(a) + y(b) + 4 * sig1 + 2 * sig2);
}

int main() {
	double n;
	double eps = 1e-4;
	double a = -1;
	double b = 15;
	double r, delta, h, maximum, Io, In, I2n;

	//Neuton Leibnic 
	Io = F(b) - F(a);
	printf("a =%.1f\n", a);
	printf("b =%.1f\n", b);
	printf("I = F(b) - F(a) = %f\n\n", Io);

	//Simpson
	printf("Simpson_method\n");
	printf("==================================================\n");
	printf("|    eps   |     h    |      I     |    delta    |\n");
	printf("==================================================\n");

	maximum = 133706.51; //we've already chosen it by ourself

	h = pow((180 * eps / (b - a) / maximum), 0.25);
	n = 2 * ceil(0.5*(b - a) / h);
	//h = (b - a) / n;
	delta = fabs(Io - Simpson(n, a, b,&h));
	printf("| %f | %.6f | %.8f | %.9f |\n", eps, h, Simpson(n, a, b,&h), delta);
	printf("==================================================\n\n");

	//Refind calculation
	printf("Refind_calculation\n");
	printf("===========================================\n");
	printf("|    delta    |     h    |       Abs      |\n");
	printf("===========================================\n");
	n = ceil((b - a) / sqrt(sqrt(delta)));
	h = (b - a) / n;

	In = Simpson(n, a, b,&h);
	I2n = Simpson(2 * n, a, b,&h);
	r = fabs(In - I2n) / 15;

	while (r > delta) {
		n *= 2;
		In = I2n;
		I2n = Simpson(2 * n, a, b,&h);
		r = fabs(In - I2n) / 15;
	}

	printf("| %.9f | %.6f | %.12f |\n", delta, h, fabs(Io - I2n));
	printf("===========================================\n");
	return 0;
}