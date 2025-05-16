#include "Graph.h"

Graph::Graph()
{
	for (int i = 0; i < maxSize; i++)
		for (int j = 0; j < maxSize; j++)
		{
			adjMatrix[i][j] = 0;
			if (i == j)
			{
				Fl_adjMatrix[i][j] = 0;
				shortestPathsMatrix[i][j] = 0;
			}
			else
			{
				Fl_adjMatrix[i][j] = inf;
				shortestPathsMatrix[i][j] = inf;
			}
			secondMatrix[i][j] = 0;
		}
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

void Graph::Fl_AddEdge(const int& vert_start, const int& vert_end, int weight)
{
	int start_pos = GetVertPos(vert_start);
	int end_pos = GetVertPos(vert_end);
	if (start_pos != -1 && end_pos != -1)
		if (!(Fl_adjMatrix[start_pos][end_pos] != inf && Fl_adjMatrix[start_pos][end_pos] != 0))
		{
			Fl_adjMatrix[start_pos][end_pos] = weight;
			secondMatrix[start_pos][end_pos] = vert_end;
		}
}

void Graph::DFS(const int& vert_start, std::vector<bool>& visited_verts, std::vector<int>& route)
{
	route.push_back(vert_start); // добавляем вершину в путь обхода в глубину
	visited_verts[GetVertPos(vert_start)] = true;
	std::vector<int> neighbours = GetNeighbours(vert_start);
	for (int i = 0; i < neighbours.size(); i++)
	{
		if (visited_verts[GetVertPos(neighbours[i])] == false)
			DFS(neighbours[i], visited_verts, route);
	}
}

void Graph::BFS(const int& vert_start, std::vector<bool>& visited_verts, std::vector<int>& route)
{
	std::queue<int> q; // очередь
	q.push(vert_start); // добавляем первый в очередь
	visited_verts[GetVertPos(vert_start)] = true; // отмечаем посещение
	route.push_back(vert_start); // добавляем вершину в путь обхода в ширину

	while (!q.empty())
	{
		int cur_vert = q.front();
		q.pop();

		std::vector<int> cur_neighbours = GetNeighbours(cur_vert);
		for (int i = 0; i < cur_neighbours.size(); i++)
		{
			int neighbour_pos = GetVertPos(cur_neighbours[i]);
			if (visited_verts[neighbour_pos] == false)
			{
				q.push(cur_neighbours[i]);
				visited_verts[neighbour_pos] = true;
				route.push_back(cur_neighbours[i]);
			}
		}
	}
}

bool Graph::AllVisited(std::vector<bool> visited_verts)
{
	for (int i = 0; i < vertList.size(); i++)
		if (visited_verts[i] == false)
			return false;
	return true;
}

void Graph::FillLabels(int& start_vertex)
{
	labelList.clear();

	for (int i = 0; i < vertList.size(); i++)
		labelList.push_back(inf);

	labelList[GetVertPos(start_vertex)] = 0;
}

int Graph::Dijkstra(int& start_vertex, std::vector<int>& result)
{
	FillLabels(start_vertex);
	std::vector<bool> visited_verts;
	for (int i = 0; i < vertList.size(); i++)
		visited_verts.push_back(false);

	// проверка на наличие отрицательных весов
	for (int i = 0; i < vertList.size(); i++)
		for (int j = 0; j < vertList.size(); j++)
			if (adjMatrix[i][j] < 0)
				return -1;

	int cur_vert = start_vertex; // текущая обрабатываемая вершина
	std::vector<int> neighbours = GetNeighbours(start_vertex); // соседи обрабатываемой вершины

	int min = inf;

	while (!AllVisited(visited_verts))
	{
		for (int i = 0; i < neighbours.size(); i++)
			if (visited_verts[GetVertPos(neighbours[i])] == false)
				if (labelList[GetVertPos(neighbours[i])] > labelList[GetVertPos(cur_vert)] + GetWeight(cur_vert, neighbours[i]))
					labelList[GetVertPos(neighbours[i])] = labelList[GetVertPos(cur_vert)] + GetWeight(cur_vert, neighbours[i]);

		visited_verts[GetVertPos(cur_vert)] = true;

		min = inf;
		for (int i = 0; i < vertList.size(); i++)
			if (labelList[i] <= min && visited_verts[i] == false)
			{
				min = labelList[i];
				cur_vert = vertList[i];
			}
		neighbours = GetNeighbours(cur_vert);
	}

	for (int i = 0; i < vertList.size(); i++)
		result.push_back(labelList[i]);

	return 0;
}

void Graph::Floyd()
{
	for (int i = 0; i < maxSize; i++)
		for (int j = 0; j < maxSize; j++)
		{
			if (i == j)
			{
				shortestPathsMatrix[i][j] = 0;
			}
			else
			{
				shortestPathsMatrix[i][j] = inf;
			}
			secondMatrix[i][j] = 0;
		}

	for (int i = 0; i < vertList.size(); i++)
	{
		std::vector<Route> routes; // все возможные маршруты от текущей вершины

		{
			std::queue<Route> routesToWatch; // очередь маршрутов для обработки (обход в ширину)

			// инициализируем очередь начальным маршрутом (содержит только начальную вершину)
			{
				Route route;
				route.verts.push_back(vertList[i]); // добавляем начальную вершину в маршрут
				routesToWatch.push(route); // добавляем маршрут в очередь маршрутов
			}

			// поиск в ширину для нахождения всех маршрутов
			while (!routesToWatch.empty())
			{
				Route cur_route = routesToWatch.front(); // текущий маршрут
				routesToWatch.pop(); // удаляем текущий из очереди
				routes.push_back(cur_route); // добавляем его в список всех маршрутов

				int last_route_vert = cur_route.verts.back(); // последняя вершина маршрута

				for (int neighbour : GetNeighbours(last_route_vert)) // соседи последней вершины маршрута
				{
					if (!cur_route.isVertexExists(neighbour))
					{
						Route route_to_watch = cur_route; // копия текущего маршрута
						route_to_watch.verts.push_back(neighbour);
						route_to_watch.weight += Fl_adjMatrix[GetVertPos(last_route_vert)][GetVertPos(neighbour)];
						routesToWatch.push(route_to_watch); // добавляем полученный маршрут в очередь
					}
				}
			}
		}
		routes.erase(routes.begin()); // удаление маршрута из вершины в саму себя

		// словарь для хранения кратчайших маршрутов от начальной вершины до каждой другой вершины
		// ключ: конечная вершина в маршруте
		// значение: пара (следующая вершина в маршруте(2-я), вес маршрута)
		std::map<int, std::pair<int, int>> shortest_routes;

		for (Route route : routes)
		{
			int end_vert = route.verts.back();
			int step_vert = route.verts[1];

			if (shortest_routes.find(end_vert) == shortest_routes.end())
				shortest_routes.insert(std::make_pair(end_vert, std::make_pair(step_vert, route.weight)));
			else
				if (shortest_routes[end_vert].second > route.weight)
					shortest_routes[end_vert] = std::make_pair(step_vert, route.weight);
		}

		for (std::pair<int, std::pair<int, int>> shortest_route : shortest_routes)
		{
			int end_vert = shortest_route.first;
			int step_vert = shortest_route.second.first;
			int min_weight = shortest_route.second.second;

			shortestPathsMatrix[i][GetVertPos(end_vert)] = min_weight;
			secondMatrix[i][GetVertPos(end_vert)] = step_vert;
		}
	}
}

void Graph::DelEdge(int start_vert, int end_vert)
{
	int start_pos = GetVertPos(start_vert);
	int end_pos = GetVertPos(end_vert);
	adjMatrix[start_pos][end_pos] = 0;
}

void Graph::Fl_DelEdge(int start_vert, int end_vert)
{
	int start_pos = GetVertPos(start_vert);
	int end_pos = GetVertPos(end_vert);
	Fl_adjMatrix[start_pos][end_pos] = inf;
	Floyd();
}

void Graph::ChangeEdgeWeight(int start_vert, int end_vert, int new_weight)
{
	int start_pos = GetVertPos(start_vert);
	int end_pos = GetVertPos(end_vert);
	if (adjMatrix[start_pos][end_pos] != 0)
		adjMatrix[start_pos][end_pos] = new_weight;
}

void Graph::Fl_ChangeEdgeWeight(int start_vert, int end_vert, int new_weight)
{
	int start_pos = GetVertPos(start_vert);
	int end_pos = GetVertPos(end_vert);
	if (Fl_adjMatrix[start_pos][end_pos] != 0 && Fl_adjMatrix[start_pos][end_pos] != inf)
		Fl_adjMatrix[start_pos][end_pos] = new_weight;
	Floyd();
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

	int new_Fl_adjMatrix[maxSize][maxSize];
	for (int i = 0; i < maxSize; i++)
		for (int j = 0; j < maxSize; j++)
			if (i == j)
				new_Fl_adjMatrix[i][j] = 0;
			else
				new_Fl_adjMatrix[i][j] = inf;

	std::vector<int> Fl_row;
	for (int i = 0; i < vertList.size(); i++)
	{
		Fl_row.clear();
		if (i == pos)
			continue;
		for (int j = 0; j < vertList.size(); j++)
			if (j != pos)
				Fl_row.push_back(Fl_adjMatrix[i][j]);

		for (int k = 0; k < Fl_row.size(); k++)
			if (i < pos)
				new_Fl_adjMatrix[i][k] = Fl_row[k];
			else if (i > pos)
				new_Fl_adjMatrix[i - 1][k] = Fl_row[k];
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
		{
			adjMatrix[i][j] = new_adjMatrix[i][j];
			Fl_adjMatrix[i][j] = new_Fl_adjMatrix[i][j];
		}
	Floyd();
}