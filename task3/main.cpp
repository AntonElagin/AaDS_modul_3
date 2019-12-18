#include <IGraph.h>
#include <queue>
#include <climits>

void Dijkstra(const IGraph& graph, int s)
{


  std::vector<bool> visited(graph.VerticesCount(), false);
  std::vector<int> r(graph.VerticesCount(), INT_MAX);
  std::vector<int> pi(graph.VerticesCount(), -1);
  std::queue<int> queue;
  queue.push(s);
  r[s] = 0;
  while (!queue.empty()) {
    int u = queue.top();
    queue.pop();
    for (auto vertex : graph.GetNextVertices(u)) {
      if (distance[vertex] == INT_MAX) {
        distance[vertex] = distance[u] + 1;
        pi[vertex] = u;
        queue.push(vertex);
      } else if (Relax(u, vertex)) {
        queue.push(vertex);
      }
    }
  }
}

int main() {

}
