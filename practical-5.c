#include <stdio.h>
#include <string.h>

int main()
{
    FILE *fp1, *fp2;
    char grammar[100];
    char nonTerminal;
    char alpha[50], beta[50];
    int i, j, pos = -1;

    /* Open input file for reading */
    fp1 = fopen("input.txt", "r");

    /* Open output file for writing */
    fp2 = fopen("output.txt", "w");

    if (fp1 == NULL)
    {
        printf("Unable to open input file.");
        return 0;
    }

    if (fp2 == NULL)
    {
        printf("Unable to create output file.");
        return 0;
    }

    /* Read grammar from input file */
    fscanf(fp1, "%s", grammar);

    printf("Given Grammar: %s\n", grammar);

    /* First character is the non-terminal */
    nonTerminal = grammar[0];

    /* Find the position of | symbol */
    for (i = 0; grammar[i] != '\0'; i++)
    {
        if (grammar[i] == '|')
        {
            pos = i;
            break;
        }
    }

    /* Check for immediate left recursion */
    if (grammar[3] == nonTerminal)
    {
        printf("Left Recursion Found.\n");

        /* Extract alpha from A->Aalpha|beta */
        j = 0;

        for (i = 4; i < pos; i++)
        {
            alpha[j] = grammar[i];
            j++;
        }

        alpha[j] = '\0';

        /* Extract beta */
        j = 0;

        for (i = pos + 1; grammar[i] != '\0'; i++)
        {
            beta[j] = grammar[i];
            j++;
        }

        beta[j] = '\0';

        /* Write transformed grammar into output file */
        fprintf(fp2, "%c->%s%c'\n",
                nonTerminal, beta, nonTerminal);

        fprintf(fp2, "%c'->%s%c'|epsilon\n",
                nonTerminal, alpha, nonTerminal);

        printf("\nGrammar after removing Left Recursion:\n");

        printf("%c->%s%c'\n",
               nonTerminal, beta, nonTerminal);

        printf("%c'->%s%c'|epsilon\n",
               nonTerminal, alpha, nonTerminal);
    }
    else
    {
        printf("No Left Recursion Found.\n");

        fprintf(fp2, "No Left Recursion Found.\n");
    }

    fclose(fp1);
    fclose(fp2);

    return 0;
}
