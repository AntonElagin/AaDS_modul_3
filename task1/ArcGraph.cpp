//
// Created by anton on 13.12.2019.
//

#include <cassert>
#include "ArcGraph.h"

ArcGraph::ArcGraph(int count) : adjacencyLists(count){
}

ArcGraph::ArcGraph(const IGraph &graph) {
  for (int i = 0; i < graph.VerticesCount(); ++i) {
    for(auto vertex : graph.GetNextVertices(i)) {
      adjacencyLists.emplace_back(i, vertex);
    }
  }
}

ArcGraph::~ArcGraph() {

}

void ArcGraph::AddEdge(int from, int to) {
  assert(from >= 0 && from < VerticesCount());
  assert(to >= 0 && to < VerticesCount());
  adjacencyLists.emplace_back(from, to);
}

int ArcGraph::VerticesCount() const {
  return adjacencyLists.size();
}

std::vector<int> ArcGraph::GetNextVertices(int vertex) const {
  std::vector<int> list;
  for (int i = 0; i < VerticesCount(); ++i) {
    if (adjacencyLists[i].first == vertex)
      list.push_back(adjacencyLists[i].second);
  }
  return list;
}

std::vector<int> ArcGraph::GetPrevVertices(int vertex) const {
  std::vector<int> list;
  for (int i = 0; i < VerticesCount(); ++i) {
    if (adjacencyLists[i].second == vertex)
      list.push_back(adjacencyLists[i].first);
  }
  return list;
}
