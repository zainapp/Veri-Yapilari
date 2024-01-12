#include <stdio.h>
#include <stdlib.h>

void merge(int dizi[], int sol, int orta, int sag) {
    
	   int i, j, k;
    int n1 = orta - sol + 1;
    int n2 = sag - orta;

    // Ge�ici diziler olu�tur
    int L[n1], R[n2];

    // Ge�ici dizilere verileri kopyala
    for (i = 0; i < n1; i++)
        L[i] = dizi[sol + i];
    for (j = 0; j < n2; j++)
        R[j] = dizi[orta + 1 + j];

    // Ge�ici dizilerden ana diziyi birle�tir
    i = 0;
    j = 0;
    k = sol;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            dizi[k] = L[i];
            i++;
        } else {
            dizi[k] = R[j];
            j++;
        }
        k++;
    }

    // Geriye kalan elemanlar� kopyala (e�er varsa)
    while (i < n1) {
        dizi[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        dizi[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int dizi[], int sol, int sag) {
    if (sol < sag) {
        // Diziyi ikiye ay�r
        int orta = sol + (sag - sol) / 2;

        // Her iki par�ay� da s�rala
        mergeSort(dizi, sol, orta);
        mergeSort(dizi, orta + 1, sag);

        // S�ral� par�alar� birle�tir
        merge(dizi, sol, orta, sag);
    }
}

int main() {
    int n;

    printf("Dizi boyutunu girin: ");
    scanf("%d", &n);

    int dizi[n];

    printf("Diziyi girin:\n");
    for (int i = 0; i < n; i++) {
        printf("Eleman %d: ", i + 1);
        scanf("%d", &dizi[i]);
    }

    // Merge Sort'u uygula
    mergeSort(dizi, 0, n - 1);

    
    printf("\nSirali dizi: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", dizi[i]);
    }

    return 0;
}

