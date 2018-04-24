#include <iostream>

typedef char (*FUNPTY)(int);//去掉typedef和别名FUNPTY。剩下的就是原变量的类型 char (*)(int)
FUNPTY pFun;
char glFun(int a)
{
	printf("%d\n", a);
	return 'a';
}

typedef int(*FP_CALC)(int, int);
int add_s(int a, int b)
{
	return a + b;
}
int sub_s(int a, int b)
{
	return a - b;
}
int mul_s(int a, int b)
{
	return a * b;
}
int div_s(int a, int b)
{
	return b ? a / b : -1;
}
   
FP_CALC calc_func(char op)
{
	switch (op)
	{
	case '+': return add_s;//返回函数的地址   
	case '-': return sub_s;
	case '*': return mul_s;
	case '/': return div_s;
	default:
		return NULL;
	}
	return NULL;
}
 
int calc(int a, int b, char op)
{
	FP_CALC fp = calc_func(op); //根据预算符得到各种运算的函数的地址   
	if (fp) 
		return fp(a, b);//根据上一步得到的函数的地址调用相应函数，并返回结果   
	else 
		return -1;
}

void main()
{
	/*pFun = glFun;
	(*pFun)(12);
	pFun(22);*/
	int a = 100, b = 20;
	printf("calc(%d, %d, %c) = %d\n", a, b, '+', calc(a, b, '+'));
	printf("calc(%d, %d, %c) = %d\n", a, b, '-', calc(a, b, '-'));
	printf("calc(%d, %d, %c) = %d\n", a, b, '*', calc(a, b, '*'));
	printf("calc(%d, %d, %c) = %d\n", a, b, '/', calc(a, b, '/'));
	getchar();
}