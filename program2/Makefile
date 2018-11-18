CFLAGS = -Wall

output: program2.o course.o linked_list.o
	gcc program2.o course.o linked_list.o -o output
program2.o: program2.c program2.h
	gcc -c program2.c
course.o: course.c course.h
	gcc -c course.c
linked_list.o: linked_list.c linked_list.h
	gcc -c linked_list.c

clean:
	rm *.o output
