#include <stdio.h>

void main (){

    int count;
    printf("sayi giriniz :");
    scanf("%d", &count);
    

    //1. sekil
    for (int i = 0; i <= count; i++)
    {
        for (int j = 0; j < i; j++)
        {
            printf("*");
        }
        printf("\n");
        
    }

    printf("\n");
    //3. sekil

     for (int i = 1; i <= count; i++)
    {
        for (int j = 1; j < i; j++)
        {
            printf(" ");
            
        }
        for (int k = count; k >= i; k--)
        {
            printf("*");
        }
        printf("\n");
    }
    printf("\n");
    //2. sekil
    for (int i = 0; i < count; i++)
    {
        for (int j = count; j > i; j--)
        {
            printf("*");
        }
        printf("\n");
    }

    //4. sekil
    printf("\n");
     for (int i = 0; i < count; i++)
    {
        for (int j = count; j > i + 1; j--)
        {
            printf(" ");
        }
        for (int k = 0; k <= i; k++)
        {
            printf("*");
        }
        
        printf("\n");
    }
    

    //segitiga sama kaki
    printf("\n");
    for (int i = 1; i < count; i++)
    {
        for (int j = count; j > i; j--)
        {
            printf(" ");
        }
        for (int k = 0; k < i ; k++)
        {
            printf("*");
        }
        for (int l = 1; l < i; l++)
        {
            printf("*");
        }
        

        printf("\n");
        
        
    }

     for (int i = 0; i < count; i++)
    {
        for (int l = 0; l < i; l++)
        {
            printf(" ");
        }
        for (int j = count; j > i; j--)
        {
            printf("*");
        }
    
        for (int k = count; k - 1 > i; k--)
        {
            printf("*");
        }
        

        printf("\n");
        
        
    }
    
}