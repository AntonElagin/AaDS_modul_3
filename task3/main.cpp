//Требуется отыскать самый выгодный маршрут между городами.
//Требования: время работы O((N+M)logN), где N-количество городов, M-известных дорог между ними.
//Формат входных данных.
//Первая строка содержит число N – количество городов.
//Вторая строка содержит число M - количество дорог.
//Каждая следующая строка содержит описание дороги (откуда, куда, время в пути).
//Последняя строка содержит маршрут (откуда и куда нужно доехать).
//Формат выходных данных.
//Вывести длину самого выгодного маршрута.
#include <queue>
#include <climits>
#include <iosfwd>
#include <set>
#include <iostream>
#include <sstream>
#include <cassert>


class ListGraph {
  std::vector<std::vector<std::pair<int, int>>> adjacencyLists;
  int vertices_count;

public:

  int dijkstra(int u1, int to);

  explicit ListGraph(int size);

  virtual ~ListGraph() = default;

  // Добавление ребра от from к to.
  void AddEdge(int from, int to, int time);
};

void run(std::istream &input, std::ostream &output) {
  int N, M;
  input >> N;
  input >> M;
  int from, to, time;
  ListGraph graph(N);
  for (int i = 0; i < M; i++) {
    input >> from >> to >> time;
    graph.AddEdge(from, to, time);
  }
  input >> from >> to;
  output << graph.dijkstra(from, to);
}

void testCase() {
  {
    std::stringstream input;
    std::stringstream output;
    input << "6\n"
          << "9\n"
          << "0 3 1\n"
          << "0 4 2\n"
          << "1 2 7\n"
          << "1 3 2\n"
          << "1 4 3\n"
          << "1 5 3\n"
          << "2 5 3\n"
          << "3 4 4\n"
          << "3 5 6\n"
          << "0 2";
    run(input, output);
    std::string str = output.str();
    assert(str == "9");
  }

}

int main(int argc, const char *argv[]) {
//  testCase();
  run(std::cin, std::cout);
  return 0;
}

ListGraph::ListGraph(int size) : vertices_count(size) {
  adjacencyLists.resize(size);
}

void ListGraph::AddEdge(int from, int to, int time) {
  adjacencyLists[from].emplace_back(std::make_pair(time, to));
  adjacencyLists[to].emplace_back(std::make_pair(time, from));
}


int ListGraph::dijkstra(int u1, int to) {
  std::vector<int> distance(vertices_count, INT_MAX), pi(vertices_count);
  pi[u1] = -1;
  distance[u1] = 0;
  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int> >, std::greater<>> qu;
  qu.push(std::make_pair(0, u1));
  while (!qu.empty()) {
    std::pair<int, int> current = qu.top();
    qu.pop();

    if (current.first <= distance[current.second]) {
      for (int i = 0; i < adjacencyLists[current.second].size(); i++) {
        int v = adjacencyLists[current.second][i].second, len = adjacencyLists[current.second][i].first;
        if (distance[v] > distance[current.second] + len) {
          distance[v] = distance[current.second] + len;
          pi[v] = current.second;
          qu.push(std::make_pair(distance[v], v));
        }
      }
    }
  }
  return distance[to];
}
