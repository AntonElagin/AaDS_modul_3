//
// Created by anton on 13.12.2019.
//

#ifndef AADS_M3_ARCGRAPH_H
#define AADS_M3_ARCGRAPH_H

#include "IGraph.h"

class ArcGraph : public IGraph {
public:
  explicit ArcGraph(int count);
  explicit ArcGraph(const IGraph& graph);
  ~ArcGraph() override;

  // Добавление ребра от from к to.
  void AddEdge(int from, int to) override;

  int VerticesCount() const override;

  std::vector<int> GetNextVertices(int vertex) const override;
  std::vector<int> GetPrevVertices(int vertex) const override;

private:
  std::vector<std::pair<int, int>> adjacencyLists;
};

#endif  // AADS_M3_ARCGRAPH_H
