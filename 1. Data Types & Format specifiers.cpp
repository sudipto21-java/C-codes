#include<stdio.h>

int main()
{
	int i; char c; float f1, f2, f3, f4; double d; bool b1, b2;
	i=10; c='g'; f1=4.3, f2=-4.32, f3=44.7, f4=44.3; d=55.32; b1=0, b2=true; 
	printf("%d, %c, %b, %b\n",i,c,b1,b2);
	printf("%f, %.6f, %lf, %.14lf, %f\n",f1,f2,d,d,d);
	printf("%.7f, %f, %f, %.15lf",f1,f3,f4,d,d);
	return 0;
}
