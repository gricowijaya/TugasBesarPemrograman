#include "structure.h"
#include "function.h"
#include "variable.h"
#include <stdio.h>
#include <stdlib.h>

//=======================================================================//
//***********   Fungsi Untuk Menampilkan Dana Darurat    ****************//
//=======================================================================//
// Nama Fungsi    : DanaDarurat                                          //
// Passing Argumen: int saldo                                            //
// Output Argumen : int dana                                             //
// Deskripsi      : Fungsi ini untuk membantu User dalam membuat Dana    //
//                  Darurat/Simpanan dalam keadaan genting yang dimana   // 
//                  aplikasi sarankan 30% dari saldo saat itu            //
//                  harus disisihkan untk ditabung                       //
// Versi : 1.0                                      Rev. 1               //
// Tgl: 27-11-2020                                  Tgl: 1-12-2020       //
// Revisi 1        : Menambahkan dialog untuk memberikan user penjelasan //
//                   tentang fungsi ini                                  //
// Gede Rico Wijaya - 2005551091                                         //
// Kelas A                                                               //
//=======================================================================//
int DanaDarurat (int *saldo){

    //Deklarasi variabel int dana untuk menyimpan nilai dari Dana yang harus dipersiapkan 
    //int dana menyimpan nilai dari perhitungan nilai saldo yang diinput oleh user
    int dana = *saldo * 0.3;
        printf ("\t\t\t\t||=====================================================================================================||");
        printf ("\t\t\t\t|| Dalam Manajemen Keungangan Anda harus diperlukan Dana Darurat\n                                     ||");                                  
        printf ("\t\t\t\t|| Mengapa ?\nKarena agar finansial bisa siap dalam keadaan darurat,\n                                 ||");
        printf ("\t\t\t\t|| Untuk itu maka diperlukan Dana Darurat yang disarankan yaitu\n30 persen dari saldo yang dimilki\n   ||");
        printf ("\t\t\t\t|| Jadi Dana Darurat yang harus ditabung untuk saat ini adalah: %d\n                                   ||", dana);
        printf ("\t\t\t\t||=====================================================================================================||");

    //untuk mengubah nilai saldo jika user memilih fungsi DanaDarurat yang akan menjadi saldo = saldo - dana
    *saldo = *saldo - dana ;
    return dana;
}
