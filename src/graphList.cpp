#include "graphList.hpp"

#include <algorithm>
#include <stdexcept>

Graph::Graph(std::size_t n) :
  adj_list_(n) {}

bool Graph::edge_exists(std::size_t from, std::size_t to) const
{
    check_vertex(from);
    check_vertex(to);
    // assumindo que a lista está ordenada
    return std::binary_search(
            adj_list_[from].begin(),
            adj_list_[from].end(),
            to);
}

void Graph::add_edge(std::size_t from, std::size_t to) {
    add_edge_directed(from, to);
    add_edge_directed(to, from);
}

void Graph::rem_edge(std::size_t from, std::size_t to) {
    rem_edge_directed(from, to);
    rem_edge_directed(to, from);
}

std::vector<std::size_t> Graph::neighbors(std::size_t v) const {
    check_vertex(v);
    return adj_list_[v];
}

std::size_t Graph::order() const {
    return adj_list_.size();
}

void Graph::add_edge_directed(std::size_t from, std::size_t to) {
    check_vertex(from);
    check_vertex(to);
    auto lb = std::lower_bound(
            adj_list_[from].begin(),
            adj_list_[from].end(),
            to);

    if (lb != adj_list_[from].end() && *lb == to)
        return;

    adj_list_[from].insert(lb, to);
}

void Graph::rem_edge_directed(std::size_t from, std::size_t to) {
    check_vertex(from);
    check_vertex(to);
    auto lb = std::lower_bound(
            adj_list_[from].begin(),
            adj_list_[from].end(),
            to);

    if (lb != adj_list_[from].end() && *lb != to)
        return;

    adj_list_[from].erase(lb);
}

void Graph::check_vertex(std::size_t v) const {
    if (v >= order()) {
        throw std::out_of_range{"vertex does not exist"};
    }
}