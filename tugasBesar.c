//contoh dari username.c
#include <stdio.h>
#include <stdlib.h>


struct User{
	char nama[20];	
	char no_telp [12];
};

struct User u1;

struct account{
    int akunBank;
    int akunCreditCard;
    int akunKartu;
}a1;

struct account a1;

void hallo();
void username(struct User u, char file[]);
int saldo(char x[]);
int DanaDarurat (int saldo);
void record(struct User u, char file[] );

char fileRecord[]={"Record.dat"};

int main(){

    //Deklarasi variable 
    //Variabel SaldoYangDimiliki untuk menyimpan total dari saldo yang dimiliki oleh 
    //Variable pil untuk menyimpan nilai dari pilihan pada menu yang akan dipakai oleh user
    int SaldoYangDimiliki ;
    int pil;
    
        hallo();
        username(u1,fileRecord);

            while (1){
                printf ("MENU:\n1. Input Saldo\n2. Dana Darurat\n3. Record\n4. Keluar Program\n");
                printf ("Pilihan Anda:");
                scanf  ("%d", &pil);
                    switch (pil){
                    case 1:
                        SaldoYangDimiliki = saldo(fileRecord);
                        break;
                    case 2:
                        DanaDarurat(SaldoYangDimiliki);
                        break;
                    case 3: 
                        record(u1, fileRecord);
                        break;
                    case 4: 
                        return 0;
                    default:
                        printf ("Silahkan Ketik Angka Antara 1-4.\n");
                        break;
                    }   
            }
    return 0;   
}

void hallo(){
    printf ("Hello !\n");
    printf ("Selamat Datang\n");
}

void username(struct User u, char file[]){
	printf ("Ketik nama anda :");
	scanf  ("%s", u1.nama);
	printf ("Ketik nomor telepon anda: ");
	scanf  ("%s", u1.no_telp);

	FILE *rc; //pointerReport pada trackRecord
    rc = fopen (file, "ab");
    fprintf (rc, "%s\t%s\t", u1.nama, u1.no_telp);
    fwrite (&u1, sizeof(u1), 1, rc);
	fclose (rc);
    system ("clear");
}

int saldo(char x[]){

        printf ("NOTE : Jika tidak memiki Saldo pada Akun dibawah ini Ketik 0\n");
        printf ("Ketik Saldo Pada Akun Bank: ");
        scanf  ("%d", &a1.akunBank);
        printf ("Ketik Saldo Pada Akun Credit Card: ");
        scanf  ("%d", &a1.akunCreditCard);
        printf ("Ketik Saldo Pada Akun Tabungan Cash: ");
        scanf  ("%d", &a1.akunKartu);
    
    // Deklarasi Variabel untuk menjumlahkan nilai accout
    int saldoDimiliki = a1.akunBank + a1.akunBank + a1.akunKartu;   
        printf ("Total Saldo yang dimiliki %d\n", saldoDimiliki);

    FILE *us; //pointerReport pada trackRecord
    us = fopen (x, "ab");
    fwrite (&a1, sizeof(a1), 1, us);
    fclose (us);
    system ("clear");
    return saldoDimiliki;
}   

int DanaDarurat (int saldo){
    int dana = saldo * 0.3;
        printf ("Maka Dana yang harus dipersiapkan adalah: %d\n", dana);
    saldo = dana;
    return saldo;
}

void record(struct User u, char file[] ){
    FILE *rc;
    rc = fopen(file, "rb");
    fread (&u, sizeof(u), 1, rc);
    fclose (rc);

    printf("%s\t",u.nama);
    printf("%s\t\n\n",u.no_telp);
}
