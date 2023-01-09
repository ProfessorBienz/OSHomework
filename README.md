# Homework 0 : GitHub, CMake, and Googletest

## Part 1 : GitHub
GitHub Classroom will be used for all homework assignments.  You will be given an initial repository.  Instructions for the assignment will be provided in the README.md.  Follow the steps below to complete the GitHub portion of Homework 0.

### 1.a) Clone the repository to a local machine
You can clone the repository with 'git clone \<repository\_name\>.  The repository name can be found by clicking the green 'Code' button.  Click on the HTTPS tab if you use Github token authentification, and the SSH tab if you have setup an SSH key.  For more information on authentification methods, refer to the Homework 0 PDF on UNM Canvas.

### 1.b) Checkout the homework0 branch
The initial repository for this homework is in the branch called 'homework0'.  You can get access to this code with the command 'git checkout homework0'

### 1.c) Pull submodule changes
All homework repositories will contain a submodule called 'cs_481_hw_src'.  Changes (such as additions to the unit tests) may be made to this submodule at any time.  Get access to the most up-to-date submodule repository with the following two commands:
- git submodule init
- git submodule update --remote

### 1.d) Push Changes
After finished Parts 2 and 3, you will need to push all changes to your GitHub repository.  This can be done with the following commands:
- git status : will show which files have been changed or added
- git add <filename> : will add the file to be committed
- git commit -m "note about changes": will commit all changes
- git push : will push commit to remote server (github.com)
  
### 1.e) Merge to Master
