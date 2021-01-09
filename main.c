//Header yang di gunakan untuk standar input output pada bahasa C
#include <stdlib.h>
#include "menu.c"
#include "loginSystem.c"
#include "pemasukan.c"
#include "transaksi.c"
#include "wishList.c"
#include "displayHistory.c"
#include "danaDarurat.c"

// fungsi main () adalah kepala dari program ini, dimana program akan di eksekusi oleh fungsi main ini.
int main (){
    system ("color 30");
    header();
    system ("clear");
    menu_masuk();
    //pemanggilan fungsi untuk menu program
    menu_program();
}
