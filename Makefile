all:
	g++ -std=c++17 -Wall -Wextra -pedantic src/main.cpp src/events.cpp src/Player.cpp src/Map.cpp src/graphList.cpp -o Exam -lsfml-window -lsfml-system -lsfml-graphics
run:
	./Exam