//
// Created by Никита on 29.03.2022.
//

#ifndef HESHMAP_HESHMAP_H
#define HESHMAP_HESHMAP_H

#include "LinkedList.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstring>

template <typename T>
class Hashmap {
private:
    short a;
    short b;
    long long size=0;
    long long arrlen=1;
    float coefload=size/arrlen;
    LinkedList<T> *array = new LinkedList<T>[arrlen];
    void resize_arr() {
        LinkedList<T> *new_arr = new LinkedList<T>[arrlen * 2];

        int oldarrlen = arrlen;
        arrlen *= 2;

        for(int i = 0;i < oldarrlen;i++){
            if(array[i].size() != 0){
                int LinkedList_size = array[i].size();
                for(int j = 0; j < LinkedList_size;j++){
                    long long key = array[i].get_front_key();
                    new_arr[hash(key)].push_back(key,array[i].pop_front());
                }
            }
        }
        delete[] array;
        array = new_arr;
    }
    long long hash(unsigned long long key)
    {
        return ((a * key + b) % 9149658775000477) % arrlen;
    }
public:
    Hashmap(): a(rand()%9 + 1), b(rand()%9+1){}

    ~Hashmap(){
        delete [] array;
    }

    long long sizeH(){
        return size;
    }

    void len(){
        cout << arrlen << "\n";
        cout << "-------" << "\n";
        for(int i = 0;i<arrlen;i++){
            cout << array[i].size() << " ";
        }
        cout << "\n";
        cout << "-------" << "\n";
        cout << "\n";

    }

    void insert(long long key,const T& value){
        coefload = (float)size/(float)arrlen;
        if(coefload>=1){
            resize_arr();
        }
        long long index = hash(key);
        T *pointer = array[index].get(key);
        if(pointer != nullptr){
            *pointer = value;
            return;
        }
        array[index].push_back(key, value);
        size++;
    }

    void erase(long long key){
        long long index = hash(key);
        int sizefirst = array[index].size();
        array[index].del_el(key);
        int sizesecond = array[index].size();
        if(sizefirst != sizesecond){
            size--;
        }
    }

    T* find(long long key){
        long long index = hash(key);
        return array[index].get(key);
    }
};


#endif //HESHMAP_HESHMAP_H
