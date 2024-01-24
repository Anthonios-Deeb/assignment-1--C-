CC=gcc
AR=ar
OBJECTS_MAIN=main.o
OBJECTS_LIB_BASIC_LOOPS=advancedClassificationLoop.o basicClassification.o
OBJECTS_LIB_BASIC_REC=advancedClassificationRecursion.o basicClassification.o
CFLAGS= -Wall

all: loops recursives recursived loopd mains maindloop maindrec

loops: $(OBJECTS_MAIN) libclassloops.a #1
	$(CC) $(CFLAGS) $(OBJECTS_MAIN) -L. -lclassloops -o loops
recursives: $(OBJECTS_MAIN) libclassrec.a #2
	$(CC) $(CFLAGS) $(OBJECTS_MAIN) -L. -lclassrec -o recursives
	
recursived: $(OBJECTS_MAIN) libclassrec.so #3
	$(CC) $(CFLAGS) -fPIC $(OBJECTS_MAIN) -L. -lclassrec -o recursived
loopd: $(OBJECTS_LIBBASIC) libclassloops.so #4
	$(CC) $(CFLAGS) -fPIC $(OBJECTS_MAIN) -L. -lclassloops -o loopd
mains: main.o libclassrec.a
	$(CC) $(CFLAGS) main.o -L. -lclassrec -o mains
maindloop: main.o libclassloops.so
	$(CC) $(CFLAGS) main.o -L. -lclassloops -o maindloop
maindrec: main.o libclassrec.so
	$(CC) $(CFLAGS) main.o -L. -lclassrec -o maindrec

libclassrec.so: $(OBJECTS_LIB_BASIC_REC)
	$(CC) -shared -o libclassrec.so $(OBJECTS_LIB_BASIC_REC)
libclassloops.so: $(OBJECTS_LIB_BASIC_LOOPS)
	$(CC) -shared -o libclassloops.so $(OBJECTS_LIB_BASIC_LOOPS)
libclassloops.a: $(OBJECTS_LIB_BASIC_LOOPS)
	$(AR) rcu libclassloops.a $(OBJECTS_LIB_BASIC_LOOPS)	
libclassrec.a: $(OBJECTS_LIB_BASIC_REC)
	$(AR) rcu libclassrec.a $(OBJECTS_LIB_BASIC_REC)	

advancedClassificationLoop.o: advancedClassificationLoop.c NumClass.h
	$(CC) -c advancedClassificationLoop.c	

advancedClassificationRecursion.o: advancedClassificationRecursion.c NumClass.h
	$(CC) -c advancedClassificationRecursion.c

basicClassification.o: basicClassification.c NumClass.h
	$(CC) -c basicClassification.c

main.o: main.c NumClass.h  
	$(CC) -c main.c 

.PHONY: clean all

clean:
	rm -f *.o *.a *.so loops loopd recursives recursived mains maindloop maindrec