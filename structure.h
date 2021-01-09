//Header untuk Structure yang diperlukan pada program ini

#ifndef __STRUCTURE_H__
#define __STRUCTURE_H__
#include "variable.h"

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

typedef struct {
    char nama[50];
    char username[12];
    char password[10];
    char email[50];
}User;

//Mendeklarasikan variabel u pada struct User
User u;
//Mendeklarasikan variabel a1 pada account
struct account a1;
//Mendeklarasikan variabel a1 pada account

//Assign pointer *saldo kepada alamat variabel dari saldoDimiliki
int *bank   = & a1.akunBank;                        //pointer bank                    => berfungsi untuk menyimpan nilai sisa dari hasil setelah saldo bank di kurang atau dengan adanya proses transaksi secara berulang kali
int *kredit = & a1.akunCreditCard;                  //pointer akunCreditCard          => berfungsi untuk menyimpan nilai sisa dari hasil setelah saldo kredit di kurang atau dengan adanya proses transaksi secara berulang kali
int *cash   = & a1.cash;                            //pointer akun.cash               => berfungsi untuk menyimpan nilai sisa dari hasil setelah saldo cash di kurang atau dengan adanya proses transaksi secara berulang kali


#endif 