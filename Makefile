SRC = src/main.c
CFLAGS = -Wpedantic
CFLAGS += -g

program: $(SRC)
	gcc -o datura $(SRC) $(CFLAGS)

clean:
	rm -rf *.o datura
