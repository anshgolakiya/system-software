#include <stdio.h>
#define MACRO(num1 , num2)								\
do{											\
	int EV = 1 ;									\
	printf("Macro expantion : \n") ;						\
	while(EV <= 2){									\
		printf("%d : %d + %d = %d\n" , EV ,num1 , num2 , (num1) + (num2)) ;	\
		EV++;									\
	}										\
}while(0)										
int main() {
	int a , b ;
	printf("Enter a value of a : ");
	scanf("%d",&a);
	printf("Enter a value of b : ");
	scanf("%d",&b);
	MACRO(a,b);
}
