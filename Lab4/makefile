INCLUDES := Includes\\
SOURCE:= Source\\
BIN := Bin\\
BUILD := Build\\
EXEC := $(BIN)Queue_Stack.exe
DELETE := del
FLAGSOBJ := g++ -g -c -std=c++17 -Wall -Wextra -Wpedantic


all: $(EXEC)

$(EXEC): $(BUILD)main.o $(BUILD)MemoryLeakChecker.o
	g++ -g -std=c++17 -Wall -Wextra -Wpedantic $(BUILD)main.o $(BUILD)MemoryLeakChecker.o -o $(EXEC)

$(BUILD)main.o: $(SOURCE)main.cpp $(INCLUDES)MemoryLeakChecker.hpp $(INCLUDES)Queue.hpp $(INCLUDES)Stack.hpp $(INCLUDES)DataContainer.hpp
	$(FLAGSOBJ) $(SOURCE)main.cpp -I$(INCLUDES) -o $(BUILD)main.o
	
$(BUILD)MemoryLeakChecker.o: $(SOURCE)MemoryLeakChecker.cpp $(INCLUDES)MemoryLeakChecker.hpp
	$(FLAGSOBJ) $(SOURCE)MemoryLeakChecker.cpp -I$(INCLUDES) -o $(BUILD)MemoryLeakChecker.o

clean:
	-$(DELETE) $(BUILD)main.o $(BUILD)MemoryLeakChecker.o $(EXEC)