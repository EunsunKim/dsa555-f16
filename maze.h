
#include <string>
using namespace std;

struct Coord{
	int x;
	int y;
	Coord(){
	}
	Coord(int a, int b){
		x=a;
		y=b;
	}
	void set(int a, int b){
		x=a;
		y=b;
	}
};

const int MARKED = 2;
const int WALL = 1;
const int EMPTY = 0;
class Maze{
	int** theMaze_;
	int width_;
	int height_;
public:
	Maze(string mazeFile);
	bool isWall(const Coord& co) const;
	bool isEmpty(const Coord& co) const;
	bool isMarked(const Coord& co) const;
	int width() const{return width_;}
	int height() const{return height_;}
	bool mark(const Coord& co);
	bool unMark(const Coord& co);
	void print() const;
	~Maze();
};

