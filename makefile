CC=tcc
output=sorth

sorth: sorth.c stack.c
	$(CC) sorth.c stack.c filehandler.c -o $(output)

clean:
	rm *.o
