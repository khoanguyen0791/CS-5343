#include "stdafx.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <deque>
#include "Graph.h"
using namespace std;

void createVector(vector<vector<int>> &temp, ifstream &fin) {
	for (auto row : temp)
		for (auto col : row)
		{
			fin >> col;
			cout << col;
		}
}
int main() {
	//Test case: https://www.math.ucdavis.edu/~daddel/linear_algebra_appl/Applications/GraphTheory/GraphTheory_9_17/node9.html

	//The graph.in file contains a 2D array of adjacency matrix (potentially with length). This does not work with
	//incident matrix.
	ifstream fin("graph.in");
	ofstream fout("graph.out");

	streambuf * coutbuf = cout.rdbuf();
	cout.rdbuf(fout.rdbuf());

	int vertices = 0;
	fin >> vertices;
	
	vector<vector<int>> temp(vertices, vector<int>(vertices, 0));

	createVector(temp, fin);

	Mgraph* graph = new Mgraph(temp);
	graph->printMatrix();

	fout.close();
	cout.rdbuf(coutbuf);

	//cin.get();





}
