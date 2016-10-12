#include <iostream>
#include <vector>

//Граф храним в виде вектора списка смежных вершин

struct  Edge
{
    unsigned vertexTo;
    unsigned length;
    Edge(unsigned _num = 0, unsigned _length = 0):
            vertexTo(_num), length(_length)
    {}
};

std::vector<unsigned> Dijkstra(std::vector<std::vector<Edge> > graph, unsigned inputV)
{
    int size = result.size();
    std::vector<unsigned> result(size, std::numeric_limits<unsigned>::max());
    result[inputV] = 0;

    for (auto v: graph[inputV])
        result[v.vertexTo] = v.length;

    for (int i = 0; i != size; ++i)
    {
        for (auto iEdge: graph[i]) {
            if ((result[i] + iEdge.length) < (result[iEdge.vertexTo]))
                result[iEdge.vertexTo] = result[i] + iEdge.length;
        }
    }
    return result;
}


