#!/bin/sh

cd /opt/repo || exit 1
git pull
git submodule foreach git pull

mkdir build && cd build || exit 1
cmake ..
#    -DCMAKE_CXX_COMPILER=/usr/lib/ccache/bin/clang++ \
#    -DCMAKE_CC_COMPILER=/usr/lib/ccache/bin/clang \
#    -DEXECUTABLE_OUTPUT_PATH=test.out

cmake --build .

./test.out