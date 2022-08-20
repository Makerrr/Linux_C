mysqlist:main.o sqlist.o
	gcc main.o sqlist.o -o mysqlist
main.o:main.c
	gcc main.c -c -Wall -g -o main.o
sqlist.o:sqlist.c
	gcc sqlist.c -c -Wall -g -o sqlist.o
clean:
	rm *.o -rf mysqlist
	
