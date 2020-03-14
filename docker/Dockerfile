FROM alpine:3.9.5

LABEL Maintainer Yuhanun Citgez <y.citgez@student.utwente.nl>

# Update lists
RUN apk update

# Update packages
RUN apk upgrade

# Get dependencies
RUN apk add \
        gtest \
        ccache \
        make \
        g++ \
        cmake \
        git
