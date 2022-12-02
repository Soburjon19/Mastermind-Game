# Welcome to My Mastermind
Welcome to My project Mastermind

## tasks
For each exercise, you will have to create a folder and in this folder, you will have additional files that contain your work. 
Folder names are provided at the beginning of each exercise under submit directory and specific file names for each 
exercise are also provided at the beginning of each exercise under submit file.

## Description
When writing the My Mastermind program, I used the following things.
Modular programming. The program is divided into three parts: 
 my_function.c - the main module, which describes the game itself 
directly without unnecessary logic, which relates to the implementation of the game itself.
headers.h - all necessary libraries are given in this file 
and my_mastermind.c file is linked with #include "headers.h".

How is this game played...

For run the code, first type 
```
make
```
in the terminal. The code in the make file opens a file named "my_mastermind" to play the game.
Then start the game 
```
./my_mastermind
```
via U file

The game gives you 4 secret numbers from "0" to "7". you will need to find that secret number
(if you want, you can enter the secret number yourself. For this, we refer to the -c command "./my_mastermind -c 1234".)

in each round it compares the numbers you entered with a secret code, and gives you hints (for example: Well placed pieces: 2Misplaced pieces: 1) 
you can find 4 numbers that are hidden logically through these clues.

the game has 10 rounds, but you can change this with the "-t" command (./my_mastermind -t 5).

if you find 4 hidden numbers, "WOWZA! You guessed it!" appears in the terminal and the game ends.



## Installation
no Installation only need write in terminal "make"

## Usage
this like game this find secret characters it works like this
```
./my_mastermind.c
```

