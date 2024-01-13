#include <stdio.h>

void insertionSort(int dizi[], int size) {
   
   		 int i, eleman, j;
    for (i = 1; i < size; i++) {
        eleman = dizi[i];
        j = i - 1;

        
        while ( j >= 0 && dizi[j] > eleman ) {
            dizi[j + 1] = dizi[j];
            j = j - 1;
        }
        dizi[j + 1] = eleman;
    }
}

int main() {
    int size;

    printf("Dizinin eleman sayisini girin: ");
    scanf("%d", &size);

    int dizi[size];

    printf("Dizinin elemanlarini girin:\n");
    for (int i = 0; i < size; i++) {
        printf("Eleman %d: ", i + 1);
        scanf("%d", &dizi[i]);
    }

    
    insertionSort(dizi, size);

    
    printf("Siralanmis dizi: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", dizi[i]);
    }

    return 0;
}

