
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

clear:
	rm -f -r $(OBJ)

clean:
	rm -f output
	rm -f -r bin

test:
	./bin/osh < input > output