CC := g++
SOURCES := $(wildcard src/*cpp)
OBJECTS := $(patsubst src/%.cpp, obj/%.o, $(SOURCES))
INC := -I./inc
DEPENDS := $(patsubst src/%.cpp,obj/%.dep,$(SOURCES))

bin/out : $(OBJECTS) ./bin
	$(CC) $(OBJECTS) -o $@

obj/%.dep : src/%.cpp
	mkdir -p obj
	$(CC) $(INC) -MM $< -MT "$@ $(patsubst %.dep,%.o,$@)" -o $@

obj/%.o :
	$(CC) -c $(INC) $< -o $@ 

run:
	./bin/out    

./bin:
	mkdir -p bin
.PHONY : clean

clean: 
	rm -rf ./obj  ./bin

-include $(DEPENDS)


