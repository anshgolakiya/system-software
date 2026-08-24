#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 20

/* Structure for Symbol Table */
struct Symbol
{
    char name[20];
    int address;
};

/* Structure for Literal Table */
struct Literal
{
    char name[20];
    int address;
};

int main()
{
    FILE *fp;

    char line[100];
    char word1[20], word2[20], word3[20];

    struct Symbol symtab[MAX];
    struct Literal littab[MAX];

    int symCount = 0;
    int litCount = 0;
    int LC = 0;

    /* Open input file */
    fp = fopen("pr8input.txt", "r");

    if (fp == NULL)
    {
        printf("File cannot be opened.\n");
        return 1;
    }

    while (fgets(line, sizeof(line), fp))
    {
        word1[0] = '\0';
        word2[0] = '\0';
        word3[0] = '\0';

        sscanf(line, "%s %s %s", word1, word2, word3);

        /* START */
        if (strcmp(word1, "START") == 0)
        {
            LC = atoi(word2);
        }

        /* Check for label */
        else if (strcmp(word1, "MOVER") == 0 ||
                 strcmp(word1, "ADD") == 0 ||
                 strcmp(word1, "MOVEM") == 0 ||
                 strcmp(word1, "STOP") == 0)
        {
            /* No label */
        }

        else if (strcmp(word1, "END") == 0)
        {
            /* Assign addresses to literals */
            for (int i = 0; i < litCount; i++)
            {
                if (littab[i].address == 0)
                {
                    littab[i].address = LC;
                    LC++;
                }
            }
        }

        else
        {
            /* Label found */
            int found = 0;

            for (int i = 0; i < symCount; i++)
            {
                if (strcmp(symtab[i].name, word1) == 0)
                {
                    symtab[i].address = LC;
                    found = 1;
                    break;
                }
            }

            if (!found)
            {
                strcpy(symtab[symCount].name, word1);
                symtab[symCount].address = LC;
                symCount++;
            }

            if (strcmp(word2, "DS") == 0)
            {
                LC += atoi(word3);
            }
            else if (strcmp(word2, "DC") == 0)
            {
                LC++;
            }
        }

        /* Find literals in operands */
        if (strchr(line, '=') != NULL)
        {
            char *p = strchr(line, '=');
            char literal[20];

            sscanf(p, "%s", literal);

            int found = 0;

            for (int i = 0; i < litCount; i++)
            {
                if (strcmp(littab[i].name, literal) == 0)
                {
                    found = 1;
                    break;
                }
            }

            if (!found)
            {
                strcpy(littab[litCount].name, literal);
                littab[litCount].address = 0;
                litCount++;
            }
        }

        /* Increment LC for instructions */
        if (strcmp(word1, "MOVER") == 0 ||
            strcmp(word1, "ADD") == 0 ||
            strcmp(word1, "MOVEM") == 0 ||
            strcmp(word1, "STOP") == 0)
        {
            LC++;
        }
    }

    fclose(fp);

    /* Display Symbol Table */
    printf("\nSYMBOL TABLE\n");
    printf("--------------------\n");
    printf("Symbol\tAddress\n");

    for (int i = 0; i < symCount; i++)
    {
        printf("%s\t%d\n",
               symtab[i].name,
               symtab[i].address);
    }

    /* Display Literal Table */
    printf("\nLITERAL TABLE\n");
    printf("--------------------\n");
    printf("Literal\tAddress\n");

    for (int i = 0; i < litCount; i++)
    {
        printf("%s\t%d\n",
               littab[i].name,
               littab[i].address);
    }

    return 0;
}
