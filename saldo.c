#include<stdio.h>
#include<stdlib.h>

//Deklarasi struct account untuk membuat member akunBank, akunCreditCard, cash
struct account{
    int akunBank; //Untuk menyimpan nilai saldo pada akun rekening di Bank
    int akunCreditCard; //Untuk menyimpan nilai saldo pada akun Credit Card
    int cash; //Untuk meniympan nilai uang cash yang dimiliki
}a1;

//=======================================================================//
//***********      Fungsi Untuk Menginput Data Saldo     ****************//
//=======================================================================//
// Nama Fungsi    : saldo                                                //
// Passing Argumen: charx[]                                              //
// Input Argumen  : a1.akunBank, a1.akunCreditCard, a1.cash              //
// Output Argumen : int saldoDimiliki                                    //
// Deskripsi      : untuk menginput dan menyimpan nilai saldo pada masing//
//                  -masing akun keuangan.                               //
// Versi : 1.0                                      Rev. 0               //
// Tgl: 28-11-2020                                  Tgl: 28-1-2020       //
// Gede Rico Wijaya - 2005551091                                         //
// Kelas A                                                               //
//=======================================================================//
int saldo(char x[]){

        //Instruksi untuk menginput nilai saldo
        printf ("NOTE : Jika tidak memiki Saldo pada Akun dibawah ini Ketik 0\n");
        printf ("Ketik Saldo Pada Akun Bank: ");
        scanf  ("%d", &a1.akunBank);
        printf ("Ketik Saldo Pada Akun Credit Card: ");
        scanf  ("%d", &a1.akunCreditCard);
        printf ("Ketik Saldo Pada Akun Tabungan Cash: ");
        scanf  ("%d", &a1.cash);
    
    //Deklarasi Variabel untuk menjumlahkan nilai accout
    int saldoDimiliki = a1.akunBank + a1.akunCreditCard + a1.cash;   
        printf ("Total Saldo yang dimiliki %d\n", saldoDimiliki);

    //Deklarasi Tipe Data File dengan pointer *us
    FILE *us; //pointerReport pada trackRecord
    //Membuka file Record.dat untuk dibuka dengan mode ab untuk menambahkan nilai saldo-saldo yang diinput
    us = fopen (x, "ab");
    //Menuliskan hasil input data kepada "Record.dat"
    fwrite (&a1, sizeof(a1), 1, us);
    //Menggunakan fungsi fclose untuk menutup file "Record.dat" agar tidak diproses lagi
    fclose (us);

    //untuk menghilangkan perintah-perintah dari layar terminal
    system ("clear");
    return saldoDimiliki;
}   
