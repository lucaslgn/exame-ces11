#include <vector>
#include <stack>

// Lista de adjacências
// Sem arestas múltiplas
// Sem peso nas arestas
class Graph {
public:
    Graph(std::size_t n);

    bool edge_exists(std::size_t from, std::size_t to) const;
    void add_edge(std::size_t from, std::size_t to);
    void rem_edge(std::size_t from, std::size_t to);

    std::vector<std::size_t> neighbors(std::size_t v) const;

    std::size_t order() const;

private:
    void add_edge_directed(std::size_t from, std::size_t to);
    void rem_edge_directed(std::size_t from, std::size_t to);

    void check_vertex(std::size_t) const;

    std::vector<std::vector<std::size_t>> adj_list_;
};
