#include "variable.h"
#include "structure.h"
#include "function.h"
#include <stdio.h>
#include <stdlib.h>


//=======================================================================//
//****************   Fungsi Untuk Menampilkan Saldo   *******************//
//=======================================================================//
// Nama Fungsi    : ceksaldo                                             //
// Input Argumen  : -                                                    //
// Output Argumen : int *bank,int *kredit,int *cash,int *saldo.          //
// Deskripsi      : Menampilkan Sisa atau Banyak saldo yang dimiliki     //
//                  Oleh user.                                           //
//                                                                       //
// Versi : 1.1                                      Rev. 1               //
// Tgl   : 03-12-2020                               Tgl: 03-12-2020      //
// Revisi: Menambahkan syntax untuk penampilan sisa saldo terbaru pada   //
//        setiap jenis saldo yang dimiliki.                              //
// I Gede Himawan - 2005551108                                           //
// Kelas A                                                               //
//=======================================================================//
void ceksaldo (){
            // Menampilkan pemberitahuan sisa saldo yang di* miliki user pada saat mengakses program
        printf ("\t\t\t\t\t|=======================================================|\n");
        printf ("\t\t\t\t\t||Saldo pada Bank   : %d\n",*bank);
        printf ("\t\t\t\t\t||Saldo pada kredit : %d\n",*kredit);
        printf ("\t\t\t\t\t||Saldo pada cash   : %d\n",*cash);
        printf ("\t\t\t\t\t||Sisa Total Saldo Anda Adalah  :Rp. %d \n" , *saldo);
            //Pointer saldo akan menyimpan sisa saldo terbaru yang akan di proses kembali apabila ada proses transaksi lagi .
}

//=======================================================================//
//**************   Fungsi Untuk Menampilkan Pesan Eror   ****************//
//=======================================================================//
// Nama Fungsi    : -                                                    //
// Input Argumen  : -                                                    //
// Output Argumen : -                                                    //
// Deskripsi      : Menampilkan Pemberitahuan Bahwa user memasukan input //
//                  bahwa user salah memasukkan pilihan.                 //
//                                                                       //
// Versi : 1.0                                      Rev. 0               //
// Tgl   : 03-12-2020                               Tgl: 03-12-2020      //
// I Gede Himawan - 2005551108                                           //
// Kelas A                                                               //
//=======================================================================//
void error_alert(){
    printf   ("\t\t\t\t\t===============================================  \n");
    printf   ("\t\t\t\t\t||     Pilihan yang Anda masukan Salah!!!     || \n");
    printf   ("\t\t\t\t\t||   Silahkan Memilih Pilihan yang Sudah ada  || \n");
    printf   ("\t\t\t\t\t===============================================  \n");
}

//=======================================================================//
//**************  Fungsi Untuk Menampilkan Record User   ****************//
//=======================================================================//
// Nama Fungsi    : record                                               //
// Passing Argumen: struct User u, char file[]                           //
// Output Argumen : u.nama                                               //
// Deskripsi      : Fungsi ini ditujukan untuk menampilkan data yang     //
//                  dimasukan oleh user yaitu berupa nama yang ada pada  //
//                  logRecord.txt                                        //
// Versi : 1.0                                      Rev. 1               //
// Tgl: 30-11-2020                                  Tgl: 19-11-2020      //
// Gede Rico Wijaya - 2005551091                                         //
// Revisi : Menghapuskan display nomor telepon karena tidak diperlukan   //
// Kelas A                                                               //
//=======================================================================//

void record(User u, char file[] ){
    time( & waktuserver);
    struct tm * waktu = localtime( & waktuserver);
    //Mendeklarasikan tipe data file dengan pointer *rc yang bertujuan untuk pointer pada file "logRecord.txt"
    FILE *rc;
    //Assign rc untuk membuka file binary Record.dat dan menggunakan mode "r" untuk membaca textfile
    rc = fopen(file, "r");
    //Menggunakan fungsi fread untuk membaca isi dari file "logRecord.txt"
    fread (&u, sizeof(u), 1, rc);
    //Menggunakan fungsi fclose untuk menutup file "logRecord.txt" agar tidak diproses lagi
    fclose (rc);

    //Menampilkan hasil dari Record nama user dan nomor telepon yang diinput oleh user
    //Menampilkan hasil dari Record nama user dan nomor telepon yang diinput oleh user
    printf("\t\t\t\t\t|=========================================|\n");
    printf("\t\t\t\t\tNama\tUsername\tTanggal\n");
    printf("\t\t\t\t\t%s\t%s\t%i-%i-%i-\n",u.nama, u.username, waktu -> tm_mday, waktu -> tm_mon + 1, waktu -> tm_year + 1900);
    printf("\t\t\t\t\t|=========================================|\n");

}

//=======================================================================//
//***********     Fungsi Untuk Menampilkan Waktu Sistem     *************//
//=======================================================================//
// Nama Fungsi    : waktu                                                //
// Input Argumen  : -                                                    //
// Output Argumen : -                                                    //
// Deskripsi      : Fungsi ini digunakan untuk mengambil dan menampilkan //
//                 Waktu sistem pada saat user mengakses program.        //
//                                                                       //
// Versi : 1.0                                      Rev. 0               //
// Tgl   : 15-12-2020                               Tgl: 03-12-2020      //
// I Gede Himawan - 2005551108                                           //
// Kelas A                                                               //
//=======================================================================//
void waktu(){
    time( & waktuserver);
    struct tm * waktu = localtime( & waktuserver);
    printf("\n\t\t\t\t\t||================Tanggal: %i/%i/%i==============||\n\n", waktu -> tm_mday, waktu -> tm_mon + 1, waktu -> tm_year + 1900);
}
