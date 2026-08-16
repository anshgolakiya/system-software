%{
#include <stdio.h>
%}

%%

^[exit].*          { return 0 ;}
^[aeiouAEIOU].*    { printf("String starts with a vowel\n"); }
.*                 { printf("String does not start with a vowel\n"); }

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