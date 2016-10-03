#include "maze.h"
#include <string>
#include <fstream>
#include <iostream>
#include <cstdio>
using namespace std;

Maze::Maze(string mazeFile){
	fstream fs(mazeFile,ios::in);
	char s[2000];
	char curr;
	fs.getline(s,99,'\n');
	sscanf(s,"%d %d",&width_,&height_);
	theMaze_=new int*[height_];
	for(int i=0;i<height_;i++){
		theMaze_[i]=new int[width_];
	}
	for(int i=0;i<height_;i++){
		fs.getline(s,1999,'\n');
		for(int j=0;j<width_;j++){
			curr=s[j];

			if(curr=='X'){
				theMaze_[i][j]=WALL;
			}
			else if(curr==' '){
				theMaze_[i][j]=EMPTY;
			}
			else if (curr=='o'){
				theMaze_[i][j]=MARKED;
			}
		}

	}
	fs.close();
}
bool Maze::isWall(const Coord& co) const{
	bool rc=false;
	if(theMaze_[co.y][co.x]==WALL){
		rc=true;
	}
	return rc;
}
bool Maze::isEmpty(const Coord& co) const{
	bool rc=false;
	if(theMaze_[co.y][co.x]==EMPTY){
		rc=true;
	}
	return rc;

}
bool Maze::isMarked(const Coord& co) const{
	bool rc=false;
	if(theMaze_[co.y][co.x]==MARKED){
		rc=true;
	}
	return rc;

};

bool Maze::mark(const Coord& co){
	bool rc=false;
	if(isEmpty(co)){
		theMaze_[co.y][co.x]=MARKED;
		rc=true;
	}
	return rc;

}
bool Maze::unMark(const Coord& co){
	bool rc=false;
	if(isMarked(co)){
		theMaze_[co.y][co.x]=EMPTY;
		rc=true;
	}
	return rc;
}

Maze::~Maze(){
	for(int i=0;i<height_;i++){
		delete [] theMaze_[i];
	}
	delete [] theMaze_;
}
void Maze::print() const{
	for(int i=0;i<height_;i++){
		for (int j=0;j<width_;j++){
			switch(theMaze_[i][j]){
				case WALL: cout << 'X'; break;
				case EMPTY: cout << ' ';  break;
				case MARKED: cout << 'o';  break;
			}
		}
		cout << endl;
	}
}