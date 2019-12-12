FROM ubuntu:16.04


RUN apt-get clean
RUN apt-get update

RUN apt-get install -y llvm
RUN apt-get update
RUN apt-get install -y clang
RUN apt-get install -y make
RUN apt-get install -y valgrind

#pthreads
RUN apt-get install libpthread-stubs0-dev


COPY gmock-1.7.0 /home/gmock-1.7.0
RUN apt-get install -y g++


#docker build . -t mgudim/libds-dev
