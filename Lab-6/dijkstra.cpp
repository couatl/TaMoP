#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Graph {
private:
    size_t num_root;
    size_t num_nodes;
    size_t num_edges;
    size_t** matrix;
public:
    Graph(size_t num_r, size_t nodes_num, size_t edges_num)
    {
        num_root = num_r;
        num_nodes = nodes_num;
        num_edges = edges_num;
        matrix = new size_t*[num_nodes];

        for (int i = 0; i < num_nodes; i++)
            matrix[i] = new size_t[num_nodes];

        for (int i = 0; i < num_nodes; i++)
            for (int j = 0; j < num_nodes; j++)
                matrix[i][j] = 0;
    }
    void getData(string& expression)
    {
        stringstream ss(expression);
        string item;
        while (getline(ss, item, ' '))
            data.push_back(item);
        if (data.size() != 3)
            return;
        if (stoi(data[0]) >= num_nodes || stoi(data[1]) >= num_nodes)
            return;
        matrix[stoi(data[0])][stoi(data[1])] = stoi(data[2]);
    }
    void Dijkstra_algorithm()
    {
        size_t* distances = new size_t[num_nodes];
        bool* isVisited = new bool[num_nodes];

        for (int i = 0; i < num_nodes; i++) {
            distances[i] = SIZE_MAX;
            isVisited[i] = false;
        }

        distances[num_root] = 0;
        size_t index, u;

        for (int i = 0; i < num_nodes - 1; i++) {
            size_t min = SIZE_MAX;

            for (int j = 0; j < num_nodes; j++)
                if (!isVisited[j] && distances[j] <= min) {
                    min = distances[j];
                    index = j;
                }

            u = index;
            isVisited[u] = true;

            for (int j = 0; j < num_nodes; j++)
                if (!isVisited[j] && matrix[u][j] && distances[u] != SIZE_MAX && distances[u] + matrix[u][j] < distances[j])
                    distances[j] = distances[u] + matrix[u][j];
        }

        for (int i = 0; i < num_nodes; i++)
            if (distances[i] != SIZE_MAX)
                cout << distances[i] << "  ";
            else
                cout << "inf  ";
        cout << endl;
    }
    ~Graph()
    {
        for (int i = 0; i < num_nodes; i++)
            delete matrix[i];
        delete matrix;
    }
};


int main() {
    size_t num_nodes, num_edges, num_root;
    cin >> num_nodes;
    cin >> num_edges;
    cin >> num_root;
    Graph graph(num_root, num_nodes, num_edges);
    string expression;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < num_edges; i++) {
        getline(cin, expression);
        graph.getData(expression);
    }
    graph.Dijkstra_algorithm();

    system("pause");
    return 0;
}


