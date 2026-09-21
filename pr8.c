 #include <stdio.h>

#include <string.h>

#include <stdlib.h>

struct symbol

{

 char name[20];

 int address;

};

struct literal

{

 char name[20];

 int address;

};
int main()

{

 FILE *fp;

 char line[100], label[20], op[20], arg[30], literal[20];

 struct symbol sym[50];

 struct literal lit[50];

 int sc = 0, lc = 0, loc = 0, i, found;

 char *p;

 fp = fopen("input.txt", "r");

 if (fp == NULL)

 {

 printf("File not found");

 return 0;

 }

 while (fgets(line, 100, fp) != NULL)

 {

 label[0] = '\0';

 op[0] = '\0';

 arg[0] = '\0';

 sscanf(line, "%s %s %s", label, op, arg);

 if (strcmp(label, "START") == 0)

 {

 loc = atoi(op);

 continue;

 }

 if (strcmp(label, "END") == 0)

 break;

 if (strcmp(label, "-") != 0)

 {

 found = 0;
for (i = 0; i < sc; i++)

 {

 if (strcmp(sym[i].name, label) == 0)

 found = 1;

 }

 if (found == 0)

 {

 strcpy(sym[sc].name, label);

 sym[sc].address = loc;

 sc++;

 }

 }

 p = strchr(line, '=');

 if (p != NULL)

 {

 sscanf(p, "%s", literal);

 found = 0;

 for (i = 0; i < lc; i++)

 {

 if (strcmp(lit[i].name, literal) == 0)

 found = 1;

 }

 if (found == 0)

 {

 strcpy(lit[lc].name, literal);

 lit[lc].address = -1;

 lc++;

 }

 }

 if (strcmp(op, "DS") == 0)
     loc += atoi(arg);

 else

 loc++;

 }

 for (i = 0; i < lc; i++)

 {

 lit[i].address = loc;

 loc++;

 }

 printf("\nSYMTAB\n");

 printf("-------\n");

 printf("Symbol\tAddress\n");

 for (i = 0; i < sc; i++)

 printf("%s\t%d\n", sym[i].name, sym[i].address);

 printf("\nLITTAB\n");

 printf("-------\n");

 printf("Literal\tAddress\n");

 for (i = 0; i < lc; i++)

 printf("%s\t%d\n", lit[i].name, lit[i].address);

 fclose(fp);

 return 0;

}
