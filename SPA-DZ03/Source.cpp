#include<iostream>
#include<chrono>
#include<thread>
#include<string>
#include<sstream>
#include "Board.h"

using namespace std;

int main() {
	bool graf[ROWS][COLUMNS] = {
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
	};
	
	Board b(graf);
	b.draw();

	int opt = 0;
	int col, row;
	stringstream ss;

	while (opt != 6)
	{
		system("cls");
		b.draw();
		cout << ss.str();

		cout << "1 = Odredi pocetnu tocku A" << endl;
		cout << "2 = Odredi krajnju tocku B" << endl;
		cout << "3 = Dodaj prepreku" << endl;
		cout << "4 = Makni prepreku" << endl;
		cout << "5 = Kreni" << endl;
		cout << "6 = Izadji" << endl << endl;

		cin >> opt;
		cin.ignore();

		ss.str("");
		ss.clear();

		system("cls");

		if (opt != 6)
		{
			b.draw();
		}

		switch (opt) {
		case 1:
			cout << "Unos koordinate pocetne tocke" << endl;
			cout << "Redak: ";
			cin >> row;
			cout << "Stupac: ";
			cin >> col;

			row--;
			col--;

			if (!b.isPointOnGrid(row, col)) {
				ss << "Pogresan unos, redak mora biti od 1 do 20, stupac od 1 do 40.\n" << endl;
				break;
			};

			if (!b.isPointValid(row, col)) {
				ss << "Tocka mora biti na slobodnom polju!\n";
				break;
			};

			if (make_pair(row, col) == b.getGoal())
			{
				ss << "Pocetna tocka ne moze biti ista kao krajnja!\n";
				break;
			}
			
			b.setStart(row, col);

			break;
		case 2:
			cout << "Unos koordinate krajnje tocke" << endl;
			cout << "Redak: ";
			cin >> row;
			cout << "Stupac: ";
			cin >> col;

			row--;
			col--;

			if (!b.isPointOnGrid(row, col)) {
				ss << "Greska! Redak tocke mora biti broj od 1 do 20, a stupac broj od 1 do 40!\n";
				break;
			};

			if (!b.isPointValid(row, col)) {
				ss << "Greska! Tocka mora biti na slobodnom polju!\n";
				break;
			};

			if (make_pair(row, col) == b.getStart())
			{
				ss << "Greska! Krajnja tocka ne moze biti ista kao pocetna!\n";
				break;
			}

			b.setGoal(row, col);

			break;
		case 3:
			cout << "Unos koordinata nove prepreke" << endl;
			cout << "Redak: ";
			cin >> row;
			cout << "Stupac: ";
			cin >> col;

			row--;
			col--;

			if (!b.isPointOnGrid(row, col)) {
				ss << "Greska! Redak prepreke mora biti broj od 1 do 20, a stupac broj od 1 do 40!\n\n";
				break;
			};

			if (make_pair(row, col) == b.getStart())
			{
				ss << "Greska! Prepreka ne moze biti na polju pocetne tocke!\n\n";
				break;
			}

			if (make_pair(row, col) == b.getGoal())
			{
				ss << "Greska! Prepreka ne moze biti na polju krajnje tocke!\n\n";
				break;
			}

			b.setObstacle(row, col);

			break;
		case 4:
			cout << "Unos koordinata prepreke koju zelite maknuti" << endl;
			cout << "Redak: ";
			cin >> row;
			cout << "Stupac: ";
			cin >> col;

			row--;
			col--;

			if (!b.isPointOnGrid(row, col)) {
				ss << "Greska! Redak prepreke mora biti broj od 1 do 20, a stupac broj od 1 do 40!\n\n";
				break;
			};

			b.removeObstacle(row, col);

			break;
		case 5:
		{
			Search search = b.findPath(b.getStart(), b.getGoal());

			bool pathFound = search.run();

			if (!pathFound)
			{
				ss << "Put od A do B ne postoji.\n\n";
				break;
			}

			vector<Point> path = search.getPath();
			for (auto it = path.rbegin(); it != path.rend(); ++it)
			{
				system("cls");
				b.draw(search, *it);
				this_thread::sleep_for(chrono::milliseconds(100));
			}
		}
			break;
		case 6:
			return 0;
		default:
			cout << "Neispravna opcija." << endl;
			break;
		}
	}

	return 0;
}