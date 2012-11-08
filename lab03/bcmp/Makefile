all: testdiff bcmp

testdiff: testdiff.o diff.o 
bcmp: bcmp.o
	gcc -o $@ $^

testdiff.o: testdiff.c diff.h
diff.o: diff.c diff.h
bcmp.o: bcmp.c

clean:
	rm *.o
