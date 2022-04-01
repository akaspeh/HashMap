#include <iostream>
#include "LinkedList.h"
#include <ctime>
#include <cstdlib>
#include <cstring>
#include "Heshmap.h"


using namespace std;


int main() {
    srand(time(nullptr));
    Hashmap<int> Hashmap;
    cout << Hashmap.hash(1) << '\n';
    //Hashmap.len();
    cout << Hashmap.hash(2) << '\n';
    //Hashmap.len();
    cout << Hashmap.hash(3) << '\n';
    //Hashmap.len();
    cout << Hashmap.hash(4) << '\n';
    //Hashmap.len();
    cout << Hashmap.hash(5) << '\n';
    Hashmap.len();
    cout << Hashmap.hash(6) << '\n';
    //Hashmap.len();
    cout << Hashmap.hash(7) << '\n';
    //Hashmap.len();
    cout << Hashmap.hash(8) << '\n';
    //Hashmap.len();
    cout << Hashmap.hash(9) << '\n';
    //Hashmap.len();
    return 0;
}
