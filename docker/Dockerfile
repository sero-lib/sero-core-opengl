FROM archlinux:latest

LABEL Maintainer = "Yuhanun Citgez <y.citgez@student.utwente.nl>"

# Update lists && packages
RUN pacman -Syu --noconfirm

# Get dependencies
RUN pacman --noconfirm --needed -S \
        ccache \
        make \
        gcc \
        clang \
        cmake \
        git \
        gtest

# Clone repo
RUN git clone https://github.com/Sero-Lib/sero-core-opengl /opt/repo && \
        cd /opt/repo && \
        git submodule update --init --recursive

# Copy over the file
COPY compile_and_run.sh /compile_and_run.sh

# Run the stuff
CMD "/compile_and_run.sh"