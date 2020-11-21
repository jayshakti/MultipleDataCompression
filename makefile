#! /bin/bash
mdc:main.o operations.o compression.o decompression.o openfile.o codelength.o create_masterarray.o unique_char.o insert_char.o preserve_ma.o findloc.o compress.o compress2.o compress3.o compress4.o compress5.o compress6.o compress7.o decompress.o decompress4.o decompress2.o decompress3.o decompress5.o decompress6.o decompress7.o
	gcc -o mdc main.o operations.o compression.o decompression.o openfile.o codelength.o create_masterarray.o unique_char.o insert_char.o preserve_ma.o findloc.o compress.o compress2.o compress3.o compress4.o compress5.o compress6.o compress7.o decompress.o decompress4.o decompress2.o decompress3.o decompress5.o decompress6.o decompress7.o

main.o:main.c headers.h prototypes.h
	gcc -c main.c
operations.o:operations.c headers.h prototypes.h
	gcc -c operations.c
compression.o:compression.c headers.h prototypes.h
	gcc -c compression.c
decompression.o:decompression.c headers.h prototypes.h
	gcc -c decompression.c
openfile.o:openfile.c headers.h prototypes.h
	gcc -c openfile.c
codelength.o:codelength.c headers.h prototypes.h
	gcc -c codelength.c
create_masterarray.o:create_masterarray.c headers.h prototypes.h
	gcc -c create_masterarray.c
unique_char.o:unique_char.c headers.h prototypes.h
	gcc -c unique_char.c
insert_char.o:insert_char.c headers.h prototypes.h
	gcc -c insert_char.c
preserve_ma.o:preserve_ma.c headers.h prototypes.h
	gcc -c preserve_ma.c
findloc.o:findloc.c headers.h prototypes.h
	gcc -c findloc.c
compress.o:compress.c headers.h prototypes.h
	gcc -c compress.c
decompress.o:decompress.c headers.h prototypes.h
	gcc -c decompress.c
compress2.o:compress2.c headers.h prototypes.h
	gcc -c compress2.c
compress3.o:compress3.c headers.h prototypes.h
	gcc -c compress3.c
compress4.o:compress4.c headers.h prototypes.h
	gcc -c compress4.c
compress5.o:compress5.c headers.h prototypes.h
	gcc -c compress5.c
compress6.o:compress6.c headers.h prototypes.h
	gcc -c compress6.c
compress7.o:compress7.c headers.h prototypes.h
	gcc -c compress7.c
decompress2.o:decompress2.c headers.h prototypes.h
	gcc -c decompress2.c
decompress3.o:decompress3.c headers.h prototypes.h
	gcc -c decompress3.c
decompress4.o:decompress4.c headers.h prototypes.h
	gcc -c decompress4.c
decompress5.o:decompress5.c headers.h prototypes.h
	gcc -c decompress5.c
decompress6.o:decompress6.c headers.h prototypes.h
	gcc -c decompress6.c
decompress7.o:decompress7.c headers.h prototypes.h
	gcc -c decompress7.c



