#pragma once
#include <iostream>
using namespace std;

// Định nghĩa template cho lớp node
template <typename T>
class node
{
private:
    T data;              // Dữ liệu của node
    node<T> *next;       // Con trỏ đến node kế tiếp
    node<T> *prev;       // Con trỏ đến node trước đó

public:
    // Các constructor của node
    node(); 
    node(node<T> *next, node<T> *prev, T data);

    // Các phương thức getter và setter cho dữ liệu và liên kết
    void setData(T data);
    T getData();
    void setNext(node<T> *next);
    node<T> *getNext();
    void setPrev(node<T> *prev);
    node<T> *getPrev();

    // Phương thức in dữ liệu của node, được định nghĩa đặc biệt cho từng loại
    void print(node<T> *tmp);

    // Định nghĩa các toán tử so sánh == và != giữa các node
    bool operator!=(const node<T> &other) const;
    bool operator==(const node<T> &other) const;

    // Khai báo LinkedList là friend class để có thể truy cập các thành viên private
    friend class LinkedList<T>;
};

// Lớp LinkedList được định nghĩa như một template
template <typename T>
class LinkedList
{
private:
    node<T> *head;   // Con trỏ đầu danh sách
    node<T> *tail;   // Con trỏ cuối danh sách
    int count;       // Số lượng node trong danh sách

public:
    // Constructor và Destructor để quản lý bộ nhớ
    LinkedList();
    ~LinkedList();

    // Các phương thức getter và setter cho head và tail
    void setHead(node<T> *head);
    void setTail(node<T> *tail);
    node<T> *getHead();
    node<T> *getTail();

    // Phương thức tìm kiếm node theo ID
    node<T> *get(string ID);
    node<T> *getAvailable(string ID); // Tìm sách còn có số lượng

    // Phương thức in dữ liệu các node
    void printNext();                // In tất cả node
    void printNextAvailable();       // In các node có sách còn số lượng

    // Phương thức thêm một node vào cuối danh sách
    void addTail(T data);

    // Getter và setter cho biến đếm số node
    int getCount();
    void setCount(int count);
};

// Constructor mặc định của node
template <typename T>
node<T>::node() {}

// Constructor có tham số của node
template <typename T>
node<T>::node(node<T> *next, node<T> *prev, T data)
{
    this->data = data;
    this->next = next;
    this->prev = prev;
}

// Setter và getter cho con trỏ next
template <typename T>
void node<T>::setNext(node<T> *next)
{
    this->next = next;
}

template <typename T>
node<T> *node<T>::getNext()
{
    return next;
}

// Setter và getter cho con trỏ prev
template <typename T>
void node<T>::setPrev(node<T> *prev)
{
    this->prev = prev;
}

template <typename T>
node<T> *node<T>::getPrev()
{
    return prev;
}

// Setter và getter cho dữ liệu của node
template <typename T>
void node<T>::setData(T data)
{
    this->data = data;
}

template <typename T>
T node<T>::getData()
{
    return data;
}

// Phương thức in thông tin của đối tượng User
template <>
void node<User>::print(node<User> *tmp)
{
    cout << "User ID: " << tmp->getData().getID() << endl;
    cout << "Name: " << tmp->getData().getName() << endl;
    cout << "Date of Birth: " << tmp->getData().getDob() << endl;
    cout << "Phone Number: " << tmp->getData().getPhone() << endl;
    cout << "Number of Borrowed Books: " << tmp->getData().getNumborrow() << endl;
    cout << "Number of Requests: " << tmp->getData().getNumrequest() << endl;
    cout << "----------------------------------------" << endl;
}

// Phương thức in thông tin của đối tượng Book
template <>
void node<Book>::print(node<Book> *tmp)
{
    cout << "Book ID: " << tmp->getData().getID() << endl;
    cout << "Title: " << tmp->getData().getName() << endl;
    cout << "Category: " << tmp->getData().getCategory() << endl;
    cout << "Publisher: " << tmp->getData().getPublisher() << endl;
    cout << "Publication Year: " << tmp->getData().getYear() << endl;
    cout << "Author: " << tmp->getData().getAuthor() << endl;
    cout << "Location: " << tmp->getData().getlocation() << endl;
    cout << "Available Copies: " << tmp->getData().getAmount() << endl;
    cout << "Total Copies: " << tmp->getData().getfixedAmount() << endl;
    cout << "----------------------------------------" << endl;
}

// Toán tử so sánh != giữa hai node
template <typename T>
bool node<T>::operator!=(const node<T> &other) const
{
    return data != other.data;  // So sánh dựa trên dữ liệu của node
}

// Toán tử so sánh == giữa hai node
template <typename T>
bool node<T>::operator==(const node<T> &other) const
{
    return data == other.data;  // So sánh dựa trên dữ liệu của node
}

// Constructor mặc định của LinkedList
template <typename T>
LinkedList<T>::LinkedList()
{
    head = NULL;
    tail = NULL;
    count = 0;
}

// Destructor để giải phóng bộ nhớ của tất cả các node trong danh sách
template <typename T>
LinkedList<T>::~LinkedList() {
    node<T> *tmp;
    while (head != NULL) {
        tmp = head;
        head = head->getNext();
        delete tmp;  // Giải phóng bộ nhớ của từng node
    }
}

// Setter và getter cho tail
template <typename T>
void LinkedList<T>::setTail(node<T> *tmp)
{
    this->tail = tmp;
}

// Setter và getter cho head
template <typename T>
void LinkedList<T>::setHead(node<T> *tmp)
{
    this->head = tmp;
    this->head->setPrev(NULL);  // Head không có node trước nó
}

template <typename T>
node<T> *LinkedList<T>::getHead()
{
    return head;
}

template <typename T>
node<T> *LinkedList<T>::getTail()
{
    return tail;
}

// Tìm kiếm node theo ID, trả về con trỏ đến node tương ứng
template <typename T>
node<T> *LinkedList<T>::get(string ID)
{
    node<T> *P;
    for (P = head; P != NULL; P = P->getNext())
    {
        if (P->getData().getID() == ID)
        {
            return P;
        }
    }
    return P;
}

// Tìm sách còn số lượng theo ID
template <typename T>
node<T> *LinkedList<T>::getAvailable(string ID)
{
    node<T> *P;
    for (P = head; P != NULL; P = P->getNext())
    {
        if (P->getData().getID() == ID && P->getData().getAmount() > 0)
        {
            return P;
        }
    }
    return P;
}

// Phương thức in thông tin tất cả các node trong danh sách
template <typename T>
void LinkedList<T>::printNext()
{
    node<T> *tmp = head;
    while (tmp != NULL)
    {
        tmp->print(tmp); // Gọi phương thức print của node
        tmp = tmp->getNext();
    }
}

// Phương thức in thông tin các node có sách còn số lượng
template <typename T>
void LinkedList<T>::printNextAvailable()
{
    node<T> *tmp = head;
    while (tmp != NULL)
    {
        // Kiểm tra điều kiện cho những book có `Amount` lớn hơn 0
        if (tmp->getData().getAmount() > 0)
        {
            tmp->print(tmp); // Gọi phương thức print cho node hiện tại
        }
        tmp = tmp->getNext();
    }
}

// Thêm một node vào cuối danh sách
template <typename T>
void LinkedList<T>::addTail(T data)
{
    node<T> *tmp = new node<T>(NULL, NULL, data);  // Tạo node mới
    if (head == NULL)
    {
        head = tail = tmp;  // Nếu danh sách rỗng, node mới là head và tail
    }
    else
    {
        tmp->setPrev(tail); // Liên kết node mới với node tail hiện tại
        tail->setNext(tmp); // Cập nhật liên kết của tail hiện tại
        tail = tmp;         // Đặt tail mới
    }
    count++; // Tăng số lượng node sau khi thêm thành công
}

// Getter cho số lượng node trong danh sách
template <typename T>
int LinkedList<T>::getCount()
{
    return count;
}

// Setter cho số lượng node trong danh sách
template <typename T>
void LinkedList<T>::setCount(int count)
{
    this->count = count;
}
