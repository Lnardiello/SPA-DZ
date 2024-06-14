#pragma once

class Search;

#include<vector>
#include"Search.h"
#include"Constants.h"

class Board
{
private:
	bool graf[ROWS][COLUMNS];
	Point start, goal;
public:
	Board(bool graf[ROWS][COLUMNS]);
	Search findPath(Point start, Point goal);
	std::vector<Point> getNeighbours(Point p);

	bool isPointOnGrid(int row, int col);
	bool isPointValid(int row, int col);

	void draw();
	void draw(Search search, Point currentStep);

	Point getStart();
	Point getGoal();

	void setStart(int row, int col);
	void setGoal(int row, int col);

	void setObstacle(int row, int col);
	void removeObstacle(int row, int col);
};

