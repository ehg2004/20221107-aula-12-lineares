all:
	gcc -o counting-sort-int counting-sort-int.c utils.c 
	gcc -o counting-sort-char counting-sort-char.c utils.c 
	gcc -o process-interval process-interval.c utils.c 
	gcc -o radix-sort-int radix-sort-int.c utils.c 
clean:
	-del *.exe
