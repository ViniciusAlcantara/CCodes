#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("cls");
    int numJog, numDup,i,soma = 0,jog = 0;

    printf("\t\t\tBEM VINDO AO PROGRAMA FUTSAL\n\n");
    printf("Aqui voce vai ser capaz de selecionar os melhores jogadores para o seu time\ninformando apenas as duplas que ja jogaram juntas!\n");
    printf("\nQual o numero de jogadores?\n");
    scanf("%i", &numJog);
    printf("\nQual o numero de duplas?\n");
    scanf("%i", &numDup);

    int duplas[numDup*2][4];

    for(i=0;i<numDup;i++)
    {
        printf("\n\nInsira abaixo as duplas da seguinte forma:\nPrimeiro jogador, Segundo Jogador, Nivel de entrosamento.\n");
        scanf("%i %i %i", &duplas[i][0], &duplas[i][1], &duplas[i][2]);
    }

    int num1, num2;

    for(i = 0; i < (numDup);i++)
    {
        if(i!=(numDup-1))
        {
            if(duplas[i][2]<duplas[i+1][2])
            {
                num1 = i+1;
            } else
            {
                num1 = i;
            }
        }
    }

    for(i = 0; i < (numDup);i++)
    {
        if(i!=(numDup-1))
        {
            if(i!=num1)
            {
                if(duplas[i][2]<duplas[i+1][2])
                {
                    num2 = i;
                } else
                {
                    num2 = i+1;
                }
            }
        }
    }

    printf("%i %i", num1, num2);

    int time = 0;

    if(duplas[num1][0] != duplas[num2][0])
    {
        time++;
    }

    if(duplas[num1][0] != duplas[num2][1])
    {
        time++;
    }

    if(duplas[num1][1] != duplas[num2][0])
    {
        time++;
    }

    if(duplas[num1][1] != duplas[num2][1])
    {
        time++;
    }

    if(time == 4)
    {
        for(i=0;i<numDup;i++)
        {
            if(duplas[num1][0]==duplas[i][0])
            {
                if(duplas[i][1]!=duplas[num1][1])
                {
                    if(duplas[i][1] == duplas[num2][0]||duplas[i][1] == duplas[num2][1])
                    {
                        soma = soma + (duplas[i][2]/2);
                    }
                }
            }

        }

        for(i=0;i<numDup;i++)
        {
            if(duplas[num1][0]==duplas[i][1])
            {
                if(duplas[i][0]!=duplas[num1][1])
                {
                    if(duplas[i][0] == duplas[num2][0]||duplas[i][0] == duplas[num2][1])
                    {
                        soma = soma + (duplas[i][2]/2);
                    }
                }
            }

        }

        for(i=0;i<numDup;i++)
        {
            if(duplas[num1][1]==duplas[i][0])
            {
                if(duplas[i][1]!=duplas[num1][0])
                {
                    if(duplas[i][1] == duplas[num2][0]||duplas[i][1] == duplas[num2][1])
                    {
                        soma = soma + (duplas[i][2]/2);
                    }
                }
            }

        }

        for(i=0;i<numDup;i++)
        {
            if(duplas[num1][1]==duplas[i][1])
            {
                if(duplas[i][0]!=duplas[num1][0])
                {
                    if(duplas[i][0] == duplas[num2][0]||duplas[i][0] == duplas[num2][1])
                    {
                        soma = soma + (duplas[i][2]/2);
                    }
                }
            }

        }

        for(i=0;i<numDup;i++)
        {
            if(duplas[num2][0]==duplas[i][0])
            {
                if(duplas[i][1]!=duplas[num2][1])
                {
                    if(duplas[i][1] == duplas[num1][0]||duplas[i][1] == duplas[num1][1])
                    {
                        soma = soma + (duplas[i][2]/2);
                    }
                }
            }

        }

        for(i=0;i<numDup;i++)
        {
            if(duplas[num2][0]==duplas[i][1])
            {
                if(duplas[i][0]!=duplas[num2][1])
                {
                    if(duplas[i][0] == duplas[num1][0]||duplas[i][0] == duplas[num1][1])
                    {
                        soma = soma + (duplas[i][2]/2);
                    }
                }
            }

        }

        for(i=0;i<numDup;i++)
        {
            if(duplas[num2][1]==duplas[i][0])
            {
                if(duplas[i][1]!=duplas[num2][0])
                {
                    if(duplas[i][1] == duplas[num1][0]||duplas[i][1] == duplas[num1][1])
                    {
                        soma = soma + (duplas[i][2]/2);
                    }
                }
            }

        }

        for(i=0;i<numDup;i++)
        {
            if(duplas[num2][1]==duplas[i][1])
            {
                if(duplas[i][0]!=duplas[num2][0])
                {
                    if(duplas[i][0] == duplas[num1][0]||duplas[i][0] == duplas[num1][1])
                    {
                        soma = soma + (duplas[i][2]/2);
                    }
                }
            }

        }

    } else
    {

        for(i=0;i<numDup;i++)
        {
            if(duplas[num1][0]==duplas[i][0])
            {
                if(duplas[i][1]!=duplas[num1][1] && duplas[i][1]!=duplas[num2][0] && duplas[i][1]!=duplas[num2][1])
                {
                    soma = soma + (duplas[i][2]/2);
                    jog = duplas[i][1];
                }
            }
        }

        for(i=0;i<numDup;i++)
        {
            if(duplas[num1][0]==duplas[i][1])
            {
                if(duplas[i][0]!=duplas[num1][1] && duplas[i][0]!=duplas[num2][0] && duplas[i][0]!=duplas[num2][1])
                {
                    soma = soma + (duplas[i][2]/2);
                    jog = duplas[i][0];
                }
            }
        }

        for(i=0;i<numDup;i++)
        {
            if(duplas[num1][1]==duplas[i][0])
            {
                if(duplas[i][1]!=duplas[num1][1] && duplas[i][1]!=duplas[num2][0] && duplas[i][1]!=duplas[num2][1])
                {
                    soma = soma + (duplas[i][2]/2);
                    jog = duplas[i][1];
                }
            }
        }

        for(i=0;i<numDup;i++)
        {
            if(duplas[num1][1]==duplas[i][1])
            {
                if(duplas[i][0]!=duplas[num1][1] && duplas[i][0]!=duplas[num2][0] && duplas[i][0]!=duplas[num2][1])
                {
                    soma = soma + (duplas[i][2]/2);
                    jog = duplas[i][0];
                }
            }
        }

        for(i=0;i<numDup;i++)
        {
            if(duplas[num2][0]==duplas[i][0])
            {
                if(duplas[i][1]!=duplas[num2][1] && duplas[i][1]!=duplas[num1][0] && duplas[i][1]!=duplas[num1][1])
                {
                    soma = soma + (duplas[i][2]/2);
                    jog = duplas[i][1];
                }
            }
        }

        for(i=0;i<numDup;i++)
        {
            if(duplas[num2][0]==duplas[i][1])
            {
                if(duplas[i][0]!=duplas[num2][1] && duplas[i][0]!=duplas[num1][0] && duplas[i][0]!=duplas[num1][1])
                {
                    soma = soma + (duplas[i][2]/2);
                    jog = duplas[i][0];
                }
            }
        }

        for(i=0;i<numDup;i++)
        {
            if(duplas[num2][1]==duplas[i][0])
            {
                if(duplas[i][1]!=duplas[num2][1] && duplas[i][1]!=duplas[num1][0] && duplas[i][1]!=duplas[num1][1])
                {
                    soma = soma + (duplas[i][2]/2);
                    jog = duplas[i][1];
                }
            }
        }

        for(i=0;i<numDup;i++)
        {
            if(duplas[num2][1]==duplas[i][1])
            {
                if(duplas[i][0]!=duplas[num2][1] && duplas[i][0]!=duplas[num1][0] && duplas[i][0]!=duplas[num1][1])
                {
                    soma = soma + (duplas[i][2]/2);
                    jog = duplas[i][0];
                }
            }
        }
    }

    printf("%i", soma);
    soma = soma + duplas[num1][2] + duplas[num2][2];

    if(jog>1)
    {
        printf("\n\nO maior entrosamento eh de %i com os jogadores %i, %i, %i, %i, Ronaldo, %i\n\n", soma, duplas[num1][0], duplas[num1][1], duplas[num2][0],duplas[num2][1], jog);
    } else
    {
        printf("\n\nO maior entrosamento eh de %i com os jogadores %i, %i, %i, %i, Ronaldo\n\n", soma, duplas[num1][0], duplas[num1][1], duplas[num2][0],duplas[num2][1]);
    }
    return 0;
}
