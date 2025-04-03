FROM gcc:latest

RUN apt-get update && \
    apt-get install -y cmake libgtest-dev

RUN mkdir -p /shared/logs

WORKDIR /app

COPY lab2/CMakeLists.txt /app/lab2/CMakeLists.txt
COPY lab2/ /app/lab2/

RUN mkdir -p /app/build && \
    cd /app/build && \
    cmake /app/lab2 && \
    make

CMD ["sh", "-c", "./build/testproj | tee /shared/logs/test-results.log"]