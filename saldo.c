#include<stdio.h>
#include<stdlib.h>

struct account{
    int akunBank;
    int akunCreditCard;
    int akunKartu;
}a1;

int saldo(char x[]){

        printf ("NOTE : Jika tidak memiki Saldo pada Akun dibawah ini Ketik 0\n");
        printf ("Ketik Saldo Pada Akun Bank: ");
        scanf  ("%d", &a1.akunBank);
        printf ("Ketik Saldo Pada Akun Credit Card: ");
        scanf  ("%d", &a1.akunCreditCard);
        printf ("Ketik Saldo Pada Akun Tabungan Cash: ");
        scanf  ("%d", &a1.akunKartu);
    
    // Deklarasi Variabel untuk menjumlahkan nilai accout
    int saldoDimiliki = a1.akunBank + a1.akunBank + a1.akunKartu;   
        printf ("Total Saldo yang dimiliki %d\n", saldoDimiliki);

    FILE *us; //pointerReport pada trackRecord
    us = fopen (x, "ab");
    fwrite (&a1, sizeof(a1), 1, us);
    fclose (us);
    system ("clear");
    return saldoDimiliki;
}   
