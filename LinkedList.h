#pragma once
#include <iostream>
using namespace std;

// Class Node
template <typename Temp>
class Node
{
public:
    Temp data;        // Dữ liệu là một đối tượng kiểu Temp (Book hoặc User)
    Node<Temp> *next; // Con trỏ trỏ đến phần tử tiếp theo

    Node(Temp d);
};

template <typename Temp>
Node<Temp>::Node(Temp d)
{
    this->data = d;
    this->next = NULL;
}

// Class Linked list
template <typename Temp>
class LinkedList
{
private:
    Node<Temp> *head; // Con trỏ trỏ đến phần tử đầu tiên của danh sách

public:
    // Constructor: Khởi tạo danh sách rỗng
    LinkedList();
    // Destructor: Giải phóng bộ nhớ
    ~LinkedList();

    //Em Hoàng thêm vào
    Node getNode(int index);

    int getSize();

    // Thêm phần tử vào cuối danh sách
    void addTail(Temp data);

    // Xóa phần tử theo ID (giả sử đối tượng T có phương thức getId())
    void removeById(string id);

    // Tìm phần tử theo ID
    Temp *findById(string id);

    // Hiển thị toàn bộ danh sách
    void display();
};

//Em Hoàng thêm
template<typename Temp>
Node LinkedList<Temp>::getNode(int index) {
    if(index < 0 || index >= size) throw std::out_of_range("Chỉ số không hợp lệ!");
    Node<Temp> *curr = head;
    for (int i = 0; i < index; ++i) current = current->next;  
    return current->data;  
}
template<typename Temp>
int LinkedList<Temp>::getSize() {
    int size = 0;
    Node<Temp> *curr = head;
    while(curr) {
        size++;
        curr = curr->next;
    }
    return size;  
}

// Constructor: Khởi tạo danh sách rỗng
template<typename Temp>
LinkedList<Temp>::LinkedList() {
    this->head = NULL;
}

// Destructor: Giải phóng bộ nhớ
template<typename Temp>
LinkedList<Temp>::~LinkedList()
{
    Node<Temp> *current = head;
    Node<Temp> *nextNode;

    while (current != nullptr)
    {
        nextNode = current->next;
        delete current;
        current = nextNode;
    }
}

// Thêm phần tử vào cuối danh sách
template<typename Temp>
void LinkedList<Temp>::addTail(Temp data)
{
    Node<Temp> *newNode = new Node<Temp>(data);
    if (head == nullptr)
    {
        head = newNode; // Nếu danh sách rỗng, thêm phần tử đầu tiên
    }
    else
    {
        Node<Temp> *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode; // Thêm phần tử vào cuối
    }
}

// Xóa phần tử theo ID (giả sử đối tượng T có phương thức getId())
template<typename Temp>
void LinkedList<Temp>::removeById(string id)
{
    if (head == nullptr)
        return; // Danh sách rỗng

    // Nếu phần tử đầu tiên cần xóa
    if (head->data.getId() == id)
    {
        Node<Temp> *temp = head;
        head = head->next;
        delete temp;
        return;
    }

    // Tìm phần tử cần xóa
    Node<Temp> *current = head;
    while (current->next != nullptr && current->next->data.getId() != id)
    {
        current = current->next;
    }

    // Xóa phần tử nếu tìm thấy
    if (current->next != nullptr)
    {
        Node<Temp> *temp = current->next;
        current->next = current->next->next;
        delete temp;
    }
}

// Tìm phần tử theo ID
template<typename Temp>
Temp* LinkedList<Temp>::findById(string id)
{
    Node<Temp> *temp = head;
    while (temp != nullptr)
    {
        if (temp->data.getId() == id)
        {
            return &temp->data; // Trả về con trỏ tới đối tượng tìm thấy
        }
        temp = temp->next;
    }
    return nullptr; // Không tìm thấy
}

// Hiển thị toàn bộ danh sách
template<typename Temp>
void LinkedList<Temp>::display()
{
    Node<Temp> *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data.getDetails() << endl;
        temp = temp->next;
    }
}
