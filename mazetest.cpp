#include "maze.h"
#include <string>
#include <iostream>
using namespace std;
//this is not the real tester
//compile this with your program:
//g++ maze.cpp a1q2.cpp mazetest.cpp -std=c++0x
int findPath (Maze& theMaze, const Coord& start, const Coord& end, Coord path[]);
int main(void){
	Coord start;
	Coord end;
	Coord path[1000];
	start.x = 1;
	start.y = 1;
	end.x = 11;
	end.y = 7;
	Maze m("maze.txt");
	cout << m.width() << endl;
	cout << m.height() << endl;
	cout << "original maze" << endl;
	m.print();
	findPath (m, start, end, path);
	m.print();
}