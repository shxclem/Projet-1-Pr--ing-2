comp:
	gcc -o prog *.c -I ./

all: comp
  
clean:
	rm prog
