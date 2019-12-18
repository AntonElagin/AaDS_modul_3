#include <cassert>
#include "SetGraph.h"

SetGraph::SetGraph(int count) : adjacencyLists(count) {

}

SetGraph::SetGraph(const IGraph &graph) {
  adjacencyLists.resize(graph.VerticesCount());
  for (int i = 0; i < graph.VerticesCount(); ++i) {
    for (const auto &vertex : graph.GetNextVertices(i)) {
      adjacencyLists[i].insert(vertex);
    }
  }
}

SetGraph::~SetGraph() {

}

void SetGraph::AddEdge(int from, int to) {
  assert(from >= 0 && from < adjacencyLists.size());
  assert(to >= 0 && to < adjacencyLists.size());
  adjacencyLists[from].insert(to);
}

int SetGraph::VerticesCount() const {
  return adjacencyLists.size();
}

std::vector<int> SetGraph::GetNextVertices(int vertex) const {
  return std::vector<int>(adjacencyLists[vertex].begin(),adjacencyLists[vertex].end());
}

std::vector<int> SetGraph::GetPrevVertices(int vertex) const {
  std::vector<int> list;
  for (int i = 0; i < VerticesCount(); ++i)
    if (adjacencyLists[i].find(vertex) != adjacencyLists[i].end()) {
      list.push_back(i);
    }
  return list;
}
