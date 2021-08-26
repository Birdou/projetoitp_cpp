
#If you are using SDL2
SDL_COMP_FLAGS=-I/usr/include/SDL2 # -I[full path to SDL2 include folder]. Default: -I/usr/include/SDL2
SDL_LINK_FLAGS=-lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf

################################
#executable name (without extension)
FILE=prog

#main file name (where the main function is)
MAINFILE=main

#source files extension (.c, .cpp)
SOURCE_EXT=.cpp
#header files extension (.h, .hpp)
HEADER_EXT=.hpp

#folder that contains the source files (.c, .cpp)
SRCFOLDER=src
#folder that contains the header files (.h, .hpp)
INCFOLDER=include
#folder where the binary files (.o) will be compiled
OBJFOLDER=objects/Linux

#compiler that will be used to build binaries and link the executable (gcc, g++, c++...)
COMPILER=g++

#flags that will be used when compiling binaries
COMPILATION_FLAGS=-Wall -Wextra -pedantic -std=c++11 ${SDL_COMP_FLAGS} -g
#flags that will be used when linking the executable
LINKER_FLAGS=${SDL_LINK_FLAGS}

#environment defines (to use with #ifdef for example)
DEFINES=DEBUG
################################

PERCENT=0

FILE-SOURCE=$(wildcard ./$(SRCFOLDER)/*$(SOURCE_EXT))
HEADERS=$(wildcard ./$(INCFOLDER)/*$(HEADER_EXT))
OBJECTS=$(subst $(SOURCE_EXT),.o,$(subst ./$(SRCFOLDER)/,./$(OBJFOLDER)/,$(FILE-SOURCE)))

OBJCOUNT=$$(($(words $(OBJECTS))+1))
CURCOUNT=0

#DEVELOPEMENT
all: objdir $(FILE)
	@ echo [100%] Built target $(FILE)

$(FILE): $(OBJECTS)
	@ printf "[%3i%%]" $$(($(CURCOUNT)*100/$(OBJCOUNT)))
	@ echo " \e[92mLinking executable $(FILE)\e[0m"
	@ $(COMPILER) $^ $(COMPILATION_FLAGS) $(LINKER_FLAGS) -o $(FILE) $(foreach I,$(INCFOLDER)/,$(shell echo -I$(I)))

$(OBJFOLDER)/%.o: $(SRCFOLDER)/%$(SOURCE_EXT) $(INCFOLDER)/%$(HEADER_EXT)
	@ printf "[%3i%%]" $$(($(CURCOUNT)*100/$(OBJCOUNT)))
	@ echo " \e[32mBuilding $(COMPILER) object $@\e[0m"
	@ $(COMPILER) $< -c $(COMPILATION_FLAGS) -o $@ $(foreach I,$(INCFOLDER)/,$(shell echo -I$(I))) $(foreach d,$(DEFINES),$(shell echo -D$(d)))
	@ $(eval CURCOUNT=$(shell echo $$(($(CURCOUNT)+1))))

$(OBJFOLDER)/$(MAINFILE).o: $(SRCFOLDER)/$(MAINFILE)$(SOURCE_EXT) $(HEADERS)
	@ printf "[%3i%%]" $$(($(CURCOUNT)*100/$(OBJCOUNT)))
	@ echo " \e[32mBuilding $(COMPILER) object $@\e[0m"
	@ $(COMPILER) $< -c $(COMPILATION_FLAGS) -o $@ $(foreach I,$(INCFOLDER)/,$(shell echo -I$(I))) $(foreach d,$(DEFINES),$(shell echo -D$(d)))
	@ $(eval CURCOUNT=$(shell echo $$(($(CURCOUNT)+1))))

objdir:
	@ mkdir -p $(OBJFOLDER)

clean:
	@ rm -rf $(OBJFOLDER)/*.o $(FILE) *~

.PHONY: all clean