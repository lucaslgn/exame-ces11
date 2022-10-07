all:
	g++ -std=c++17 -Wall -Werror -Wextra -pedantic main.cpp events.cpp -o exe -lsfml-window -lsfml-system
run:
	./exe
