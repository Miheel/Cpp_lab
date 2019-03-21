INCLUDES := Includes\\
SOURCE:= Source\\
BIN := Bin\\
BUILD := Build\\
EXEC := $(BIN)asdf.exe
DELETE := del

all: $(EXEC)

$(EXEC): $(BUILD)main.o $(BUILD)MemoryLeakChecker.o
	g++ -g -std=c++11 $(BUILD)main.o $(BUILD)MemoryLeakChecker.o -o $(EXEC)

$(BUILD)main.o: $(SOURCE)main.cpp $(INCLUDES)MemoryLeakChecker.hpp $(INCLUDES)Queue.hpp $(INCLUDES)Stack.hpp $(INCLUDES)DataContainer.hpp
	g++ -g -c -std=c++11 $(SOURCE)main.cpp -I$(INCLUDES) -o $(BUILD)main.o
	
$(BUILD)MemoryLeakChecker.o: $(SOURCE)MemoryLeakChecker.cpp $(INCLUDES)MemoryLeakChecker.hpp
	g++ -g -c -std=c++11 $(SOURCE)MemoryLeakChecker.cpp -I$(INCLUDES) -o $(BUILD)MemoryLeakChecker.o

clean:
	-$(DELETE) $(BUILD)main.o $(BUILD)MemoryLeakChecker.o $(EXEC)