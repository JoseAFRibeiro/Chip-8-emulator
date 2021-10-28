# José Ribeiro's Chip-8 emulator
*A simple Chip 8 emulator written in C as a way to learn more about emulation*
## The emulator
The emulator hosted in this repository is a Chip-8 intrepreter built in C with 3 objectives:
1. Portability: my objective is to get the emulator running on windows first and then port it to the Sega Dreamcast
2. Speed: I want to make this interpreter as fast as I can possibly make it
3. Readability: Ideally, anyone with just the basic knowledge of C would be able to look at the source code and use it as study material to learn more about C
## Note for VSCode users
In your launch.json file make sure to change "cwd" variable to your current workspace folder

## Building the emulator 
The compiler used during development was GCC, so I can't gurantee other compilers will work without complaining.
`gcc *.c` will be enough to compile the program, `gcc -D DEBUG *.c` will enable debug feature that are inlcuded in the program. Note that, right  now, the program is hard coded to try to load a certain ROM file, you can change this by altering the source code and editing the path to the ROM file or you can fimd the ROM I'm usin gon this Github page https://github.com/kripod/chip8-roms 

## Last but not least
This project is not mean to become a fully featured Chip-8 emulator, it's purpose is to allow me to learn more about emulation. Hopefully you'll find it useful too. If you have any feedback or comments, don't hesitate contribute or contct me! 