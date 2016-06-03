#include <iostream>
#include <string>

using namespace std;
struct Node
{
    int _data;
    Node* _next;
    Node(int data): _data(data), _next(nullptr)
    {}
    Node(int data, Node* next): _data(data), _next(next)
    {}
};

class List
{
    Node* _head;
    size_t size;
public:
    List() : _head(nullptr)
    {
        size = 0;
    }
    List(int data)
    {
        _head = new Node(data);
        size = 1;
    }
    List(Node* node): _head(node)
    {
        size = 1;
    }
    List(const List& other): _head(other._head), size(other.size)
    {}
    ~List()
    {
        if (size == 0) return;
        while(_head)
        {
            Node* t = _head;
            _head = _head->_next;
            delete t;
        }
    }
    Node* AddNth(int data, size_t n)
    {
        if (n <= (size-1))
        {
            size_t i = 0;
            Node *t = _head;
            while (!(i == (n-1)))
            {
                t = t->_next;
                i++;
            }
            t->_next = new Node(data, t->_next);
            size++;
            return t->_next;
        }
        else
        {
            return nullptr;
        }
    }
    int GetNth(size_t n) const
    {
        if(n <= (size-1))
        {
            size_t i = 0;
            Node *t = _head;
            while (!(i == n))
            {
                t = t->_next;
                i++;
            }
            return t->_data;
        }
        else
        {
            return 0;
        }
    }
    void DeleteNth(size_t n)
    {
        if (!_head) return;
        if(n <= (size-1))
        {
            if (n == 0)
            {
                Node *t = _head;
                _head = t->_next;
                delete t;
                return;
            }
            size_t i = 0;
            Node* t = _head;
            while (!(i == (n-1)))
            {
                t = t->_next;
                i++;
            }
            Node *t1 = t->_next;
            t->_next = t1->_next;
            delete t1;
            size--;
        }
        else
        {
            return;
        }
    }
} List;

int main() {
    size_t n;
    int ind;
    string line;
    int data;
    cin >> n;
    for (size_t i = 0; i < n; i++) {
        cin >> line;
        if (line == "add") {
            cin >> ind >> data;
            List.AddNth(data, ind);
        }
        else if (line == "get") {
            cin >> ind;
            List.GetNth(ind);
        }
        else if (line == "del") {
            cin >> ind;
            List.DeleteNth(ind);
        }
        else
        {
            cout << "No such command" << endl;
            return 1;
         }

    }

    return 0;
}

