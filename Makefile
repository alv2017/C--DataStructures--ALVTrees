build:
	gcc -Wall -std=c99 main.c menu/*.c src/*.c -o main
run:
	./main
debug:
	gcc -g -std=c99 main.c menu/*.c src/*.c
clean:
	rm main