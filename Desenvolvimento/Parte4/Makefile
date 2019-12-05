a.out:	avl.o
	@gcc -Wall -Wextra -Werror -Wpedantic main.c avl.o
	@rm -rf *.o
	@./a.out
	@rm -rf *.out

ArvoreBinaria.o:	avl.c
	gcc -Wall -Wextra -Werror -Wpedantic -c avl.c -o avl.o

clear:
	@rm -rf *.o
	@rm -rf a.out