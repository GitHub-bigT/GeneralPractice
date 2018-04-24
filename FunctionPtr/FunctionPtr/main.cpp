#include <iostream>

typedef char (*FUNPTY)(int);//ȥ��typedef�ͱ���FUNPTY��ʣ�µľ���ԭ���������� char (*)(int)
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
	case '+': return add_s;//���غ����ĵ�ַ   
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
	FP_CALC fp = calc_func(op); //����Ԥ����õ���������ĺ����ĵ�ַ   
	if (fp) 
		return fp(a, b);//������һ���õ��ĺ����ĵ�ַ������Ӧ�����������ؽ��   
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