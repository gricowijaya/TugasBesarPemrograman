#include<stdio.h>

int DanaDarurat (int saldo){
    int dana = saldo * 0.3;
        printf ("Dalam Manajemen Keungangan Anda harus diperlukan Dana Darurat\n");
        printf ("Mengapa ?\nKarena agar finansial bisa siap dalam keadaan darurat,\n");
        printf ("Untuk itu maka diperlukan Dana Darurat yang disarankan yaitu\n30 persen dari saldo yang dimilki\n");
        printf ("Jadi Dana yang harus dipersiapkan adalah: %d\n", dana);
    saldo = dana;
    return dana;
}