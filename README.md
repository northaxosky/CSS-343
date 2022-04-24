# CSS 343 B Sp 22: Data Structures, Algorithms, And Discrete Mathematics II
Github for CSS 343 Assignments  
Professor: Dong, si

## Grading
Assignments (4) - 50%  
Tests (2 * 20% Each) - 40%  
Discussion & Participation - 10%

## Compile and Valgrind
**Compile**   
g++ -g -std=c++11 -Wall -Wextra -Wno-sign-compare *.cpp   
**Valgrind:**   
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./a.out
 (--verbose --log-file=valgrind-out.txt)
**Clang-Format:**   
clang-format -i *.cpp *.h   
**Clang-Tidy**   
clang-tidy *.cpp
