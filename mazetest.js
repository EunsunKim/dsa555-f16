function Maze(mazeArray){
	that={};
	var width_;
	var height_;
	var initialized_=false;
	var startRow_;
	var startCol_;
	var endRow_;
	var endCol_;
	var flashy_;

	that.init = function(mazeArray,sx,sy,ex,ey){
		maze_=mazeArray;
		width_=maze_[0].length;
		height_=maze_.length;
		wallWidth_=5;
		startRow_=sy;
		startCol_=sx;
		endRow_=ey;
		endCol_=ex;
		initialized_=true;
		flashy_=0;
	}
	that.draw=function(){
		if(initialized_){
			var i;
			var j;
			if(flashy_!=4){
				fill(0,255,0);
				stroke(0,255,0);
				rect(startCol_*wallWidth_,startRow_*wallWidth_,wallWidth_,wallWidth_);
			}
			if(flashy_!=3){
				fill(255,0,0);
				stroke(255,0,0);
				rect(endCol_*wallWidth_,endRow_*wallWidth_,wallWidth_,wallWidth_);
			}
			for(i=0;i<height_;i++){
				for(j=0;j<width_;j++){
					if(maze_[i][j]==1){
						fill(0);
						stroke(0);
						rect(j*wallWidth_,i*wallWidth_,wallWidth_,wallWidth_);
					}
/*				else{
					fill(255);
					stroke(255);
					rect(j*wallWidth_,i*wallWidth_,wallWidth_,wallWidth_);
					
				}*/
				}
			}
			flashy_=(flashy_+1)%10;
		}
	}
	that.mazeWidth=function(){
		return width_;
	}
	that.mazeHeight=function(){
		return height_;
	}
	return that;
}

var theMaze;
var inputfile;
var radio;
var thePath;
function Path(){
	var that = {}
	var initialized_=false;
	var thePath_;
	var curr_=0;
	var wallWidth_=5;
	that.init=function(pathArray){
		thePath_=JSON.parse(pathArray);
		initialized_=true;
	}
	that.draw=function(){
		if(initialized_){
			for(var i=0;i<curr_;i++){
				fill(0,0,255);
				stroke(0,0,255);
				rect(thePath_[i*2]*wallWidth_,thePath_[i*2+1]*wallWidth_,wallWidth_,wallWidth_);			
			}
			curr_+=5;;
		}
	}
	that.isInitialized=function(){
		return initialized_;
	}
	that.reset=function(){
		initialized_=false;
		curr_=0;
	}
	return that;
}
function loadPathFile(file){
	if(thePath.isInitialized()){
		thePath.reset();
	}
	thePath.init(file.data);
}
function loadMaze(){
	switch(radio.value()){
		case '1': 
			theMaze.init(maze1,1,1,1,99); break;
		case '2':
			theMaze.init(maze1,75,69,99,85); break;
		case '3':
			theMaze.init(maze1,75,69,75,69); break;		
		case '4': 
			theMaze.init(maze1,99,85,75,69); break;			
		case '5': 
			theMaze.init(maze2,1,1,191,199); break;
		case '6':
			theMaze.init(maze3,1,1, 75,69); break;
		default:
			theMaze.init(maze1,1,1,1,99);		
	}
	thePath.reset();
}

function setup(){
	theMaze=Maze();
	thePath=Path();
	inputFile=createFileInput(loadPathFile);
	radio=createRadio();
	radio.option("test 1",1);
	radio.option("test 2",2);
	radio.option("test 3",3);
	radio.option("test 4",4);
	radio.option("test 5",5);
	radio.option("test 6",6);
	radio.value(1);
	radio.changed(loadMaze);
	theMaze.init(maze1,1,1,1,99);
	createCanvas(1200,1010);

}

function draw(){
	background(255);
	theMaze.draw();
	thePath.draw();

}
