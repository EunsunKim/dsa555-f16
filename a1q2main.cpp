/*********************************************************************/
/*                                                                   */
/* Tester for DSA555 assignment 1, question 2                        */
/*                                                                   */
/* copy your file a1q2.cpp to this folder.  As there are many data   */
/* files and the tester will generate files that you can use for     */
/* checking the result, it will be cleaner to do it this way.        */
/* Note, I do not need this tester folder submitted with your        */
/* just your a1q2.cpp is all I need                                  */
/*                                                                   */
/* To compile:                                                       */
/*                                                                   */
/*      g++ a1q2main.cpp maze.cpp a1q2.cpp -std=c++0x                */
/*                                                                   */
/* Aside from indicating if you passed the 6 tests, it will also     */
/* produce a result file named  test#result.txt file.  (the #        */
/* will be changed to the test number the file shows)                */
/* You can see your maze run here:                                   */
/*                                                                   */
/* http://seneca-dsa555.github.io/dsa555-f16/                        */
/* use the browse button to select the test#result.txt file  for     */
/* the test.  it will animate your path                              */
/* green dot is start point, red is end point.                       */
/*********************************************************************/

#include "maze.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;
#define VERBOSE 0


int findPath (Maze& theMaze, const Coord& start, const Coord& end, Coord path[]);
void printPath(const char* fname, Coord path[],int n);
bool operator==(const Maze& left, const Maze& right);
bool testPath(const Maze* original,const Maze* marked, Coord start, Coord end, const Coord path[], int n);

int main(void){
	int testStart[7][2]={{1,1},{75,69},{75,69},{99,85},{1,1},{1,1}};
	int testEnd[7][2]={{1,99},{99,85},{75,69},{75,69},{191,199},{75,69}};
	const char* mazeFiles[10]={"maze1.txt", "maze1.txt","maze1.txt", "maze1.txt","maze2.txt", "maze3.txt"};
	const char* json[10]={"test1result.txt","test2result.txt","test3result.txt","test4result.txt","test5result.txt","test6result.txt"};
	const int numTests=6;
	int pathLength;
	Coord start;
	Coord end;
	Coord path[10000];
	Maze* m;
	Maze* original;
	ofstream out;
	int numPassed=0;
	for(int i=0;i<numTests && i == numPassed;i++){

		m=new Maze(mazeFiles[i]);
		start.set(testStart[i][0],testStart[i][1]);
		end.set(testEnd[i][0],testEnd[i][1]);
		pathLength=findPath (*m, start, end, path);
		original=new Maze(mazeFiles[i]);
		cout << "checking path for Test #" << i+1 << endl;
		if(testPath(original, m, start, end, path, pathLength)){
			cout << "Test # " << i+1 << " passed" << endl;			
			numPassed++;
		}
		else{
			cout << "Test # " << i+1 << " failed" << endl;			
		}
		if(pathLength > 0){
			printPath(json[i],path,pathLength);
		}
		delete original;
		delete m;
		#if VERBOSE == 1
		cout << "your maze" << endl;
		m->print();
		#endif

	}
	cout << numPassed << "/" << numTests << " passed" << endl;
	if(numPassed <  numTests){
		cout << "It looks like you still have some work to do" << endl;
	}
	else{
		cout << "This question is now completed" << endl;
	}
}

void printPath(const char* fname, Coord path[],int n){
	ofstream fs(fname);
	fs << "[";
	for(int i=0;i<n-1;i++){
		fs << path[i].x << ", " << path[i].y <<", " ;
	}
	fs << path[n-1].x << ", " << path[n-1].y <<"]" << endl;
	fs.close();
}

bool isBeside(const Coord& a, const Coord& b){
	bool rc=true;
	if(a.x == b.x){
		if(abs(a.y-b.y) != 1){
			rc=false;
		}
	}
	else if(a.y==b.y){
		if(abs(a.x-b.x) != 1){
			rc=false;
		}
	}
	else{
		rc=false;
	}
	return rc;
}
bool search(const Coord& c, const Coord path[], int n){
	bool found=false;
	for(int i=0;!found && i<n;i++){
		if(c==path[i]){
			found=true;
		}
	}
	return found;
}
bool testPath(const Maze* original,const Maze* marked, Coord start, Coord end, const Coord path[], int n){
	bool isGood=true;
	if(n > 0){
		if(path[0]!= start){
			isGood=false;
		}
		if(path[n-1]!= end){
			isGood=false;
		}
		for(int i=1;isGood && i<n;i++){
			if(!isBeside(path[i],path[i-1])){
				isGood=false;
			}
			if(!original->isEmpty(path[i])){
				isGood=false;
			}
			if(!marked->isMarked(path[i])){
				isGood=false;
			}
		}
	}
	Coord curr;
	for(int i=0;isGood && i<original->height();i++){
		for(int j=0;isGood && j<original->width();j++){
			curr.set(j,i);
			if(marked->isMarked(curr)){
				if(!search(curr,path,n)){
					isGood = false;
				}
			}
		}
	}
	return isGood;
}