#include <stdio.h>
#include <stdlib.h>
typedef long T;

T fact_do(T n)
{
	T result = 1;
	do
	{
		result*=n;
		n--;
	}
	while(n>1);
	return result;
}


int main(int argc,char *argv[])
{
	T tmp = atoi(argv[1]);
	T res = fact_do(tmp);
	printf("factorial of %s is %ld\n",argv[1],res);
	return 0;

}
