#include <stdio.h>

// 0 1 1 2 3 5 8 13
//  

void main() {
    int fn; 
    int fn_1 = 1;
    int fn_2 = 0;
    int count;

    printf("Sayi girin : ");
    scanf("%d", &count);
    printf("%d  ", fn_2);

    for (int i = 0 ; i < count; i++)
    {
        
        fn = fn_1 + fn_2;
        fn_1 = fn_2;
        fn_2 = fn;

        printf("%d  ", fn); 
    }
    


}
