//Header yang digunakan untuk fungsi-fungsi protoype yang digunakan pada Program Manajemen Keuangan

#ifndef __FUNCTION_H__
#define __FUNCTION_H__
#include "structure.h"
//Deklarasi fungsi-fungsi yang digunkan pada program manajemen keuangan'
int pemasukan ();                                    /* Merupakan fungsi yang digunakan untuk menampilkan dan menyimpan semua kategori,
                                                        dan inputan pemasukan saldo user. */

int transaksi ();                                    /* Merupakan fungsi yang digunakan untuk menampilkan dan menyimpan semua kategori,
                                                        dan inputan transaksi(pengeluaran) user. */
                                                        
void header ();

void ceksaldo ();                                    // Merupakan fungsi yang digunakan untuk Menampilkan keselurahan saldo terbaru yang di miliki oleh user.

void menu ();                                        /* Merupakan fungsi yang di gunakan untuk menampilakan berbagai isi dari MENU ,
                                                        yaitu di dalamnya terdapat menu transaksi dan kaetgori transaksi serta menampilkan pilihan untuk
                                                        user melakukan pengecekkan sisa saldo yang di miliki oleh user sendiri */

void input_transaksi();                              /* Merupakan fungsi yang digunakan untuk meminta dan menyimpan inputan dari jumlah transaksi
                                                        yang di lakukan oleh user */

void input_masukan();                                /* Merupakan fungsi yang digunakan untuk meminta dan menyimpan inputan dari jumlah masukkan
                                                        yang di lakukan oleh user */

void error_alert();                                  /* Merupakan fungsi yang digunakan untuk menampilan pemberitahuan ketika user menginputkan
                                                        pilihan yang salah pada setiap switch case. */

void menu_program();                                 // Merupakan fungsi yang digunakan untuk menampilkan pilihan menu program yang ada

void menu_masuk();                                   // Merupakan fungsi yang digunakan untuk menampilkan pilihan menu masuk Login atau SignUp

void email_pw();                                     /* Merupakan fungsi yang digunakan untuk meminta user untuk menginput Email dan Password
                                                        yang di gunakan untuk Masuk ke dalam program */

void record(User u1, char file[]);                   // Merupakan fungsi yang digunakan untuk memperlihatkan track record dari file "Record.dat"
void wish_list();                                    // Merupakan fungsi yang digunakan untuk menambahkan daftar barang yang diinginkan oleh user
void menupil ();                                     // Merupakan fungsi yang digunakan untuk pilihan apakah ingin menambah wishlist atau kembali ke menu utama
void daftarwishlist();                               // Merupakan fungsi yang digunakan untuk memilih kategori dari barang wishlist yang diinginkan
int DanaDarurat (int *saldo);                        // Merupakan fungsi yang digunakan untuk membantu User dalam mempersiapkan DanaDarurat
int inputSaldo(char x[]);                            // Merupakan fungsi yang digunakan untuk menginput saldo dengan akun Bank, akun CreditCard, akun Cash
void waktu();                                        // Merupakan fungsi yang digunakan untuk menampilkan waktu pada sistem tempat user mengakses

void daftar();                                       /* Fungsi void daftar() untuk menyimpan perintah-perintah yang dibutuhkan
                                                        untuk registrasi yang akan menyimpan nama, username, serta password yang
                                                        akan digunakan oleh pengguna*/

void masuk();                                        /* Fungsi void masuk() digunakan agar pengguna dapat masuk dengan username serta
                                                        password yang sudah dibuat dan nantinya akan dilanjutkan kedalam fitur program*/

#endif