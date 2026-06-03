#ifndef LRUCACHE_H
#define LRUCACHE_H
#include <iomanip>
#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;
class LRUCache {

private:
    list<int> lruOrder;
    unordered_map<int, list<int>::iterator> cacheMap;
    int capacity;
    int hitCount, missCount, evictionCount;

public:
    LRUCache(int i);
    void access(int address);
    void printStats();
    double getHitRate();
};
#endif
