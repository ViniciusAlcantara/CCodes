#include <stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv)
{
    int m[3][12],soma,d;//declacao de variaveis
    int resto_div,i,j,x;
    soma = 0;
    printf("Entre com os digitos ISBN:");
    for(j=0;j<12;j++)//repeticao para ler os digitos do teclado
    {
        scanf(" %d",&m[0][j]);
        if(j%2==0)//condicao para preencher os espacos com 1 e 3
        {
            m[1][j]= 1;
        }else
        {
             m[1][j]= 3;
        }
    }
    for(i=0;i<12;i++)//for para fazer a multiplicacao dos valores das linhas 0 e 1
    {
        m[2][i]= m[0][i]*m[1][i];
        soma = soma + m[2][i];//soma dos produtos encontrados na linha de cima
    }
    resto_div = soma%10;//linha para fazer a divisao da soma por 10 e pegar o resto
    if(resto_div>0)//teste para saber se o resto eh maior que 0 para poder subtrair de 10 e encontrar o digito
    {
        d = 10 - resto_div;
    }else if(resto_div==0)
    {
        d = 0;
    }
    x = soma + d;//somando a soma com o digito verificador encontrado acima para poder testar
    x = x%10;//pegando o resto da divisao do calculo feito na linha de cima por 10.
    if(x==0)//teste para saber se o d
    {
        printf("\nDigito verificador: %d\n", d);
    }else
    {
        printf("\nDigito verificador invalido.\n");
    }
    system("pause");
    return 0;
}
