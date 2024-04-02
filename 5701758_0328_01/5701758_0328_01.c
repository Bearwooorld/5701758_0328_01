#include<stdio.h>
#define MAX_DEGREE 101

typedef struct {
	int degree;
	float coef[MAX_DEGREE];
}polynomial;

polynomial a = { 3, {4.0, 3.0, 2.0, 1.0} };
polynomial b = { 2, {3.0, 2.0, 8.0} };
polynomial c = { 6, {7.0, 0.0, 0.0, 5.0, 9.0, 0.0, 1.0} };
polynomial d = { 3, {5.0, 2.0, 1.0, 10.0} };

void print_poly(polynomial p);

polynomial multi_poly(polynomial A, polynomial B);

int main() {
	polynomial X, Y;

	print_poly(a);
	print_poly(b);

	X = multi_poly(a, b);
	printf("-----------------------------\n");
	print_poly(X);

	printf("-----------------------------\n");

	print_poly(d);
	print_poly(c);

	Y = multi_poly(c, d);
	printf("-----------------------------\n");
	print_poly(Y);
}

void print_poly(polynomial p) {
	for (int i = p.degree; i > 0; i--) {
		printf("%3.1fx^%d + ", p.coef[p.degree-i], i);
	}
	printf("%3.1f\n", p.coef[p.degree]);
}

polynomial multi_poly(polynomial A, polynomial B)
{
	polynomial C;
	int i, j;
	for (i = 0; i < A.degree + B.degree + 1; i++) C.coef[i] = 0;
	C.degree = A.degree + B.degree;
	for (i = 0; i < A.degree + 1; i++)
		for (j = 0; j < B.degree + 1; j++)
			C.coef[i + j] += A.coef[i] * B.coef[j];
	return C;

}