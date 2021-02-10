CC = g++
SOURCE = $(wildcard *.cpp)
OBJECTS = $(patsubst %.cpp,%.o, $(SOURCE))
EXECUTABLE = ISECTotalWar

all: $(OBJECTS)
	@ $(CC) $(patsubst %,Build/%, $(OBJECTS)) -o $(EXECUTABLE)
	@ echo "Compilation finished sucessfully."
	
%.o: %.cpp | folder
	@ $(CC) -c $< -o Build/$@

folder:
	@ mkdir -p Build

clean: clean-obj
	@ rm $(EXECUTABLE).exe -f
	@ echo "Directory cleaned."
	
clean-obj:
	@ rm -r Build -f