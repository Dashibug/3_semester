// queue.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <exception>

//using namespace std;


class Queue {
private:
    struct Node
    {
        double data = 0.0;
        Node *next = nullptr;//указатель на след объект
    };
    Node *head = nullptr;//указатель на 1 объект

public:
    Queue() = default;
    Queue(const Queue& rhs)
    {
        auto rhs_ptr = rhs.head;// обращаемся к 1 объекту
        auto this_ptr = new Node;//выделение памяти
        head = this_ptr;
        while (this_ptr != nullptr) {
            this_ptr->data = rhs_ptr->data;
            if (rhs_ptr->next != nullptr) {
                this_ptr->next = new Node;
                this_ptr = this_ptr->next;
            }
            rhs_ptr = rhs_ptr->next;
        }
    };
    ~Queue() 
    {
        delete head;
    }
    int top() {
        if (!is_empty()) {
            return head->data;
        }
        else throw std::out_of_range("empty right now");//разыменовываю указатель на head
        //и получаю доступ к полю data
    }
    void push(double value)
    {
        if (is_empty())
            head = new Node({ value });//инициализация по умолчанию
        else {
            Node *node1 = head;
            while (node1->next != nullptr) {
                node1 = node1->next;
            }
            node1->next = new Node({ value, nullptr });
        }
    }   
    void pop() 
    {
        if (is_empty()) {
            throw ("empty right now");
            return;
        }
        Node* new_head = head->next;
        delete head;
        head = new_head;
    }
    bool is_empty() {
        return head == nullptr;
    }
};


int main() {
    Queue q;
    q.top();

}

/*class list
{ 
    struct node
    {
        int data;
        node* next = nullptr;
    };

    node* head, tail;
public:
   list() = default;
   list(const list& rhs)
   {
       head = nullptr;
       tail = nullptr;
   }
   void insert(int t) 
   {
       node* temp = new node;
       temp->data = t;
       temp->next = nullptr;
       if (head == nullptr) 
       {
           head = t;
           tail = t;
       }
       else 
       {
           tail->next = t;
           tail = t;
       }
       
   }
   void deletstart() 
   {
       if (head == nullptr) 
       {
           std::cout << "empty list";
       }
       else 
       {
           head = head - next;
       }
   }
   void deletend() 
   {
       node* cur, temp;
       temp = head;
       while (temp->next == nullptr) 
       {
           cur = temp;
           temp = temp->next;
       }
       cur->next = nullptr;
       tail = cur;
   }
   void deletepos(int pos)
   {
       node* cur, prev;
       for (int i = 1; i < pos; i++) 
       {
           prev = cur;
           cur = cur->next;
       }
       prev->next = cur->next;
   }
};
*?
* */

