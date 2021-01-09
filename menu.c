#include "function.h"
#include <stdio.h>
#include <stdlib.h>

void header (){
    system ("clear");
	printf  ("\t\t\t\t\t====================================================\n");
	printf  ("\t\t\t\t\t||            Program Manajemen Keuangan          ||\n");
	printf  ("\t\t\t\t\t====================================================\n");
	printf  ("\t\t\t\t\t||          Program disusun dan dibuat oleh:      ||\n");
	printf  ("\t\t\t\t\t||    1. Luh Putu Monica Arysta Putri Suastawan   ||\n");
	printf  ("\t\t\t\t\t||               2. Gede Rico Wijaya              ||\n");
	printf  ("\t\t\t\t\t||                3. I Gede Himawan               ||\n");
	printf  ("\t\t\t\t\t====================================================\n");
	printf  ("\t\t\t\t\t         Tekan ENTER  untuk melanjutkan....    \n");
    printf  ("\t\t\t\t\t====================================================\n");
	getchar ();
    system ("clear");
}

//=======================================================================//
//************   Fungsi Untuk Menampilkan Menu Pilihan   ****************//
//=======================================================================//
// Nama Fungsi    : menu                                                 //
// Input Argumen  : int kategori , int p                                 //
// Output Argumen : -                                                    //
// Deskripsi      : Memasukan Saldo dan pilihan menu yang ingin di       //
//                  jalankan , lalu pada setiap pilihan akan meminta     //
//                  user untuk memilih salah satu kategori yang ingin    //
//                  dijalankan sesuai dengan kebutuhan dan keingan user. //
//                                                                       //
// Versi : 1.0                                      Rev. 0               //
// Tgl   : 03-12-2020                               Tgl: 03-12-2020      //
// I Gede Himawan - 2005551108                                           //
// Kelas A                                                               //
//=======================================================================//
void menu (){

    //Memanggil fungsi inputSaldo
    inputSaldo(namaFile);

    //Mendeklarasikan label ktgri untuk menampilkan kategori menu yang ingin dipilih
    ktgri:
    //pada bagian looping ini , disini berfungsi untuk menjalankan proses dari program manjemen keungan ini, dimana setiap dilakukan proses transaksi atau cek saldo maka yang akan di proses dan di tampilkan adalah saldo terbaru yang merupakan hasil dari proses sebelumnya yang di lakukan oleh user seperti proses transaksi yang dapat merubah banya saldo, sehingga program dapat di jalankan sesuai ekspetasi yang di inginkan oleh penulis programnya
    for(i=0; i<1; i++){

    printf ("\t\t\t\t\t|================================================|\n");
    printf ("\t\t\t\t\t|            KATEGORI MANAJEMEN KEUANGAN         |\n");
    printf ("\t\t\t\t\t|================================================|\n");
    printf ("\t\t\t\t\t|   No  |    Pilihan Kategori                    |\n");
    printf ("\t\t\t\t\t|-------|----------------------------------------|\n");
    printf ("\t\t\t\t\t|   1   |    Transaksi                           |\n");
    printf ("\t\t\t\t\t|   2   |    Pemasukan                           |\n");
    printf ("\t\t\t\t\t|   3   |    Cek Saldo                           |\n");
    printf ("\t\t\t\t\t|   4   |    Dana Darurat                        |\n");
    printf ("\t\t\t\t\t|   5   |    Log Record                          |\n");
    printf ("\t\t\t\t\t|   6   |    Wishlist                            |\n");
    printf ("\t\t\t\t\t|   7   |    EXIT                                |\n");
    printf ("\t\t\t\t\t|================================================|\n");

    printf ("\n\t\t\t\t\t||Masukkan Pilihan Anda :");
        scanf  ("%d",&kategori);
        system ("clear");
        //pada menu switch case bagian ini , merupakan lanjutan proses dari pilihan user yang di inputkan sebelumnya pada pilihan pada MENU program.
        switch (kategori)
        {
            // pada case 1 ini, karena user milih program transaksi maka program akan menampilkan menu kategori dan user akan diminta untuk memilih kategori untuk transaksi yang di lakukan oleh user.
            case 1:
                transaksi();
                goto ktgri;
                break;
            //pada case 2 dari menu switch (kategori), karena user memilih menu untuk mengecek saldo maka program akan menampilkan sisa saldo yang dimiliki oleh user saat menu ini di akses
            case 2:
                pemasukan();
                goto ktgri;
                break;
            //pada case 3 user akan mengecek saldo yang dimiliki sekarang baik sebelum melakukan input transaksi dan input pemasukan maupun setelahnya
            case 3:
                ceksaldo();
                goto ktgri;
                break;
            case 4:
                DanaDarurat(saldo);
                goto ktgri;
                break;
            case 5:
                record(u, namaFile);
                goto ktgri;
                break;
            case 6:
                daftarwishlist();
                menupil  ();
                goto ktgri;
                break;
            case 7:
                exit (0);
                break;
            default:
                printf ("Silahkan ketik ulang pilihan anda");
                goto ktgri;
                break;
        }
    }
}

//=======================================================================//
//*************  Fungsi Untuk Menampilkan Pilihan Masuk   ***************//
//=======================================================================//
// Nama Fungsi    : menu_program                                         //
// Input Argumen  : int email & char password                            //
// Output Argumen : -                                                    //
// Deskripsi      : menampilkan pilihan untuk program yang akan          //
//                  dijalankan, dimana pada fungsi ini baru ada satu     //
//                  apilihan yaitu MENU .                                //
//                                                                       //
// Versi : 1.1                                      Rev. 1               //
// Tgl   : 03-12-2020                               Tgl: 19-12-2020      //
// I Gede Himawan - 2005551108                                           //
// Gede Rico Wijaya - 2005551091                                         //
// Revisi : Menambahkan Menu EXIT                                        //
// Kelas A                                                               //
//=======================================================================//
void menu_program(){
    pilih:

    printf ("\n");
    printf ("\t\t\t\t\t|================================================|\n");
    printf ("\t\t\t\t\t|                   MENU PROGRAM                 |\n");
    printf ("\t\t\t\t\t|================================================|\n");
    printf ("\t\t\t\t\t|   No  |    Pilihan Menu Program                |\n");
    printf ("\t\t\t\t\t|-------|----------------------------------------|\n");
    printf ("\t\t\t\t\t|   1   |    MENU                                |\n");
    printf ("\t\t\t\t\t|   2   |    EXIT                                |\n");
    printf ("\t\t\t\t\t|================================================|\n"); 
    printf ("\t\t\t\t\t|================================================|\n");
    printf ("\n\t\t\t\t\t Masukan Pilihan Anda => ");
    scanf  ("%d",&pilihanmenu);
    printf ("\t\t\t\t\t|================================================|\n");
    system ("clear");

    // pada switch case bagian ini , disini akan memproses dari inputan yang sudah dimasukkan oleh user pada proses pemiihan pemilihan menu sebelumnya dan mengantarkan program pada fungsi yang merupakan panggilan dari pilihan yang di inputkan oleh user.
    switch (pilihanmenu)
    {
        //pada case 1 ini, program akan memanggil fungsi yang sudah dibuat yaitu fungsi yang bernama void menu();
        case 1:
            menu ();
            break;
        case 2:
            system (EXIT_SUCCESS);
            break;
        //Jika user menginput pilihan yang salah, atau menginput nilai yang tidak ada pada tampilan menu maka program akan mengesekusi pada bagian default seperti di bawah ini:
        default:
            error_alert();
            //goto pilih; dimana syntax ini akan membawa user kembali ke menu pemilihan program untuk menginputkan pilihan yang benar, ini akan terus berulang hingga user menginputkan pilihan yang benar sesaui apa yang sudah ditampilkan pada menu pilihan.
            goto pilih;
            break;
    }
}

//=======================================================================//
//**              Fungsi Untuk Memilih Menu Wishlist                  ***//
//=======================================================================//
// Nama Fungsi    : menupil                                              //
// Input Argumen  : int pilihanMenu                                      //
// Output Argumen : -                                                    //
// Deskripsi      : User diminta untuk memilih menu dan memasukkan       //
//                  pilihannya. Nanti pilihan user akan disimpan         //
//                  dan digunakan kembali untuk menentukan tampilan      //
//                  menu selanjutnya yang akan keluar.                   //
// Versi : 1.0                                      Rev. 0               //
// Tgl   : 04-12-2020                               Tgl: 04-12-2020      //
// Luh Putu Monica Arysta Putri Suastawan/2005551090                     //
// Kelas A                                                               //
//=======================================================================//
void menupil (){
akhir :

    printf ("\t\t\t\t\t|================================================|\n");
    printf ("\t\t\t\t\t|                  MENU WISHLIST                 |\n");
    printf ("\t\t\t\t\t|================================================|\n");
    printf ("\t\t\t\t\t|   No  |      Pilihan Menu Wishlis              |\n");
    printf ("\t\t\t\t\t|-------|----------------------------------------|\n");
    printf ("\t\t\t\t\t|   1   |       Kembali ke menu wishlist         |\n");
    printf ("\t\t\t\t\t|   2   |       Kembali ke menu utama            |\n");
    printf ("\t\t\t\t\t|================================================|\n");


    printf ("\n\t\t\t\t\t Apakah anda ingin melanjutkan menu? \n");
    scanf  ("%d",&pilihanMenu);

        switch (pilihanMenu){
        case 1:
            daftarwishlist();
            break;
        case 2:
            printf ("Terima kasih\n");
            break;
        default:;
            printf ("Perhatikan angka yang anda inputkan!\n");
            goto akhir;
            break;
    }
    system ("clear");
}
