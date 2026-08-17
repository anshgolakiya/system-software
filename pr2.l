%{
#include <stdio.h>
%}

%%
[A-Z]    { printf("%c", yytext[0] + 32); }
[a-z]    { printf("%c", yytext[0] - 32); }
\n       { return 0 ;} // if it is remove than more than one input we provide one by one
.        { 
            printf("%s", yytext); 
        }

%%

int yywrap()
{
    return 1;
}

int main()
{
    printf("Enter a string: ");
    yylex();
    return 0;
}
