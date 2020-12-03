#include <stdio.h>

struct User{
	char nama[30];
	char no_telp[12];
}u1;

void record(struct User u, char file[] ){
    FILE *rc;
    rc = fopen(file, "rb");
    fread (&u1, sizeof(u1), 1, rc);
    fclose (rc);

    printf("Nama\t\tNomor Telepon\n\n");
    printf("%s\t",u1.nama);
    printf("%s\t\n\n",u1.no_telp);
}