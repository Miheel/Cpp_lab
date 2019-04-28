INCLUDES := Includes\\
SOURCE:= Source\\
BIN := Bin\\
BUILD := Build\\
EXEC := $(BIN)Queue_Stack.exe
DELETE := rm -f
FLAGSOBJ := g++ -g -c -std=c++17 -Wextra -Wpedantic
FLAGEX := g++ -g -std=c++17 -Wall -Wextra -Wpedantic

all: $(BUILD) $(BIN) $(EXEC)

$(EXEC): $(BUILD)main.o $(BUILD)MemoryLeakChecker.o
	$(FLAGEX) $(BUILD)main.o $(BUILD)MemoryLeakChecker.o -o $(EXEC)

$(BUILD): 
	-@if [ ! -d "$(BUILD)" ]; then mkdir "$(BUILD)"; fi

$(BIN):
	-@if [ ! -d "$(BIN)" ]; then mkdir "$(BIN)"; fi

$(BUILD)main.o: $(SOURCE)main.cpp $(INCLUDES)MemoryLeakChecker.hpp $(INCLUDES)Queue.hpp $(INCLUDES)Stack.hpp
	$(FLAGSOBJ) $(SOURCE)main.cpp -I$(INCLUDES) -o $(BUILD)main.o
	
$(BUILD)MemoryLeakChecker.o: $(SOURCE)MemoryLeakChecker.cpp $(INCLUDES)MemoryLeakChecker.hpp
	$(FLAGSOBJ) $(SOURCE)MemoryLeakChecker.cpp -I$(INCLUDES) -o $(BUILD)MemoryLeakChecker.o

clean:
	$(DELETE) $(BUILD)main.o $(BUILD)MemoryLeakChecker.o $(EXEC)