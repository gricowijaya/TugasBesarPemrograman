#include <stdio.h>
#include <stdlib.h>

int harga;
int menuUtama;
int pilihanMenu;
int pilihanTarget;
char namaTarget;

void wish_list();
void menupil ();
void daftarwishlist();

//=======================================================================//
//*****         Fungsi Untuk Meminta User Menginputkan Target      ******//
//=======================================================================//
// Nama Fungsi    : wishlist                                             //
// Input Argumen  : int pilihanTarget dan char namaTarget                //
// Output Argumen : -                                                    //
// Deskripsi      : Memasukkan kategori target yang diminta.             //
//                  Nanti deskripsi target dan harga                     //
//                  akan di simpan dan di gunakan kembali saat melakukan //
//                  proses pencapaian target terhadap uang yang          //
//                  dimiliki oleh user .                                 //
// Versi : 1.0                                      Rev. 0               //
// Tgl   : 04-12-2020                               Tgl: 04-12-2020      //
// Luh Putu Monica Arysta Putri Suastawan/2005551090                     //
// Kelas A                                                               //
//=======================================================================// 

int main (){

        daftarwishlist();
        menupil();

    return 0;
}

void daftarwishlist(){
    wishlist:
        printf ("Kategori target\n");
        printf ("1. Pendidikan \n2. Tempat tinggal \n3. Liburan \n4. Kesehatan \n5. Investasi \n6. Kendaraan \n7. Alat Elektronik");
        printf ("\nMasukan Pilihan : ");
        scanf  ("%d",&pilihanTarget);

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
}
}

void menupil (){
akhir :
        printf ("1.Kembali ke menu wishlist\n2.Kembali ke menu utama\n3.Keluar");
        printf ("\nApakah anda ingin melanjutkan menu? \n");
        scanf ("%d",&pilihanMenu);

        switch (pilihanMenu){
        case 1:
            daftarwishlist();
        break;
        case 2:
            printf ("Terima kasih");
            exit(0);
        default:;
            printf ("Perhatikan angka yang anda inputkan!");
        goto akhir;
        break;
    }
}

void wish_list(){

        printf ("Deskripsi :");
        scanf  ("%s",&namaTarget);
        printf ("Kisaran Harga :");
        scanf  ("%d",&harga);
}