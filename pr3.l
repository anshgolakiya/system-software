%{
#include <stdio.h>
%}

%%

0[0-7]+              { printf("Octal Number\n"); }
0[xX][0-9a-fA-F]+    { printf("Hexadecimal Number\n"); }
[0-9]+               { printf("Decimal Number\n"); }
[ \t]		     {}
\n                   { return 0; }
.                    { printf("Invalid Input\n"); }

%%

int yywrap()
{
    return 1;
}

int main()
{
    printf("Enter a number: ");
    yylex();
    return 0;
}
