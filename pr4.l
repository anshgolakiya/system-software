%{
#include <stdio.h>
int count = 0;
%}

%%

[a-zA-Z]+ 	 { if(yyleng <= 5)
			count++; }
\n               {return 0 ; }

%%

int yywrap()
{
    return 1;
}

int main()
{
    printf("Enter a string: ");
    yylex();
    printf("Number of words with length <= 5 = %d\n",count);
    
    return 0;
}
