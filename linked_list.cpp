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

    /// @brief Returns the Index of the value if found, if not in list, returns -1
    /// @param val The value to be found
    /// @param skip Default: 0 =>If multiple of the same element exists, then the no. of skips will correspond to which one of the duplicates will be send back
    /// @return int
    int find(const int value, int skip = 0) {
        int index{};
        for (linked_list::Iterator iter{ begin() }; iter != nullptr; iter++, index++) {
            if (*iter == value && skip-- == 0) {
                return index;
            }
        }
        return -1;
    }

    void del(const int value) {
        linked_list::Iterator iter{ begin() };
        if (*iter == value) {
            head = iter->link;
        }
        else {
            while (iter->link->data != value) { iter++; }
            node* temp = iter->link;
            iter->link = iter->link->link;
        }
        _size--;
    }

    // void delin(const int indexa, const int indexb = 0) {
    //     linked_list::Iterator
    //     for (int i{};i < indexa;i++) {}

    // }
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

    println("\n\nFinding:\n1 at {}\n3 at {}\n5 at {}", list.find(1), list.find(3), list.find(5));

    list.appends(4, 8, 9, 2, 0, 1, -5, 2, 5);
    println("\nAdded Elements:");
    list.print();
    print("\n\nDuplicates: \n5 at: ");
    for (int i{}, j{ 5 }; list.find(j, i) != -1;i++) {
        cout << list.find(j, i) << " ";
    }

    println("\n\nDelete Values");
    list.del(1);
    list.del(8);
    list.del(5);
    list.print();

    println("\n\nDelete from Indexes");

    println("\n\n\n\nStrings:");
    linked_list<string> list2("123", "Such a", "Why does this work");
    list2.print();
    list2.appends("wooowowow", "Please Work");
    println();
    list2.print();

    println("\n\nFloats:");
    linked_list<float> list3(4.2, 0.123, 9.1233);
    list3.print();

    return 0;
}