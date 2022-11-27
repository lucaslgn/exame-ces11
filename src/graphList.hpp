#pragma once

#include <vector>
#include <stack>
#include <algorithm>
#include <stdexcept>
#include <queue>
#include <limits>

// Lista de adjacências
// Sem arestas múltiplas
// Com peso nas arestas (por padrão é 1)

struct Edge {
    std::size_t destination;
    double weight;
};

class Graph {
public:
    Graph();
    Graph(const std::size_t &n);

    Edge edge(const std::size_t &from, const std::size_t &to) const;
    // Se a aresta não existir, retorna um Edge com destination = from e weight = -1.0

    void add_edge(const std::size_t &from, const std::size_t &to, const double &weight = 1);
    void rem_edge(const std::size_t &from, const std::size_t &to);

    std::vector<Edge> edgesFrom(const std::size_t &v) const;

    std::size_t order() const;

    std::vector<std::size_t> dijkstra(const std::size_t &from, const std::size_t &to) const;

private:
    void add_edge_directed(const std::size_t &from, const std::size_t &to, const double &weight);
    void rem_edge_directed(const std::size_t &from, const std::size_t &to);
    void check_vertex(const std::size_t &v) const;

    std::vector<std::vector<Edge>> edge_list_;
};
