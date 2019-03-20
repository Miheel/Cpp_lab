INCLUDES := Includes\\
SOURCE:= Source\\
BIN := Bin\\
BUILD := Build\\

all:$(BIN) $(BUILD) $(BIN)asdf.exe 

$(BIN)asdf.exe: $(BUILD)main.o $(BUILD)MemoryLeakChecker.o
	g++ -g -std=c++11 $(BUILD)main.o $(BUILD)MemoryLeakChecker.o -o $(BIN)asdf.exe

$(BIN):
	if not exist $(BIN) mkdir $(BIN)

$(BUILD):
	if not exist $(BUILD) mkdir $(BUILD)

$(BUILD)main.o: $(SOURCE)main.cpp $(INCLUDES)MemoryLeakChecker.hpp $(INCLUDES)Queue.hpp $(INCLUDES)Stack.hpp $(INCLUDES)DataContainer.hpp
	g++ -g -c -std=c++11 $(SOURCE)main.cpp -I$(INCLUDES) -o $(BUILD)main.o
	
$(BUILD)MemoryLeakChecker.o: $(SOURCE)MemoryLeakChecker.cpp $(INCLUDES)MemoryLeakChecker.hpp
	g++ -g -c -std=c++11 $(SOURCE)MemoryLeakChecker.cpp -I$(INCLUDES) -o $(BUILD)MemoryLeakChecker.o

clean:
	-del $(BUILD)main.o $(BUILD)MemoryLeakChecker.o $(BIN)asdf.exe