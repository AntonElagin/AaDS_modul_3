//
// Created by anton on 13.12.2019.
//

#include <cassert>
#include <algorithm>
#include "MatrixGraph.h"

MatrixGraph::MatrixGraph(int count) : adjacencyLists(count,std::vector<int>(count, 0)), size(count)  {
//  adjacencyLists.reserve(count);
//  for (int i = 0; i < count; ++i) {
//    adjacencyLists[i].reserve(count);
//    for (int j = 0; j < count; ++j) {
//      adjacencyLists[i][j] = 0;
//    }
//  }
}

int MatrixGraph::VerticesCount() const {
  return size;
}

MatrixGraph::MatrixGraph(const IGraph &graph) {
  for (int i = 0; i < graph.VerticesCount(); ++i) {
    for (auto vertex : graph.GetNextVertices(i)) {
        adjacencyLists[i][vertex] = 1;
    }
  }
}

void MatrixGraph::AddEdge(int from, int to) {
  assert(from >= 0 && from < size);
  assert(to >= 0 && to < size);
  adjacencyLists[from][to] = 1;
}

std::vector<int> MatrixGraph::GetNextVertices(int vertex) const {
  assert(vertex >= 0 && vertex < size);
  std::vector<int> list;
  for (int i = 0; i < size; ++i) {
    int to = adjacencyLists[vertex][i];
    if (to > 0)
      list.push_back(i);
  }
  return list;
}

std::vector<int> MatrixGraph::GetPrevVertices(int vertex) const {
  assert(vertex >= 0 && vertex < size);
  std::vector<int> list;
  for (int i = 0; i < size; ++i) {
    int to = adjacencyLists[i][vertex];
    if (to > 0)
      list.push_back(i);
  }
  return list;
}

MatrixGraph::~MatrixGraph() {

}
