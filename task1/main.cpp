//Дан базовый интерфейс для представления ориентированного графа:
//struct IGraph {
//virtual ~IGraph() {}
//
//	// Добавление ребра от from к to.
//virtual void AddEdge(int from, int to) = 0;
//
//	virtual int VerticesCount() const  = 0;
//
//virtual std::vector<int> GetNextVertices(int vertex) const = 0;
//virtual std::vector<int> GetPrevVertices(int vertex) const = 0;
//};
//
//Необходимо написать несколько реализаций интерфейса:
//ListGraph, хранящий граф в виде массива списков смежности,
//MatrixGraph, хранящий граф в виде матрицы смежности,
//SetGraph, хранящий граф в виде массива хэш-таблиц/сбалансированных деревьев поиска,
//ArcGraph, хранящий граф в виде одного массива пар {from, to}.
//Также необходимо реализовать конструктор, принимающий const IGraph&. Такой конструктор должен скопировать переданный граф в создаваемый объект.
//Для каждого класса создавайте отдельные h и cpp файлы.
//Число вершин графа задается в конструкторе каждой реализации.
#include <iostream>
#include "IGraph.h"
#include "ListGraph.h"
#include "ArcGraph.h"
#include "SetGraph.h"
#include "MatrixGraph.h"
#include <queue>
#include <climits>
#include <sstream>
#include <cassert>


int BFS(const IGraph &graph, int start, int finish) {
  std::vector<int> wayFromStart(graph.VerticesCount(), INT_MAX);
  std::vector<int> counter(graph.VerticesCount(), 0);
  std::queue<int> qu;
  qu.push(start);
  wayFromStart[start] = 0;
  counter[start] = 1;

  while (!qu.empty()) {
    int current = qu.front();
    qu.pop();
    std::vector<int> nextVertices = graph.GetNextVertices(current);
    for (int v : nextVertices)
      if (wayFromStart[v] > wayFromStart[current] + 1) {
        counter[v] = counter[current];
        wayFromStart[v] = wayFromStart[current] + 1;
        qu.push(v);
      } else if (wayFromStart[v] == wayFromStart[current] + 1)
        counter[v] += counter[current];
  }
  return counter[finish];
}


void run(std::istream &input, std::ostream &output) {
  int v, n;
  input >> v >> n;
  ListGraph graph(v);
  for (int i = 0; i < n; ++i) {
    int v1, v2;
    input >> v1 >> v2;
    graph.AddEdge(v1, v2);
    graph.AddEdge(v2, v1);
  }
  int st, fin;
  input >> st >> fin;
  output << BFS(graph, st, fin);
}

void run2(std::istream &input, std::ostream &output) {
  int v, n;
  input >> v >> n;
  SetGraph graph(v);
  for (int i = 0; i < n; ++i) {
    int v1, v2;
    input >> v1 >> v2;
    graph.AddEdge(v1, v2);
    graph.AddEdge(v2, v1);
  }
  int st, fin;
  input >> st >> fin;
  output << BFS(graph, st, fin);
}

void run3(std::istream &input, std::ostream &output) {
  int v, n;
  input >> v >> n;
  ArcGraph graph(v);
  for (int i = 0; i < n; ++i) {
    int v1, v2;
    input >> v1 >> v2;
    graph.AddEdge(v1, v2);
    graph.AddEdge(v2, v1);
  }
  int st, fin;
  input >> st >> fin;
  output << BFS(graph, st, fin);
}

void run4(std::istream &input, std::ostream &output) {
  int v, n;
  input >> v >> n;
  MatrixGraph graph(v);
  for (int i = 0; i < n; ++i) {
    int v1, v2;
    input >> v1 >> v2;
    graph.AddEdge(v1, v2);
    graph.AddEdge(v2, v1);
  }
  int st, fin;
  input >> st >> fin;
  output << BFS(graph, st, fin);
}

void test() {
  {
    std::stringstream input;
    std::stringstream output;
    input << "7\n"
          << "8\n"
          << "0 1\n"
          << "0 2\n"
          << "1 3\n"
          << "2 3\n"
          << "3 4\n"
          << "3 5\n"
          << "4 6\n"
          << "5 6\n"
          << "0 6";
    run(input, output);
    assert(output.str() == "4");
    output.clear();
  }
  {
    std::stringstream input;
    std::stringstream output;
    input << "7\n"
          << "8\n"
          << "0 1\n"
          << "0 2\n"
          << "1 3\n"
          << "2 3\n"
          << "3 4\n"
          << "3 5\n"
          << "4 6\n"
          << "5 6\n"
          << "0 6";
    run2(input, output);
    assert(output.str() == "4");
    output.clear();
  }
  {
    std::stringstream input;
    std::stringstream output;
    input << "7\n"
          << "8\n"
          << "0 1\n"
          << "0 2\n"
          << "1 3\n"
          << "2 3\n"
          << "3 4\n"
          << "3 5\n"
          << "4 6\n"
          << "5 6\n"
          << "0 6";
    run3(input, output);
    assert(output.str() == "4");
    output.clear();
  }
  {
    std::stringstream input;
    std::stringstream output;
    input << "7\n"
          << "8\n"
          << "0 1\n"
          << "0 2\n"
          << "1 3\n"
          << "2 3\n"
          << "3 4\n"
          << "3 5\n"
          << "4 6\n"
          << "5 6\n"
          << "0 6";
    run4(input, output);
    assert(output.str() == "4");
    output.clear();

  }
  {
    std::stringstream input;
    std::stringstream output;
    input << "7\n"
          << "8\n"
          << "0 1\n"
          << "0 2\n"
          << "1 3\n"
          << "2 3\n"
          << "3 4\n"
          << "3 5\n"
          << "4 6\n"
          << "5 6\n"
          << "0 6";
    int v, n;
    input >> v >> n;
    MatrixGraph graph(v);
    for (int i = 0; i < n; ++i) {
      int v1, v2;
      input >> v1 >> v2;
      graph.AddEdge(v1, v2);
      graph.AddEdge(v2, v1);
    }
    int st, fin;
    input >> st >> fin;
    ListGraph l1(graph);
    ArcGraph l2(graph);
    SetGraph l3(graph);
    assert(BFS(l1, st, fin) == 4);
    assert(BFS(l2, st, fin) == 4);
    assert(BFS(l3, st, fin) == 4);
  }
  {
    std::stringstream input;
    std::stringstream output;
    input << "7\n"
          << "8\n"
          << "0 1\n"
          << "0 2\n"
          << "1 3\n"
          << "2 3\n"
          << "3 4\n"
          << "3 5\n"
          << "4 6\n"
          << "5 6\n";
    int v, n;
    input >> v >> n;
    MatrixGraph graph(v);
    for (int i = 0; i < n; ++i) {
      int v1, v2;
      input >> v1 >> v2;
      graph.AddEdge(v1, v2);
      graph.AddEdge(v2, v1);
    }
    std::vector<int> l0 = {1, 2};
    std::vector<int> l1 = {0, 3};
    std::vector<int> l2 = {0, 3};
    assert(graph.GetPrevVertices(0) == l0);
    assert(graph.GetPrevVertices(1) == l1);
    assert(graph.GetPrevVertices(2) == l2);
  }
}

int main() {
  test();
  std::cout << "Its okey!";
  return 0;
}
