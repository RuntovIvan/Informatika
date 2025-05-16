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
	std::vector<int> verts; // ������ ������ � ��������
	int weight = 0; // ����� ��� ��������

	// �������� �� ���������� ������� � ��������
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

	int adjMatrix[maxSize][maxSize]; // ������� ���������

	Graph();
	int GetVertPos(const int& vertex); // ��������� ������� ������� � ������� ������
	bool IsEmpty(); // �������� ������ �� ����
	bool IsFull(); // �������� ����� �� ����
	int GetAmountVerts(); // ���������� ������ � �����
	int GetAmountEdges(); // ���������� ����� � �����
	int GetWeight(const int& start_vert, const int& vert_end); // ��������� ���� �����
	std::vector<int> GetNeighbours(const int& vertex); // ��������� ������� �������
	void AddVertex(const int& vertex); // ���������� �������
	void AddEdge(const int& vert_start, const int& vert_end, int weight); // ���������� �����

	void DelEdge(int start_vert, int end_vert);
	void ChangeEdgeWeight(int start_vert, int end_vert, int new_weight);

	void DelVert(int vertex);

	std::vector<int> get_route_TSP(int start_vert);
	int get_route_weight(std::vector<int> route);
};