FROM alpine:3.9.5

LABEL Maintainer = "Yuhanun Citgez <y.citgez@student.utwente.nl>"

# Update lists
RUN apk update

# Update packages
RUN apk upgrade

# Get dependencies
RUN apk add --no-cache \
        gtest \
        ccache \
        make \
        g++ \
        clang \
        cmake \
        git

# Clone repo
RUN git clone https://github.com/Sero-Lib/sero-core-opengl /opt/repo && \
        cd /opt/repo && \
        git submodule update --init --recursive

# Copy over the file
COPY compile_and_run.sh /compile_and_run.sh

# Run the stuff
#CMD "/compile_and_run.sh"