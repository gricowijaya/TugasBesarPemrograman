#include "function.h"
#include "structure.h"
#include "variable.h"
#include <stdio.h>
#include <stdlib.h>


//=======================================================================//
//**************       Fungsi Untuk Input Transaksi      ****************//
//=======================================================================//
// Nama Fungsi    : input_transaksi                                      //
// Input Argumen  : int harga [], char Det_Transaksi                     //
// Output Argumen : -                                                    //
// Deskripsi      : Meminta user untuk memasukan harga barang yang dibeli//
//                  dan mengisi detail transaksi dari barang transaksi   //
//                  yang dilakukan oleh user.                            //
//                                                                       //
// Versi : 1.0                                      Rev. 0               //
// Tgl   : 03-12-2020                               Tgl: 03-12-2020      //
// I Gede Himawan - 2005551108                                           //
// Kelas A                                                               //
//=======================================================================//
void input_transaksi(){
        printf ("\t\t\t\t\t|===================================|\n");
        printf ("\t\t\t\t\t||Masukkan Total Transaksi anda: ");
        scanf  ("%d",&harga );
        printf ("\t\t\t\t\t||Deskripsi: ");
        scanf  ("%s",&Det_Transaksi[50]);
        printf ("\t\t\t\t\t|===================================|\n");
        system ("clear");
}

//=======================================================================//
//***********   Fungsi Untuk Menampilkan Pilihan transaksi  *************//
//=======================================================================//
// Nama Fungsi    : metode_pembayaran                                    //
// Input Argumen  : int metode, md.bank , md.creditCard, dan md.cash     //
// Output Argumen : -                                                    //
// Deskripsi      : Program akan menampilkan pilihan metode pembayaran   //
//                  dan meminta user untuk memilih metode yang digunakan //
//                  untuk pengeluaran. Setelah itu, user diminta untuk   //
//                  menginputkan harga barang yang dijadikan sebagai     //
//                  perhitungan saldo yang dimiliki saat ini. Nantinya   //
//                  saldo tersebut akan ditampilkan pada fungsi cek saldo//
//                                                                       //
// Versi : 1.2                                      Rev. 2               //
// Tgl   : 03-12-2020                               Tgl: 21-12-2020      //
// Revisi: 1. Menambahkan syntax untuk menghitung jumlah saldo terbaru   //
//        pada setiap metode yang di gunakan seperti bank, credit card & //
//        cash.                                                          //
//         2. Melakukan perubahan dan penambahan syntax pada fungsi      //
//        metode_pembayaran dimana user tidak bisa melakukan transaksi   //
//        pada akun tertentu jika saldo yang dimiliki lebih kecil dari   //
//        jumlah harga transaksi yang dilakukan. oleh karena tujuan dari //
//        syntax untuk mejaga saldo pada setiap akun tidak dapat kurang  //
//        dari 0 atau minus.                                             //
// I GEDE HIMAWAN - 2005551108                                           //
// Luh Putu Monica Arysta Putri Suastawan - 2005551090                   //
// Kelas A                                                               //
//=======================================================================//
bayar metode_pembayaran (bayar md){
    printf ("\t\t\t\t\tSaldo yang anda miliki pada setiap akun keuangan:\n");
    printf ("\t\t\t\t\t            ||Saldo pada Bank   : %d\n",*bank);
    printf ("\t\t\t\t\t            ||Saldo pada kredit : %d\n",*kredit);
    printf ("\t\t\t\t\t            ||Saldo pada cash   : %d\n",*cash);

    metode:
    printf ("\t\t\t\t\t|================================================|\n");
    printf ("\t\t\t\t\t|               KATEGORI PENGELUARAN             |\n");
    printf ("\t\t\t\t\t|================================================|\n");
    printf ("\t\t\t\t\t|   No  |    Pilihan Kategori Pengeluaran        |\n");
    printf ("\t\t\t\t\t|-------|----------------------------------------|\n");
    printf ("\t\t\t\t\t|   1   |    Akun Bank                           |\n");
    printf ("\t\t\t\t\t|   2   |    Akun Credit Card                    |\n");
    printf ("\t\t\t\t\t|   3   |    Cash                                |\n");
    printf ("\t\t\t\t\t|================================================|\n");
    
    printf ("\t\t\t\t\t|================================================|");
    printf ("\n\t\t\t\t\t|| Masukkan Metode Pembayaran :");
    scanf  ("%d",&metode);

        switch (metode){
        case 1:
            printf ("\n\n\t\t\t\t\t||Akun Bank\n");
            printf ("\t\t\t\t\t||Masukkan harga barang :");
            scanf  ("%d",&md.bank);
            if (*bank < md.bank){
                printf ("\t\t\t\t\t||Saldo yang anda miliki pada akun Bank kurang dari jumlah transaksi\n");
                printf ("\t\t\t\t\t||Silahkan coba dengan metode pembayaran lain\n");
                printf ("\t\t\t\t\t|================================================|");
                goto metode;
            }
            else{
            int tb = *bank - md.bank;
            *bank  = tb;
            total  = *saldo - md.bank;
            *saldo = total;
            }

            break;
        case 2:
            printf ("\n\n\t\t\t\t\t||Akun credit card\n");
            printf ("\t\t\t\t\t||Masukkan harga barang :");
            scanf  ("%d",&md.bank);
            if (*kredit < md.bank){
                printf ("\t\t\t\t\t||Saldo yang anda miliki pada akun kredit kurang dari jumlah transaksi\n");
                printf ("\t\t\t\t\t||Silahkan coba dengan metode pembayaran lain\n");
                printf ("\t\t\t\t\t|================================================|");
                goto metode;
            }
            else{
            int tc   = *cash - md.bank;
            *kredit  = tc;
            total  = *saldo - md.bank;
            *saldo = total;
            }
            break;
        case 3:
            printf ("\n\n\t\t\t\t\t||Cash\n");
            printf ("\t\t\t\t\t||Masukkan harga barang :");
            scanf  ("%d",&md.bank);
            if (*cash < md.bank){
                printf ("\t\t\t\t\t||Saldo cash yang anda miliki kurang dari jumlah transaksi\n");
                printf ("\t\t\t\t\t||Silahkan coba dengan metode pembayaran lain\n");
                printf ("\t\t\t\t\t|================================================|");
                goto metode;
            }
            else{
            int tc = *cash - md.bank;
            *cash  = tc;
            total  = *saldo - md.bank;
            *saldo = total;
            }
            break;
        //Jika user menginput pilihan yang salah, atau menginput nilai yang tidak ada pada tampilan menu maka program akan mengesekusi pada bagian default seperti di bawah ini:
        default:
            printf   ("\t\t\t\t\t||Pilihan yang Anda masukan Salah!!!\n");
            printf   ("\t\t\t\t\t||Silahkan Memilih Pilihan yang Sudah ada\n");
            printf   ("\t\t\t\t\t|=========================================|");
            break;
            system ("clear");
        }
    return md;
}

//=======================================================================//
//***********   Fungsi Untuk Menampilkan Pilihan transaksi  *************//
//=======================================================================//
// Nama Fungsi    : transaksi                                            //
// Input Argumen  : int milih                                            //
// Output Argumen : -                                                    //
// Deskripsi      : Menampilkan Kategori Transaksi yang ada lalu         //
//                  memanggil fungsi input_transaksi yang meminta user   //
//                  untuk melakukan input harga dan di proses untuk      //
//                  mendapatkan jumlah sisa saldo terbaru.               //
//                                                                       //
// Versi : 1.1                                      Rev. 1               //
// Tgl   : 03-12-2020                               Tgl: 03-12-2020      //
// Revisi: Menambahkan pemanggilan fungsi waktu untuk menginfokan waktu  //
//        Saat user mengakses program.                                    //
// I Gede Himawan - 2005551108                                           //
// Kelas A                                                               //
//=======================================================================//
int transaksi (){
    bayar md;

    printf ("\t\t\t\t\t|================================================|\n");
    printf ("\t\t\t\t\t|                KATEGORI TRANSAKSI              |\n");
    printf ("\t\t\t\t\t|================================================|\n");
    printf ("\t\t\t\t\t|   No  |      Jenis Transaksi                   |\n");
    printf ("\t\t\t\t\t|-------|----------------------------------------|\n");
    printf ("\t\t\t\t\t|   1   |        Makanan                         |\n");
    printf ("\t\t\t\t\t|   2   |        Transportasi                    |\n");
    printf ("\t\t\t\t\t|   3   |        Fashion                         |\n");
    printf ("\t\t\t\t\t|   4   |        Rumah Tangga                    |\n");
    printf ("\t\t\t\t\t|   5   |        Pendidikan                      |\n");
    printf ("\t\t\t\t\t|   6   |        Lainnya...                      |\n");
    printf ("\t\t\t\t\t|================================================|\n");

    printf ("\n\t\t\t\t\t Masukan Pilihan Anda : ");
        scanf  ("%d",&milih);
        system ("clear");

        switch (milih){

        //pada case 1 dari menu switch(kategori), memiliki syntax switch case lagi di dalamnya, dimana disini berfungsi untuk meneksekusi inputan dari pilihan yang dimasukkan oleh user pada pilihan kategori transaksi sebelumnya.
        //dalam case 1 ini mengeksekusi perintah jika user memilih kategori makanan pada pemilihan kategori transaksi, dimana disini user akan diminta untuk memasukkan harga dan detail tambahan untuk transaksi yang sudah di lakukan oleh user.
        case 1:
            printf ("\t\t\t\t\t\t\t |============|\n");
            printf ("\t\t\t\t\t\t\t | Makanan    |\n");
            printf ("\t\t\t\t\t\t\t |============|\n");
            metode_pembayaran (md);
            waktu();
            break;

        //dalam case 2 ini mengeksekusi perintah jika user memilih kategori Transportasi pada pemilihan kategori transaksi, dimana disini user akan diminta untuk memasukkan harga dan detail tambahan untuk transaksi yang sudah di lakukan oleh user.
        case 2:
            printf ("\t\t\t\t\t\t|============|\n");
            printf ("\t\t\t\t\t\t|Transportasi|\n");
            printf ("\t\t\t\t\t\t|============|\n");
            metode_pembayaran (md);
            waktu();
            break;

        //dalam case 3 ini mengeksekusi perintah jika user memilih kategori Fashion pada pemilihan kategori transaksi, dimana disini user akan diminta untuk memasukkan harga dan detail tambahan untuk transaksi yang sudah di lakukan oleh user.
        case 3:
            printf ("\t\t\t\t\t\t |============|\n");
            printf ("\t\t\t\t\t\t |   Fashion  |\n");
            printf ("\t\t\t\t\t\t |============|\n");
            metode_pembayaran (md);
            waktu();
            break;

        //dalam case 4 ini mengeksekusi perintah jika user memilih kategori Rumah Tangga pada pemilihan kategori transaksi, dimana disini user akan diminta untuk memasukkan harga dan detail tambahan untuk transaksi yang sudah di lakukan oleh user.
        case 4:
            printf ("\t\t\t\t\t\t |============|\n");
            printf ("\t\t\t\t\t\t |Rumah Tangga|\n");
            printf ("\t\t\t\t\t\t |============|\n");
            metode_pembayaran (md);
            waktu();
            break;

        //dalam case 5 ini mengeksekusi perintah jika user memilih kategori Pendidikan pada pemilihan kategori transaksi, dimana disini user akan diminta untuk memasukkan harga dan detail tambahan untuk transaksi yang sudah di lakukan oleh user.
        case 5:
            printf ("\t\t\t\t\t\t |============|\n");
            printf ("\t\t\t\t\t\t | Pendidikan |\n");
            printf ("\t\t\t\t\t\t |============|\n");
            metode_pembayaran (md);
            waktu();
            break;

        //dalam case 6 ini mengeksekusi perintah jika user memilih kategori Lainnya pada pemilihan kategori transaksi, dimana disini user akan diminta untuk memasukkan harga dan detail tambahan untuk transaksi yang sudah di lakukan oleh user.
        case 6:
            printf ("\t\t\t\t\t\t |============|\n");  
            printf ("\t\t\t\t\t\t | Lainnya    |\n");
            printf ("\t\t\t\t\t\t |============|\n");
            metode_pembayaran (md);
            waktu();
            break;

        //Jika user menginput pilihan yang salah, atau menginput nilai yang tidak ada pada tampilan menu maka program akan mengesekusi pada bagian default seperti di bawah ini:
        default:
            printf   ("\t\t\t\t\t|=========================================|\n");
            printf   ("\t\t\t\t\t|Pilihan yang Anda masukan Salah!!!       |\n");
            printf   ("\t\t\t\t\t|Silahkan Memilih Pilihan yang Sudah ada  |\n");
            printf   ("\t\t\t\t\t|=========================================|\n");
            break;
        }
    total  = *saldo - harga;
    *saldo = total;
    system ("clear");
    return total;
}
