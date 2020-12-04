#include <stdio.h>

//Membuat Struct User dengan member nama dan no_telp
struct User{
	char nama[30];
	char no_telp[12];
}u1; //Mendeklarasikan variabel u1 pada struct User

//=======================================================================//
//**************  Fungsi Untuk Menampilkan Record User   ****************//
//=======================================================================//
// Nama Fungsi    : record                                               //
// Passing Argumen: struct User u, char file[]                           //
// Output Argumen : u1.nama u1.no_telp                                   //
// Deskripsi      : Fungsi ini ditujukan untuk menampilkan data yang     //
//                  dimasukan oleh user yaitu berupa nama dan no.telp    //
//                  yang disimpan pada file Record.dat                   //
// Versi : 1.0                                      Rev. 0               //
// Tgl: 30-11-2020                                  Tgl: 30-11-2020       //
// Gede Rico Wijaya - 2005551091                                         //
// Kelas A                                                               //
//=======================================================================//
void record(struct User u, char file[] ){
    //Mendeklarasikan tipe data file dengan pointer *rc yang bertujuan untuk pointer pada file "Record.dat"
    FILE *rc;
    //Assign rc untuk membuka file binary Record.dat dan menggunakan mode "rb" untuk membuka non-text file
    rc = fopen(file, "rb");
    //Menggunakan fungsi fread untuk membaca isi dari file "Record.dat"
    fread (&u1, sizeof(u1), 1, rc);
    //Menggunakan fungsi fclose untuk menutup file "Record.dat" agar tidak diproses lagi
    fclose (rc);

    //Menampilkan hasil dari Record nama user dan nomor telepon yang diinput oleh user 
    printf("Nama\t\tNomor Telepon\n\n");
    printf("%s\t",u1.nama);
    printf("%s\t\n\n",u1.no_telp);
}
