#include <stdio.h>


void selectionSort(int dizi[], int n) {
    int i, j, minIndis, temp;
    
    for (i = 0; i < n - 1; i++) {
        minIndis = i;
        for (j = i + 1; j < n; j++) {
            if (dizi[j] < dizi[minIndis]) {
                minIndis = j;
            }
        }
       
        temp = dizi[minIndis];
        dizi[minIndis] = dizi[i];
        dizi[i] = temp;
    }
}

int main() {
    int n, i;

    printf("Dizinin boyutunu girin: ");
    scanf("%d", &n);

    int dizi[n];

    printf("Dizinin elemanlarini girin:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &dizi[i]);
    }

    
    selectionSort(dizi, n);

    
    printf("Siralanmis dizi: ");
    for (i = 0; i < n; i++) {
        printf("%d ", dizi[i]);
    }

    return 0;
}

