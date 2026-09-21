#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *fp ;
    char prod1[50], prod2[50] ;
    char common[50];
    int i =0 ;
    fp = fopen("input.txt","r");
    if(fp == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }
    fscanf(fp,"%s",prod1);
    fscanf(fp,"%s",prod2);
    fclose(fp);
    printf("Given grammer:\n");
    printf("A -> %s|%s\n",prod1,prod2);
    while(prod1[i] == prod2[i] && prod1[i] != '\0'){
    	common[i] = prod1[i];
    	i++;
    }
    common[i] = '\0' ;
    
    if(i == 0)
    {
    	printf("\nNo left fectoring is required.\n");
    }
    else
    {
    	printf("\nCommon Prefix: %s\n",common);
    	printf("\nAfter left fectoring :\n");
    	printf("A -> %sA'\n",common);
    	printf("A' -> ");
    	
    	if(prod1[i] == '\0')
    		printf("epsilon");
    	else
    		printf("%s",&prod1[i]);
    	printf("|");
    	if(prod2[i] == '\0')
    		printf("epsilon");
    	else
    		printf("%s",&prod2[i]);
    	printf("\n");
    }
    return 0 ;
}
