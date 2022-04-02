//
// Created by Никита on 29.03.2022.
//

#ifndef HESHMAP_LINKEDLIST_H
#define HESHMAP_LINKEDLIST_H

#include <iostream>

using namespace std;

template <typename T>
class LinkedList {
private:
    int cur = -1;
    struct Node{
        long long key;
        T data;
        Node* next;
    };

    Node* head;
    Node* tail;
public:

    LinkedList(){
        head = nullptr;
        tail = nullptr;
    }
    ~LinkedList(){
        Node *curr = head;
        for(int i = 0;i<cur;i++){
            curr = curr->next;
            delete head;
            head = curr;
        }
        delete head;
        head = nullptr;
        tail = nullptr;
    }

    void push_back(long long key,T element){
        Node *newNode = new Node;
        newNode->data = element;
        newNode->key = key;
        newNode->next = nullptr;

        if(cur == -1){
            head = newNode;
            tail = newNode;
            cur++;
        }
        else{
            tail->next=newNode;
            tail = newNode;
            cur++;
        }
    }

    long long pop_front_key(){
        if(cur == -1){
            cout << "nothing to pop\n";
            return 0;
        }
        else{
            long long a = head->key;
            return a;
        }
    }
    T pop_front() {
        if (cur == -1) {
            cout << "nothing to pop\n";
            return T{};
        } else if (head == tail) {
            T a = head->data;
            cur--;
            delete head;
            head = nullptr;
            tail = nullptr;
            return a;
        } else {
            T a = head->data;
            Node *tmp = head;
            head = head->next;
            delete tmp;
            cur--;
            return a;
        }
    }

    int size(){
        return cur+1;
    }

    void del_el(unsigned long long key)
    {
        Node* next_node = head;
        Node* prev_node = nullptr;
        while (next_node != nullptr)
        {
            if (next_node->key == key)
            {
                if (prev_node!=nullptr)
                    prev_node->next = next_node->next;
                else
                    head = next_node->next;

                delete next_node;
                cur--;
                return;
            }

            prev_node = next_node;
            next_node = next_node->next;
        }
    }

    T* get(unsigned long long key)
    {
        Node* a = head;
        while (a!=nullptr)
        {
            if (a->key == key)
                return &a->data;
            a = a->next;
        }
        return nullptr;
    }
};



#endif //HESHMAP_LINKEDLIST_H