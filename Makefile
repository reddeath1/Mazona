build:
	gcc -Wall -Werror -Wextra -pedantic ./src/*.c -o mazona -lm -ldl `sdl2-config --cflags` `sdl2-config --libs`;

run:
	./mazona;

clean:
	rm mazona;

Installation of the necessary software for me to start working on game development can be challenging. SDL2 on Windows is a daunting task to install, as almost all online solutions seem to not be working. I've tried installing Cygwin64, which comes with the GCC C compiler, and then setting up SDL2 with MinGW, but all attempts have failed, resulting in an error: