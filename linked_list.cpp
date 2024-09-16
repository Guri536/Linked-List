#include<bits/stdc++.h>
using namespace std;

struct mydt {
    int a{};
    string b;
    mydt(int i, string j) : a(i), b(j) {}
};

void operator<<(ostream& out, mydt obj) {
    std::print("Id: {}\nName: {}", obj.a, obj.b);
}

void operator<<(ostream&, vector<int>& obj) {
    for (int i : obj) { cout << i << " "; }
}


template<typename data_type>
struct _node {
    data_type data{};
    _node<data_type>* link = nullptr;
    _node(data_type value) : data(value) {}
    _node(data_type value, _node<data_type>* _link) : data(value), link(_link) {}
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
        dt* operator*() { return &(ptr->data); }
        node* operator->() { return ptr; }
        Iterator* operator++() { ptr = ptr->link; return this; }
        Iterator* operator++(int) { return ++ * this; }
        bool operator!=(Iterator check) { return !(&(*ptr) == &(*check.ptr)); }
    };

    Iterator begin() { return Iterator(head); }
    Iterator end() { return Iterator(last); }

    template<typename ...Args> linked_list(Args ...arg) { (append(arg), ...); }
    template<typename ...Args> void appends(Args ...arg) { (append(arg), ...); }

    dt* operator[](const int index) {
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

    void prepend(const dt value) {
        head = new node(value, head);
        _size++;
    }

    void end_update() noexcept {
        while (last->link != nullptr) { last = last->link; }
    }

    int size() { return _size; }

    template <typename T, typename N = void>
    struct check : false_type {};

    template <typename T>
    struct check<T, typename enable_if<is_same<decltype((declval<std::ostream&>()) << (declval<T>())), ostream&>::value>::type>
        : true_type {};

    // void print() {
    template<typename T = void>
    auto print() noexcept -> enable_if<check<dt>::value, T>::type {
        std::print("{} ", "{");
        for (linked_list::Iterator iter = begin(); iter != nullptr; iter++) {
            cout << **iter; cout << " ";
        }
        std::print("{}", "}");
    }
    template<typename T = void>
    auto print() noexcept -> enable_if<!check<dt>::value, T>::type {
        std::print("No Return Type for ");
        cout << typeid(dt).name();
    }

    void println() {
        print();
        std::println();
    }

    void insert(const int index, const dt value) {
        node* temp = new node(value);
        linked_list::Iterator iter = begin();
        for (int i{}; i < index - 1; i++) { iter++; }
        temp->link = (index == 0 ? head : iter->link);
        (index == 0 ? head : iter->link) = temp;
        end_update();
        _size++;
    }

    void replace(const int index, const dt value) {
        linked_list::Iterator iter = begin();
        for (int i{}; i < index; i++) { iter++; }
        iter->data = value;
    }

    void clear() noexcept {
        delete head;
        head = nullptr;
        last = nullptr;
        _size = 0;
    }

    /// @brief Returns the Index of the value if found, if not in list, returns -1
    /// @param val The value to be found
    /// @param skip Default: 0 =>If multiple of the same element exists, then the no. of skips will correspond to which one of the duplicates will be send back
    /// @return int
    int find(const dt value, int skip = 0) {
        int index{};
        for (linked_list::Iterator iter{ begin() }; iter != nullptr; iter++, index++) {
            if (*iter == value && skip-- == 0) {
                return index;
            }
        }
        return -1;
    }

    void del(const dt value) {
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
        end_update();
    }
    void delin(const int indexa, const int indexb = 1) {
        linked_list::Iterator iter{ begin() };
        for (int i{};i < indexa - 1;i++) { iter++; }
        linked_list::Iterator iter2{ iter->link };
        for (int i{};i < indexb - (indexa != 0 ? 1 : 2);i++) { iter2++; }
        (indexa == 0 ? head : iter->link) = iter2->link;
        _size -= indexb;
        end_update();
    }
};


// void operator<<(ostream& out, mydt& obj){
//     print("Id: {}\nName: ", obj.a, obj.b);
// }

int main() {
    // linked_list<mydt> list;
    // list.appends(mydt(1, "boo"), mydt(4, "wow"));
    // list.println();
    // // list.prin
    // for (int i : views::iota(0, list.size())) {
    //     cout << list[i]->b << " ";
    // }
    // println();
    // linked_list<int> list2;
    // list2.appends(7, 2, 2, 4, 12, 5);
    // list2.println();
    linked_list<vector<int>> list3;
    list3.appends(vector<int>{1, 2, 3});
    list3.print();
    return 0;
}