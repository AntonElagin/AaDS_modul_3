#include "ListGraph.h"
#include <cassert>
#include <queue>
#include <iostream>

ListGraph::ListGraph(int count) : adjacencyLists(count) {}

ListGraph::ListGraph(const IGraph& graph) : ListGraph(graph.VerticesCount()) {
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

void BFS(const IGraph& graph, int vertex, void (*visit)(int)) {
  std::vector<bool> visited(graph.VerticesCount(), false);
  std::queue<int> qu;
  qu.push(vertex);
  visited[vertex] = true;

  while (!qu.empty()) {
    int current = qu.front();
    visit(current);
    qu.pop();
    std::vector<int> nextVertices = graph.GetNextVertices(current);
    for (int v : nextVertices)
      if (!visited[v]) {
        qu.push(v);
        visited[v] = true;
      }
  }
}
