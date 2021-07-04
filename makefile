
TARGET_LIST=project1

SDL_COMP_FLAGS=-I/usr/include/sdl
SDL_LINK_FLAGS=-lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf

########### project1 ###########
FILE-project1=prog

COMPILER-project1=g++
COMPILATION_FLAGS-project1=-O3 -Wall -Wextra -pedantic $(SDL_COMP_FLAGS)
LINKER_FLAGS-project1=$(SDL_LINK_FLAGS)

DEFINES-project1=DEBUG

MAINFILE-project1=main
 SRCPATH-project1=./src/
 INCPATH-project1=./include/
 OBJPATH-project1=./objects/

SOURCE_EXT-project1=.cpp
HEADER_EXT-project1=.hpp
################################

FIRST_TARGET=$(firstword $(TARGET_LIST))

.DEFAULT_GOAL:=$(FIRST_TARGET)

FILE=

FILE-SOURCE=$(wildcard $(SRCPATH-$(FILE))*$(SOURCE_EXT-$(FILE)))
HEADERS=$(wildcard $(INCPATH-$(FILE))*$(HEADER_EXT-$(FILE)))
OBJECTS=$(subst $(SOURCE_EXT-$(FILE)),.o,$(subst $(SRCPATH-$(FILE)),$(OBJPATH-$(FILE)),$(FILE-SOURCE)))

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
	@ $(COMPILER-$(FILE)) $^ $(COMPILATION_FLAGS-$(FILE)) $(LINKER_FLAGS-$(FILE)) -o $(FILE-$(FILE)) $(foreach I,$(INCPATH-$(FILE)),$(shell echo -I$(I)))

$(OBJPATH-$(FILE))%.o: $(SRCPATH-$(FILE))%$(SOURCE_EXT-$(FILE)) $(INCPATH-$(FILE))%$(HEADER_EXT-$(FILE))
	@ printf "[%3i%%] \e[32mBuilding $(COMPILER-$(FILE)) object $@\e[0m\n" $$(($(CURCOUNT)*100/$(OBJCOUNT)))
	@ $(COMPILER-$(FILE)) $< -c $(COMPILATION_FLAGS-$(FILE)) -o $@ $(foreach I,$(INCPATH-$(FILE)),$(shell echo -I$(I))) $(foreach d,$(DEFINES-$(FILES)),$(shell echo -D$(d)))
	@ $(eval CURCOUNT=$(shell echo $$(($(CURCOUNT)+1))))

$(OBJPATH-$(FILE))$(MAINFILE-$(FILE)).o: $(SRCPATH-$(FILE))$(MAINFILE-$(FILE))$(SOURCE_EXT-$(FILE)) $(HEADERS)
	@ printf "[%3i%%] \e[32mBuilding $(COMPILER-$(FILE)) object $@\e[0m\n" $$(($(CURCOUNT)*100/$(OBJCOUNT)))
	@ $(COMPILER-$(FILE)) $< -c $(COMPILATION_FLAGS-$(FILE)) -o $@ $(foreach I,$(INCPATH-$(FILE)),$(shell echo -I$(I))) $(foreach d,$(DEFINES-$(FILES)),$(shell echo -D$(d)))
	@ $(eval CURCOUNT=$(shell echo $$(($(CURCOUNT)+1))))

objdir:
	-@ $(foreach F,$(TARGET_LIST), $(shell mkdir -p $(OBJPATH-$(F))))

clean:
	-@ $(foreach F,$(TARGET_LIST), $(shell rm -rf $(OBJPATH-$(F))*.o $(FILE-$(F)) *~))
	@ echo "All binaries have been deleted."

.PHONY: all clean