PYLIB=/usr/lib/python3.5/config-3.5m-x86_64-linux-gnu/libpython3.5m.a
PYINC=-I-I/usr/include -I/usr/include -I/usr/include/python3.5m -I/usr/include/python3.5m 
LIBS=-L/usr/lib -lexpat -L/usr/lib -lz  -lexpat -lpthread -ldl  -lutil -lm -lallegro -lallegro_image
OPTS=-DNDEBUG -g -fwrapv -O2 -Wall -Wstrict-prototypes
PROGRAMS=emerl
all: $(PROGRAMS)

emerl:main.o
	gcc main.o $(LIBS) $(PYLIB) -o $(PROGRAMS)
	
main.o:main.c
	gcc -c main.c $(PYINC) $(OPTS)

clean:
	rm -f *.o *.pyc core
mrproper:
	rm -f $(PROGRAMS) *.o *.pyc core
