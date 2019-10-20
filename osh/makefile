
CC = g++
CFLAG = -Wall
OBJ = obj/main.o obj/getInput.o obj/special.o obj/createPipe.o obj/redirect.o obj/execute.o

all: 
	$(shell mkdir -p bin)
	$(shell mkdir -p obj)
	$(MAKE) bin/osh

bin/osh: $(OBJ)
	$(CC) -o $@ $^

obj/%.o: code/%.cpp
	$(CC) $(CFLAG) -o $@ -c $< 

test:
	./bin/osh < input > output

clear:
	rm -f -r $(OBJ)
	rm -f output
	rm -f txt
	rm -f bin/history.txt

remove:
	rm -f -r bin
	rm -f -r obj
	rm -f output
	rm -f txt
	
