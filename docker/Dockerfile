FROM ubuntu:latest

LABEL Maintainer = "Yuhanun Citgez <y.citgez@student.utwente.nl>"

# Update lists
RUN apt-get update

# Update packages
RUN apt-get -y dist-upgrade

# Get dependencies
RUN apt-get install -y \
        ccache \
        make \
        g++ \
        clang \
        cmake \
        git

# Setup gtest
RUN git clone https://github.com/google/googletest.git /opt/googletest && \
    cd /opt/googletest && \
    mkdir install && \
    cd install && \
    cmake .. && \
    make -j $(nproc) && \
    make install

# Clone repo
RUN git clone https://github.com/Sero-Lib/sero-core-opengl /opt/repo && \
        cd /opt/repo && \
        git submodule update --init --recursive

# Copy over the file
COPY compile_and_run.sh /compile_and_run.sh

# Run the stuff
#CMD "/compile_and_run.sh"