#include <vector>
#include <stack>

// Lista de adjacências
// Sem arestas múltiplas
// Com peso nas arestas (por padrão é 1)

struct Edge {
    std::size_t destination;
    double weight;
};

class Graph {
public:
    Graph(std::size_t n);

    Edge edge(std::size_t from, std::size_t to) const;
    // Se a aresta não existir, retorna um Edge com destination = from e weight = -1.0

    void add_edge(std::size_t from, std::size_t to, double weight = 1);
    void rem_edge(std::size_t from, std::size_t to);

    std::vector<Edge> edgesFrom(std::size_t v) const;

    std::size_t order() const;

    std::vector<std::size_t> dijkstra(std::size_t from, std::size_t to) const;

private:
    void add_edge_directed(std::size_t from, std::size_t to, double weight);
    void rem_edge_directed(std::size_t from, std::size_t to);
    void check_vertex(std::size_t) const;

    std::vector<std::vector<Edge>> edge_list_;
};
