#include <stdio.h>
#include <stdlib.h>

struct User{
	char nama[30];
	char no_telp[12];
}u1;

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