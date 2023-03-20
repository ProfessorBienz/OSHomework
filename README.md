# Homework 3 : Concurrency and Locks

## Part 1 : Concurrently Compute PI (compute\_pi.cpp)
The goal of this portion of the programming assignment is to compute the value of pi concurrently among many threads.  The value of pi can be computed by randomly accessing points within a unit square, and computing how many of these points fall within the unit circle.  

You will add your implementation into the method compute\_pi.  This method is passed a thread_data_t* struct which contains : 
- int thread\_id : the ID associated with your thread.  This is a unique ID starting at 0.  For example, if there are three threads, they will have IDs 0, 1, and 2.
- calc\_t* struct that contains : 
    - int global_n_samples : the total number of samples of (x, y) coordinates to be computed
    - int global_n_threads : the total number of threads that will run this method
    - int global_sum : the total number of samples that fall within the unit circle.  Each thread will increment this value when a sample falls within the unit circle.  The value of the global\_sum is originally initialized to 0.
    - lock\_t* lock : a struct containing a mutex to be used in all lock and unlock calls.  The following methods can be used with this lock variable : 
        - init(lock_t* lock) : initializes the lock.  This is done for you before threads are initialized.
        - lock(lock_t* lock) :  waits until a thread receives the lock.
        - unlock(lock_t* lock) : releases the lock for another thread to grab.
        - destroy(lock_t* lock) : destroys the struct.  This method will me called for you after your threads complete.
        An initial implementation of the lock\_t* struct is provided for you in the file mutex\_lock.cpp within the submodule.  
    
The method pthread\_compute\_pi within the submodule file src.cpp initializes a number of threads so that each calls the compute\_pi method that you will be editting.  This part of the programming assignment can be completed through the subtasks described below.

### 1.a) Calculate random coordinates
Each thread should calculate an approximately equal portion of (x,y) coordinates, so that in total the global number of samples are calculated among all threads.  Each thread should compute an equal number of samples, with threads with lowest thread ids each calculating one extra sample if the number of samples does not evenly divide the number of threads.

For each local sample, compute two random values (one for x and one for y) between -1 and 1.  **The method rand() is not thread safe!  To calculate a random sample, call thread_rand(), which is implemented for you in src.cpp.**

### 1.b) Calculate global sum 
The variable global_sum is shared by all threads.  This variable should be incremented for each (x, y) coordinate that falls within the unit circle.  For any (x, y) coordinate from subtask 1.b, if x\*x + y\*y is less than or equal to 1, the value is within the unit circle.

### 1.c) Avoid race conditions
Global sum is a shared variable that all threads will be updating.  As a result, this will need to be updated atomically.  **Use the provided lock to atomically update this method.  You must use the provided lock structure, and the methods lock(...) and unlock(...) to pass the autograder.**  If you were to use an atomic instruction instead, you will fail tests in later portions of the programming assignment.

### 1.d) Gaurantee performance
Locks are typically expensive, so make sure to avoid locking within a for loop, and the overhead will cause your program to time out within tests.  Similarly, you do not want to lock around an entire for loop, as this will remove all concurrency from your program and also cause time outs.  Instead, you want to increment a local variable within the for loop and have each thread update the shared global counter only a single time so that each thread needs to aquire the lock only once and allowing for threads to all perform the while loop (and calculate random values) concurrently.

### 1.e) No return statement
This method should return NULL, as originally provided for you.


## Part 2 : Ticket Spin Lock
The goal of this portion of the programming assignment is to implement a ticket spin lock that spins while waiting to acquire the lock.  To complete this part of the programming assignment, you will edit the methods within the file ticket_spin_lock.cpp. Some hints for creating this lock : 
- The lock_t* lock struct contains : 
    - int ticket : initialized to 0
    - int turn : initialized to 0
- Use the atomic method __sync_fetch_and_add(int* ticket, int addition).  This method will atomically fetch the value in ticket and add `addition' to this value.
- You may not need to do anything in the destroy method.

## Part 3 : Ticket Yield Lock
The goal of this portion of the programming assignment is to implement a ticket yield lock that yields control of the CPU while waiting to acquire the lock.  To complete this part of the programming assignment, you will edit the methods within the file ticket_yield_lock.cpp. Some hints for creating this lock : 
- The lock_t* lock struct contains : 
    - int ticket : initialized to 0
    - int turn : initialized to 0
- Use the atomic method __sync_fetch_and_add(int* ticket, int addition).  This method will atomically fetch the value in ticket and add `addition' to this value.
- To yield control of the CPU, call the method `sched_yield()'
- You may not need to do anything in the destroy method.

## Part 4 : Queue Lock
The goal of this portion of the programming assignment is to create a lcok that adds waiting threads to a queue and puts threads to sleep.   When releasing the lock, if the queue is not empty, the first thread in the queue will be woken.  To complete this part of the assignment, you will edit the methods within the file queue_lock.cpp.  Some hints for creating this lock : 
- The lock_t* lock struct contains:
    - int flag : intialized to 0
    - int guard : initialized to 0
    - queue_t : a queue struct.  The available methods for manipulating this queue are : 
        - queue_init(queue_t queue) : intializes an empty queue
        - queue_add(queue_t queue, pthread_t thread) : adds `thread' to the back of the queue
        - queue_remove(queue_t queue) : removes the first thread from the queue, returning
        - queue_empty(queue_t queue) : returns 1 if the queue is empty, 0 otherwise
- The atomic method __sync_lock_test_and_set(int* ptr, int val) will atomically set the ptr to the passed value if not already equal to val.   It will return what was originally in the ptr.
- The method `pause()' will cause a thread to sleep indefinitely.
- The method pthread_kill(pthread_t thread, int signal) will wake up the given thread and pass the given signal to the thread.  The signal SIGCONT tells the thread to continue (e.g. moves the thread back to the ready queue)
- The method pthread_self() returns the pthread_id of the calling thread, which is of type pthread_t (and should be added to the queue when needed).
- You may not need to do anything in the destroy method.

## Part 5 : Semaphore Lock
The goal of this portion of the programming assignment is to create a semaphore lock.  To complete this part of the assignment, you will edit the methods in the file `semaphore_lock.cpp'.  The lock(...) method will operate equivalently to a semaphore wait(...) method while the unlock(...) method will be equivalent to a semaphore signal(...).  Some hints for completing this method : 
- The lock_t* lock struct contains: 
    - int S 
    - pthread_mutex_t mutex : Needed to lock the wait and signal methods
- The method `pthread_mutex_lock(...)' can be used to lock the mutex
- The method `pthread_mutex_unlock(...)' can be used to unlock the mutex
- The atomic method __sync_fetch_and_add(int* ptr, int var) will atomically add var to the current value in ptr
- The atomic method __sync_fetch_and_sub(int* ptr, int var) will automatically subtract var from the current value in ptr
- The variable pthread_mutex_t will need to be initialized and destroyed.



