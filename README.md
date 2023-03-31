# Homework 4 : Dining Philosophers and Producer Consumer Problems

## Part 1 : Producer Consumer Problem 
The goal of this portion of the programming assignment is to solve the producer consumer problem.  The producer will put a value into the buffer if the buffer has space, and the consumer thread will grab a value from the buffer if the buffer has entries.  

- The producer thread is passed the following : 
    - buffer_t* buf : buffer to which a value should be added
    - int val : value to be added to the buffer
    
- The consumer thread : 
    - buffer_t* buf : buffer from which a value should be pulled
    - returns int containing value pulled from buffer

There are two available methods that you should call : 
- void put(buffer_t* buf, int val) : this method adds val to the buffer
- void get(buffer_t* buf, int* val) : this method grabs the first available value from the buffer and returns a pointer to it
**Note, these methods are not currently thread safe, and it is your job to make sure that multiple threads are unable to call these methods at the same time.**

To get full credit on this portion of the assignment, you should edit the producer_thread(...) method to put the given value in the buffer, but only once the buffer has room.  Similarly, you should edit the consumer_thread(...) method to get a value from the buffer, but only once the buffer has values.  The producer thread should return NULL, but the consumer thread must return the value that is received from the get(...) method.  Note, there may be multiple consumers, multiple producers, or both.

### Part 1a : Using Condition Variables (condition_var.cpp)
The data structure buffer_t* contains the following : 
- int limit : the maximum number of values that can be in the buffer at any time
- int size : the current number of values in the buffer
- pthread_mutex_t mutex : a mutex lock, which is initialized and freed for you in the test files.
- pthread_cond_t empty : a condition variable, intialized and freed for you
- pthread_cond_t full : a second condition variable, initialized and freed for you

For this subportion of the assignment, you will fill in the methods as described above, using the provided condition variables and mutex.  You can assume all condition variables and locks have been initialized before the method is called.  Some hints : 
- You will want to use the methods pthread_cond_wait and pthread_cond_signal
- The method pthread_cond_wait takes both a condition variable and a locked mutex
- You have two condition variables to work with, and you should use both of them
- The size and limit variables, within the buffer_t* struct, can be used to determine if there is buffer space available and if anything is in the buffer
- Condition variables require while loops

### Part 1b : Using Semaphores (semaphore.cpp)
The data structure buffer_t* contains the following : 
- int limit : the maximum number of values that can be in the buffer at any time
- int size : the current number of values in the buffer
- pthread_mutex_t mutex : a mutex lock, which is initialized and freed for you in the test files.
- sem_t* sem_empty : a pointer to a semaphore, initialized to limit and freed for you
- sem_t* sem_full : a pointer to a semaphore, initialized to 0 and freed for you

For this subportion of the assignment, you will fill in the methods as described above, using the provided semaphore variables and mutex.  You can assume all condition variables and locks have been initialized before the method is called.  Some hints : 
- You will want to use the methods sem_wait and sem_post
- You have two semaphores to work with, and you should use both of them
- The size and limit variables, within the buffer_t* struct, can be used to determine if there is buffer space available and if anything is in the buffer


## Part 2 : Dining Philosophers
The goal of this portion of the programming assignment is to implement the dining philosophers problem.  The method is passed a diners_t* struct, which contains the following : 
- sem_t** forks : an array of pointers to semaphores, one for each fork.  These have already been initialized to 1.
- int size : the number of philosophers, and the number of forks.  This is also equivalent to the number of threads.
- pthread_mutex_t : an initialized mutex lock
- int philosopher : the thread ID for a given thread.  This ID corresponds to the philosopher for which the thread is controlling.

You should use the following methods : 
- sem_t* left(diners_t* diner) : Returns the semaphore that controls the calling philosophers left fork
- sem_t* right(diners_t* diner) : Returns the semaphore that controls the calling philosophers right fork

A given fork can be acquired with the method sem_wait(...) and can be released with sem_post(...).  Once a philosopher has both forks, that philosopher can call eat by calling the method eat(diners_t* diner).  After the eat method returns, the philosopher should release both forks.

**The standard approach for the philosopher probblem has all philosophers grab their left fork before any grabs the right.  This can redult in a deadlock.  You will prevent this deadlock in two different ways, described below.**

### Part 2a : Avoiding the Circular Wait (circular.cpp)
Complete the dining philosophers problem described above by avoiding the circular wait. Make sure that all philosophers cannot grab the same fork first.  

### Part 2b : Avoiding the Hold-and-Wait (hold_and_wait.cpp)
Complete the dining philosophers problem described above by avoiding hold-and-wait.  Use the mutex lock to have a single philosopher grab all necessary forks at once.
