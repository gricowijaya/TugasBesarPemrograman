#include "function.h"
#include "structure.h"
#include "variable.h"
#include <stdio.h>
#include <stdlib.h>


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
int inputSaldo(char x[]){
        //Pada bagian ini user diminta untuk memasukkan jumlah saldo yang di miliki sebagai starter dalam program manajemen keuangan ini
        printf ("\t\t\t\t\t||=============||\n");
        printf ("\t\t\t\t\t||Masukan Saldo||\n");
        printf ("\t\t\t\t\t||=============||\n");
        //Instruksi untuk menginput nilai saldo
        printf ("\t\t\t\t\t #NOTE : Jika tidak memiki Saldo pada Akun dibawah ini Ketik 0\n\n\n");
        printf ("\t\t\t\t\t||==================================||\n");
        printf ("\t\t\t\t\t||Ketik Saldo Pada Akun Bank         : ");
        scanf  ("%d", &a1.akunBank);
        printf ("\t\t\t\t\t||Ketik Saldo Pada Akun Credit Card  : ");
        scanf  ("%d", &a1.akunCreditCard);
        printf ("\t\t\t\t\t||Ketik Saldo Pada Akun Tabungan Cash: ");
        scanf  ("%d", &a1.cash);
        printf ("\t\t\t\t\t||==================================||\n");

    //Deklarasi Variabel untuk menjumlahkan nilai accout
        saldoDimiliki = a1.akunBank + a1.akunCreditCard + a1.cash;
        printf ("\t\t\t\t\t||Total Saldo yang dimiliki %d\n", saldoDimiliki);
        printf ("\t\t\t\t\t||==================================||\n");

    //Deklarasi Tipe Data File dengan pointer *us
    FILE *us; //pointerReport pada trackRecord
    //Membuka file Record.dat untuk dibuka dengan mode ab untuk menambahkan nilai saldo-saldo yang diinput
    us = fopen (x, "a");
    //Menuliskan hasil input data kepada "Record.dat"
    fwrite (&a1, sizeof(a1), 1, us);
    //Menggunakan fungsi fclose untuk menutup file "Record.dat" agar tidak diproses lagi
    fclose (us);

    //untuk menghilangkan perintah-perintah dari layar terminal
    system ("clear");
    return saldoDimiliki;
}

//=======================================================================//
//**************       Fungsi Untuk Input Pemasukan      ****************//
//=======================================================================//
// Nama Fungsi    : input_masukan                                        //
// Input Argumen  : int masukan [], char Det_Masukan                     //
// Output Argumen : -                                                    //
// Deskripsi      : Meminta user untuk memasukan banyak pemasukan        //
//                  dan mengisi detail pemasukan yang dilakukan oleh     //
//                  yang dilakukan oleh user.                            //
//                                                                       //
// Versi : 1.0                                      Rev. 0               //
// Tgl   : 03-12-2020                               Tgl: 03-12-2020      //
// I Gede Himawan - 2005551108                                           //
// Kelas A                                                               //
//=======================================================================//
void input_masukan(){
        printf ("\t\t\t\t\t|===================================|\n");
        printf ("\t\t\t\t\t|| Masukkan Banyak Pemasukan Anda :");
        scanf  ("%d",&masukan);
}

//=======================================================================//
//**************   Fungsi Untuk Menginputkan Pemasukan   ****************//
//=======================================================================//
// Nama Fungsi    : pemasukan                                            //
// Input Argumen  : int ktgrimasukan                                     //
// Output Argumen : -                                                    //
// Deskripsi      : Menampilkan Kategori Pemasukan yang ada lalu         //
//                  memanggil fungsi input_masukan yang meminta user     //
//                  untuk melakukan input saldo dan di proses untuk      //
//                  mendapatkan jumlah saldo terbaru.                    //
//                                                                       //
// Versi : 1.2                                      Rev. 2               //
// Tgl   : 03-12-2020                               Tgl: 21-12-2020      //
// Revisi: Menambahkan pemanggilan fungsi waktu untuk menginfokan waktu  //
//        Saat user mengakses program.                                   //
// I Gede Himawan - 2005551108                                           //
// Kelas A                                                               //
//=======================================================================//
int pemasukan (){
    printf ("\t\t\t\t\tSaldo yang anda miliki pada setiap akun keuangan:\n");
    printf ("\t\t\t\t\t            ||Saldo pada Bank   : %d\n",*bank);
    printf ("\t\t\t\t\t            ||Saldo pada kredit : %d\n",*kredit);
    printf ("\t\t\t\t\t            ||Saldo pada cash   : %d\n",*cash);
    mtd:
    printf ("\t\t\t\t\t|================================================|\n");
    printf ("\t\t\t\t\t|                  AKUN PEMASUKAN                |\n");
    printf ("\t\t\t\t\t|================================================|\n");
    printf ("\t\t\t\t\t|   No  |    Pilihan Akun Pemasukan              |\n");
    printf ("\t\t\t\t\t|-------|----------------------------------------|\n");
    printf ("\t\t\t\t\t|   1   |    Akun Bank                           |\n");
    printf ("\t\t\t\t\t|   2   |    Akun Credit Card                    |\n");
    printf ("\t\t\t\t\t|   3   |    Cash                                |\n");
    printf ("\t\t\t\t\t|================================================|\n");
    printf ("\t\t\t\t\t|================================================|\n");
    printf ("\n\t\t\t\t\t Masukkan Akun Pemasukan :");
    scanf  ("%d",& mtdmsk);
    printf ("\t\t\t\t\t|================================================|\n");
    system ("clear");
    ktgrimasuk:
    printf ("\t\t\t\t\t|================================================|\n");
    printf ("\t\t\t\t\t|                KATEGORI PEMASUKAN              |\n");
    printf ("\t\t\t\t\t|================================================|\n");
    printf ("\t\t\t\t\t|   No  |      Jenis Pemasukan                   |\n");
    printf ("\t\t\t\t\t|-------|----------------------------------------|\n");
    printf ("\t\t\t\t\t|   1   |        Sewa                            |\n");
    printf ("\t\t\t\t\t|   2   |        Sumbangan                       |\n");
    printf ("\t\t\t\t\t|   3   |        Dividen                         |\n");
    printf ("\t\t\t\t\t|   4   |        Pengembalian Dana               |\n");
    printf ("\t\t\t\t\t|   5   |        Upah                            |\n");
    printf ("\t\t\t\t\t|   6   |        Penjualan                       |\n");
    printf ("\t\t\t\t\t|   7   |        Bonus                           |\n");
    printf ("\t\t\t\t\t|   8   |        Voucher                         |\n");
    printf ("\t\t\t\t\t|   9   |        Lainnya                         |\n");
    printf ("\t\t\t\t\t|================================================|\n");

    printf ("\t\t\t\t\t| Masukan Kategori Pemasukan yang anda miliki => ");
    scanf  ("%d",&ktgrimasukan);
    switch (ktgrimasukan){
        case 1:
            printf ("\n\n\t\t\t\t\t|=================|\n");
            printf ("\t\t\t\t\t|      Sewa       |\n");
            printf ("\t\t\t\t\t|=================|\n");
            waktu();
            input_masukan();
            system ("clear");
            break;
        case 2:
            printf ("\n\n\t\t\t\t\t|=================|\n");
            printf ("\t\t\t\t\t|    Sumbangan    |\n");
            printf ("\t\t\t\t\t|=================|\n");
            waktu();
            input_masukan();
            system ("clear");
            break;
        case 3:
            printf ("\n\n\t\t\t\t\t|=================|\n");
            printf ("\t\t\t\t\t|      Deviden    |\n");
            printf ("\t\t\t\t\t|=================|\n");
            waktu();
            input_masukan();
            system ("clear");
            break;
        case 4:
            printf ("\n\n\t\t\t\t\t|=====================|\n");
            printf ("\t\t\t\t\t|   Pengembalian Dana |\n");
            printf ("\t\t\t\t\t|=====================|\n");
            waktu();
            input_masukan();
            system ("clear");
            break;
        case 5:
            printf ("\n\n\t\t\t\t\t|=================|\n");
            printf ("\t\t\t\t\t|       Upah      |\n");
            printf ("\t\t\t\t\t|=================|\n");
            waktu();
            input_masukan();
            system ("clear");
            break;
        case 6:
            printf ("\n\n\t\t\t\t\t|=================|\n");
            printf ("\t\t\t\t\t|    Penjualan    |\n");
            printf ("\t\t\t\t\t|=================|\n");
            waktu();
            input_masukan();
            system ("clear");
            break;
        case 7:
            printf ("\n\n\t\t\t\t\t|=================|\n");
            printf ("\t\t\t\t\t|      Bonus      |\n");
            printf ("\t\t\t\t\t|=================|\n");
            waktu();
            input_masukan();
            system ("clear");
            break;
        case 8:
            printf ("\n\n\t\t\t\t\t|=================|\n");
            printf ("\t\t\t\t\t|      Voucher    |\n");
            printf ("\t\t\t\t\t|=================|\n");
            waktu();
            input_masukan();
            system ("clear");
            break;
        case 9:
            printf ("\n\n\t\t\t\t\t|=================|\n");
            printf ("\t\t\t\t\t|      Lainnya    |\n");
            printf ("\t\t\t\t\t|=================|\n");
            waktu();
            input_masukan();
            waktu();
            system ("clear");
            break;
        default:
           error_alert();
        goto ktgrimasuk;
        break;
        system ("clear");
    }
    if (mtdmsk == 1){
        int pb  = *bank + masukan;
        *bank   = pb;
    }
    else if (mtdmsk == 2){
        int pk   = *kredit + masukan;
        *kredit = pk;

    }
    else if (mtdmsk == 3){
        int pc  = *cash + masukan;
        *cash  = pc;
    }
    else{
        error_alert();
        goto mtd;
    }
    total  = *saldo + masukan;
    *saldo = total;
    return total;
}
