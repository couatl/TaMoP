
#include <iostream>

using namespace std;

class Stack
{
    int *_array;
    const size_t _size;
    size_t cur_size;
public:
    Stack(size_t size = 100):
        _size(size)
    {
        _array = new int[_size];
        cur_size = 0;
    }
    ~Stack()
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
            std::cout << "Stack is fool" << std::endl;
    }
    void pop()
    {
        if(!empty())
        {
            _array[cur_size] = 0;
            cur_size--;
        }
        else
            std::cout << "Stack is empty" << std::endl;
    }
    int getTop()
    {
        if(!empty())
            return _array[cur_size-1];
        else
        {
            std::cout << "Stack is empty" << std::endl;
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

} Stack;

int main() {
    size_t n;
    string line;
    int data;
    cin >> n;
    for (size_t i = 0; i < n; i++) {
        cin >> line;
        if (line == "add") {
            cin >> data;
            Stack.push(data);
        }
        else if (line == "get") {
            Stack.getTop();
        }
        else if (line == "del") {
            Stack.pop();
        }
        else
        {
            cout << "No such command" << endl;
            return 1;
         }
    }

    return 0;
}
