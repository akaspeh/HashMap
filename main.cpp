#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include "Heshmap.h"


using namespace std;


int main() {
    srand(time(nullptr));
    Hashmap<int> Hashmap;
    for(int i = 0; i < 1000; i++){
        int a = rand()%1000;
        Hashmap.insert(rand()%50,a);
    }
    return 0;
}
