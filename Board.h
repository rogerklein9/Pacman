#pragma once

#include <conio.h> 
#include <vector>
#include <fstream>
#include <sstream>
#include <utility>    
#include <set>    
#include "Pacman.h"
#include "Ghost.h"
using std::vector;



class Board
{
	vector<string> Org_map, Play_map;    // We creat 2 identical maps; one to keep for new game beginnings 
	Pacman pac;						   // and one to play and change in real time.
	vector<Ghost> ghosts;
	Point legend;
	bool legend_flag = false;
	short rows = 0, cols = 0;
	short breadcrumbs = 0;
private:
	//-------------------------pacman movement-----------------------------------
	bool findBorder_Top(const unsigned short& col, unsigned short& line);
	void changeFood2Path(Point pos) { Play_map[pos.getY()][pos.getX()] = ' '; }
	static bool isBlank(char a) { return a == ' ' || a == '%' || a == '.'; }
	bool isOnBorder(Point pos);
	bool isTopBorder(const unsigned& X, const unsigned& Y);
	//------------------------ghosts movement------------------------------------

	void nextContAndOppDic(Direction dic, Direction& op_dic, char& next_cont, char* cont_around);
	void AnalyzeAround(Ghost g, char* conts, bool* paths);
	void NoviceMovement(const vector<Direction>&, Direction&, const char&, bool, Ghost& G,const char&);
	void BestMovement(const vector<Direction>& options, bool colored, Ghost& G, const char&);
	pair<Direction, int> BestMovement_Util(vector<vector<bool>>canGo, int path_len, Point dest, Point cur, Direction,set<Point>);
	vector<vector<bool>> createTrackingMap();
	//-----------------------------ctor-----------------------------------------
	void create_map_from_file();

public:
	Board();
	//---------------------utilities----------------------------------
	vector<string>& getPlay_map() { return Play_map; }
	const Point& getlegend() const { return legend; }
	bool getLegend_flag() const { return legend_flag; }
	void resetCharacters() { pac.resetMe(); for (auto& g : ghosts) g.resetMe(); }
	void resetMap();
	short getCrumbs() { return breadcrumbs; }
	char nextCellCont(Point pos, Direction dic);      // returns map content in a given postion.
	bool Collision();
	void printMap(bool colored);

	//-------------------pacman---------------------------
	Pacman& Pac() { return pac; }
	void movePac(Direction dic, bool colored, short& score);
	bool portals(Direction dic, Point& pos);
	
	//----------------------ghosts----------------------
	const vector<Ghost>& Ghosts() { return ghosts; }
	Ghost& Ghosts(int i) { return ghosts[i]; } // needs to be changed in Game.cpp and therefor not const.
	void moveGhost(bool colored,int);

};