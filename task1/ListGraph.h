//
// Created by anton on 13.12.2019.
//

#ifndef AADS_M3_LISTGRAPH_H
#define AADS_M3_LISTGRAPH_H

#include <vector>
#include "IGraph.h"

class ListGraph : public IGraph {
 public:
  explicit ListGraph(int count);
  explicit ListGraph(const IGraph& graph);
  ~ListGraph() override;

  // Добавление ребра от from к to.
  void AddEdge(int from, int to) override;

  int VerticesCount() const override;

  std::vector<int> GetNextVertices(int vertex) const override;
  std::vector<int> GetPrevVertices(int vertex) const override;

 private:
  std::vector<std::vector<int>> adjacencyLists;
};

#endif  // AADS_M3_LISTGRAPH_H
