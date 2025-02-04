#include "Search.h"

double Search::heuristic(Point current)
{
	return sqrt(pow(current.first - goal.first, 2) + pow(current.second - goal.second, 2));
}

Search::Search(Board* board, Point start, Point goal) : board(board), start(start), goal(goal)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLUMNS; j++)
		{
			parents[i][j] = { -1, -1 };
			distances[i][j] = INF;
		}
	}

	distances[start.first][start.second] = 0;
	q.push({ 0, start });
}

bool Search::run()
{
	while (!q.empty())
	{
		Point node = q.top().second;
		q.pop();

		if (node.first == goal.first && node.second == goal.second) return true;

		for (Point& neighbour : board->getNeighbours(node))
		{
			double distance = distances[node.first][node.second];
			int dx = node.first - neighbour.first, dy = node.second - neighbour.second;

			distance += dx != 0 && dy != 0 ? sqrt(2) : 1;

			if (distances[neighbour.first][neighbour.second] <= distance) continue;

			parents[neighbour.first][neighbour.second] = node;
			distances[neighbour.first][neighbour.second] = distance;
			q.push({ distances[neighbour.first][neighbour.second] + heuristic(neighbour), neighbour });
		}
	}

	return false;
}

std::vector<Point> Search::getPath()
{
	if (!pathExists()) return std::vector<Point>();

	std::vector<Point> path;
	Point current = goal;

	while (parents[current.first][current.second].first != -1)
	{
		path.push_back(current);
		current = parents[current.first][current.second];
	}

	return path;
}

bool Search::pathExists()
{
	return parents[goal.first][goal.second].first != -1;
}

Point Search::getStart()
{
	return start;
}

Point Search::getGoal()
{
	return goal;
}

bool Search::isDone()
{
	return q.empty() || pathExists();
}