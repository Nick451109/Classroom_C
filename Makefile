all: tareaOpciones tareaSinOpciones metodos.s regDatos.s regDatosOpciones.s estructuras.s

tareaOpciones: regDatosOpciones.o
	gcc -o tareaOpciones regDatosOpciones.o

tareaSinOpciones: regDatos.o
	gcc -o tareaSinOpciones regDatos.o 

regDatosOpciones.o: regDatosOpciones.c
	gcc -c regDatosOpciones.c

regDatosOpciones.s: regDatosOpciones.o
	objdump -S regDatosOpciones.o > regDatosOpciones.s	


regDatos.o: regDatos.c
	gcc -c regDatos.c

regDatos.s: regDatos.o
	objdump -S regDatos.o > regDatos.s


estructuras.o: estructuras.c
	gcc -c estructuras.c

estructuras.s: estructuras.o
	objdump -S estructuras.o > estructuras.s

metodos.o: metodos.c
	gcc -c metodos.c

metodos.s: metodos.o
	objdump -S metodos.o > metodos.s

clean:
	rm *.exe *.o *.s