#pragma once

using namespace std;

class Board;

#include"Board.h"
#include"Constants.h"
#include<queue>

class Search
{
private:
	Board* board;
	Point parents[ROWS][COLUMNS];
	double distances[ROWS][COLUMNS];
	priority_queue<fPair, vector<fPair>, greater<fPair>> q;
	Point start, goal;
	double heuristic(Point current);
public:
	Search(Board* board, Point start, Point goal);
	bool run();
	std::vector<Point> getPath();
	bool isDone();
	bool pathExists();
	Point getStart();
	Point getGoal();
};

