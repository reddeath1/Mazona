# 🎮 Mazona
# Introduction
This repository houses the source code for an exciting maze game project. Embark on a journey through intricately designed mazes, overcome challenges, and reach the elusive exit. Whether you're a game development enthusiast, a programmer honing your skills, or simply someone who loves a good maze challenge, this project is for you!
# Installation

* using MAC install the following software.
```
brew install SDL2
brew install SDL2_image
brew install SDL2_ttf
```
* LINUX/UBUNTU
```
sudo apt install SDL2
sudo apt install SDL2_image
sudo apt install SDL2_ttf
```

* Windows
 Follow this link for installation details ```https://lazyfoo.net/tutorials/SDL/01_hello_SDL/windows/index.php```
* THEN
 ```git clone https://github.com/reddeath1/Mazona.git```
* 
# Usage
* Execute ```./mazona``` or type ```make run``` to open the game
* Use up and down arrow keys to move forward and back
* Use right and left arrow keys to turn the camera around
# Compilation
* Run ```make``` to compile with ```gcc -Wall -Werror -Wextra -pedantic ./src/*.c -o mazona -lm -ldl `sdl2-config --cflags` `sdl2-config --libs` ```.
# Authors
Frank Galos - [Linkedin](https://www.linkedin.com/in/frankgalos)    
