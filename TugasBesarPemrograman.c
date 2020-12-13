//Header yang di gunakan untuk standar input output pada bahasa C
#include <stdio.h>

//Dekalarasi variable global yang di gunakan pada program manjemen keuangan ini:
int masukan [10];                     //variabel masukan      => berfungsi untuk menyimpann masukan saldo yang di inputkan oleh user
int ktgrimasukan;                     //variabel ktgrimasukan => berfungsi untuk menyimpan pilihan yang dimasukan oleh user untuk di proses ke switch case pada pemilihan kategori pemasukan yang di miliki oleh user
int p;                                //variabel p            => berfungsi untuk menyimpan masukkan saldo yang di inputkan oleh user
int kategori;                         //variabel kategori     => berfungsi untuk menyimpan pilihan yang dimasukan oleh user untuk di proses ke switch case pada pemilihan kategori transaksi yang di lakukan oleh user
int pilihanmasuk;                     //variabel pilihanmasuk => berfungsi untuk menyimpan pilihan yang dimasukan oleh user untuk di proses ke switch case pada pemilihan menu login
int pilihanmenu;                      //variabel kategori     => berfungsi untuk menyimpan pilihan yang dimasukan oleh user untuk di proses ke switch case pada pemilihan menu program
int *saldo;                           //pointer saldo         => berfungsi untuk menyimpan nilai sisa dari hasil setelah saldo di kurang dengan adanya proses transaksi secara berulang kali
int harga [10];                       //variabel harga        => berfungsi untuk menyimpan masukkan harga dari transaksi yang di inputkan oleh user pada menu transaksi
int total;                            //variabel total        => berfungsi untuk menyimpan hasil dari proses pengurangan saldo setelah user melakukan proses transaksi, dimana setelah proses ini variabel total ini akan menyimpan sisa dari saldo terbaru yang di miliki oleh user
int milih;                            //variabel milih        => berfungsi untuk menyimpan pilihan yang dimasukkan oleh user untuk di proses ke switch case pada pemilihan jenis dari transaksi yang ingin di lakukan oleh user pada menu transaksi yang sudahh terdapat pada program
int Det_Transaksi [50];               //Variabel Det_Transaksi=> berfunsgi untuk menyimpan masukan dari info transaksi yang di masukkan user jika pada melihilan jenis transaksi user memilih kategori lainnya sehingga user di minta untuk memasukkan manual informasi dari transaksi yang di lakukan.
int i;                                //variabel i            => berfungsi untuk menyimpan nilai increment pada proses looping yang terdapat pada fungsi menu,dimana variabel ini akan melakukan pengulangan proses transaksi dengan nilai saldo yang di proses merupakan sisa dari saldo transaksi yang dilakukan oleh user sebelumnya.
char email [50];                      //variabel email        => berfungsi untuk menyimpan inputan email yang dimasukkan oleh user
char password [50];                   //variabel password     => berfungsi untuk menyimpan inputan password yang dimasukkan oleh user
char nama [50];                       //variabel nama         => berfungsi untuk menyimpan inputan nama yang dimasukkan oleh user
char passwordcoba [50];               //variabel passwordcoba => berfungsi untuk menyimpan inputan password dari user yang akan di gunakan untuk mengecek apakah yang sedang login adalah pemilik akun dari program yang sedang berjalan
char Det_Masukan;                     //variabel Det_Masukan  => berfungsi untuk menyimpan inputan Detail Informasi Pemasukan saldo yang di inputkan oleh user.
char nomortlp [50]                    //variabel nomortlp     => berfungsi untuk menyimpan inputan Nomor Telepon user sebagai informasi tambahan dalam membuat email.
    
//Deklarasi fungsi fungsi yang digunkan pada program manajemen keuangan
int pemasukan ();                     // Merupakkan fungsi yang digunakan untuk menampilkan dan menyimpan semua kategori, dan inputan pemasukan saldo user.
int transaksi ();                     // Merupakkan fungsi yang digunakan untuk menampilkan dan menyimpan semua kategori, dan inputan transaksi(pengeluaran) user.
void ceksaldo ();                     // Merupakkan fungsi yang digunakan untuk Menampilkan keselurahan saldo terbaru yang di miliki oleh user.
void konfirmasi ( char password1);    // Merupakan fungsi yang di gunakan untuk melakukan pengecekkan apakah yang sedang menjalankan program adalah user yang memiliki akun dari program ini , dengan membbuat parameter char password untuk menyimpan inputan password yang dibuat oleh user pada saat pertama kali memasuki program
void menu ();                         // Merupakan fungsi yang di gunakan untuk menampilakan berbagai isi dari MENU , yaitu di dalamnya terdapat menu transaksi dan kaetgori transaksi serta menampilkan pilihan utnuk user melakukan pengecekkan sisa saldo yang di miliki oleh user sendiri
void input_transaksi();               // Merupakkan fungsi yang digunakan untuk meminta dan menyimpan inputan dari jumlah transaksi yang di lakukan oleh user
void input_masukan();                 // Merupakkan fungsi yang digunakan untuk meminta dan menyimpan inputan dari jumlah masukkan yang di lakukan oleh user
void error_alert();                   // Merupakkan fungsi yang digunakan untuk menampilan pemberitahuan ketika user menginputkan pilihan yang salah pada setiap switch case.
void menu_program();                  // Merupakan fungsi yang digunakan untuk menampilkan pilihan menu program yang ada
void menu_masuk();                    // Merupakan fungsi yang digunakan untuk menampilkan pilihan menu masuk Login atau SignUp     
void username();                      // Merupakan fungsi yang digunakan untuk meminta dan menampilkan USERNAME yang digunakan oleh user
void email_password();                // Merupakan fungsi yang digunakan untuk meminta user untuk menginput Email dan Password yang di gunakan untuk Masuk ke dalam program

// fungsi main () adalah kepala dari program ini, dimana program akan di eksekusi oleh fungsi main ini.
int main (){
    //pemanggilan fungsi untuk pilihan dan pengisisan langkah awal untuk memasuki progrm
    menu_masuk();
    //pemanggilan fungsi untuk membuat dan menampilkan username
    username();
    //pemanggilan fungsi untuk konfrimasi password
    konfirmasi(password[50]);
    //pemanggilan fungsi untuk menu program
    menu_program();
}
//=======================================================================//
//*************  Fungsi Untuk Meminta Konirmasi Password   **************//
//=======================================================================//
// Nama Fungsi    : konfirmasi                                           //
// Input Argumen  : int passwordcoba                                     //
// Output Argumen : -                                                    //
// Deskripsi      : Memasukkan email dan password yang diminta.          //
//                  dimana nanti password yang di buat pertama kali      //
//                  akan di simpan dan di gunakan kembali saat melakukan //
//                  konfirmasi user .                                    //
//                                                                       //
// Versi : 1.0                                      Rev. 0               //
// Tgl   : 03-12-2020                               Tgl: 03-12-2020      //
// I Gede Himawan - 2005551108                                           //
// Kelas A                                                               //
//=======================================================================//
void konfirmasi (char password1){

    //bagian ini akan menampilkan pilihan dari program yang sedang di akses oleh user
    printf ("Cek Saldo...\n");
    pass:

    // bagian ini akan menampilkan perintah dan meminta user untuk memasukkan ulang password yang sudah di buatnya pada pertama kali login untuk mengkonvirmasi bahwa yang sedang mengakses program ini adalah pemilik akun dari program yang sedang dijalankan,
    printf ("\nMasukan Password untuk mengetahui Jumlah SALDO Anda :");
    scanf  ("%s",&passwordcoba [50]);

    // melakukan pengecekkan apabila password yang baru saja di masukkan untuk mengkonvirmasi sama dengan password yang di buat pertama kali yang dibuat oleh user, maka proses akan di lanjutkan pada program selanjutnya.
    if (passwordcoba [50] == password1)
    {
        printf ("Password Benar!!\n");
    }
    // jika password yang di masukan salah , maka program akan menampilakn pemberitahuan pasword salah
    else
    {
        printf ("Password Salah!!\n");
        //goto pass; syntax ini digunakan untuk mebawa user kembali ke menu masukkan pasword untuk mengkonvirmasi ulang, jadi syntax ini akan terus berulang hingga user memasukkan pasword yang benar dengan password yang dibuat pada saat pertama kali masuk kedalam program
        goto pass;
    }
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

    //Pada bagian ini user diminta untuk memasukkan jumlah saldo yang di miliki sebagai starter dalam program manajemen keuangan ini
    printf   ("Masukan Saldo :");
    scanf    ("%d",& p);

    //penginisialisain bahwa pointer saldo yang sudah di buat sebelumnya disimpan pada variabel p
    saldo = &p;
      ktgri:
  //pada bagian looping ini , disini berfungsi untuk menjalankan proses dari program manjemen keungan ini, dimana setiap dilakukan proses transaksi atau cek saldo maka yang akan di proses dan di tampilkan adalah saldo terbaru yang merupakan hasil dari proses sebelumnya yang di lakukan oleh user seperti proses transaksi yang dapat merubah banya saldo, sehingga program dapat di jalankan sesuai ekspetasi yang di inginkan oleh penulis programnya
  for(i=0; i<1; i++){
    printf ("pilihan : \n1.Transaksi\n2.Pemasukan\n3.CekSaldo\nMasukan Pilihan Anda:");
    scanf  ("%d",&kategori);

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
    case 3:
            ceksaldo();
            goto ktgri;
            break;
    }
  }
}
//=======================================================================//
//**************   Fungsi Untuk Menginputkan Pemasukan   ****************//
//=======================================================================//
// Nama Fungsi    : pemasukan                                            //
// Input Argumen  : int ktgrimasukan                                     //
// Output Argumen : -                                                    //
// Deskripsi      : Menampilkan Kategori Pemasukan yang ada lalu         //
//                  memanggil fungsi input_masukan yang meminta user     //
//                  untuk melakukan input saldo dan di proses untuk      //
//                  mendapatkan jumlah saldo terbaru.                    //
//                                                                       //
// Versi : 1.0                                      Rev. 0               //
// Tgl   : 03-12-2020                               Tgl: 03-12-2020      //
// I Gede Himawan - 2005551108                                           //
// Kelas A                                                               //
//=======================================================================// 
int pemasukan (){

    ktgrimasuk:
    printf ("Kategori Pemasukan \n");
    printf ("1. Sewa\n2.Sumbangan\n3. Dividen\n4. Pengembalian Dana\n5. Upah\n6. Penjualan\n7. Bonus\n8.Voucher\n9. Lainnya...\n");
    printf ("Masukan Kategori Pemasukan yang anda miliki =>");
    scanf  ("%d",&ktgrimasukan);

    switch (ktgrimasukan){
        case 1:
            printf ("Sewa....\n");
            input_masukan();
            break;
        case 2:
            printf ("Sumbangan....\n");
            input_masukan();
            break;
        case 3:
            printf ("Deviden....\n");
            input_masukan();
            break;
        case 4:
            printf ("Pengembalian Dana...\n");
            input_masukan();
            break;
        case 5:
            printf ("Upah....\n");
            input_masukan();
            break;
        case 6:
            printf ("Penjualan....\n");
            input_masukan();
            break;
        case 7:
            printf ("Bonus....\n");
            input_masukan();
            break;
        case 8:
            printf ("Voucher....\n");
            input_masukan();
            break;
        case 9:
            printf ("Lainnya....\n");
            input_masukan();
            break;
        default:
           error_alert();
        goto ktgrimasuk;
        break;
    }
    total  = *saldo + masukan[i];
    *saldo = total;

    return total;
}
//=======================================================================//
//***********   Fungsi Untuk Menampilkan Pilihan transaksi  *************//
//=======================================================================//
// Nama Fungsi    : transaksi                                            //
// Input Argumen  : int milih                                            //
// Output Argumen : -                                                    //
// Deskripsi      : Menampilkan Kategori Transaksi yang ada lalu         //
//                  memanggil fungsi input_transaksi yang meminta user   //
//                  untuk melakukan input harga dan di proses untuk      //
//                  mendapatkan jumlah sisa saldo terbaru.               //
//                                                                       //
// Versi : 1.0                                      Rev. 0               //
// Tgl   : 03-12-2020                               Tgl: 03-12-2020      //
// I Gede Himawan - 2005551108                                           //
// Kelas A                                                               //
//=======================================================================// 
int transaksi (){
            printf ("Kategori Pengeluaran\n");
            printf ("1. Makanan\n2. Transportasi\n3. Fashion\n4. Rumah Tangga\n5. Pendidikan\n6. Lainnya..\nMasukan Pilihan Anda :");
            scanf  ("%d",&milih);
            switch (milih){

        //pada case 1 dari menu switch(kategori), memiliki syntax switch case lagi di dalamnya, dimana disini berfungsi untuk meneksekusi inputan dari pilihan yang dimasukkan oleh user pada pilihan kategori transaksi sebelumnya.
        //dalam case 1 ini mengeksekusi perintah jika user memilih kategori makanan pada pemilihan kategori transaksi, dimana disini user akan diminta untuk memasukkan harga dan detail tambahan untuk transaksi yang sudah di lakukan oleh user.
        case 1:
            printf ("Makanan....\n");
            input_transaksi();
            break;

        //dalam case 2 ini mengeksekusi perintah jika user memilih kategori Transportasi pada pemilihan kategori transaksi, dimana disini user akan diminta untuk memasukkan harga dan detail tambahan untuk transaksi yang sudah di lakukan oleh user.
        case 2:
            printf ("Transportasi....\n");
            input_transaksi();
            break;

        //dalam case 3 ini mengeksekusi perintah jika user memilih kategori Fashion pada pemilihan kategori transaksi, dimana disini user akan diminta untuk memasukkan harga dan detail tambahan untuk transaksi yang sudah di lakukan oleh user.
        case 3:
            printf ("Fashion....\n");
            input_transaksi();

            break;

        //dalam case 4 ini mengeksekusi perintah jika user memilih kategori Rumah Tangga pada pemilihan kategori transaksi, dimana disini user akan diminta untuk memasukkan harga dan detail tambahan untuk transaksi yang sudah di lakukan oleh user.
        case 4:
            printf ("Rumah Tangga....\n");
            input_transaksi();
            break;

        //dalam case 5 ini mengeksekusi perintah jika user memilih kategori Pendidikan pada pemilihan kategori transaksi, dimana disini user akan diminta untuk memasukkan harga dan detail tambahan untuk transaksi yang sudah di lakukan oleh user.
        case 5:
            printf ("Pendidikan....\n");
            input_transaksi();
            break;

        //dalam case 6 ini mengeksekusi perintah jika user memilih kategori Lainnya pada pemilihan kategori transaksi, dimana disini user akan diminta untuk memasukkan harga dan detail tambahan untuk transaksi yang sudah di lakukan oleh user.
        case 6:
            printf ("Lainnya....\n");
            input_transaksi();
            break;

        //Jika user menginput pilihan yang salah, atau menginput nilai yang tidak ada pada tampilan menu maka program akan mengesekusi pada bagian default seperti di bawah ini:
        default:
            printf   ("Pilihan yang Anda masukan Salah!!!\n");
            printf   ("Silahkan Memilih Pilihan yang Sudah ada\n");
            printf   ("=========================================");
            break;
        }
    total  = *saldo - harga[i];
    *saldo = total;

    return total;
}
//=======================================================================//
//****************   Fungsi Untuk Menampilkan Saldo   *******************//
//=======================================================================//
// Nama Fungsi    : ceksaldo                                             //
// Input Argumen  : -                                                    //
// Output Argumen : int *saldo                                           //
// Deskripsi      : Menampilkan Sisa atau Banyak saldo yang dimiliki     //
//                  Oleh user.                                           //
//                                                                       //
// Versi : 1.0                                      Rev. 0               //
// Tgl   : 03-12-2020                               Tgl: 03-12-2020      //
// I Gede Himawan - 2005551108                                           //
// Kelas A                                                               //
//=======================================================================//
void ceksaldo (){

            // Menampilkan pemberitahuan sisa saldo yang di* miliki user pada saat mengakses program
            printf ("Sisa Saldo Anda Adalah  :Rp. %d \n" , *saldo);
            //Pointer saldo akan menyimpan sisa saldo terbaru yang akan di proses kembali apabila ada proses transaksi lagi .
}
//=======================================================================//
//**************       Fungsi Untuk Input Pemasukan      ****************//
//=======================================================================//
// Nama Fungsi    : input_masukan                                        //
// Input Argumen  : int masukan [], char Det_Masukan                     //
// Output Argumen : -                                                    //
// Deskripsi      : Meminta user untuk memasukan banyak pemasukan        //
//                  dan mengisi detail pemasukan yang dilakukan oleh     //
//                  yang dilakukan oleh user.                            //
//                                                                       //
// Versi : 1.0                                      Rev. 0               //
// Tgl   : 03-12-2020                               Tgl: 03-12-2020      //
// I Gede Himawan - 2005551108                                           //
// Kelas A                                                               // 
//=======================================================================//
void input_masukan(){
        printf ("Masukkan Banyak Pemasukan Anda :");
        scanf  ("%d",&masukan[i]);
        printf ("Masukan Detail Pemasukan:");
        scanf   (" %[^\n]",&Det_Masukan);
}
//=======================================================================//
//**************       Fungsi Untuk Input Transaksi      ****************//
//=======================================================================//
// Nama Fungsi    : input_transaksi                                      //
// Input Argumen  : int harga [], char Det_Transaksi                     //
// Output Argumen : -                                                    //
// Deskripsi      : Meminta user untuk memasukan harga barang yang dibeli//
//                  dan mengisi detail transaksi dari barang transaksi   //
//                  yang dilakukan oleh user.                            //
//                                                                       //
// Versi : 1.0                                      Rev. 0               //
// Tgl   : 03-12-2020                               Tgl: 03-12-2020      //
// I Gede Himawan - 2005551108                                           //
// Kelas A                                                               // 
//=======================================================================// 
void input_transaksi(){
        printf ("Masukkan Total Transaksi anda :");
        scanf  ("%d",&harga [i]);
        printf ("Masukan Jenis Transaksi :");
        scanf  (" %[^\n]",&Det_Transaksi);
}
//=======================================================================//
//**************   Fungsi Untuk Menampilkan Pesan Eror   ****************//
//=======================================================================//
// Nama Fungsi    : error_alert                                          //
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
printf   ("Pilihan yang Anda masukan Salah!!!\n");
printf   ("Silahkan Memilih Pilihan yang Sudah ada\n");
printf   ("=========================================");
//goto ktgri; syntax ini akan mengembalikan user ke menu pemilihan kategori untu memilih kembali menu program jika pada bagian ini user sudah melakukan inputan sesuai dengan apa yang di minta oleh program,
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
// Versi : 1.0                                      Rev. 0               //
// Tgl   : 03-12-2020                               Tgl: 03-12-2020      //
// I Gede Himawan - 2005551108                                           //
// Kelas A                                                               //
//=======================================================================// 
void menu_program(){
        pilih:
            puts   ("\nMenu Program");
            puts   ("============");
            puts   ("1. MENU");
            printf ("Masukan Pilihan Anda :");
            scanf  ("%d",&pilihanmenu);

        // pada switch case bagian ini , disini akan memproses dari inputan yang sudah dimasukkan oleh user pada proses pemiihan pemilihan menu sebelumnya dan mengantarkan program pada fungsi yang merupakan panggilan dari pilihan yang di inputkan oleh user.
        switch (pilihanmenu)
        {
            //pada case 1 ini, program akan memanggil fungsi yang sudah dibuat yaitu fungsi yang bernama void menu();
        case 1:
            menu ();
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
//***************  Fungsi Untuk Menampilkan Menu Masuk  *****************//
//=======================================================================//
// Nama Fungsi    : menu_masuk                                           //
// Input Argumen  : int pilihanmasuk                                     //
// Output Argumen : -                                                    //
// Deskripsi      : Fungsi ini di buat unutk menampilkan menu program    //
//                  yang ada pada project ini, dimana disini sudah dibuat//
//                  pilihan yaitu ada program yang disediakan seperti    //
//                  Transaksi, Pemasukan, Cek saldo , dimana pada masing //
//                  masing pilihan terdapat lagi kategori seperti        //
//                  Kategori Transaksi, Kategori Pemasukan dll.          //
//                                                                       //
// Versi : 1.0                                      Rev. 0               //
// Tgl   : 03-12-2020                               Tgl: 03-12-2020      //
// I Gede Himawan - 2005551108                                           //
// Kelas A                                                               //
//=======================================================================// 
void menu_masuk(){
        // Pada menu awal user akan dimnta untuk memasukkan pilihan untuk masuk ke dalam program, dimana disini terdapat dua pilihan yaitu Login dan SignUp, dimana disetiap pilihan akan mengantarkan user ke masing masing menu dari setiap pilihan tersebut
        masuk:
            printf ("Pilihan Masuk\n");
            printf ("1. Login \n2. SignUp\n");
            printf ("Masukan Pilihan :");
            scanf  ("%d",&pilihanmasuk);

        // menu switch case disini merupakan lanjutan dari pilihan yang di masukkan oleh user sebelumnya, dimana user akan di minta untuk megisi beberapa data yang di butuhkan untuk melakukan proses masuk ke dalam program
        switch (pilihanmasuk)
        {
        //pada case 1 ini program akan menampilakn tampilan seperti berikut ini, dan meminta user untuk mengisi dat ayang sudah di inputkan sebagai pendukung  untuk menu login
        case 1:
            printf ("\nLogin.....\n=============================\n");
            email_password();
            break;

        //pada case 2 ini program akan menampilakn tampilan seperti berikut ini, dan meminta user untuk mengisi dat ayang sudah di inputkan sebagai pendukung  untuk menu SignUp
        case 2:
            printf ("\nSignUp....\n==========================\n");
            printf ("LENGKAPI BIODATA\n");
            email_password();
            break;
        //Jika user menginput pilihan yang salah, atau menginput nilai yang tidak ada pada tampilan menu maka program akan mengesekusi pada bagian default seperti di bawah ini:
        default:
            printf   ("Pilihan yang Anda masukan Salah!!!\nSilahkan Memilih Pilihan yang Sudah ada\n=========================================\n");
            //goto masuk; dimana syntax ini akan membawa user kembali ke menu pemilihan metode masuk program untuk menginputkan pilihan yang benar, ini akan terus berulang hingga user menginputkan pilihan yang benar sesaui apa yang sudah ditampilkan pada menu pilihan.
            goto masuk;
            break;
        }
}
//=======================================================================//
//*********   Fungsi Untuk Membuat dan Menampilkan USERNAME   ***********//
//=======================================================================//
// Nama Fungsi    : username                                             //
// Input Argumen  : int nama                                             //
// Output Argumen : -                                                    //
// Deskripsi      : Meminta user untuk memasukan USERNAME.               //
//                  Setelah user melakukan input USERNAME , selanjutnya  //
//                  USERNAME ini akan di tampilkan bersamaan pada bagian //
//                  dimana Program memberikan ucapan SELAMAT DATANG      //
//                                                                       //
// Versi : 1.0                                      Rev. 0               //
// Tgl   : 03-12-2020                               Tgl: 03-12-2020      //
// I Gede Himawan - 2005551108                                           //
// Kelas A                                                               //
//=======================================================================// 
void username(){
    // Pada bagian ini sistem akan meminta agar user memasukkan nama atau username sebagai inisial pengguna untuk memngakses program selanjutnya
    printf ("\n==================\n");
    printf ("TENTUKAN NAMA PENGGUNA\n");
    printf ("Masukan Nama Pengguna  :");
    scanf  (" %[^\n]",&nama);
    // Pada bagian ini program akan menampilkan ucapan selamat datang untuk pertama kalinya dengan menyertakan username yang sudah di tentukan oleh user pada proses sebelumnya.
    printf ("\nHALLO %s....\n",nama);
    printf ("Selamat datang... :)\n");
    printf ("==================\n");
}
//=======================================================================//
//************   Fungsi Untuk Meminta Email & Password   ****************//
//=======================================================================//
// Nama Fungsi    : email_password                                       //
// Input Argumen  : int email & char password                            //
// Output Argumen : -                                                    //
// Deskripsi      : Memasukkan email, password, dan nomor telepon yang   //
//                  diminta. dimana nanti password yang di buat pertama  //
//                  kali akan di simpan dan di gunakan kembali saat      //
//                  melakukan konfirmasi user .                          //
// Versi : 1.0                                      Rev. 1               //
// Tgl   : 03-12-2020                               Tgl: 03-12-2020      //
// I Gede Himawan - 2005551108                                           //
// Kelas A                                                               //
//=======================================================================// 
void email_password(){
        printf ("Buat Email Anda           :");
        scanf  ("%s",&email [50]);
        printf ("Buat Password untuk login :");
        scanf  ("%s",&password [50]);
        printf ("Masukkan Nomor telepon    :");
        scanf  ("%s",&nomortlp [50]);
}

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
   
//=======================================================================//
//**              Fungsi Untuk Memilih Menu Wishlist            ***//
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
        printf ("1.Kembali ke menu wishlist\n2.Kembali ke menu utama");
        printf ("\nApakah anda ingin melanjutkan menu? \n");
        scanf ("%d",&pilihanMenu);

        switch (pilihanMenu){
        case 1:
            daftarwishlist();
            break;
        case 2:
            printf ("Terima kasih");
            break;
        default:;
            printf ("Perhatikan angka yang anda inputkan!");
            goto akhir;
            break;
    }
    system ("clear");
}
