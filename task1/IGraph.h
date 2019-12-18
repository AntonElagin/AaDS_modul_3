//  q
// Created by anton on 13.12.2019.
//

#ifndef AADS_M3_IGRAPH_H
#define AADS_M3_IGRAPH_H

#include <vector>

struct IGraph {
  virtual ~IGraph() {}

  // Добавление ребра от from к to.
  virtual void AddEdge(int from, int to) = 0;

  virtual int VerticesCount() const = 0;

  virtual std::vector<int> GetNextVertices(int vertex) const = 0;
  virtual std::vector<int> GetPrevVertices(int vertex) const = 0;
};

#endif  // AADS_M3_IGRAPH_H
