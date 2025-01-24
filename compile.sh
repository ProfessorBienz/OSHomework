git submodule init
git submodule update --remote

mkdir build
cd build
cmake ..
make
