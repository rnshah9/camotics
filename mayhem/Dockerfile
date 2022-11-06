FROM --platform=linux/amd64 ubuntu:20.04 as builder

RUN apt-get update
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y build-essential scons build-essential qt5-default python-six libqt5websockets5-dev libqt5opengl5-dev libnode-dev libglu1-mesa-dev pkgconf git python3-distutils python3-pip clang

RUN git clone https://github.com/CauldronDevelopmentLLC/cbang.git
RUN scons -C cbang
ENV CBANG_HOME=/cbang

COPY . /repo
WORKDIR /repo
RUN pip3 install six
RUN scons
RUN clang++ /repo/mayhem/fuzz_find.cpp -L/repo/build  -lGCode -I/repo/src/gcode -I/cbang/src -I/repo/src -fsanitize=fuzzer,address -o /fuzz_find -L/cbang/lib -lcbang -lcbang-boost -llz4 -lbz2 -levent -lre2 -lsqlite3 -lyaml -lz

# FROM ubuntu:20.04 as package
# RUN apt-get update
# RUN DEBIAN_FRONTEND=noninteractive apt-get install -y libssl-dev libexpat-dev
# COPY --from=builder /fuzz /fuzz_find
