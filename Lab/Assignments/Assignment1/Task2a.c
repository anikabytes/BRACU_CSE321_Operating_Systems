#include <stdio.h>
#include <stdlib.h>

int sub(int x, int y){
	int s;
	s = x - y;
	return s;
}

int add(int a, int b){
	int t;
	t = a + b;
	return t;
}


int mul(int c, int d){
	int w;
	w = c * d;
	return w;
}

int main(){

	int num1,num2;
	char operator;
	int ans;
	
	printf("Please enter 2 numbers:\n");
	scanf("%d\n %d",&num1,&num2);
	
	printf("Please enter 1 operator:\n");
	scanf("%c\n",&operator);
	
	if (num1 > num2){
		ans = sub(num1,num2);
		printf("Result: %d - %d = %d\n",num1,num2,ans);
	}
	else if (num1 < num2){
		ans = add(num1,num2);
		printf("Result: %d + %d = %d\n",num1,num2,ans);
	}
	else if (num1 = num2){
		ans = mul(num1,num2);
		printf("Result: %d * %d = %d\n",num1,num2,ans);
	}
	
}
