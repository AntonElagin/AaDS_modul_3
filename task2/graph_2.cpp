#include <iostream>
#include <queue>
#include <cassert>
#include <climits>

struct IGraph {
  virtual ~IGraph() {}

  // Добавление ребра от from к to.
  virtual void AddEdge(int from, int to) = 0;

  virtual int VerticesCount() const = 0;

  virtual std::vector<int> GetNextVertices(int vertex) const = 0;

  virtual std::vector<int> GetPrevVertices(int vertex) const = 0;

  int BFS(int start, int finish) {
    std::vector<int> wayFromStart(VerticesCount(), INT_MAX);
    std::vector<int> counter(VerticesCount(), 0);
    std::queue<int> qu;
    qu.push(start);
    wayFromStart[start] = 0;
    counter[start] = 1;

    while (!qu.empty()) {
      int current = qu.front();
      qu.pop();
      std::vector<int> nextVertices = GetNextVertices(current);
      for (int v : nextVertices)
        if (wayFromStart[v] > wayFromStart[current] + 1) {
          counter[v] = counter[current];
          wayFromStart[v] = wayFromStart[current] + 1;
          qu.push(v);
        } else if (wayFromStart[v] == wayFromStart[current] + 1)
          counter[v] +=  counter[current];
    }
    return counter[finish];
  }
};
////////////////////////////////////////////////////////////////

class ListGraph : public IGraph {
public:
  explicit ListGraph(int count);

  explicit ListGraph(const IGraph &graph);

  ~ListGraph() override;

  // Добавление ребра от from к to.
  void AddEdge(int from, int to) override;

  int VerticesCount() const override;

  std::vector<int> GetNextVertices(int vertex) const override;

  std::vector<int> GetPrevVertices(int vertex) const override;

private:
  std::vector<std::vector<int>> adjacencyLists;
};

////////////////////////////////////////////////////////////////

ListGraph::ListGraph(int count) : adjacencyLists(count) {}

ListGraph::ListGraph(const IGraph &graph) : ListGraph(graph.VerticesCount()) {
  for (int i = 0; i < graph.VerticesCount(); i++)
    adjacencyLists[i] = graph.GetNextVertices(i);
}

ListGraph::~ListGraph() {}

void ListGraph::AddEdge(int from, int to) {
  assert(from >= 0 && from < adjacencyLists.size());
  assert(to >= 0 && to < adjacencyLists.size());
  adjacencyLists[from].push_back(to);
}

int ListGraph::VerticesCount() const { return adjacencyLists.size(); }

std::vector<int> ListGraph::GetNextVertices(int vertex) const {
  assert(vertex >= 0 && vertex < adjacencyLists.size());
  return adjacencyLists[vertex];
}

std::vector<int> ListGraph::GetPrevVertices(int vertex) const {
  assert(vertex >= 0 && vertex < adjacencyLists.size());

  std::vector<int> result;
  for (int from = 0; from < adjacencyLists.size(); from++)
    for (int i = 0; i < adjacencyLists[from].size(); i++)
      if (adjacencyLists[from][i] == vertex) result.push_back(from);

  return result;
}

/////////////////////////////////////////////////////////////////
//int BFS(const IGraph &graph, int start, int finish) {
//  std::vector<int> wayFromStart(graph.VerticesCount(), INT_MAX);
//  std::vector<int> counter(graph.VerticesCount(), 0);
//  std::queue<int> qu;
//  qu.push(start);
//  wayFromStart[start] = 0;
//  counter[start] = 1;
//
//  while (!qu.empty()) {
//    int current = qu.front();
//    qu.pop();
//    std::vector<int> nextVertices = graph.GetNextVertices(current);
//    for (int v : nextVertices)
//      if (wayFromStart[v] > wayFromStart[current] + 1) {
//        counter[v] = counter[current];
//        wayFromStart[v] = wayFromStart[current] + 1;
//        qu.push(v);
//      } else if (wayFromStart[v] == wayFromStart[current] + 1)
//        counter[v] +=  counter[current];
//  }
//  return counter[finish];
//}


void run(std::istream &input, std::ostream &output) {
  int v, n;
  input >> v >> n;
  ListGraph graph(v);
  for (int i = 0; i < n; ++i) {
    int v1, v2;
    input >> v1 >> v2;
    graph.AddEdge(v1, v2);
    graph.AddEdge(v2, v1);
  }
  int st, fin;
  input >> st >> fin;
  output << graph.BFS(st, fin);
}

int main() {
  run(std::cin, std::cout);
  return 0;
}
