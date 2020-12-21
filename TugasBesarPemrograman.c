//Header yang di gunakan untuk standar input output pada bahasa C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Note : Pada beberapa compiler kode system ("clear") dapat dituliskan system ("cls");

// Dekalarasi variable global yang di gunakan pada program manjemen keuangan ini:
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

// Struct User untuk menyimpan member nama, username, password 
typedef struct {
    char nama[50];
    char username[12];
    char password[10];
    char email[50];
}User;

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

//Mendeklarasikan variabel u pada struct User
User u;

//Mendeklarasikan variabel a1 pada account
struct account a1;

//Deklarasi fungsi-fungsi yang digunkan pada program manajemen keuangan'
int pemasukan ();                                    /* Merupakan fungsi yang digunakan untuk menampilkan dan menyimpan semua kategori, 
                                                        dan inputan pemasukan saldo user. */

int transaksi ();                                    /* Merupakan fungsi yang digunakan untuk menampilkan dan menyimpan semua kategori,
                                                        dan inputan transaksi(pengeluaran) user. */

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

// assign namaFile (nF) agar menyimpan string "logRecord.txt"
char namaFile[] = "logRecord.txt";

//Assign pointer *saldo kepada alamat variabel dari saldoDimiliki
int *saldo = &saldoDimiliki;
int *bank   = & a1.akunBank;
int *kredit = & a1.akunCreditCard;
int *cash   = & a1.cash;

// fungsi main () adalah kepala dari program ini, dimana program akan di eksekusi oleh fungsi main ini.
int main (){
    system ("clear");
    menu_masuk();
    //pemanggilan fungsi untuk menu program
    menu_program();
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

    //Memanggil fungsi inputSaldo
    inputSaldo(namaFile);

    //Mendeklarasikan label ktgri untuk menampilkan kategori menu yang ingin dipilih
    ktgri:
    //pada bagian looping ini , disini berfungsi untuk menjalankan proses dari program manjemen keungan ini, dimana setiap dilakukan proses transaksi atau cek saldo maka yang akan di proses dan di tampilkan adalah saldo terbaru yang merupakan hasil dari proses sebelumnya yang di lakukan oleh user seperti proses transaksi yang dapat merubah banya saldo, sehingga program dapat di jalankan sesuai ekspetasi yang di inginkan oleh penulis programnya
    for(i=0; i<1; i++){
        printf ("pilihan : \n1. Transaksi\n2. Pemasukan\n3. Cek Saldo\n4. Dana Darurat\n5. Log Record\n6. Wishlist\n7. EXIT\nMasukan Pilihan Anda:");
        scanf  ("%d",&kategori);
        system ("clear");
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
                record(u, namaFile);
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
        scanf  (" %[^\n]",&Det_Masukan);
        system ("clear");
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
        system ("clear");
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
// Versi : 1.1                                      Rev. 1               //
// Tgl   : 03-12-2020                               Tgl: 19-12-2020      //
// I Gede Himawan - 2005551108                                           //
// Gede Rico Wijaya - 2005551091                                         //
// Revisi : Menambahkan Menu EXIT                                        //
// Kelas A                                                               //
//=======================================================================//
void menu_program(){
    pilih:
        puts   ("\nMenu Program");
        puts   ("============");
        puts   ("1. MENU");
        puts   ("2. EXIT");
        printf ("Masukan Pilihan Anda :");
        scanf  ("%d",&pilihanmenu);
        system ("clear");

    // pada switch case bagian ini , disini akan memproses dari inputan yang sudah dimasukkan oleh user pada proses pemiihan pemilihan menu sebelumnya dan mengantarkan program pada fungsi yang merupakan panggilan dari pilihan yang di inputkan oleh user.
    switch (pilihanmenu)
    {
        //pada case 1 ini, program akan memanggil fungsi yang sudah dibuat yaitu fungsi yang bernama void menu();
        case 1:
            menu ();
            break;
        case 2:
            system (EXIT_SUCCESS);
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
    printf ("1. Masuk\n2. Registrasi\n3. EXIT\n");
    printf ("Pilihan => ");
    scanf  ("%d", &pilihan);
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
    printf ("LOGIN\n");
    printf ("Username: ");
    scanf  ("%s", username);
    printf ("Password: ");
    scanf  ("%s", password);    
    system ("clear");
    // Membeaca file "logRecord.txt"
    while(fread(&u,sizeof(u),1,record)){
        /*  Mengkomparasi username serta password yang diinput pengguna kedalam fungsi 
            masuk() dengan username serta password yang sudah terdaftar */
        if(strcmp(username, u.username)==0 && strcmp(password, u.password)==0){   
            printf("\nLogin Berhasil!\n");
        } 
        //  Jika akun tidak terdaftar maka akan diberikan pilihan untuk mendaftar atau keluar dari program
        else {
            printf("\nAkun tidak terdaftar!\n");
            instruksi:
            printf("Ketik 1 untuk daftar\nKetik 2 untuk masuk ulang\nKetik 3 untuk EXIT\n");
            printf("Pilihan: ");
            scanf ("%d", &pilihan);
            system ("cls");
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
                printf ("ERROR");
                goto instruksi;
            }
        }   
    }
    fclose(record);
    return;
}

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
    printf("\nSilahkan registrasi akun anda!\n\n");
    printf("Nama Panggilan: ");
    scanf ("%s", u.nama);
    printf("Email anda: ");
    scanf ("%s", u.email);
    printf("\nHallo %s!\nSilahkan membuat username (max 12 karakter)\nSerta membuat password (max 10 karakter)\n", u.nama);
    
    // Instruksi untuk menginput username serta password
    printf("\nEnter Username:");
    scanf ("%s", u.username);
    printf("\nEnter Password:");
    scanf ("%s", u.password);
 
    // Menuliskan nama yang diinput oleh pengguna kedalam file "logRecord.txt"
    fwrite(&u,sizeof(u),1,regis);
    fclose(regis);
    printf("\nRegistrasi Selesai!\nAkun anda terdaftar, silahkan mencoba !");
    getchar();
    
    // Membersikan layar terminal
    system ("cls");
    // Memanggil fungsi masuk()
    masuk();
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
    //Mendeklarasikan tipe data file dengan pointer *rc yang bertujuan untuk pointer pada file "logRecord.txt"
    FILE *rc;
    //Assign rc untuk membuka file binary Record.dat dan menggunakan mode "r" untuk membaca textfile
    rc = fopen(file, "r");
    //Menggunakan fungsi fread untuk membaca isi dari file "logRecord.txt"
    fread (&u, sizeof(u), 1, rc);
    //Menggunakan fungsi fclose untuk menutup file "logRecord.txt" agar tidak diproses lagi
    fclose (rc);

    //Menampilkan hasil dari Record nama user dan nomor telepon yang diinput oleh user
    printf("Nama\tUsername\tTanggal\n");
    printf("%s\t%s\t-\n",u.nama, u.username);
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
        system ("clear");
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
    system ("clear");
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
        scanf  ("%[^\n]%*c", namaTarget);
        printf ("Kisaran Harga :");
        scanf  ("%d",&hargaBarangDiinginkan);
        system ("clear");
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
        //Pada bagian ini user diminta untuk memasukkan jumlah saldo yang di miliki sebagai starter dalam program manajemen keuangan ini
        printf   ("Masukan Saldo\n");
        //Instruksi untuk menginput nilai saldo
        printf ("#NOTE : Jika tidak memiki Saldo pada Akun dibawah ini Ketik 0\n\n\n");
        printf ("Ketik Saldo Pada Akun Bank         : ");
        scanf  ("%d", &a1.akunBank);
        printf ("Ketik Saldo Pada Akun Credit Card  : ");
        scanf  ("%d", &a1.akunCreditCard);
        printf ("Ketik Saldo Pada Akun Tabungan Cash: ");
        scanf  ("%d", &a1.cash);
        
    //Deklarasi Variabel untuk menjumlahkan nilai accout
        saldoDimiliki = a1.akunBank + a1.akunCreditCard + a1.cash;
        printf ("Total Saldo yang dimiliki %d\n", saldoDimiliki);

    //Deklarasi Tipe Data File dengan pointer *us
    FILE *us; //pointerReport pada trackRecord
    //Membuka file Record.dat untuk dibuka dengan mode ab untuk menambahkan nilai saldo-saldo yang diinput
    us = fopen (x, "a");
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
    printf("Tanggal: %i/%i/%i\n\n", waktu -> tm_mday, waktu -> tm_mon + 1, waktu -> tm_year + 1900);
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
// Versi : 1.2                                      Rev. 2               //
// Tgl   : 03-12-2020                               Tgl: 21-12-2020      //
// Revisi: 1. Menambahkan syntax untuk menghitung jumlah saldo terbaru   //
//        pada setiap metode yang di gunakan seperti bank, credit card & //
//        cash.                                                          //
//         2. Melakukan perubahan dan penambahan syntax pada fungsi      //
//        metode_pembayaran dimana user tidak bisa melakukan transaksi   //
//        pada akun tertentu jika saldo yang dimiliki lebih kecil dari   //
//        jumlah harga transaksi yang dilakukan. oleh karena tujuan dari //
//        syntax untuk mejaga saldo pada setiap akun tidak dapat kurang  //
//        dari 0 atau minus.                                             //
// I GEDE HIMAWAN - 2005551108                                           //
// Luh Putu Monica Arysta Putri Suastawan - 2005551090                   //
// Kelas A                                                               //
//=======================================================================//
bayar metode_pembayaran (bayar md){
    metode:
            printf ("Kategori Pengeluaran\n");
            printf ("1. Akun bank\n2. Akun credit card\n3. Cash\n");
            printf ("Masukkan Metode Pembayaran :");
            scanf  ("%d",&metode);
            switch (metode){
        case 1:
            printf ("Akun Bank\n");
            printf ("Masukkan harga barang :");
            scanf  ("%d",&md.bank);
            if (*bank < md.bank){
                printf ("Saldo yang anda miliki pada akun Bank kurang dari jumlah transaksi\n");
                printf ("Silahkan coba dengan metode pembayaran lain\n");
                goto metode;
            }
            else{
            int tb = *bank - md.bank;
            *bank  = tb;    
            total  = *saldo - md.bank;
            *saldo = total;
            }
            
            break;
        case 2:
            printf ("Akun credit card\n");
            printf ("Masukkan harga barang :");
            scanf  ("%d",&md.creditCard);
            if (*kredit < md.creditCard){
                printf ("Saldo yang anda miliki pada akun kredit kurang dari jumlah transaksi\n");
                printf ("Silahkan coba dengan metode pembayaran lain\n");
                goto metode;
            }
            else{
            int tc   = *kredit - md.creditCard;
            *kredit  = tc;    
            total  = *saldo - md.bank;
            *saldo = total;
            }
            break;
        case 3:
            printf ("Cash\n");
            printf ("Masukkan harga barang :");
            scanf  ("%d",&md.cash);
            if (*kredit < md.creditCard){
                printf ("Saldo cash yang anda miliki kurang dari jumlah transaksi\n");
                printf ("Silahkan coba dengan metode pembayaran lain\n");
                goto metode;
            }
            else{
            int tc = *cash - md.cash;
            *cash  = tc;
            total  = *saldo - md.bank;
            *saldo = total;
            }
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
            system ("clear");
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
        }
    total  = *saldo - harga;
    *saldo = total;
    system ("clear");
    return total;   
}
