# CPU CACHE SIMULATOR

## Overview
This is a CPU cache simulator program that simulates the mechanics of 
CPU cache access, retrieval, and storage.The program keeps track of cache hits and misses, and calculates the hit rate based on the number of accesses.
## Why this project is important
The CPU cache lies beween the main processor and the main memory, 
and is designed to speed up data access by storing frequently used data.
Understanding how the CPU cache works is crucial for optimizing software performance, 
as it can significantly reduce the time it takes for the processor to access data. 
By simulating the CPU cache, developers can gain insights into how their code interacts with the cache,and optimize their code for better performance.

## How It Works
The program simmulates the order of the programs by storing the data as unordered_map object in order to simulate
the location of the data in the cache and the order by which they enter as a list object and when a cache access is requested it
searches the map for the most file and in the case of a hit the file is retrieved and pushed forward while in the case of a miss its stored in the cache, in which case
the files storage is checked and the file with the oldest precedence is cleared.

## How to run
1. Clone the repository
2. Create a text file with one memory address per line.
3. Compile the program using a C++ compiler.

## Example Output
  ```
Cache Hits: 1
Cache Misses: 5
Evictions: 2
Hit Rate: 16.67%
```
## Concepts Demonstrated
-CPU cache mechanics
-cache hits and misses
-hit rate calculation
-Classes and data structures (unordered_map, list)
-Cache replacement policies (LRU - Least Recently Used)

