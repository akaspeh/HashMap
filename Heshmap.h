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
    int size=0;
    int arrlen=1;
    float coefload=size/arrlen;
    LinkedList<T> *array = new LinkedList<T>[arrlen];
    void resize_arr() {
        LinkedList<T> *new_arr = new LinkedList<T>[arrlen * 2];

        for (int i = 0; i < arrlen; i++) {
            new_arr[i] = array[i];
        }

        int oldarrlen = arrlen;
        arrlen *= 2;
        delete[] array;
        array = new_arr;

        for(int i = 0;i < oldarrlen;i++){
            if(array[i].size() != 0){
                int LinkedList_size = array[i].size();
                for(int j = 0; j < LinkedList_size;j++){
                    long long key = array[i].pop_front_key();
                    T val = array[i].pop_front();
                    long long index = hash(key);
                    array[index].push_back(key,val);
                }
            }
        }
    }
    long long hash(unsigned long long key)
    {
        return ((3 * key - 5) % 9149658775000477) % arrlen;
    }
public:
    ~Hashmap(){
        delete [] array;
    }

    long sizeH(){
        return size;
    }

    long long generateRandLong(){
        string str = "";
        for(int i = 0; i < 10;i++){
            char a = rand() % 10 + 48;
            str[i] = a;
        }
        long long num = stoll(str);
        return num;
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

    void insert(long long key,T value){
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
};


#endif //HESHMAP_HESHMAP_H
