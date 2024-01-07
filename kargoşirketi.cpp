#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLO_BOYUTU 10
#define DOSYA_ADI "veri.txt"

typedef struct {
    int takipNo;
    char gonderici[100];
    char alici[100];
    char kargoDurum[100];
} Kargo;

Kargo *hash_tablo[TABLO_BOYUTU];

int hashIndex(int takipNo) {
    return takipNo % TABLO_BOYUTU;
}

int doubleHash(int takipNo, int i) {
    int originalIndex = 7 - (takipNo % 7);
    return (hashIndex(takipNo) + i * originalIndex) % TABLO_BOYUTU;
}

void kargoEkle(Kargo *kargo) {
      Kargo *yeniKargo = (Kargo *)malloc(sizeof(Kargo));
    yeniKargo->takipNo = kargo->takipNo;
    strcpy(yeniKargo->gonderici, kargo->gonderici);
    strcpy(yeniKargo->alici, kargo->alici);
    strcpy(yeniKargo->kargoDurum, kargo->kargoDurum);

    int index = hashIndex(kargo->takipNo);

    if (hash_tablo[index] == NULL) {
        hash_tablo[index] = yeniKargo;
        printf("EKLE -> %d: Hash tablosunun %d. indeksine eklendi.\n", kargo->takipNo, index);
    } else {
        int i = 1;
        int originalIndex = 7 - (kargo->takipNo % 7);

        while (1) {
            int newIndex = (index + i * originalIndex) % TABLO_BOYUTU;

            if (hash_tablo[newIndex] == NULL) {
                hash_tablo[newIndex] = yeniKargo;
                printf("EKLE -> %d: Hash tablosunun %d. indeksine eklendi.\n", kargo->takipNo, newIndex);
                break;
            }
            i++;

            if (i >= TABLO_BOYUTU) {
                printf("EKLE -> %d: Tablo dolu, takip numarasi ekleme islemi basarisiz.\n", kargo->takipNo);
                free(yeniKargo); 
                return;
            }
        }
    }
 }

void kargoSil(int takipNo) {
    int index = hashIndex(takipNo);

    if (hash_tablo[index] != NULL && hash_tablo[index]->takipNo == takipNo) {
        free(hash_tablo[index]);
        hash_tablo[index] = NULL;
        printf("Takip No: %d olan kargo basariyla silindi.\n", takipNo);
        return;
    }

    int adim = 1;
    int originalIndex = index;

    while (1) {
        index = doubleHash(takipNo, adim);
        adim++;

        if (hash_tablo[index] != NULL && hash_tablo[index]->takipNo == takipNo) {
            free(hash_tablo[index]);
            hash_tablo[index] = NULL;
            printf("Takip No: %d olan kargo basariyla silindi.\n", takipNo);
            return;
        }

        if (index == originalIndex) {
            break;
        }
    }

    printf("Takip No: %d olan kargo bulunamadi.\n", takipNo);
    
}
void kargoEkleDosyaya(Kargo *kargo) {
    FILE *dosya = fopen(DOSYA_ADI, "a"); 

    if (dosya == NULL) {
        printf("Dosya acma hatasi!\n");
        return;
    }

    fprintf(dosya, "%d %s %s %s\n", kargo->takipNo, kargo->gonderici,
            kargo->alici, kargo->kargoDurum);

    fclose(dosya);
}

void kargoBilgileriDosyadanOku() {
     FILE *dosya = fopen(DOSYA_ADI, "r");

    if (dosya == NULL) {
        printf("Dosya acma hatasi!\n");
        return;
    }

    while (1) {
        Kargo *kargo = (Kargo *)malloc(sizeof(Kargo));

        int result = fscanf(dosya, "%d %s %s %s", &kargo->takipNo, kargo->gonderici,
                            kargo->alici, kargo->kargoDurum);

        if (result == 4) {
            kargoEkle(kargo);
        } else {
            free(kargo);
            break;
        }
    }

    fclose(dosya);

    }


Kargo *kargoAra(int takipNo, int *adimSayisi) {
    int index =0;
    int adim = 1;
    int originalIndex = index;

    while (1) {
        if (hash_tablo[index] != NULL && hash_tablo[index]->takipNo == takipNo) {
            *adimSayisi = adim;
            return hash_tablo[index];
        }
         index++;
        
        adim++;
        if(hash_tablo[index] == NULL){
        	adim--;
		}
    }
    return NULL;
}


void kargoBilgisiGir() {
    Kargo *kargo = (Kargo *)malloc(sizeof(Kargo));

    printf("Takip No: ");
    scanf("%d", &kargo->takipNo);
    printf("Gonderici: ");
    scanf("%s", kargo->gonderici);
    printf("Alici: ");
    scanf("%s", kargo->alici);
    printf("Kargo Durumu: ");
    scanf("%s", kargo->kargoDurum);

    kargoEkle(kargo);
    kargoEkleDosyaya(kargo);
    free(kargo); 
}

void kargoTakip() {
    int takipNo;
    printf("Takip Numarasi: ");
    scanf("%d", &takipNo);

    int adimSayisi;
    Kargo *arananKargo = kargoAra(takipNo, &adimSayisi);

    if (arananKargo != NULL && adimSayisi != -1) {
        printf("Kargo bulundu! Hash tablosunda %d adimda bulundu.\n", adimSayisi);
        printf("Kargo Bilgileri:\n");
        printf("Takip No: %d, Gonderici: %s, Alici: %s, Durum: %s\n",
               arananKargo->takipNo, arananKargo->gonderici,
               arananKargo->alici, arananKargo->kargoDurum);
    } else {
        printf("Kargo bulunamadi.\n");
    }
}

void kargoYazdir() {
    printf("Hash Tablosu:\n");
    for (int i = 0; i < TABLO_BOYUTU; i++) {
        if (hash_tablo[i] != NULL) {
            printf("Index %d: Takip No:%d\tGonderici:%s\tAlici:%s\tDurum:%s\n",
                   i, hash_tablo[i]->takipNo, hash_tablo[i]->gonderici,
                   hash_tablo[i]->alici, hash_tablo[i]->kargoDurum);
        } else {
            printf("Index %d: Bos\n", i);
        }
    }
}
void kargolariListele() {
    printf("Hash Tablosundaki Kargolar:\n");
    for (int i = 0; i < TABLO_BOYUTU; i++) {
        if (hash_tablo[i] != NULL) {
            int adimSayisi;
            Kargo *arananKargo = kargoAra(hash_tablo[i]->takipNo, &adimSayisi);

            if (arananKargo != NULL) {
                printf("Index %d: %d adimda bulundu\t", i, adimSayisi);
                printf("Takip No:%d\tGonderici:%s\tAlici:%s\tDurum:%s\n",
                       arananKargo->takipNo, arananKargo->gonderici,
                       arananKargo->alici, arananKargo->kargoDurum);
            } else {
                printf("Index %d: Hatali\n", i);
            }
        } else {
            printf("Index %d: Bos\n", i);
        }
    }
}


int main() {
    kargoBilgileriDosyadanOku(); 

    int secim;
    do {
        printf("\n1. Kargo Bilgilerini Goster\n2. Kargo Bilgisi Gir\n3. Kargo Teslim Et\n4. Kargolari Listele\n5.Kargo Takip\n6.Cikis\nSecim: ");
        scanf("%d", &secim);

        switch (secim) {
            case 1:
                kargoYazdir(); 
                break;
            case 2:
                kargoBilgisiGir(); 
                break;
            case 3:
                printf("Teslim etmek istediginiz kargonun takip numarasini girin: ");
                int takipNo;
                scanf("%d", &takipNo);
                kargoSil(takipNo);
                break;
            case 4:
                kargolariListele();
                break;
                case 5:
                kargoTakip(); 
                break;
            case 6:
                printf("Programdan cikiliyor...\n");
                break;
            default:
                printf("Gecersiz secim! Tekrar deneyin.\n");
                break;
        }
    } while (secim != 6);

    return 0;
}

