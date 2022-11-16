all:
	g++ -std=c++17 -Wall -Werror -Wextra -pedantic src/main.cpp src/events/events.cpp -o Exam -lsfml-window -lsfml-system -lsfml-graphics
run:
	./Exam
