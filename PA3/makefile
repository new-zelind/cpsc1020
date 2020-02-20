CC=g++
CFLAGS=-Wall -g -std=c++11
TARGET=pa3
INPUT=inputData.txt
OUTPUT=dailySalesOutput.txt customerOutput.txt

C_SRCS := \
	$(wildcard *.cpp)\
	$(wildcard src/*.cpp)\
	$(wildcard src/**/*.cpp)

HDRS :=\
	$(wildcard *.h)\
	$(wildcard src/*.h)\
		$(wildcard src/**/*.h)

OBJS := $(patsubst %.cpp, bin/%.o, $(wildcard *.cpp))
OBJS += $(filter %.o, $(patsubst src/%.cpp, bin/%.o, $(C_SRCS)))

all: build
	@echo "All Done!"

build: $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

bin/%.o: %.cpp $(HDRS)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

bin/%.o: src/%.cpp $(HDRS)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET)
	rm -rf bin
	rm -f $(OUTPUT)

run: build
	./$(TARGET) $(INPUT) $(OUTPUT) 

which:
	@echo "FOUND SOURCES: $(C_SRCS)"
	@echo "FOUND HEADERS: $(HDRS)"
	@echo "TARGET OBJS: $(OBJS)"
