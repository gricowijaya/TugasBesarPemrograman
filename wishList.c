#include "variable.h"
#include "function.h"
#include "structure.h"
#include <stdio.h>
#include <stdlib.h>


//=======================================================================//
//**       Fungsi Untuk Memilih Menu Kategori Wishlist          ***//
//=======================================================================//
// Nama Fungsi    : daftarwishlist                                       //
// Input Argumen  : int pilihanTarget                                    //
// Output Argumen : -                                                    //
// Deskripsi      : User diminta untuk memilih menu kategori target.     //
//                  Setelah itu, pilihan user akan disimpan dan          //
//                  akan menampilkan kategori serta akan beralih ke      //
//                  fungsi wishlist. Dimana user diminta untuk           //
//                  menginputkan deskripsi dan kisaran harga dari        //
//                  target tersebut                                      //
// Versi : 1.0                                      Rev. 0               //
// Tgl   : 04-12-2020                               Tgl: 04-12-2020      //
// Luh Putu Monica Arysta Putri Suastawan/2005551090                     //
// Kelas A                                                               //
//=======================================================================//
void daftarwishlist(){
    wishlist:

    printf ("\t\t\t\t\t|================================================|\n");
    printf ("\t\t\t\t\t|                KATEGORI WISHLIST               |\n");
    printf ("\t\t\t\t\t|================================================|\n");
    printf ("\t\t\t\t\t|   No  |      Jenis Wishlist                    |\n");
    printf ("\t\t\t\t\t|-------|----------------------------------------|\n");
    printf ("\t\t\t\t\t|   1   |        Pendidikan                      |\n");
    printf ("\t\t\t\t\t|   2   |        Tempat tinggal                  |\n");
    printf ("\t\t\t\t\t|   3   |        Liburan                         |\n");
    printf ("\t\t\t\t\t|   4   |        Kesehatan                       |\n");
    printf ("\t\t\t\t\t|   5   |        Investasi                       |\n");
    printf ("\t\t\t\t\t|   6   |        Kendaraan                       |\n");
    printf ("\t\t\t\t\t|   7   |        Alat Elektronik                 |\n");
    printf ("\t\t\t\t\t|================================================|\n");

    printf ("\n\t\t\t\t\t Masukan Pilihan : ");
    scanf  ("%d",&pilihanTarget);
    system ("clear");

    switch(pilihanTarget)
    {
    case 1 :
        printf ("Pendidikan \n ");
        wish_list();
    break;
    case 2 :
        printf ("Rumah \n ");
        wish_list();
    break;
    case 3 :
        printf ("Liburan  \n");
        wish_list();
    break;
    case 4 :
        printf ("Kesehatan \n ");
        wish_list();
    break;
    case 5 :
        printf ("Investasi \n ");
        wish_list();
    break;
    case 6 :
        printf ("Kendaraan \n ");
        wish_list();
    break;
    case 7 :
        printf ("Elektronik \n ");
        wish_list();
    break;
    system ("clear");
    }
}

//=======================================================================//
//*         Fungsi Untuk Meminta User Menginputkan Target      **//
//=======================================================================//
// Nama Fungsi    : wishlist                                             //
// Input Argumen  : int hargaBarangDiinginkan dan char namaTarget        //
// Output Argumen : -                                                    //
// Deskripsi      : User diminta untuk menginputkan deskripsi target     //
//                  dan kisaran harga barang yang diinginkan             //
//                  Nanti deskripsi target dan harga barang diinginkan   //
//                  akan disimpan dan digunakan kembali saat melakukan   //
//                  proses pencapaian target terhadap uang yang          //
//                  dimiliki oleh user .                                 //
// Versi : 1.0                                      Rev. 1               //
// Tgl   : 04-12-2020                               Tgl: 11-12-2020      //
// Luh Putu Monica Arysta Putri Suastawan/2005551090                     //
// Kelas A                                                               //
//=======================================================================//
void wish_list(){
        printf ("\t\t\t\t\t||=====================||\n");
        getchar ();
        printf ("\t\t\t\t\t||    Deskripsi :");
        gets   ( namaTarget);
        printf ("\t\t\t\t\t||    Kisaran Harga :");
        scanf  ("%d",&hargaBarangDiinginkan);
        system ("clear");
}
