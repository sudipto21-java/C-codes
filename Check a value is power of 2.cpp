#include<stdio.h>

void CheckWithLoop(int num) {
	
	int f=1;
	
	for(int i=2;i<=num;i*=2) {
		
		if(num%i!=0) {
			f=0;
			printf("No\n");
			break;
		}
	}
	
	if(f==1)
		printf("Yes\n");
}

void CheckWithoutLoop(int num) {
	
	if((num & num-1)==0){
		printf("Yes\n");
	}
	else
		printf("No\n");
}

int main() {
	
	int num;
	
	printf("enter a number to be checked:");
	scanf("%d",&num);
	
	CheckWithoutLoop(num);
	CheckWithLoop(num);
	
	return 0;
}
