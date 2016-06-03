#include <iostream>

using namespace std;

class Queue
{
    int *_array;
    int _top; //index of the first to out
    const size_t _size;
    size_t cur_size;
public:
    Queue(size_t size = 100):
        _size(size)
    {
        _array = new int[_size];
        _top = 0;
        cur_size = 0;
    }
    ~Queue()
    {
        delete [] _array;
    }
    void push(int data)
    {
        if (!fool())
        {
            _array[cur_size] = data;
            cur_size++;
        }
        else
            std::cout << "Queue is fool" << std::endl;
    }
    void pop()
    {
        if(!empty())
        {
            _array[_top] = 0;
            _top++;
            cur_size--;
        }
        else
            std::cout << "Queue is empty" << std::endl;
    }
    int getTop()
    {
        if(!empty())
            return _array[_top];
        else
        {
            std::cout << "Queue is empty" << std::endl;
            return 0;
        }
    }
    bool empty()
    {
        return cur_size == 0 ? true : false;
    }
    bool fool()
    {
        return cur_size == _size ? true : false;
    }

} Queue;

int main() {
    size_t n;
    string line;
    int data;
    cin >> n;
    for (size_t i = 0; i < n; i++) {
        cin >> line;
        if (line == "add") {
            cin >> data;
            Queue.push(data);
        }
        else if (line == "get") {
            Queue.getTop();
        }
        else if (line == "del") {
            Queue.pop();
        }
        else
        {
            cout << "No such command" << endl;
            return 1;
         }
    }

    return 0;
}
