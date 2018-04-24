#include <iostream>

/*
int add(int a, int b)
{
	return a + b;
}

double add(double a, double b)
{
	return a + b;
}*/

template <typename T>
T add(T a, T b)
{
	return a + b;
}

void main()
{
	printf("int add = 5 + 3 = %d\n", add(5, 3));
	printf("double add = 5.5 + 3.3 = %lf\n", add(5.5, 3.3));
	getchar();
}