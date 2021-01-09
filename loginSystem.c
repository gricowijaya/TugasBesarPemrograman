#include "variable.h"
#include "function.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//=======================================================================//
//************* Fungsi Untuk  Daftar Akun serta Username ****************//
//=======================================================================//
// Nama Fungsi    : void daftar()                           		     //
// Input Argumen  : char l.username[12], char l.password[10]             //
// Deskripsi      : Fungsi ini ditujukan untuk menginput username,       //
//                  serta password untuk disimpan pada file              //
//                  logRecord.txt yang nantinya akan divalidasi saat     //
//                  login                                    	         //
// Versi : 1.1                                      Rev. 1               //
// Tgl: 03-12-2020                              Tgl: 19-12-2020          //
// I Gede Himawan - 2005551108                                           //
// Gede Rico Wijaya - 2005551091                                         //
// Revisi : Menggantikan fungsi email_pw() agar pendaftaran email serta  //
//          password dapat dilakukan pada satu naungan bersama dengan    //
//          nama dan username                                            //
// Kelas A                                                               //
//=======================================================================//
void daftar(){
    // Membuat pointer regis untuk file "logRecord.txt"
    FILE *regis;

    // Membuka file "logRecord.txt" dengan mode "w"
    regis = fopen(namaFile,"w");

    // Melakukan Pengecekan apakah pointer regis menunjuk kepada file yang dituju ("logRecord.txt")
    if (regis == NULL)
    {
        fputs("ERROR, Tidak ada File!", stderr);
        exit(1);
    }

    // Instruksi untuk menginput nama
    printf("\n\t\t\t\t\t Silahkan registrasi akun anda!\n\n");
    getchar();
    printf("\t\t\t\t\t Nama Lengkap: ");
    gets(u.nama);
    printf("\t\t\t\t\t Email anda: ");
    scanf ("%s", u.email);
    printf("\n\t\t\t\t\t Hallo %s!\n", u.nama);
    printf ("\t\t\t\t\t Silahkan membuat username (max 12 karakter) serta membuat password (max 10 karakter)\n");

    // Instruksi untuk menginput username serta password
    printf("\n\t\t\t\t\t Enter Username:");
    scanf ("%s", u.username);
    printf("\n\t\t\t\t\t Enter Password:");
    scanf ("%s", u.password);

    // Menuliskan nama yang diinput oleh pengguna kedalam file "logRecord.txt"
    fwrite(&u,sizeof(u),1,regis);
    fclose(regis);
    printf("\n\t\t\t\t\t Registrasi Selesai!");
    printf ("\n\t\t\t\t\t Akun anda terdaftar, silahkan mencoba !");
    getchar();

    // Membersikan layar terminal
    system ("clear");
    // Memanggil fungsi masuk()
    masuk();
}

//=======================================================================//
//********* Fungsi Untuk Login dan Regis Akun serta Username ************//
//=======================================================================//
// Nama Fungsi    : void masuk()                            		     //
// Input Argumen  : char username[12], char password[10]                 //
// Output Argumen : l.username, l.password                               //
// Deskripsi      : Fungsi ini ditujukan untuk menginput username,       //
//                  serta password untuk berlanjut ke pada program       //
//                  Manajemem Keuangan                       	         //
// Versi : 1.1                                      Rev. 1               //
// Tgl: 30-11-2020                                  Tgl: 19-12-2020      //
// Revisi : Menggantikan fungsi username()                               //
// Gede Rico Wijaya - 2005551091                                         //
// Kelas A                                                               //
//=======================================================================//
void masuk(){
    /*  Variabel username[12] digunakan untuk menyimpan input username
        yang dilakukan oleh pengguna. Inputan tersebut akan divalidasi
        dengan username yang sudah terdaftar pada file logRecord.txt   */
    char username[12];

    /*  Variabel password[10] digunakan untuk menyimpan input password
        yang dilakukan oleh pengguna. Inputan tersebut akan divalidasi
        dengan password yang sudah terdaftar pada file logRecord.txt   */
    char password[10];

    // Variabel pilihan untuk pilihan user apakah ingin mendaftar atau keluar
    int pilihan;

    // Membuat pointer record untuk menunjuk pada file "logRecord.txt"
    FILE *record;
    // Membuka file dengan mode "r"
    record = fopen (namaFile, "r");
    if (record == NULL){
        fputs ("Error, Tidak terdapat File untuk penyimpanan akun\n", stderr);
        daftar();
    }

    // Memperlihatkan tanggal login
    waktu();
    // Instruksi untuk LOGIN
    printf ("\t\t\t\t\t||=============||\n");
    printf ("\t\t\t\t\t|| LOGIN\n");
    printf ("\t\t\t\t\t||=============||\n");
    printf ("\t\t\t\t\t|| Username: ");
    scanf  ("%s", username);
    printf ("\t\t\t\t\t||=============||\n");
    printf ("\t\t\t\t\t|| Password: ");
    scanf  ("%s", password);
    printf ("\t\t\t\t\t||=============||\n");
    system ("clear");
    // Membeaca file "logRecord.txt"
    while(fread(&u,sizeof(u),1,record)){
        /*  Mengkomparasi username serta password yang diinput pengguna kedalam fungsi
            masuk() dengan username serta password yang sudah terdaftar */
        if(strcmp(username, u.username)==0 && strcmp(password, u.password)==0){
            printf ("\t\t\t\t\t|==================|\n");
            printf ("\t\t\t\t\t|| Login Berhasil!||\n");
            printf ("\t\t\t\t\t|==================|\n");

        }
        //  Jika akun tidak terdaftar maka akan diberikan pilihan untuk mendaftar atau keluar dari program
        else {
            printf ("\t\t\t\t\t|=====================||\n");
            printf ("\t\t\t\t\t||Akun tidak terdaftar!\n");
            printf ("\t\t\t\t\t|=====================||\n");

            instruksi:
            printf ("\t\t\t\t\t||=============||\n");
            printf ("\t\t\t\t\t||Ketik 1 untuk daftar");
            printf ("\n\t\t\t\t\t||Ketik 2 untuk masuk ulang");
            printf ("\n\t\t\t\t\t||Ketik 3 untuk EXIT\n");
            printf ("\t\t\t\t\t||=============||\n");
            printf ("\n\t\t\t\t\t||Pilihan: ");
            scanf ("%d", &pilihan);
            system ("clear");
            // Jika pengguna mengetik nomor 1 maka akan dialihkan kepada fungsi daftar
            if (pilihan == 1){
                daftar();
            /* Menggunakan fungsi recursive kepada fungsi masuk agar pengguna
               dapat melakukan percobaan masuk kembali jika terjadi kesalahan penulisan */
            } else if (pilihan==2) {
                masuk();
            } else if (pilihan ==3){
                exit(1);
            } else {
                printf ("\t\t\t\t\t ERROR");
                goto instruksi;
            }
        }
    }
    fclose(record);
    return;
}

//=======================================================================//
//***************  Fungsi Untuk Menampilkan Menu Masuk  *****************//
//=======================================================================//
// Nama Fungsi    : menu_masuk                                           //
// Input Argumen  : int pilihanmasuk                                     //
// Output Argumen : -                                                    //
// Deskripsi      : Fungsi ini di buat unutk menampilkan menu program    //
//                  yang ada pada project ini, dimana disini sudah dibuat//
//                   pilihan yaitu ada program yang disediakan seperti   //
//                  Transaksi, Pemasukan, Cek saldo , dimana pada masing //
//                  masing pilihan terdapat lagi kategori seperti        //
//                  Kategori Transaksi, Kategori Pemasukan dll.          //
//                                                                       //
// Versi : 1.1                                      Rev. 1               //
// Tgl   : 03-12-2020                               Tgl: 19-12-2020      //
// I Gede Himawan - 2005551108                                           //
// Gede Rico Wijaya - 2005551091                                         //
// Revisi : Pemanggilan Fungsi masuk dan daftar                          //
// Kelas A                                                               //
//=======================================================================//
void menu_masuk(){
    // Variabel pilihan yang digunakan untuk menyimpan pilihan pengguna antara Masuk dengan Registrasi
    int pilihan;

    // Instruksi yang diberikan kepada pengguna
    instruksi:
    printf ("\t\t\t\t\t|================================================|\n");
    printf ("\t\t\t\t\t|                PILIHAN MENU MASUK              |\n");
    printf ("\t\t\t\t\t|================================================|\n");
    printf ("\t\t\t\t\t|   No  |    Menu Masuk                          |\n");
    printf ("\t\t\t\t\t|-------|----------------------------------------|\n");
    printf ("\t\t\t\t\t|   1   |    Masuk                               |\n");
    printf ("\t\t\t\t\t|   2   |    Registrasi                          |\n");
    printf ("\t\t\t\t\t|   3   |    Exit                                |\n");
    printf ("\t\t\t\t\t|================================================|\n");
    printf ("\t\t\t\t\t|================================================|\n");
    printf ("\t\t\t\t\t|| Masukkan pilihan Anda => ");
    scanf  ("%d", &pilihan);
    printf ("\t\t\t\t\t|================================================|\n");
    // Membersihkan Layar terminal 
    system ("clear");

    /* Percabangan Switch dengan kondisi nilai yang disimpan pada variabel
       pilihan jika pengguna menuliskan 1 maka akan dipanggil fungsi masuk()
       jika pengguna menuliskna 2 maka akan dipanggil fungsi registrasi()    */
    switch (pilihan){
    case 1:
        // Jika pengguna menginput angka 1 maka dipanggil fungsi masuk
        masuk();
        break;
    case 2:
        // Jika pengguna menginput angka 2 maka dipanggil fungsi registrasi
        daftar();
        break;
    case 3:
        exit(1);
        break;
    default:
        error_alert();
        // Kembali ke label instruksi jika terjadi kesalahan dalam menginput pilihan
        goto instruksi;
        break;
    }
}
