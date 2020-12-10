#include <stdio.h>
/* mini program belajar bubble short by Maviism */

void printBubble(int arr[], int size){
    int i;
    printf("bubble short ascending : ");

    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bubbleShortAscend(int arr[], int size){
    int i, j;
    int temp;
    for (i = 0; i < size; i++)
    {
        for (j = 1; j < size; j++)
        {
            if (arr[j] < arr[j-1])
            {
                temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
            }
            
        }
        
    }
    printBubble(arr, size);
}

void bubbleShortDescend(int arr[], int size){
    int i,j;
    int temp;
    
    for (i = 0; i < size; i++)
    {
        for (j = 1; j < size; j++)
        {
            if (arr[j] > arr[j-1])
            {
                temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
            }
            
        }
        
    }
    printBubble(arr, size);
    
}

void main(){
    int i;
    int size;

    printf("====bubble short program====\n");
    printf("Masukan jumlah angka : ");
    scanf("%d", &size);
    int arr[size];
    
    for (i = 0; i < size; i++)
    {
        printf("masukan angka ke - %d : ", i);
        scanf("%d", &arr[i]);
    }

    bubbleShortAscend(arr, size);
    bubbleShortDescend(arr, size);
    
    
    getchar();
    
}