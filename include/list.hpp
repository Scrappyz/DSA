#pragma once

#include <iostream>
#include <initializer_list>

template<typename T>
struct Node {
    Node<T>* prev;
    T data;
    Node<T>* next;

    Node() : prev(), data(), next() {}
    Node(const T& d) : prev(), data(d), next() {}
};

template<typename T>
class List {
    private:
        Node<T>* head_;
        Node<T>* tail_;
        int size_;
    public:
        List() : head_(), tail_(), size_() {}
        List(const List<T>& l) : head_(), tail_(), size_() 
        {
            assign(l);
        }
        List(const std::initializer_list<T>& il) : head_(), tail_(), size_() 
        {
            assign(il);
        }
        
        ~List()
        {
            clear();
        }

        Node<T>* head() const
        {
            return head_;
        }

        Node<T>* tail() const
        {
            return tail_;
        }

        int size() const
        {
            return size_;
        }

        Node<T>* node(int k) const
        {
            if(k < 0 || k > size_-1) {
                throw "[Error] Index out of range";
            }

            Node<T>* ptr;
            if(k < size_ / 2) {
                ptr = head_; // use to traverse list
                for(int i = 0; i < k; i++) {
                    if(ptr == nullptr) { // reached the end of list
                        break;
                    }
                    ptr = ptr->next; // move to next node
                }
            } else {
                ptr = tail_;
                for(int i = size_-1; i > k; i--) {
                    if(ptr == nullptr) {
                        break;
                    }
                    ptr = ptr->prev;
                }
            }

            return ptr;
        }

        Node<T>* find(const T& val) const
        {
            Node<T>* ptr = head_;
            while(ptr != nullptr && ptr->data != val) {
                ptr = ptr->next;
            }

            return ptr;
        }
        
        void append(const T& data)
        {
            Node<T>* n = new Node<T>(data); // create new node

            if(empty()) { // when list is empty
                head_ = n;
                tail_ = n;
                n->prev = nullptr;
            } else {
                tail_->next = n; // link the address of the tail_ node to the new node
                n->prev = tail_; // link the address of the new node to the previous node
                tail_ = n; // change the address of tail_ to new node
            }
            size_++;
        }

        void prepend(const T& data)
        {
            if(empty()) {
                append(data);
                return;
            }

            Node<T>* n = new Node<T>(data); // create new node
            Node<T>* temp = head_; // save the address of the current head_ node
            head_ = n; // update the head_ node to the new node
            n->next = temp; // link the new node to the previous head_ node
            temp->prev = n; // link next node to new node
            size_++;
        }

        void insert(int k, const T& data)
        {
            if(k < 0 || k > size_-1) {
                throw "[Error] Index out of range";
            }

            if(k == 0) {
                prepend(data);
                return;
            }

            Node<T>* ptr = head_;
            for(int i = 0; i < k-1; i++) { // stop at the one before
                ptr = ptr->next;
            }

            Node<T>* n = new Node<T>(data);
            n->next = ptr->next; // link new node to the next node of ptr
            ptr->next->prev = n; // link the next node of ptr to n
            n->prev = ptr; // link the new node to the ptr
            ptr->next = n; // link ptr to new node
            size_++;
        }

        void assign(const List<T>& l)
        {
            size_ = 0;
            for(Node<T>* ptr = l.head_; ptr != nullptr; ptr = ptr->next) { // for loop to traverse list
                append(ptr->data);
            }
        }

        void assign(const std::initializer_list<T>& il)
        {
            size_ = 0;
            for(const auto& i : il) {
                append(i);
            }
        }

        void popFront()
        {
            if(empty()) {
                return;
            }

            if(size_ == 1) {
                delete head_;
                head_ = nullptr;
                tail_ = nullptr;
            } else {
                head_ = head_->next;
                delete head_->prev;
                head_->prev = nullptr;
            }
            size_--;
        }

        void popBack()
        {
            if(empty()) {
                return;
            }

            if(size_ == 1) {
                delete tail_;
                head_ = nullptr;
                tail_ = nullptr;
            } else {
                tail_ = tail_->prev;
                delete tail_->next;
                tail_->next = nullptr;
            }
            size_--;
        }

        void remove(int k)
        {
            if(k < 0 || k > size_-1) {
                throw "[Error] Index out of range";
            }

            if(k == 0) { // at the start
                popFront();
                return;
            }

            if(k == size_-1) { // at the end
                popBack();
                return;
            }

            Node<T>* ptr = node(k);
            
            ptr->prev->next = ptr->next;
            ptr->next->prev = ptr->prev;
            delete ptr;
            size_--;
        }

        void clear()
        {
            while(head_ != nullptr) {
                Node<T>* temp = head_;
                head_ = head_->next;
                delete temp;
            }
            head_ = nullptr;
            tail_ = nullptr;
            size_ = 0;
        }

        T& operator[](int k) const
        {
            return node(k)->data;
        }

        bool empty() const
        {
            return size_ <= 0;
        }

        void operator=(const List<T>& l)
        {
            assign(l);
        } 

        void operator=(const std::initializer_list<T>& il)
        {
            assign(il);
        }

        bool operator==(const List<T>& l) const
        {
            if(size_ != l.size_) {
                return false;
            }

            Node<T>* p1 = head_;
            Node<T>* p2 = l.head_;
            while(p1 != nullptr && p2 != nullptr) {
                if(p1->data != p2->data) {
                    return false;
                }
                p1 = p1->next;
                p2 = p2->next;
            }

            return true;
        }

        void print(bool reverse = false) const
        {
            if(reverse) {
                for(Node<T>* ptr = tail_; ptr != nullptr; ptr = ptr->prev) {
                    std::cout << ptr->data << " ";
                }
            } else {
                for(Node<T>* ptr = head_; ptr != nullptr; ptr = ptr->next) { // for loop to traverse list
                    std::cout << ptr->data << " ";
                }
            }
            std::cout << std::endl;
        }
};