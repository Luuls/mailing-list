CC = gcc
CFLAGS = -g -Wall
OBJ = main.o linked_list.o

all: mail_list

mail_list: $(OBJ)
	$(CC) $(CFLAGS) -o mail_list $(OBJ)

main.o: main.c linked_list.h

linked_list.o: linked_list.c linked_list.h

clean: 
	rm mail_list $(OBJ)