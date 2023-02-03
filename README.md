# Homework 1 : Processes and CPU Scheduling

## Part 1 : Processes
For this part of the programming assignment, you will edit the file processes.cpp

### 1.a) Create a child process
Create a child process with the 'fork' method

### 1.b) Create a grandchild process
Have the child process create a child process of its own with with the 'fork' method.  We will refer to this as the grandchild method.

### 1.c) Call appropriate methods
Three methods have been declared in src.hpp: 'parent()', 'child()', and 'grandchild()'.  Have the grandchild process call 'grandchild()', the child process call 'child()', and the parent process call 'parent()'.

### 1.d) Order the processes
Guarantee that the grandchild method is called before the child method, which is called before the parent method.

## Part 2 : CPU Scheduling
For this part of the programming assignment, you will edit the file scheduler.cpp.  You will write two CPU scheduling algorithms: a priority scheduler and a round-robin + priority scheduler.  **Assume all jobs require only CPU time, and have no I/O requirements.**  You are given an array Job* job, where Job is a struct containing the following 
- idx : the position in which the job arrived into the ready queue.
- priority : the priority of the job in the scheduler, with priority 0 highest, followed by priority 1, etc.
- time : the total time required by the job
- run_job : the function that the job will execute.  These functions are non-associative and must be run in the correct order to get the correct answer.  This function takes an integer 't', the amount of time for which the job will be executed.  Assume 'time' and this 't' are the same unit (e.g. both in seconds).

### 2.a) Priority Scheduler
Add a priority scheduler to the method 'priority(...)'.  This scheduler should do the following:
- The job with the highest priority runs first.  Assume priority 0 is highest, priority 1 is next highest, and so on.
- If multiple jobs have the same priority, the scheduler will use a FIFO scheduler for tiebreaking. 
- Each job will run for its entirety
- A job can be run with the following : jobs[i]->run_job(t) where t is the amount of time to run job i 


### 2.b) Priority + Round-Robin Scheduler
Add a priority + round-robin scheduler to the method 'priority_rr(...).  This scheduler should do the following:
- The job with the highest priority runs first.  Assume priority 0 is highest, priority 1 is next highest, and so on.
- If multiple jobs have the same priority 'p', all jobs with priority 'p' will be run round-robin
- The round-robin portion of the scheduler will use FIFO to determine the ordering of all jobs with priority 'p'
- When running round-robin, each job runs for a single time slice.  The value of a time slice is passed to this method as a parameter.  Assume the time slice is in the same unit as the struct value 'time' (e.g. both in seconds).
- A job can be run with the following : jobs[i]->run_job(t) where t is the amount of time that job i should run
- A job should not run for longer than its total amount of time.  For example, assume job 0 (idx 0) has time 4 and job 1 (idx 1) has time 3.  Also assume the time slice is 2 seconds.  If both jobs have the same priority, this method should do the following : 
  1. Run job 0 for 2 second
  2. Run job 1 for 2 second
  3. Run job 0 for 2 second
  4. Run job 1 for 1 second

## Part 3 : Push to Main
Merge all changes to the 'main' branch.  Check GitHub 'actions' to make sure all provided tests have passed.

## Optional Part 4 : Googletests
I will run your code through additional unit tests when grading the homeworks.  You are welcome to add your own tests to 'tests/additional_tests.cpp' to make sure your code is working.  If you submit any additional testing along with your homework, I will give you up to 2 points extra credit.
