#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char masa[10], icecek[10], sayi[30];
} Siparis;
//girilen icecegin en cok soylendigi siparisi geri donduren fonksiyon
Siparis siparisAdet(char *icecekisim);

int main() {
    char girick[10];
    printf("Icecek adi: ");
    scanf("%9s", girick);

    for (int i = 0; girick[i]; i++) girick[i] = toupper(girick[i]);
    //burdaki amaç kucuk harfleri buyuk harflere cevirmek

    Siparis sonuc = siparisAdet(girick);

    if (strcmp(sonuc.masa, "YOK") != 0) {
        printf("En fazla %s icen : %s (%zu)\n",
                sonuc.icecek, sonuc.masa, strlen(sonuc.sayi));
    }

    return 0;
}

Siparis siparisAdet(char *icecekisim) {
    FILE *file = fopen("Siparis.txt", "r");
    Siparis mevcut, enIyisi = {"YOK", "YOK", "YOK"};
    int bulundu = 0;
    if (file == NULL) {
        printf("Dosya acilamadi...\n");
        return enIyisi;
    }

    while (fscanf(file, "%s %s %s", mevcut.masa, mevcut.icecek, mevcut.sayi) == 3) {
        if (strcmp(icecekisim, mevcut.icecek) == 0) {
            if (!bulundu || strlen(mevcut.sayi) > strlen(enIyisi.sayi)) {
                enIyisi = mevcut;
                bulundu = 1;
            }
        }
    }
    //dosyayı kapattık
    fclose(file);
    //siparis bulunmadiginda bu calısacak
    if (!bulundu) {
        printf("\nBu icecek tuketilmemistir...\n");
        strcpy(enIyisi.masa, "YOK");
        //burda "YOK" yazisini enIyisi.masaya kopyaladik;
    }
    return enIyisi;
}
