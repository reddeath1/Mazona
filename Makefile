build:
	gcc -Wall -Werror -Wextra -pedantic ./src/*.c -o mazona -lm -ldl `sdl2-config --cflags` `sdl2-config --libs`;

run:
	./mazona;

clean:
	rm mazona;