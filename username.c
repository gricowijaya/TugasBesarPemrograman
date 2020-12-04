#include <stdio.h>
#include <stdlib.h>

//Membuat Struct User dengan member nama dan no_telp
struct User{
	char nama[30];
	char no_telp[12];
}u1; //Mendeklarasikan variabel u1 pada struct User

//=======================================================================//
//**************  Fungsi Untuk Menginput Nama dan No.Tel ****************//
//=======================================================================//
// Nama Fungsi    : username            				 //
// Input Argumen  : u1.nama, u1.no_telp                                  //
// Passing Argumen: struct User u1, char file[]                          //
// Output Argumen : u1.nama, u1.no_telp                                  //
// Deskripsi      : Fungsi ini ditujukan untuk menginput Nama User dan 	 //
//					No.Telp User			 //
// Versi : 1.0                                      Rev. 0               //
// Tgl: 30-11-2020                                  Tgl: 30-11-2020      //
// Gede Rico Wijaya - 2005551091                                         //
// Kelas A                                                               //
//=======================================================================//
void username(struct User u1, char file[]){
	//Instruksi dari input nama 
	printf ("Ketik nama anda :");
	scanf  ("%s", u1.nama); //menyimpan nilai input dengan akses member nama dengan variabel u1
	//Instruksi dari input nomor telepon
	printf ("Ketik nomor telepon anda: ");
	scanf  ("%s", u1.no_telp); //menyimpan nilai input dengan akses member no_telp dengan variabel u1

	//Mendeklarasikan Tipe Data FILE dengan pointer rc
	FILE *rc; //pointerReport pada file Record.dat
	//Assign rc untuk membuka file binary Record.dat dan menggunakan mode "rb" untuk membuka non-text file
    rc = fopen (file, "ab");
	//Menuliskan hasil inputan kepada file Record.dat
    fprintf (rc, "%s\t%s\t", u1.nama, u1.no_telp);
	//Menuliskan data kepada file Record.dat
    fwrite (&u1, sizeof(u1), 1, rc);
	//Menggunakan fungsi fclose untuk menutup file "Record.dat" agar tidak diproses lagi
	fclose (rc);

	//untuk menghilangkan perintah-perintah dari layar terminal
    system ("clear");
}
