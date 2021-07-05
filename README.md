# Eltex
Статическая библиотека:
  gcc file1.c -c
  gcc file2.c -c
  ar rc libmyname.a file1.o file2.o
  gcc test.c -o test -L -lmyname
  ./test
Динамическая библиотека:
  gcc file1.c fPIC -c
  gcc file2.c fPIC -c
  gcc -shared file1.o file2.o -o libmyname.so
  gcc test.c -o test -L. -lmyname
  LD_LIBRARY_PATH=$PWD ./test
GCC - https://man7.org/linux/man-pages/man1/gcc.1.html
LD - https://www.opennet.ru/man.shtml?topic=ld.so&category=8&russian=0
Readelf - https://www.opennet.ru/man.shtml?topic=readelf&category=1&russian=1
Objdump - https://www.opennet.ru/man.shtml?topic=objdump&category=1&russian=1
