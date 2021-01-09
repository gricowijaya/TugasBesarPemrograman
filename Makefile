#untuk mengcompile file main.c dengan mengetik "make" pada terminal lalu ./a.out
all :
	gcc main.c -o ./a.out

#untuk menghapus file a.out dengan mengetik "make clear" pada terminal
clear: 
	rm -rf *o ./a.out
