
SDL_COMP_FLAGS_NATIVE = -I/usr/include/SDL2
SDL_LINK_FLAGS_NATIVE = -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf

SDL_COMP_FLAGS_CROSS = -I/usr/local/x86_64-w64-mingw32/include
SDL_LINK_FLAGS_CROSS = -L/usr/local/x86_64-w64-mingw32/lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf

# gcc
# g++
# i686-w64-mingw32-gcc
# x86_64-w64-mingw32-gcc
# i686-w64-mingw32-g++
# x86_64-w64-mingw32-g++

########### general ###########
MAINFILE   = main
SRC_FOLDER = src
INC_FOLDER = include

SOURCE_EXT = .cpp
HEADER_EXT = .hpp
###############################

TARGET_LIST = debug linux windows
########### debug ###########
FILE-debug = prog

COMPILER-debug          = g++
COMPILATION_FLAGS-debug = -Wall -Wextra -pedantic -g $(SDL_COMP_FLAGS_NATIVE)
LINKER_FLAGS-debug      = $(SDL_LINK_FLAGS_NATIVE)

DEFINES-debug = DEBUG

OBJ_FOLDER-debug = objects/Linux/debug

########### linux ###########
FILE-linux = paint

COMPILER-linux          = g++
COMPILATION_FLAGS-linux = -O3 -Wall -Wextra -pedantic $(SDL_COMP_FLAGS_NATIVE)
LINKER_FLAGS-linux      = $(SDL_LINK_FLAGS_NATIVE)

DEFINES-linux = 

OBJ_FOLDER-linux = objects/Linux/release

########### windows ###########
FILE-windows = paint.exe

COMPILER-windows          = x86_64-w64-mingw32-g++
COMPILATION_FLAGS-windows = -O3 -Wall -Wextra -pedantic $(SDL_COMP_FLAGS_CROSS)
LINKER_FLAGS-windows      = $(SDL_LINK_FLAGS_CROSS)

DEFINES-windows = DEBUG

OBJ_FOLDER-windows = objects/Windows
###############################

.DEFAULT_GOAL:=$(firstword $(TARGET_LIST))

FILE=

FILE-SOURCE=$(wildcard ./$(SRC_FOLDER)/*$(SOURCE_EXT))
HEADERS=$(wildcard ./$(INC_FOLDER)/*$(HEADER_EXT))
OBJECTS=$(subst $(SOURCE_EXT),.o,$(subst ./$(SRC_FOLDER)/,./$(OBJ_FOLDER-$(FILE))/,$(FILE-SOURCE)))

OBJCOUNT=$$(($(words $(OBJECTS))+1))
CURCOUNT=1

#DEVELOPEMENT
all: objdir
	@ $(foreach F,$(TARGET_LIST), $(MAKE) --silent --stop $(F);)

%:
	@ $(eval FILE=$@)
	@ if [ "$(findstring $(FILE),$(TARGET_LIST))" = "$(FILE)" ]; then ($(MAKE) --silent --stop FILE=$(FILE) objdir $(FILE-$(FILE));printf "[100%%] Built target %s\n" $(FILE);); else (echo "make: There is no recipe for target '$(FILE)'"; exit); fi

$(FILE-$(FILE)): $(OBJECTS)
	@ printf "[%3i%%] \e[92mLinking executable $(FILE-$(FILE))\e[0m\n" $$(($(CURCOUNT)*100/$(OBJCOUNT)))
	@ $(COMPILER-$(FILE)) $^ $(COMPILATION_FLAGS-$(FILE)) $(LINKER_FLAGS-$(FILE)) -o $(FILE-$(FILE)) $(foreach I,./$(INC_FOLDER)/,$(shell echo -I$(I)))

./$(OBJ_FOLDER-$(FILE))/%.o: ./$(SRC_FOLDER)/%$(SOURCE_EXT) ./$(INC_FOLDER)/%$(HEADER_EXT)
	@ printf "[%3i%%] \e[32mBuilding $(COMPILER-$(FILE)) object $@\e[0m\n" $$(($(CURCOUNT)*100/$(OBJCOUNT)))
	@ $(COMPILER-$(FILE)) $< -c $(COMPILATION_FLAGS-$(FILE)) -o $@ $(foreach I,./$(INC_FOLDER)/,$(shell echo -I$(I))) $(foreach d,$(DEFINES-$(FILE)),$(shell echo -D$(d)))
	@ $(eval CURCOUNT=$(shell echo $$(($(CURCOUNT)+1))))

./$(OBJ_FOLDER-$(FILE))/$(MAINFILE).o: ./$(SRC_FOLDER)/$(MAINFILE)$(SOURCE_EXT) $(HEADERS)
	@ printf "[%3i%%] \e[32mBuilding $(COMPILER-$(FILE)) object $@\e[0m\n" $$(($(CURCOUNT)*100/$(OBJCOUNT)))
	@ $(COMPILER-$(FILE)) $< -c $(COMPILATION_FLAGS-$(FILE)) -o $@ $(foreach I,./$(INC_FOLDER)/,$(shell echo -I$(I))) $(foreach d,$(DEFINES-$(FILE)),$(shell echo -D$(d)))
	@ $(eval CURCOUNT=$(shell echo $$(($(CURCOUNT)+1))))

objdir:
	@ $(foreach F,$(TARGET_LIST), $(shell mkdir -p ./$(OBJ_FOLDER-$(F))/))

clean:
	@ $(foreach F,$(TARGET_LIST), $(shell rm -rf ./$(OBJ_FOLDER-$(F))/*.o $(FILE-$(F)) *~))
	@ echo "All binaries have been deleted."

.PHONY: all clean
