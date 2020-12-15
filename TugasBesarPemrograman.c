//Header yang di gunakan untuk standar input output pada bahasa C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//Dekalarasi variable global yang di gunakan pada program manjemen keuangan ini:
int masukan [10];                     //variabel masukan      => berfungsi untuk menyimpann masukan saldo yang di inputkan oleh user
int ktgrimasukan;                     //variabel ktgrimasukan => berfungsi untuk menyimpan pilihan yang dimasukan oleh user untuk di proses ke switch case pada pemilihan kategori pemasukan yang di miliki oleh user
int p;                                //variabel p            => berfungsi untuk menyimpan masukkan saldo yang di inputkan oleh user
int kategori;                         //variabel kategori     => berfungsi untuk menyimpan pilihan yang dimasukan oleh user untuk di proses ke switch case pada pemilihan kategori transaksi yang di lakukan oleh user
int pilihanmasuk;                     //variabel pilihanmasuk => berfungsi untuk menyimpan pilihan yang dimasukan oleh user untuk di proses ke switch case pada pemilihan menu login
int pilihanmenu;                      //variabel kategori     => berfungsi untuk menyimpan pilihan yang dimasukan oleh user untuk di proses ke switch case pada pemilihan menu program
int *saldo;                           //pointer saldo         => berfungsi untuk menyimpan nilai sisa dari hasil setelah saldo di kurang dengan adanya proses transaksi secara berulang kali
int harga;                            //variabel harga        => berfungsi untuk menyimpan masukkan harga dari transaksi yang di inputkan oleh user pada menu transaksi
int total;                            //variabel total        => berfungsi untuk menyimpan hasil dari proses pengurangan saldo setelah user melakukan proses transaksi, dimana setelah proses ini variabel total ini akan menyimpan sisa dari saldo terbaru yang di miliki oleh user
int milih;                            //variabel milih        => berfungsi untuk menyimpan pilihan yang dimasukkan oleh user untuk di proses ke switch case pada pemilihan jenis dari transaksi yang ingin di lakukan oleh user pada menu transaksi yang sudahh terdapat pada program
char Det_Transaksi [50];              //Variabel Det_Transaksi=> berfunsgi untuk menyimpan masukan dari info transaksi yang di masukkan user jika pada melihilan jenis transaksi user memilih kategori lainnya sehingga user di minta untuk memasukkan manual informasi dari transaksi yang di lakukan.
int i;                                //variabel i            => berfungsi untuk menyimpan nilai increment pada proses looping yang terdapat pada fungsi menu,dimana variabel ini akan melakukan pengulangan proses transaksi dengan nilai saldo yang di proses merupakan sisa dari saldo transaksi yang dilakukan oleh user sebelumnya.
char email [50];                      //variabel email        => berfungsi untuk menyimpan inputan email yang dimasukkan oleh user
int password;                         //variabel password     => berfungsi untuk menyimpan inputan password yang dimasukkan oleh user
char nama [50];                       //variabel nama         => berfungsi untuk menyimpan inputan nama yang dimasukkan oleh user
int passwordcoba;                     //variabel passwordcoba => berfungsi untuk menyimpan inputan password dari user yang akan di gunakan untuk mengecek apakah yang sedang login adalah pemilik akun dari program yang sedang berjalan
char Det_Masukan;                     //variabel Det_Masukan  => berfungsi untuk menyimpan inputan Detail Informasi Pemasukan saldo yang di inputkan oleh user.
int hargaBarangDiinginkan;            //variabel hargaBarangDiinginkan => berfungsi untuk menyimpan harga barang
int pilihanTarget;                    //variabel pilihanTarget => berfungsi untuk menyimpan pilihan dari kategori target pada bagian Wishlist
char namaTarget[50];                  //variabel namaTarget    => berfungsi untuk menyimpan deskripsi dari target barang yang diinginkan pada bagian Wishlist
char usernameCoba [15];               //variabel usernameCoba  => berfungsi untuk menyimpan username yang dilogin oleh user
int pilihanMenu;                      //variable pilihanMenu   => berfungsi untuk menyimpan pilihan untuk user apakah user ingin menambah wishlist atau kembali ke menu utama
int saldoDimiliki;                    //variabel saldoDimiliki => berfungsi untuk menyimpan saldo yang dituliskan dari pada akunBank, akunCreditCard, cash
time_t waktuserver;                   //variavel waktuserver   => berfungsi untuk mengambil waktu dari sistem.
int metode;                           //variable pilihanMenu   => berfungsi untuk menyimpan pilihan metode pembayaran pada fungsi transaksi.
int *bank;                            //pointer bank           => berfungsi untuk menyimpan nilai sisa dari hasil setelah saldo bank di kurang atau dengan adanya proses transaksi secara berulang kali 
int *kredit;                          //pointer bank           => berfungsi untuk menyimpan nilai sisa dari hasil setelah saldo kredit di kurang atau dengan adanya proses transaksi secara berulang kali 
int *cash;                            //pointer bank           => berfungsi untuk menyimpan nilai sisa dari hasil setelah saldo cash di kurang atau dengan adanya proses transaksi secara berulang kali                         
//Membuat Struct User dengan member nama dan no_telp
struct User{
	char nama[30];
	char no_telp[12];
    char username[15];
};

//Membuat struct account dengan member akunBank, akunCreditCard, cash.
struct account{
    int akunBank; //Untuk menyimpan nilai saldo pada akun rekening di Bank
    int akunCreditCard; //Untuk menyimpan nilai saldo pada akun Credit Card
    int cash; //Untuk meniympan nilai uang cash yang dimiliki
};

//Membuat struct bayar dengan member bank, creditCard, dan cash
typedef struct {
    int bank;
    int creditCard;
    int cash;
}bayar;

//Mendeklarasikan variabel u1 pada struct User
struct User u1;
struct account a1;
//Deklarasi fungsi fungsi yang digunkan pada program manajemen keuangan'
int pemasukan ();                                    // Merupakan fungsi yang digunakan untuk menampilkan dan menyimpan semua kategori, dan inputan pemasukan saldo user.
int transaksi ();                                    // Merupakan fungsi yang digunakan untuk menampilkan dan menyimpan semua kategori, dan inputan transaksi(pengeluaran) user.
void ceksaldo ();                                    // Merupakan fungsi yang digunakan untuk Menampilkan keselurahan saldo terbaru yang di miliki oleh user.
void konfirmasi (struct User u1,int password1);    // Merupakan fungsi yang di gunakan untuk melakukan pengecekkan apakah yang sedang menjalankan program adalah user yang memiliki akun dari program ini , dengan membbuat parameter char password untuk menyimpan inputan password yang dibuat oleh user pada saat pertama kali memasuki program
void menu ();                                        // Merupakan fungsi yang di gunakan untuk menampilakan berbagai isi dari MENU , yaitu di dalamnya terdapat menu transaksi dan kaetgori transaksi serta menampilkan pilihan utnuk user melakukan pengecekkan sisa saldo yang di miliki oleh user sendiri
void input_transaksi();                              // Merupakan fungsi yang digunakan untuk meminta dan menyimpan inputan dari jumlah transaksi yang di lakukan oleh user
void input_masukan();                                // Merupakan fungsi yang digunakan untuk meminta dan menyimpan inputan dari jumlah masukkan yang di lakukan oleh user
void error_alert();                                  // Merupakan fungsi yang digunakan untuk menampilan pemberitahuan ketika user menginputkan pilihan yang salah pada setiap switch case.
void menu_program();                                 // Merupakan fungsi yang digunakan untuk menampilkan pilihan menu program yang ada
void menu_masuk();                                   // Merupakan fungsi yang digunakan untuk menampilkan pilihan menu masuk Login atau SignUp
void username(struct User u1, char *nm);             // Merupakan fungsi yang digunakan untuk meminta dan menampilkan USERNAME yang digunakan oleh user
void email_pw();                                     // Merupakan fungsi yang digunakan untuk meminta user untuk menginput Email dan Password yang di gunakan untuk Masuk ke dalam program
void record(struct User u1, char file[]);            // Merupakan fungsi yang digunakan untuk memperlihatkan track record dari file "Record.dat"
void wish_list();                                    // Merupakan fungsi yang digunakan untuk menambahkan daftar barang yang diinginkan oleh user
void menupil ();                                     // Merupakan fungsi yang digunakan untuk pilihan apakah ingin menambah wishlist atau kembali ke menu utama
void daftarwishlist();                               // Merupakan fungsi yang digunakan untuk memilih kategori dari barang wishlist yang diinginkan
int DanaDarurat (int *saldo);                        // Merupakan fungsi yang digunakan untuk membantu User dalam mempersiapkan DanaDarurat
int inputSaldo(char x[]);                            // Merupakan fungsi yang digunakan untuk menginput saldo dengan akun Bank, akun CreditCard, akun Cash
void waktu();                                        // Merupakan fungsi yang digunakan untuk menampilkan waktu pada sistem tempat user mengakses
//Deklarasi variabel namaFile  "Record.dat" untuk menyimpan data nama dan nomor telepon"
char namaFile[] = "Record.dat";
//Assign pointer *saldo kepada alamat variabel dari saldoDimiliki
int *saldo = &saldoDimiliki;
int *bank   = & a1.akunBank;
int *kredit = & a1.akunCreditCard;
int *cash   = & a1.cash;
// fungsi main () adalah kepala dari program ini, dimana program akan di eksekusi oleh fungsi main ini.
int main (){
    bayar md;
    //pemanggilan fungsi untuk pilihan dan pengisisan langkah awal untuk memasuki progrm
    menu_masuk();
    //pemanggilan fungsi untuk membuat dan menampilkan username
    username(u1, namaFile);
    //pemanggilan fungsi untuk konfrimasi password
    konfirmasi(u1, password);
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
// Versi : 1.1                                      Rev. 1               //
// Tgl   : 03-12-2020                               Tgl: 03-12-2020      //
// Revisi: Memperbaiki Logical Error yang sebelumnya terjadi. Dimana     //
//        saat user melakukan konfirmasi password dengan password yang   //
//        salah , pogram tetap membenarkan, namun setelah di perbaiki    //
//        kini user harus memasukkan password dengan benar untuk lanjut. //
// I Gede Himawan - 2005551108                                           //
// Kelas A                                                               //
//=======================================================================//
void konfirmasi (struct User u1,int password1){
    pass:
    printf ("\nMasukan Password untuk mengetahui Jumlah SALDO Anda :");
    scanf  ("%d",&passwordcoba);
    // melakukan pengecekkan apabila password yang baru saja di masukkan untuk mengkonvirmasi sama dengan password yang di buat pertama kali yang dibuat oleh user, maka proses akan di lanjutkan pada program selanjutnya.
    if ( passwordcoba == password1){
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
    printf   ("Masukan Saldo\n");
    //penginisialisain bahwa pointer saldo yang sudah di buat sebelumnya disimpan pada variabel p
    inputSaldo(namaFile);

    //Mendeklarasikan label ktgri untuk menampilkan kategori menu yang ingin dipilih
    ktgri:
    //pada bagian looping ini , disini berfungsi untuk menjalankan proses dari program manjemen keungan ini, dimana setiap dilakukan proses transaksi atau cek saldo maka yang akan di proses dan di tampilkan adalah saldo terbaru yang merupakan hasil dari proses sebelumnya yang di lakukan oleh user seperti proses transaksi yang dapat merubah banya saldo, sehingga program dapat di jalankan sesuai ekspetasi yang di inginkan oleh penulis programnya
    for(i=0; i<1; i++){
        printf ("pilihan : \n1. Transaksi\n2. Pemasukan\n3. Cek Saldo\n4. Dana Darurat\n5. Log Record\n6. Wihslist\n7. EXIT\nMasukan Pilihan Anda:");
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
            //pada case 3 user akan mengecek saldo yang dimiliki sekarang baik sebelum melakukan input transaksi dan input pemasukan maupun setelahnya
            case 3:
                ceksaldo();
                goto ktgri;
                break;
            case 4:
                DanaDarurat(saldo);
                goto ktgri;
                break;
            case 5:
                record(u1, namaFile);
                goto ktgri;
                break;
            case 6:
                wish_list();
                menupil  ();
                goto ktgri;
                break;
            case 7:
                exit (0);
                break;
            default:
                printf ("Silahkan ketik ulang pilihan anda");
                goto ktgri;
                break;
        }
    }
    system ("clear");
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
// Versi : 1.1                                      Rev. 1               //
// Tgl   : 03-12-2020                               Tgl: 03-12-2020      //
// Revisi: Menambahkan pemanggilan fungsi waktu untuk menginfokan waktu  //
//        Saat user mengakses program.                                   //
// I Gede Himawan - 2005551108                                           //
// Kelas A                                                               //
//=======================================================================//
int pemasukan (){

    ktgrimasuk:
    printf ("Kategori Pemasukan \n");
    printf ("1. Sewa\n2. Sumbangan\n3. Dividen\n4. Pengembalian Dana\n5. Upah\n6. Penjualan\n7. Bonus\n8. Voucher\n9. Lainnya...\n");
    printf ("Masukan Kategori Pemasukan yang anda miliki =>");
    scanf  ("%d",&ktgrimasukan);

    switch (ktgrimasukan){
        case 1:
            printf ("Sewa....\n");
            input_masukan();
            waktu();
            break;
        case 2:
            printf ("Sumbangan....\n");
            input_masukan();
            waktu();
            break;
        case 3:
            printf ("Deviden....\n");
            input_masukan();
            waktu();
            break;
        case 4:
            printf ("Pengembalian Dana...\n");
            input_masukan();
            waktu();
            break;
        case 5:
            printf ("Upah....\n");
            input_masukan();
            waktu();
            break;
        case 6:
            printf ("Penjualan....\n");
            input_masukan();
            waktu();
            break;
        case 7:
            printf ("Bonus....\n");
            input_masukan();
            waktu();
            break;
        case 8:
            printf ("Voucher....\n");
            input_masukan();
            waktu();
            break;
        case 9:
            printf ("Lainnya....\n");
            input_masukan();
            waktu();
            break;
        default:
           error_alert();
        goto ktgrimasuk;
        break;
        system ("clear");
    }
    total  = *saldo + masukan[i];
    *saldo = total;

    return total;
}


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
            printf ("Saldo pada Bank   : %d\n",*bank);
            printf ("Saldo pada kredit : %d\n",*kredit);
            printf ("Saldo pada cash   : %d\n",*cash);
            printf ("Sisa Total Saldo Anda Adalah  :Rp. %d \n" , *saldo);
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
        printf ("Masukkan Total Transaksi anda: ");
        scanf  ("%d",&harga );
        printf ("Deskripsi: ");
        scanf  ("%s",&Det_Transaksi[50]);
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
printf   ("Pilihan yang Anda masukan Salah!!!\n");
printf   ("Silahkan Memilih Pilihan yang Sudah ada\n");
printf   ("=========================================");
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
//                   pilihan yaitu ada program yang disediakan seperti    //
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
            email_pw();
            break;

        //pada case 2 ini program akan menampilakn tampilan seperti berikut ini, dan meminta user untuk mengisi dat ayang sudah di inputkan sebagai pendukung  untuk menu SignUp
        case 2:
            printf ("\nSignUp....\n==========================\n");
            printf ("LENGKAPI BIODATA\n");
            email_pw();
            break;
        //Jika user menginput pilihan yang salah, atau menginput nilai yang tidak ada pada tampilan menu maka program akan mengesekusi pada bagian default seperti di bawah ini:
        default:
            printf   ("Pilihan yang Anda masukan Salah!!!\nSilahkan Memilih Pilihan yang Sudah ada\n=========================================\n");
            //goto masuk; dimana syntax ini akan membawa user kembali ke menu pemilihan metode masuk program untuk menginputkan pilihan yang benar, ini akan terus berulang hingga user menginputkan pilihan yang benar sesaui apa yang sudah ditampilkan pada menu pilihan.
            goto masuk;
            break;
        }
    system ("clear");
}

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
	printf ("Ketik nama anda :\n");
    scanf  ("%s", u1.nama);//menyimpan nilai input dengan akses member nama dengan variabel u1
	//Instruksi dari input nomor telepon
	printf ("Ketik nomor telepon anda: \n");
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

//=======================================================================//
//************   Fungsi Untuk Meminta Email & Password   ****************//
//=======================================================================//
// Nama Fungsi    : email_pw                                             //
// Input Argumen  : int email & char password                            //
// Output Argumen : -                                                    //
// Deskripsi      : Memasukkan email dan password yang diminta.          //
//                  dimana nanti password yang di buat pertama kali      //
//                  akan di simpan dan di gunakan kembali saat melakukan //
//                  konfirmasi user .                                    //
// Versi : 1.0                                      Rev. 0               //
// Tgl   : 03-12-2020                               Tgl: 03-12-2020      //
// I Gede Himawan - 2005551108                                           //
// Kelas A                                                               //
//=======================================================================//
void email_pw(){
        printf ("Buat Email Anda           :");
        scanf  ("%s",&email [50]);
        printf ("Buat Password untuk login :");
        scanf  ("%d",&password);
        system ("clear");
}

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
void record(struct User u1, char file[] ){
    //Mendeklarasikan tipe data file dengan pointer *rc yang bertujuan untuk pointer pada file "Record.dat"
    FILE *rc;
    //Assign rc untuk membuka file binary Record.dat dan menggunakan mode "rb" untuk membuka non-text file
    rc = fopen(file, "rb");
    //Menggunakan fungsi fread untuk membaca isi dari file "Record.dat"
    fread (&u1, sizeof(u1), 1, rc);
    //Menggunakan fungsi fclose untuk menutup file "Record.dat" agar tidak diproses lagi
    fclose (rc);

    //Menampilkan hasil dari Record nama user dan nomor telepon yang diinput oleh user
    printf("Nama\tNomor Telepon\n\n");
    printf("%s\t",u1.nama);
    printf("%s\t\n\n",u1.no_telp);
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
//**              Fungsi Untuk Memilih Menu Wishlist                  ***//
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
        scanf  ("%d",&pilihanMenu);

        switch (pilihanMenu){
        case 1:
            daftarwishlist();
            break;
        case 2:
            printf ("Terima kasih\n");
            break;
        default:;
            printf ("Perhatikan angka yang anda inputkan!\n");
            goto akhir;
            break;
    }
    system ("clear");
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
        printf ("Deskripsi :");
        scanf("%[^\n]%*c", namaTarget);
        printf ("Kisaran Harga :");
        scanf  ("%d",&hargaBarangDiinginkan);
}

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
        printf ("Dalam Manajemen Keungangan Anda harus diperlukan Dana Darurat\n");
        printf ("Mengapa ?\nKarena agar finansial bisa siap dalam keadaan darurat,\n");
        printf ("Untuk itu maka diperlukan Dana Darurat yang disarankan yaitu\n30 persen dari saldo yang dimilki\n");
        printf ("Jadi Dana Darurat yang harus ditabung untuk saat ini adalah: %d\n", dana);
    //untuk mengubah nilai saldo jika user memilih fungsi DanaDarurat yang akan menjadi saldo = saldo - dana
    saldo = saldo - dana ;
    return dana;
}

//Deklarasi struct account untuk membuat member akunBank, akunCreditCard, cash

//=======================================================================//
//***********      Fungsi Untuk Menginput Data Saldo     ****************//
//=======================================================================//
// Nama Fungsi    : saldo                                                //
// Passing Argumen: charx[]                                              //
// Input Argumen  : a1.akunBank, a1.akunCreditCard, a1.cash              //
// Output Argumen : int saldoDimiliki                                    //
// Deskripsi      : untuk menginput dan menyimpan nilai saldo pada masing//
//                  -masing akun keuangan.                               //
// Versi : 1.0                                      Rev. 0               //
// Tgl: 28-11-2020                                  Tgl: 28-1-2020       //
// Gede Rico Wijaya - 2005551091                                         //
// Kelas A                                                               //
//=======================================================================//
int inputSaldo(char x[]){

        //Instruksi untuk menginput nilai saldo
        printf ("NOTE : Jika tidak memiki Saldo pada Akun dibawah ini Ketik 0\n");
        printf ("Ketik Saldo Pada Akun Bank: ");
        scanf  ("%d", &a1.akunBank);
        printf ("Ketik Saldo Pada Akun Credit Card: ");
        scanf  ("%d", &a1.akunCreditCard);
        printf ("Ketik Saldo Pada Akun Tabungan Cash: ");
        scanf  ("%d", &a1.cash);
        
    //Deklarasi Variabel untuk menjumlahkan nilai accout
        saldoDimiliki = a1.akunBank + a1.akunCreditCard + a1.cash;
        printf ("Total Saldo yang dimiliki %d\n", saldoDimiliki);

    //Deklarasi Tipe Data File dengan pointer *us
    FILE *us; //pointerReport pada trackRecord
    //Membuka file Record.dat untuk dibuka dengan mode ab untuk menambahkan nilai saldo-saldo yang diinput
    us = fopen (x, "ab");
    //Menuliskan hasil input data kepada "Record.dat"
    fwrite (&a1, sizeof(a1), 1, us);
    //Menggunakan fungsi fclose untuk menutup file "Record.dat" agar tidak diproses lagi
    fclose (us);

    //untuk menghilangkan perintah-perintah dari layar terminal
    system ("clear");
    return saldoDimiliki;
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
    printf("Tanggal anda saat ini %i/%i/%i\n\n", waktu -> tm_mday, waktu -> tm_mon + 1, waktu -> tm_year + 1900);
}

//=======================================================================//
//***********   Fungsi Untuk Menampilkan Pilihan transaksi  *************//
//=======================================================================//
// Nama Fungsi    : metode_pembayaran                                    //
// Input Argumen  : int metode, md.bank , md.creditCard, dan md.cash     //
// Output Argumen : -                                                    //
// Deskripsi      : Program akan menampilkan pilihan metode pembayaran   //
//                  dan meminta user untuk memilih metode yang digunakan //
//                  untuk pengeluaran. Setelah itu, user diminta untuk   //
//                  menginputkan harga barang yang dijadikan sebagai     //
//                  perhitungan saldo yang dimiliki saat ini. Nantinya   //
//                  saldo tersebut akan ditampilkan pada fungsi cek saldo//
//                                                                       //
// Versi : 1.1                                      Rev. 1               //
// Tgl   : 03-12-2020                               Tgl: 15-12-2020      //
// Revisi: Menambahkan syntax untuk menghitung jumlah saldo terbaru pada //
//        setiap metode yang di gunakan seperti bank, credit card & cash.//
// I GEDE HIMAWAN - 2005551108                                           //
// Luh Putu Monica Arysta Putri Suastawan - 2005551090                   //
// Kelas A                                                               //
//=======================================================================//

bayar metode_pembayaran (bayar md){
            printf ("Kategori Pengeluaran\n");
            printf ("1. Akun bank\n2. Akun credit card\n3. Cash\n");
            printf ("Masukkan Metode Pembayaran :");
            scanf  ("%d",&metode);
            switch (metode){
        case 1:
            printf ("Akun Bank\n");
            printf ("Masukkan harga barang :");
            scanf  ("%d",&md.bank);
            int tb = *bank - md.bank;
            *bank  = tb;
            total  = *saldo - md.bank;
            *saldo = total;
            break;
        case 2:
            printf ("Akun credit card\n");
            printf ("Masukkan harga barang :");
            scanf  ("%d",&md.creditCard);
            int tk = *bank - md.creditCard;
            *kredit  = tk;
            total  = *saldo - md.creditCard;
            *saldo = total;
            break;
        case 3:
            printf ("Cash\n");
            printf ("Masukkan harga barang :");
            scanf  ("%d",&md.cash);
            int tc = *cash - md.cash;
            *cash  = tc;
            total  = *saldo - md.cash;
            *saldo = total;
            break;

        //Jika user menginput pilihan yang salah, atau menginput nilai yang tidak ada pada tampilan menu maka program akan mengesekusi pada bagian default seperti di bawah ini:
        default:
            printf   ("Pilihan yang Anda masukan Salah!!!\n");
            printf   ("Silahkan Memilih Pilihan yang Sudah ada\n");
            printf   ("=========================================");
            break;
            system ("clear");
        }
    return md;
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
// Versi : 1.1                                      Rev. 1               //
// Tgl   : 03-12-2020                               Tgl: 03-12-2020      //
// Revisi: Menambahkan pemanggilan fungsi waktu untuk menginfokan waktu  //
//        Saat user mengakses program.                                    //
// I Gede Himawan - 2005551108                                           //
// Kelas A                                                               //
//=======================================================================//


int transaksi (){
    bayar md;
            printf ("Kategori Pengeluaran\n");
            printf ("1. Makanan\n2. Transportasi\n3. Fashion\n4. Rumah Tangga\n5. Pendidikan\n6. Lainnya..\nMasukan Pilihan Anda :");
            scanf  ("%d",&milih);
            switch (milih){

        //pada case 1 dari menu switch(kategori), memiliki syntax switch case lagi di dalamnya, dimana disini berfungsi untuk meneksekusi inputan dari pilihan yang dimasukkan oleh user pada pilihan kategori transaksi sebelumnya.
        //dalam case 1 ini mengeksekusi perintah jika user memilih kategori makanan pada pemilihan kategori transaksi, dimana disini user akan diminta untuk memasukkan harga dan detail tambahan untuk transaksi yang sudah di lakukan oleh user.
        case 1:
            printf ("Makanan....\n");
            metode_pembayaran (md);
            waktu();
            break;

        //dalam case 2 ini mengeksekusi perintah jika user memilih kategori Transportasi pada pemilihan kategori transaksi, dimana disini user akan diminta untuk memasukkan harga dan detail tambahan untuk transaksi yang sudah di lakukan oleh user.
        case 2:
            printf ("Transportasi....\n");
            metode_pembayaran (md);
            waktu();
            break;

        //dalam case 3 ini mengeksekusi perintah jika user memilih kategori Fashion pada pemilihan kategori transaksi, dimana disini user akan diminta untuk memasukkan harga dan detail tambahan untuk transaksi yang sudah di lakukan oleh user.
        case 3:
            printf ("Fashion....\n");
            metode_pembayaran (md);
            waktu();
            break;

        //dalam case 4 ini mengeksekusi perintah jika user memilih kategori Rumah Tangga pada pemilihan kategori transaksi, dimana disini user akan diminta untuk memasukkan harga dan detail tambahan untuk transaksi yang sudah di lakukan oleh user.
        case 4:
            printf ("Rumah Tangga....\n");
            metode_pembayaran (md);
            waktu();
            break;

        //dalam case 5 ini mengeksekusi perintah jika user memilih kategori Pendidikan pada pemilihan kategori transaksi, dimana disini user akan diminta untuk memasukkan harga dan detail tambahan untuk transaksi yang sudah di lakukan oleh user.
        case 5:
            printf ("Pendidikan....\n");
            metode_pembayaran (md);
            waktu();
            break;

        //dalam case 6 ini mengeksekusi perintah jika user memilih kategori Lainnya pada pemilihan kategori transaksi, dimana disini user akan diminta untuk memasukkan harga dan detail tambahan untuk transaksi yang sudah di lakukan oleh user.
        case 6:
            printf ("Lainnya....\n");
            metode_pembayaran (md);
            waktu();
            break;

        //Jika user menginput pilihan yang salah, atau menginput nilai yang tidak ada pada tampilan menu maka program akan mengesekusi pada bagian default seperti di bawah ini:
        default:
            printf   ("Pilihan yang Anda masukan Salah!!!\n");
            printf   ("Silahkan Memilih Pilihan yang Sudah ada\n");
            printf   ("=========================================");
            break;
            system ("clear");
        }
    total  = *saldo - harga;
    *saldo = total;

    return total;
}
