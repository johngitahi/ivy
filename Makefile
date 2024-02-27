SRC = src/main.c
SRC += src/reader.c
CFLAGS = -Wpedantic
CFLAGS += -g

datura: $(SRC)
	gcc -o datura $(SRC) $(CFLAGS)

install: datura
	sudo cp datura /usr/local/bin
clean:
	rm -rf *.o datura
