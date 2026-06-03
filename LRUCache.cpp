#include "LRUcache.h"
//Capacity Parametrized Constructor
LRUCache:: LRUCache(int i) : capacity(i), hitCount(0), missCount(0), evictionCount(0) {

}
void LRUCache:: access(int address) {
    if (cacheMap.count(address) > 0) {
        //if hit fetch the adrdress in the list
        auto  it = cacheMap[address]; //sets it to the iterator returned by the cachemap
        hitCount++; //incremented becasue a hit was found
        lruOrder.erase(it); //erase the iterator from the list 
        lruOrder.push_back(address); //insert the address iterator to the end of the list
        cacheMap[address] = prev(lruOrder.end()); // update the new iterator at the back of the list 

    }

    else {
        //0 placeholder for max value

        if (capacity > cacheMap.size()) {
            //eviction is not needed proceed to add the address to the list and map
            lruOrder.push_back(address);  // add the iterator to the front
            cacheMap[address] = prev(lruOrder.end()); // update the new iterator at the back of the list

            missCount++; //increment miss count

        }
        // if capacity is full
        else {
            //grab address at the front of the list
            auto  evicted = lruOrder.front();
            //and erase it from the cache map and the list
            cacheMap.erase(evicted);
            lruOrder.erase(lruOrder.begin());
            //add new address to the back of the list
            lruOrder.push_back(address);
            // add the iterator to the front
            cacheMap[address] = prev(lruOrder.end()); // update the new iterator at the back of the list 
            //increment miss count and eviction count
            missCount++;
            evictionCount++;
        }

    }

}
// Function to print cache statistics
void LRUCache:: printStats() {
    cout << "Cache Hits: " << hitCount << endl;
    cout << "Cache Misses: " << missCount << endl;
    cout << "Evictions: " << evictionCount << endl;
    cout << "Hit Rate: " << fixed << setprecision(2) << getHitRate() * 100 << "%" << endl;
}
// Function to calculate hit rate
double LRUCache:: getHitRate() {
    double totalAccess = hitCount + missCount;
    double hitRate = hitCount / totalAccess;
    return hitRate;

}