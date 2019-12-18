
#ifndef AADS_M3_SETGRAPH_H
#define AADS_M3_SETGRAPH_H

#include <unordered_set>
#include "IGraph.h"

class SetGraph : public IGraph {
public:
  explicit SetGraph(int count);
  explicit SetGraph(const IGraph& graph);
  ~SetGraph() override;

  // Добавление ребра от from к to.
  void AddEdge(int from, int to) override;

  int VerticesCount() const override;

  std::vector<int> GetNextVertices(int vertex) const override;
  std::vector<int> GetPrevVertices(int vertex) const override;

private:

  std::vector<std::unordered_set<int>> adjacencyLists;
};

#endif  // AADS_M3_SETGRAPH_H
