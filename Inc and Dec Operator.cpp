#include<stdio.h>

int main() {
	
	int i=10;
	
	//printing from L->R and assigning form R->L
	printf("%d %d %d %d",i++,++i,--i,i--);
	//all the pre-operations will hold the final value of i
	return 0;
}
