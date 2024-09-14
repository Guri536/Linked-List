#include<bits/stdc++.h>
using namespace std;

template<typename data_type>
struct _node {
    data_type data{};
    _node<data_type>* link = nullptr;
    _node(data_type value) : data(value) {}
};

template<typename s_data_type>
struct linked_list {
private:
    typedef _node<s_data_type> node;
    typedef s_data_type dt;
    int _size{};
    node* head = nullptr;
    node* last = nullptr;

public:

    struct Iterator {
    private:
        node* ptr;
    public:
        Iterator(node* _ptr) : ptr(_ptr) {}
        dt operator*() { return ptr->data; }
        node* operator->() { return ptr; }
        Iterator* operator++() { ptr = ptr->link; return this; }
        Iterator* operator++(int) { return ++ * this; }
        bool operator!=(Iterator check) { return !(&(*ptr) == &(*check.ptr)); }
    };

    Iterator begin() { return Iterator(head); }
    Iterator end() { return Iterator(last); }

    template<typename ...Args> linked_list(Args ...arg) { (append(arg), ...); }
    template<typename ...Args> void append(const dt val, const Args ...arg) {
        append(val);
        append(arg...);
    }

    dt operator[](const int index) {
        linked_list::Iterator iter = begin();
        for (int i{ index }; i > 0; i--) { iter++; }
        return *iter;
    }

    void append(const dt value) {
        if (this->head == nullptr) {
            head = new node(value);
            last = head;
        }
        else {
            last->link = new node(value);
            last = last->link;
        }
        _size++;
    }

    int size() { return _size; }

    void print() {
        std::print("{} ", "{");
        for (linked_list::Iterator iter = begin(); iter != nullptr; iter++) {
            std::print("{} ", *iter);
        }
        std::print("{}", "}");
    }
};

int main() {
    linked_list<int> list(1, 2, 3);
    list.append(4, 5);
    // cout << list.size() << "\n";
    list.print();
    println();
    for (int i{}; i < list.size(); i++) {
        cout << list[i] << " ";
    }
    println();

    // linked_list<string> list("123", "Such a", "Why does this work");
    // list.print();
    // list.append("hmm");
    // list.append("wooowowow", "Please Work");
    // list.append("No");
    // println();
    // list.print();

    // linked_list<float> list(4.2, 0.123, 9.1233);
    // list.print();

    return 0;
}