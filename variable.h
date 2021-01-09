//Header untuk menyimpan variable-variable yang digunakan pada program ini

#ifndef __VARIABLE_H__
#define __VARIABLE_H__
#include <time.h>
#include "structure.h"


// Dekalarasi variable global yang di gunakan pada program manjemen keuangan ini:

int masukan;                          //variabel masukan      => berfungsi untuk menyimpann masukan saldo yang di inputkan oleh user
int ktgrimasukan;                     //variabel ktgrimasukan => berfungsi untuk menyimpan pilihan yang dimasukan oleh user untuk di proses ke switch case pada pemilihan kategori pemasukan yang di miliki oleh user
int p;                                //variabel p            => berfungsi untuk menyimpan masukkan saldo yang di inputkan oleh user
int kategori;                         //variabel kategori     => berfungsi untuk menyimpan pilihan yang dimasukan oleh user untuk di proses ke switch case pada pemilihan kategori transaksi yang di lakukan oleh user
int pilihanmasuk;                     //variabel pilihanmasuk => berfungsi untuk menyimpan pilihan yang dimasukan oleh user untuk di proses ke switch case pada pemilihan menu login
int pilihanmenu;                      //variabel kategori     => berfungsi untuk menyimpan pilihan yang dimasukan oleh user untuk di proses ke switch case pada pemilihan menu program
int harga;                            //variabel harga        => berfungsi untuk menyimpan masukkan harga dari transaksi yang di inputkan oleh user pada menu transaksi
int total;                            //variabel total        => berfungsi untuk menyimpan hasil dari proses pengurangan saldo setelah user melakukan proses transaksi, dimana setelah proses ini variabel total ini akan menyimpan sisa dari saldo terbaru yang di miliki oleh user
int milih;                            //variabel milih        => berfungsi untuk menyimpan pilihan yang dimasukkan oleh user untuk di proses ke switch case pada pemilihan jenis dari transaksi yang ingin di lakukan oleh user pada menu transaksi yang sudahh terdapat pada program
char Det_Transaksi [50];              //Variabel Det_Transaksi=> berfunsgi untuk menyimpan masukan dari info transaksi yang di masukkan user jika pada melihilan jenis transaksi user memilih kategori lainnya sehingga user di minta untuk memasukkan manual informasi dari transaksi yang di lakukan.
int i;                                //variabel i            => berfungsi untuk menyimpan nilai increment pada proses looping yang terdapat pada fungsi menu,dimana variabel ini akan melakukan pengulangan proses transaksi dengan nilai saldo yang di proses merupakan sisa dari saldo transaksi yang dilakukan oleh user sebelumnya.
char Det_Masukan;                     //variabel Det_Masukan  => berfungsi untuk menyimpan inputan Detail Informasi Pemasukan saldo yang di inputkan oleh user.
int hargaBarangDiinginkan;            //variabel hargaBarangDiinginkan => berfungsi untuk menyimpan harga barang
int pilihanTarget;                    //variabel pilihanTarget => berfungsi untuk menyimpan pilihan dari kategori target pada bagian Wishlist
char namaTarget[50];                  //variabel namaTarget    => berfungsi untuk menyimpan deskripsi dari target barang yang diinginkan pada bagian Wishlist
char usernameCoba [15];               //variabel usernameCoba  => berfungsi untuk menyimpan username yang dilogin oleh user
int pilihanMenu;                      //variable pilihanMenu   => berfungsi untuk menyimpan pilihan untuk user apakah user ingin menambah wishlist atau kembali ke menu utama
int saldoDimiliki;                    //variabel saldoDimiliki => berfungsi untuk menyimpan saldo yang dituliskan dari pada akunBank, akunCreditCard, cash
time_t waktuserver;                   //variavel waktuserver   => berfungsi untuk mengambil waktu dari sistem.
int metode;                           //variable pilihanMenu   => berfungsi untuk menyimpan pilihan metode pembayaran pada fungsi transaksi.
                         
int mtdmsk;                           //variabel mtdmsk        => untuk memilih akun mana yang ingin dicatat pemasukannya
char namaFile[] = "logRecord.txt";    // assign namaFile (nF) agar menyimpan string "logRecord.txt"

int *saldo = &saldoDimiliki;                        //pointer saldo                   => berfungsi untuk menyimpan nilai sisa dari hasil setelah saldo di kurang dengan adanya proses transaksi secara berulang kali


#endif
