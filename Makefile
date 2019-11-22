CXX = g++
LIBS = -lncurses

DIR_INCLUDE = include
DIR_BUILD = build
DIR_SRC = src

CXXFLAGS = $(LIBS) -I $(DIR_INCLUDE)

all: clean createdir tetris.debug tetris.build

tetris.debug: $(DIR_SRC)/*.cpp
	$(CXX) -g $^ -o $(DIR_BUILD)/tetris.debug $(CXXFLAGS)
	@echo "\n\t!! New File Created: $(DIR_BUILD)/$@\n"

tetris.build: $(DIR_SRC)/*.cpp
	$(CXX) $^ -o $(DIR_BUILD)/tetris.build $(CXXFLAGS)
	@echo "\n\t!! New File Created: $(DIR_BUILD)/$@\n"

clean:
	rm -rf build
	@echo "\n\t!! A Folder Cleaned: $(DIR_BUILD)\n"

createdir:

	mkdir build
	@echo "\n\t!! A Folder Created: $(DIR_BUILD)\n"
