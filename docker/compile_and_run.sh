#!/bin/sh

pacman --noconfirm -Syu
export CCACHE_DIR=/opt/.ccache


cd /opt/repo || exit 1

mkdir build && cd build || exit 1
cmake .. \
    -DCMAKE_CXX_COMPILER=/usr/lib/ccache/bin/clang++ \
    -DCMAKE_CC_COMPILER=/usr/lib/ccache/bin/clang

cmake --build . -- -j "$(nproc)"

./sero_core_opengl_tests