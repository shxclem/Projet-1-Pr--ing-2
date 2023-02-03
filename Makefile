comp:
	gcc -o main *.c -I ./

all: comp
  
clean:
	rm prog
