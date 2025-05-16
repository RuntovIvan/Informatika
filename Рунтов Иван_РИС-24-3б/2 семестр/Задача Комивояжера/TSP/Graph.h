#pragma once
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <iterator>

const int maxSize = 8;
const int inf = 10000;

struct Route
{
	std::vector<int> verts; // список вершин в маршруте
	int weight = 0; // общий вес маршрута

	// проверка на содержание вершины в маршруте
	bool isVertexExists(int vertex) const
	{
		return std::find(verts.cbegin(), verts.cend(), vertex) != verts.cend();
	}
};

struct Pos
{
	float x;
	float y;
	bool isDragging;

	Pos()
	{
		x = rand() % 601 + 100;
		y = rand() % 601 + 100;
		isDragging = false;
	}
};

class Graph
{
public:
	std::vector<int> vertList;
	std::vector<Pos> posList;

	int adjMatrix[maxSize][maxSize]; // матрица смежности

	Graph();
	int GetVertPos(const int& vertex); // получение индекса вершины в векторе вершин
	bool IsEmpty(); // проверка пустой ли граф
	bool IsFull(); // проверка полон ли граф
	int GetAmountVerts(); // количество вершин в графе
	int GetAmountEdges(); // количество ребер в графе
	int GetWeight(const int& start_vert, const int& vert_end); // получение веса ребра
	std::vector<int> GetNeighbours(const int& vertex); // получение соседей вершины
	void AddVertex(const int& vertex); // добавление вершины
	void AddEdge(const int& vert_start, const int& vert_end, int weight); // добавление ребра

	void DelEdge(int start_vert, int end_vert);
	void ChangeEdgeWeight(int start_vert, int end_vert, int new_weight);

	void DelVert(int vertex);

	std::vector<int> get_route_TSP(int start_vert);
	int get_route_weight(std::vector<int> route);
};