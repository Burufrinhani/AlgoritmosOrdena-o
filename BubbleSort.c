#include <stdio.h>
int main()
{
    int data[100],i,n,step,temp;
    printf("Digite o número de elementos que deseja ordenar: ");
    scanf("%d",&n);
    for(i=0;i<n;++i)
    {
        printf("%d. Insira o elemento aqui:",i+1);
        scanf("%d",&data[i]);
    }
    for(step=0;step<n-1;++step)
    for(i=0;i<n-step-1;++i)
    {
        if(data[i]>data[i+1]) 
        {
            temp=data[i];
            data[i]=data[i+1];
            data[i+1]=temp;
        }
    }
    printf("Em ordem crescente:");
    for(i=0;i<n;++i)
         printf("%d  ",data[i]);
    return 0;
}