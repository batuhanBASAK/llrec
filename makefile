all: clear clean compile run

clean:
	@rm -rf driver driver.o llrec.o

clear:
	@clear

compile: llrec.o driver.o
	@gcc -o driver llrec.o driver.o --ansi

llrec.o: llrec.c
	@gcc -c llrec.c	--ansi

driver.o: driver.c
	@gcc -c driver.c --ansi

run:
	@./driver

