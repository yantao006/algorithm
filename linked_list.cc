#include <iostream>
#include <vector>
#include <string>

class Node {
public:
    Node() : _value(0), _next(nullptr) {}
    ~Node() {}
public:
    int32_t _value;
    Node* _next;
};

class LinkedList {
private:
    Node* head;
    int pos;
    int length;
public:
    LinkedList() {
        // 头结点不参与计数
        head = new Node();
        head->_value = 0;
        head->_next = nullptr;
        pos = 0;
        length = 0;
    }
    ~LinkedList() { delete head; }
    void create(std::vector<int32_t>& input);
    void insert(int32_t pos, int32_t value);
    void print(); // 遍历打印
    bool is_empty();
    int32_t get_length() { return length; }
    void delete_node(int32_t pos);
    void delete_list();
};

void LinkedList::create(std::vector<int32_t>& input) {
    if (input.size() == 0) {
        return;
    }
    Node* p_tmp = head;
    for (auto& it : input) {
        Node* p_new = new Node();
        p_new->_value = it;

        head->_next = p_new;
        head = head->_next;
        length++;
    }
    head = p_tmp;
    return;
}

void LinkedList::print() {
    std::string print_log;
    print_log.append("head->");
    if (head->_next == nullptr) {
        print_log.append("tail");
        std::cout << print_log << std::endl;
        return;
    }
    Node* tmp = head;
    while (tmp->_next != nullptr) {
        print_log.append(std::to_string(tmp->_next->_value)).append("->");
        tmp = tmp->_next;
    }
    print_log.append("tail");
    std::cout << print_log << std::endl;
    return;
}

bool LinkedList::is_empty() {
    if (head->_next == nullptr) {
        return true;
    } else {
        return false;
    }
}

void LinkedList::insert(int32_t pos, int32_t value) {
    if (pos < 0 || pos > length + 1) { 
        std::cout << "invalid pos" << std::endl;
        return;
    }
    Node* p_new = new Node();
    p_new->_value = value;

    Node* tmp = head;
    while (pos-- > 1) { // 当pos=0/1时，均表示插在head后的第1个位置
        tmp = tmp->_next;
    }
    p_new->_next = tmp->_next;
    tmp->_next = p_new;
    length++;
}

void LinkedList::delete_node(int32_t pos) {
    if (pos <= 0 || pos > get_length()) {
        std::cout << "invalid pos" << std::endl;
        return;
    }
    Node* tmp = head;
    while (pos-- > 1 ) { // 遍历获取指定pos的上一个node
        tmp = tmp->_next;
    }
    Node* tmp_next = tmp->_next->_next;
    delete tmp->_next;
    tmp->_next = tmp_next;
    length--;
}

void LinkedList::delete_list() {
    Node* p_delete = head->_next;
    while(p_delete != nullptr) {
        Node* tmp = p_delete->_next;
        delete p_delete;
        p_delete = tmp;
        head->_next = tmp;
    }
}

// 测试
int main(int argc, char* argv[]) {
    LinkedList list;
    std::vector<int32_t> input = {3, 2, 8, 6, 5, 9};
    list.create(input);
    list.print();
    std::cout << "length:" << list.get_length() << std::endl;    
    list.insert(7, 10);
    list.print();
    std::cout << "length:" << list.get_length() << std::endl;    
    list.delete_node(7);
    list.print();
    list.delete_list();
    list.print();
    return 0;
}

/*
 * head->3->2->8->6->5->9->tail
 * length:6
 * head->3->2->8->6->5->9->10->tail
 * length:7
 * head->3->2->8->6->5->9->tail
 * head->tail
 */

// gcc -g -lstdc++ -std=c++11 main_test.cc -o test -lm
