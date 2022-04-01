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
    struct HashNode{
        T Data;
        long long index;
    };
    int size=0;
    int arrlen=1;
    float coefload=size/arrlen;
    void resize_arr() {

        LinkedList<HashNode> *new_arr = new LinkedList<HashNode>[arrlen * 2];

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
                    HashNode b = array[i].pop_front();
                    coefload = size/arrlen;
                    hashd(b.Data);
                }
            }
        }
    }
public:
    LinkedList<HashNode> *array = new LinkedList<HashNode>[arrlen];

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

    long long hash(T data){
        coefload = size/arrlen;
        if(coefload>=1){
            resize_arr();
        }
        HashNode a;
        long long c = generateRandLong()%arrlen;
        a.index = c;
        a.Data = data;
        array[a.index].push_back(a);
        size++;
        return a.index;
    }
    long long hashd(T data){
        coefload = size/arrlen;
        HashNode a;
        long long c = generateRandLong()%arrlen;
        a.index = c;
        a.Data = data;
        array[a.index].push_back(a);
        return a.index;
    }

};


#endif //HESHMAP_HESHMAP_H
