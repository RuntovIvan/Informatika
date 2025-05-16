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
		y = rand() % 401 + 100;
		isDragging = false;
	}
};

class Graph
{
public:
	std::vector<int> vertList;
	std::vector<Pos> posList;

	std::vector<int> labelList;
	int adjMatrix[maxSize][maxSize]; // ������� ���������

	int Fl_adjMatrix[maxSize][maxSize]; // ������� ��������� ��� ��������� ������
	int shortestPathsMatrix[maxSize][maxSize]; // ������� ���� �����
	int secondMatrix[maxSize][maxSize]; // ������� ���������� �����

	Graph();
	int GetVertPos(const int& vertex); // ��������� ������� ������� � ������� ������
	bool IsEmpty(); // �������� ������ �� ����
	bool IsFull(); // �������� ����� �� ����
	int GetWeight(const int& start_vert, const int& vert_end); // ��������� ���� �����
	std::vector<int> GetNeighbours(const int& vertex); // ��������� ������� �������
	void AddVertex(const int& vertex); // ���������� �������
	void AddEdge(const int& vert_start, const int& vert_end, int weight); // ���������� �����
	void Fl_AddEdge(const int& vert_start, const int& vert_end, int weight);

	void DFS(const int& vert_start, std::vector<bool>& visited_verts, std::vector<int>& route); // ����� � �������
	void BFS(const int& vert_start, std::vector<bool>& visited_verts, std::vector<int>& route); // ����� � ������

	bool AllVisited(std::vector<bool> visited_verts); // ��������� ��� �� ��������
	void FillLabels(int& start_vertex); // ���������� ������ �����
	int Dijkstra(int& start_vertex, std::vector<int>& result);

	void Floyd();

	void DelEdge(int start_vert, int end_vert);
	void Fl_DelEdge(int start_vert, int end_vert);
	void ChangeEdgeWeight(int start_vert, int end_vert, int new_weight);
	void Fl_ChangeEdgeWeight(int start_vert, int end_vert, int new_weight);

	void DelVert(int vertex);
};