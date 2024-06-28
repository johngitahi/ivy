SRC = src/main.c
SRC += src/utils.c
CFLAGS = -Wpedantic
CFLAGS += -g

ivy: $(SRC)
	gcc -o build/ivy $(SRC) $(CFLAGS)

install: ivy
	sudo cp build/ivy /usr/local/bin
clean:
	rm -rf *.o ivy
