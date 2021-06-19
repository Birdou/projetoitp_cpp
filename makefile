
SDL_COMP_FLAGS=-IY:/MinGW/include/SDL2
SDL_LINK_FLAGS=-lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf

################################
FILE=prog

MAINFILE=main

SOURCE_EXT=.cpp
HEADER_EXT=.hpp

SRCFOLDER=src
INCFOLDER=include
OBJFOLDER=objects

COMPILER=g++

COMPILATION_FLAGS=-Wall -Wextra -pedantic ${SDL_COMP_FLAGS}
LINKER_FLAGS=${SDL_LINK_FLAGS}

DEFINES=#DEBUG
################################

PERCENT=0

FILE-SOURCE=$(wildcard ./$(SRCFOLDER)/*$(SOURCE_EXT))
HEADERS=$(wildcard ./$(INCFOLDER)/*$(HEADER_EXT))
OBJECTS=$(subst $(SOURCE_EXT),.o,$(subst ./$(SRCFOLDER)/,./$(OBJFOLDER)/,$(FILE-SOURCE)))

OBJCOUNT=$(shell echo|set /a $(words $(OBJECTS))+1)
CURCOUNT=0

#DEVELOPEMENT
all: objdir $(FILE)
	@ echo [100%%] Built target $(FILE)

$(FILE): $(OBJECTS)
	@ $(eval PERCENT=$(shell echo|set /a $(CURCOUNT)*100/$(OBJCOUNT)))
	@ if $(PERCENT) LSS 10 (echo [  $(PERCENT)%%] [1;92mLinking executable $(FILE)[0;21m) else (if $(PERCENT) GEQ 10 (echo [ $(PERCENT)%%] [1;92mLinking executable $(FILE)[0;21m) else (if $(PERCENT) EQU 100 (echo [100%%] [1;92mLinking executable $(FILE)[0;21m)))
	@ $(COMPILER) $^ $(COMPILATION_FLAGS) $(LINKER_FLAGS) -o $(FILE) $(foreach I,./$(INCFOLDER)/,$(shell echo -I$(I)))

./$(OBJFOLDER)/%.o: ./$(SRCFOLDER)/%$(SOURCE_EXT) ./$(INCFOLDER)/%$(HEADER_EXT)
	@ $(eval PERCENT=$(shell echo|set /a $(CURCOUNT)*100/$(OBJCOUNT)))
	@ if $(PERCENT) LSS 10 (echo [  $(PERCENT)%%] [32mBuilding $(COMPILER) object $@[0m) else (if $(PERCENT) GEQ 10 (echo [ $(PERCENT)%%] [32mBuilding $(COMPILER) object $@[0m) else (if $(PERCENT) EQU 100 (echo [100%%] [32mBuilding $(COMPILER) object $@[0m)))
	@ $(COMPILER) $< -c $(COMPILATION_FLAGS) -o $@ $(foreach I,./$(INCFOLDER)/,$(shell echo -I$(I))) $(foreach d,$(DEFINES),$(shell echo -D$(d)))
	@ $(eval CURCOUNT=$(shell echo|set /a $(CURCOUNT)+1))

./$(OBJFOLDER)/$(MAINFILE).o: ./$(SRCFOLDER)/$(MAINFILE)$(SOURCE_EXT) $(HEADERS)
	@ $(eval PERCENT=$(shell echo|set /a $(CURCOUNT)*100/$(OBJCOUNT)))
	@ if $(PERCENT) LSS 10 (echo [  $(PERCENT)%%] [32mBuilding $(COMPILER) object $@[0m) else (if $(PERCENT) GEQ 10 (echo [ $(PERCENT)%%] [32mBuilding $(COMPILER) object $@[0m) else (if $(PERCENT) EQU 100 (echo [100%%] [32mBuilding $(COMPILER) object $@[0m)))
	@ $(COMPILER) $< -c $(COMPILATION_FLAGS) -o $@ $(foreach I,./$(INCFOLDER)/,$(shell echo -I$(I))) $(foreach d,$(DEFINES),$(shell echo -D$(d)))
	@ $(eval CURCOUNT=$(shell echo|set /a $(CURCOUNT)+1))

objdir:
	-@ if NOT EXIST "$(OBJFOLDER)" (mkdir "$(OBJFOLDER)" >nul)

clean:
	-@ del /f /s /q "$(OBJFOLDER)\*.o" "$(FILE).exe" *~ >nul 2>nul

.PHONY: all clean