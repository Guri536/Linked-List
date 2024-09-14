#include<bits/stdc++.h>
using namespace std;

template<typename data_type>
struct _node {
    data_type data{};
    _node<data_type>* link = nullptr;
    _node(data_type value) : data(value) {}
    ~_node() {
        if (link != nullptr)
            delete link;
    }
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
    template<typename ...Args> void appends(Args ...arg) { (append(arg), ...); }

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

    void end_update() {
        while (last->link != nullptr) { last = last->link; }
    }

    int size() { return _size; }

    void print() {
        std::print("{} ", "{");
        for (linked_list::Iterator iter = begin(); iter != nullptr; iter++) {
            std::print("{} ", *iter);
        }
        std::print("{}", "}");
    }

    void insert(const int index, const dt value) {
        node* temp = new node(value);
        if (index == 0) {
            temp->link = head;
            head = temp;
        }
        else {
            linked_list::Iterator iter = begin();
            for (int i{}; i < index - 1; i++) { iter++; }
            temp->link = iter->link;
            iter->link = temp;
            end_update();
        }
        _size++;
    }

    void replace(const int index, const dt value) {
        linked_list::Iterator iter = begin();
        for (int i{}; i < index; i++) { iter++; }
        iter->data = value;
    }

    void clear() {
        delete head;
        head = nullptr;
        last = nullptr;
    }

    int find(const int val, const int skip){
        
    }
};

int main() {
    linked_list<int> list(1, 2, 3);
    list.appends(4, 5);
    cout << list.size() << "\n";
    list.print();

    println("\n\nIndexing Test:");
    for (int i{}; i < list.size(); i++) {
        cout << list[i] << " ";
    }

    println("\n\nInsertion Test: ");
    list.insert(0, 99);
    list.insert(list.size() / 2, 98);
    list.insert(list.size(), 97);
    list.print();

    println("\n\nReplace by Index Test:");
    list.replace(3, 7);
    list.replace(0, 1);
    list.replace(list.size() - 1, 100);
    list.print();

    println("\n\nClear Test:");
    list.clear();
    list.print();

    println("\n\nReAdding Elements:");
    list.appends(1, 2, 3, 4, 5);
    list.print();

    println("\n\nStrings:");
    linked_list<string> list2("123", "Such a", "Why does this work");
    list2.print();
    list2.appends("wooowowow", "Please Work");
    println();
    list2.print();

    // linked_list<float> list(4.2, 0.123, 9.1233);
    // list.print();

    return 0;
}