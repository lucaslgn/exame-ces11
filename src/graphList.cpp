#include "graphList.hpp"

#include <algorithm>
#include <stdexcept>
#include <queue>
#include <limits>

Graph::Graph(std::size_t n) :
        edge_list_(n) {}

bool compareDestinations(Edge a, Edge b) {
    if (a.destination < b.destination)
        return true;
    return false;
}

Edge Graph::edge(std::size_t from, std::size_t to) const {
    check_vertex(from);
    check_vertex(to);
    Edge tempEdge = {to, 1}; // O peso da aresta não importa para a comparação

    // assumindo que a lista está ordenada
    auto lb = std::lower_bound(
            edge_list_[from].begin(), edge_list_[from].end(),
            tempEdge, compareDestinations);
    if (lb != edge_list_[from].end() && lb->destination == to)
        return *lb;
    return {from, -1.0};
}

void Graph::add_edge(std::size_t from, std::size_t to, double weight) {
    add_edge_directed(from, to, weight);
    add_edge_directed(to, from, weight);
}

void Graph::rem_edge(std::size_t from, std::size_t to) {
    rem_edge_directed(from, to);
    rem_edge_directed(to, from);
}

std::vector<Edge> Graph::edgesFrom(std::size_t v) const {
    check_vertex(v);
    return edge_list_[v];
}

std::size_t Graph::order() const {
    return edge_list_.size();
}

std::vector<std::size_t> Graph::dijkstra(std::size_t from, std::size_t to) const {
    std::vector<std::size_t> previous(order(), order()); // φ = order()
    std::vector<double> distances(order(), std::numeric_limits<double>::max());
    std::vector<bool> visited(order(), false);
    std::priority_queue<std::pair<double, std::size_t>, std::vector<std::pair<double, std::size_t>>, std::greater<>> toBeVisited;
    toBeVisited.push({0.0, from});
    distances[from] = 0.0;
    while (!toBeVisited.empty()) {
        auto v = toBeVisited.top().second;
        toBeVisited.pop();
        if (visited[v])
            continue;
        visited[v] = true;
        auto edges = edgesFrom(v);
        for (const auto &edge: edges) {
            auto x = edge.destination;
            if (visited[x])
                continue;
            if (distances[v] + edge.weight < distances[x]) {
                distances[x] = distances[v] + edge.weight;
                previous[x] = v;
                toBeVisited.push({distances[x], x});
            }
        }
    }

    // Recuperação do caminho
    std::stack<std::size_t> S;
    std::size_t v = to;
    while (previous[v] != order()) {
        S.push(previous[v]);
        v = previous[v];
    }
    std::vector<std::size_t> result;
    while (!S.empty()) {
        result.push_back(S.top());
        S.pop();
    }
    return result;
}

void Graph::add_edge_directed(std::size_t from, std::size_t to, double weight) {
    check_vertex(from);
    check_vertex(to);
    Edge newEdge = {to, weight}; // O peso da aresta não importa para a comparação

    auto lb = std::lower_bound(
            edge_list_[from].begin(),
            edge_list_[from].end(),
            newEdge, compareDestinations);

    if (lb != edge_list_[from].end() && lb->destination == to) {
        *lb = newEdge; // se já existe aresta, atualiza o valor do peso
        return;
    }
    edge_list_[from].insert(lb, newEdge);
}

void Graph::rem_edge_directed(std::size_t from, std::size_t to) {
    check_vertex(from);
    check_vertex(to);
    Edge tempEdge = {to, 1}; // O peso da aresta não importa para a comparação

    auto lb = std::lower_bound(
            edge_list_[from].begin(),
            edge_list_[from].end(),
            tempEdge, compareDestinations);

    if (lb != edge_list_[from].end() && lb->destination != to)
        return; // não encontrou

    edge_list_[from].erase(lb);
}

void Graph::check_vertex(std::size_t v) const {
    if (v >= order()) {
        throw std::out_of_range{"vertex does not exist"};
    }
}