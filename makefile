dircompile: dir.c
	gcc dir.c
run: dircompile
	./a.out
