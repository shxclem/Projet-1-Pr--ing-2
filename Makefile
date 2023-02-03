comp:
  gcc -o prog *.c -I ./

all: comp
  ./projet_wa.sh
  
clean:
  rm prog
  
