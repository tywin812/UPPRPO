FROM gcc:latest

RUN apt-get update && \
    apt-get install -y cmake libgtest-dev

RUN mkdir -p /shared/logs

COPY . /app
WORKDIR /app

RUN mkdir build && \
    cd build && \
    cmake .. && \
    make

CMD ["sh", "-c", "./build/testproj | tee /shared/logs/test-results.log"]