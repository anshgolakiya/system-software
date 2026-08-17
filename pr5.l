%{
#include <stdio.h>
%}

%%


^[aeiouAEIOU].*    { printf("String starts with a vowel\n"); }
.*                 { printf("String does not start with a vowel\n"); }
\n 		   { return 0 ; }
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
