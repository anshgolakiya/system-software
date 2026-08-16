%{
#include <stdio.h>

int vowels = 0, consonants = 0;
%}

%%

[aAeEiIoOuU]      { vowels++; }
[a-zA-Z]          { consonants++; }
\n                { 
                     printf("\nNumber of vowels = %d", vowels);
                     printf("\nNumber of consonants = %d\n", consonants);
                     return 0;
                  }
.                 ;

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