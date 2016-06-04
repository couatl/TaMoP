#include <iostream>

using namespace std;

class Tree {
private:
    int* data;
    size_t n;
public:
    Tree(int* tmp, size_t number) :
        data(tmp), n(number)
    {};
    void direct(int key) const
    {
        for (size_t i = 0; i < n; i++) {
            if (data[i] == key) {
                cout << i << ' ';
                direct(i);
            }
        }
    }
    void reverse(int key) const
    {
        for (size_t i = 0; i < n; i++) {
            if (data[i] == key) {
                reverse(i);
            }
        }
        if (key != -1) {
            cout << key << ' ';
        }
    }
    void symmetric(int key) const
    {
        size_t x = 0;
        for (size_t i = 0; i < n; i++) {
            if (data[i] == key) {
                symmetric(i);
                if ((!x) && (key != -1)) {
                    cout << key << ' ';
                }
                x++;
            }
        }
        if (x == 0) {
            cout << key << ' ';
        }
    }
};

int main() {
    size_t n;
    cin >> n;
    int* tree = new int[n];
    for (size_t i = 0; i < n; i++) {
        cin >> tree[i];
    }

    Tree t(tree, n);

    t.direct(-1);
    cout << endl;

    t.reverse(-1);
    cout << endl;

    t.symmetric(-1);
    cout << endl;

    delete[] tree;
    system("pause");
    return 0;
}

