# ParallelDirListing
I've Learnt basics of Concurrency in general and in C++. This is just a small example to Demonstrate Massively Parallel Directory Listing in C++


### In main.cpp

  Change the 'root_dir' variable to whichever Directory you want to search.
  All dirs with '.' predecessor has been ignored.

Run the compiler/linker with following command:

### *g++ --std=c++17 main.cpp -o main -O3 -pthread*

--std=c++17 sets compiler to C++ 2017 Standard

-O3 allows compile-time Optimization

-pthread allows use of POSIX Threads.
