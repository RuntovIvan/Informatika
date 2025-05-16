#include "Graph.h"

Graph::Graph()
{
	for (int i = 0; i < maxSize; i++)
		for (int j = 0; j < maxSize; j++)
			adjMatrix[i][j] = 0;
}

int Graph::GetVertPos(const int& vertex)
{
	for (int i = 0; i < vertList.size(); i++)
		if (vertList[i] == vertex)
			return i;
	return -1;
}

bool Graph::IsEmpty()
{
	if (vertList.size() == 0) return true;
	return false;
}

bool Graph::IsFull()
{
	if (vertList.size() == maxSize) return true;
	return false;
}

int Graph::GetAmountVerts()
{
	return vertList.size();
}

int Graph::GetAmountEdges()
{
	int amount = 0;
	if (!IsEmpty())
		for (int i = 0; i < vertList.size(); i++)
			for (int j = 0; i < vertList.size(); j++)
				if (adjMatrix[i][j] != 0)
					amount += 1;
	return amount;
}

int Graph::GetWeight(const int& start_vert, const int& end_vert)
{
	if (!IsEmpty())
	{
		int pos_start = GetVertPos(start_vert);
		int pos_end = GetVertPos(end_vert);
		return adjMatrix[pos_start][pos_end];
	}
	return 0;
}

std::vector<int> Graph::GetNeighbours(const int& vertex)
{
	std::vector<int> neighbours;
	int vert_pos = GetVertPos(vertex);
	if (vert_pos != -1)
	{
		for (int i = 0; i < vertList.size(); i++)
			if (adjMatrix[vert_pos][i] != 0)
				neighbours.push_back(vertList[i]);
	}
	return neighbours;
}

bool vec_include(std::vector<int> vec, int vertex)
{
	for (int i = 0; i < vec.size(); i++)
		if (vec[i] == vertex) return true;
	return false;
}

void Graph::AddVertex(const int& vertex)
{
	if (!IsFull())
		if (!vec_include(vertList, vertex))
		{
			vertList.push_back(vertex);
			posList.push_back(Pos());
		}
}

void Graph::AddEdge(const int& vert_start, const int& vert_end, int weight)
{
	int start_pos = GetVertPos(vert_start);
	int end_pos = GetVertPos(vert_end);
	if (start_pos != -1 && end_pos != -1)
		if (adjMatrix[start_pos][end_pos] == 0)
			adjMatrix[start_pos][end_pos] = weight;
}

void Graph::DelEdge(int start_vert, int end_vert)
{
	int start_pos = GetVertPos(start_vert);
	int end_pos = GetVertPos(end_vert);
	adjMatrix[start_pos][end_pos] = 0;
}

void Graph::ChangeEdgeWeight(int start_vert, int end_vert, int new_weight)
{
	int start_pos = GetVertPos(start_vert);
	int end_pos = GetVertPos(end_vert);
	if (adjMatrix[start_pos][end_pos] != 0)
		adjMatrix[start_pos][end_pos] = new_weight;
}

void Graph::DelVert(int vertex)
{
	int pos = GetVertPos(vertex);
	if (pos == -1) return;

	int new_adjMatrix[maxSize][maxSize];
	for (int i = 0; i < maxSize; i++)
		for (int j = 0; j < maxSize; j++)
			new_adjMatrix[i][j] = 0;

	std::vector<int> row;
	for (int i = 0; i < vertList.size(); i++)
	{
		row.clear();
		if (i == pos)
			continue;
		for (int j = 0; j < vertList.size(); j++)
			if (j != pos)
				row.push_back(adjMatrix[i][j]);

		for (int k = 0; k < row.size(); k++)
			if (i < pos)
				new_adjMatrix[i][k] = row[k];
			else if (i > pos)
				new_adjMatrix[i - 1][k] = row[k];
	}

	std::vector<int> new_vertList;
	std::vector<Pos> new_posList;
	for (int i = 0; i < vertList.size(); i++)
		if (i != pos)
		{
			new_vertList.push_back(vertList[i]);
			new_posList.push_back(posList[i]);
		}

	vertList = new_vertList;
	posList = new_posList;

	for (int i = 0; i < maxSize; i++)
		for (int j = 0; j < maxSize; j++)
			adjMatrix[i][j] = new_adjMatrix[i][j];
}

int reduceMatrix(std::vector<std::vector<int>>& matrix)
{
	int reductionCost = 0;
	int n = matrix.size();

	for (auto& row : matrix)
	{
		int minVal = *min_element(row.begin(), row.end());
		if (minVal != inf && minVal != 0)
		{
			for (auto& elem : row)
				if (elem != inf)
					elem -= minVal;
		}
		reductionCost += minVal;
	}

	for (int j = 0; j < n; j++)
	{
		int minVal = inf;
		for (int i = 0; i < n; i++)
			if (matrix[i][j] < minVal)
				minVal = matrix[i][j];

		if (minVal != inf && minVal != 0)
		{
			for (int i = 0; i < n; i++)
				if (matrix[i][j] != inf)
					matrix[i][j] -= minVal;
		}
		reductionCost += minVal;
	}

	return reductionCost;
}

std::vector<std::vector<int>> evaluateZeros(std::vector<std::vector<int>> matrix)
{
	std::vector<std::vector<int>> zeros;
	int n = matrix.size();

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (matrix[i][j] == 0)
			{
				int minrow = inf;
				for (int k = 0; k < n; k++)
					if (k != j && matrix[i][k] < minrow)
						minrow = matrix[i][k];

				int mincol = inf;
				for (int k = 0; k < n; k++)
					if (k != i && matrix[k][j] < mincol)
						mincol = matrix[k][j];

				if (minrow == inf) minrow = 0;
				if (mincol == inf) mincol = 0;

				zeros.push_back({ i, j, minrow + mincol });
			}
		}
	}
	return zeros;
}

std::vector<std::vector<int>> createNewMatrix(std::vector<std::vector<int>> matrix, int row, int col)
{
	std::vector<std::vector<int>> new_matrix = matrix;

	for (int i = 0; i < matrix.size(); i++)
		for (int j = 0; j < matrix.size(); j++)
			if (i == row || j == col)
				new_matrix[i][j] = inf;

	return new_matrix;
}

bool all_inf(std::vector<std::vector<int>> matrix)
{
	for (int i = 0; i < matrix.size(); i++)
		for (int j = 0; j < matrix.size(); j++)
			if (matrix[i][j] != inf)
				return false;
	return true;
}

std::vector<int> Graph::get_route_TSP(int start_vert)
{
	std::vector<std::vector<int>> matrix;

	// копирование матрицы смежности
	for (int i = 0; i < vertList.size(); i++)
	{
		std::vector<int> row;
		for (int j = 0; j < vertList.size(); j++)
			if (adjMatrix[i][j] == 0)
				row.push_back(inf);
			else
				row.push_back(adjMatrix[i][j]);

		matrix.push_back(row);
	}

	std::vector<std::vector<int>> part_routes;
	
	while (!all_inf(matrix))
	{
		reduceMatrix(matrix); // редуцируем матрицу
		std::vector<std::vector<int>> zeros = evaluateZeros(matrix); // находим все 0
		
		std::vector<int> max_zero = {0, 0}; // для нахождения 0 с макс оценкой
		int max = -1;
		for (int i = 0; i < zeros.size(); i++)
			if (zeros[i][2] > max)
			{
				max = zeros[i][2];
				max_zero[0] = zeros[i][0];
				max_zero[1] = zeros[i][1];
			}

		matrix = createNewMatrix(matrix, max_zero[0], max_zero[1]); // удаляем столбец и строку с макс 0

		part_routes.push_back({vertList[max_zero[0]], vertList[max_zero[1]]}); // запоминаем позицию 0 с макс оценкой
	}


	// построение пути
	std::vector<int> route;
	int cur = start_vert;
	while (route.size() != vertList.size())
	{
		route.push_back(cur);
		for (int i = 0; i < part_routes.size(); i++)
			if (cur == part_routes[i][0])
			{
				cur = part_routes[i][1];
				break;
			}
	}
	route.push_back(start_vert);
	return route;
}

int Graph::get_route_weight(std::vector<int> route)
{
	int weight = 0;
	for (int i = 0; i < route.size() - 1; i++)
		weight += adjMatrix[GetVertPos(route[i])][GetVertPos(route[i + 1])];
	return weight;
}