//
// Created by anton on 13.12.2019.
//

#ifndef AADS_M3_MATRIXGRAPH_H
#define AADS_M3_MATRIXGRAPH_H

#include <vector>
#include "IGraph.h"


class MatrixGraph : public IGraph {
  public:
    explicit MatrixGraph(int count);
    explicit MatrixGraph(const IGraph& graph);
    ~MatrixGraph() override;

    // Добавление ребра от from к to.
    void AddEdge(int from, int to) override;

    int VerticesCount() const override;

    std::vector<int> GetNextVertices(int vertex) const override;
    std::vector<int> GetPrevVertices(int vertex) const override;

  private:
    std::vector<std::vector<int>> adjacencyLists;
    int size{};
};

#endif  // AADS_M3_MATRIXGRAPH_H
