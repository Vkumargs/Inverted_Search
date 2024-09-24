OBJ:= $(patsubst %.c, %.o, $(wildcard *.c))
WDS.exe: $(OBJ)
	gcc -o $@ $^  
clean:
	rm *.o