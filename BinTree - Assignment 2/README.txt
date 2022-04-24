Written in latest Version of C++
Used Visual Studio Code C++ extension
Compiled using 'g++ -g -std=c++11 -Wall -Wextra -Wno-sign-compare *.cpp' in the console.
Produced the correct output for lab1 on linux machine and local machine.
Produced no memory leaks from lab1's main.
Checked for memory leaks using valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./a.out

// CONCERNING int getHeight() //
the getHeight function is not const because I streamlined it using retrieve which is not const.
This allows me to not create another helper function for getHeight and lets me reuse my retrieve function.