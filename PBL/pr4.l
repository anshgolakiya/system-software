%{
#include <stdio.h>
int count = 0;
%}

%%

[a-zA-Z]{1,5}    { count++; }
[ \t\n]+         { }
.                {return 0 ; }

%%

int yywrap()
{
    return 1;
}

int main()
{
    printf("Enter a string: ");
    yylex();

    if(count <= 5)
        printf("Number of words is %d (length <= 5\)n", count);
    else
        printf("Number of words is %d",count);
    return 0;
}