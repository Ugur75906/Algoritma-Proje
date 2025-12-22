#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct{
    char masa[10],icecek[10],sayi[30];}Siparis;
Siparis siparisAdet(char *icecekisim){
    char liste[255],gecici[255];
    liste[0] = '\0';
    FILE *file;
    file = fopen("Siparis.txt","r");
    if (file == NULL) {
        printf("File cannot be opened...\n");
        Siparis bulunamadi = {"YOK","YOK","YOK"};
        return bulunamadi;
    }
    while (fgets(gecici, sizeof(gecici), file)) {
     strcat(liste, gecici);} 
    fclose(file);
    int sipsay = 1, icilmismi = 0, verileceksiparis = -1, icilmesayi = 0;
    for(int i=0;liste[i]!='\0';i++){
     if(liste[i]=='\n'){
      sipsay++;}  }
    Siparis siparis[sipsay];
    int okunanKar=0,ilerleme=0,sipTakip=0;
    while(sscanf(liste+ilerleme,"%s %s %s%n",siparis[sipTakip].masa,siparis[sipTakip].icecek,siparis[sipTakip].sayi,&okunanKar)==3){
     sipTakip++;
     ilerleme +=okunanKar; }
    for (int i = 0; i < sipsay; i++) {
     if (strcmp(icecekisim, siparis[i].icecek) == 0) {
      if (verileceksiparis == -1 || strlen(siparis[i].sayi) > icilmesayi) {
       verileceksiparis = i;
       icilmesayi = strlen(siparis[i].sayi);
      }
      icilmismi = 1;
     }
    }
    if(icilmismi == 0){
     printf("\nBu icecek tuketilmemistir...\n");
     Siparis bulunamadi = {"YOK","YOK","YOK"};
     return bulunamadi;}
    return siparis[verileceksiparis];
}
int main() {
    Siparis istenensiparis = {"YOK","YOK","YOK"};
    Siparis bulunmamis = {"YOK","YOK","YOK"};
    char girick[10];
    printf("Icecek adi: ");
    scanf("%9s", girick);
    for (int i = 0; girick[i] != '\0'; i++) {
    girick[i] = toupper(girick[i]);}
    fflush(stdout);
    istenensiparis = siparisAdet(girick);
    if(strcmp(istenensiparis.masa,bulunmamis.masa) == 0){
    return 1;}
    printf("En fazla %s icen : %s (%zu)\n", istenensiparis.icecek, istenensiparis.masa, strlen(istenensiparis.sayi));
    return 0;
}