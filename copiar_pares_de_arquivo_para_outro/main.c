#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *p = fopen("inteiros.txt", "r");
    FILE *a = fopen ("inteirosout.txt", "w");
    int x[30],i;
    i = 0;
    if(p != NULL)
    {
      while(!feof(p))
      {
            fscanf (p, "%d", &x[i]);
            if(x[i]%2==0)
            {
                fprintf(a, "%d\n", x[i]);
            }
            i++;
      }
      fclose(p);
      fclose(a);
    } else
    {
        printf ("Nao ha arquivo para ser aberto.\n");
        return 0;
    }
    system("pause");
    return 0;
}
