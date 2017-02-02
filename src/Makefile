# Makefile
# author: Hang
# Date: 13.11.2016

# search all of headers in src
HEADERS = $(shell ls *.h)
# search all of sources in src
SOURCES = $(shell ls *.cpp)

# record all flags of used compiling paras.
CFLAGS := -Wall -ggdb -c

# record all targets will be generated.
OTHER_OBJECTS := main.o input_management.o map_management.o display_management.o datetime.o

CHARACTER_OBJECTS := chars_management.o character.o player.o human.o elf.o dwarf.o hobbit.o orc.o

ITEM_OBJECTS := item_management.o item.o weapon.o armour.o shield.o ring.o

# record all targets were generated.
exec := Game $(OTHER_OBJECTS) $(CHARACTER_OBJECTS) $(ITEM_OBJECTS)

# target all will compile everything
# as it is first target, just "make" will execute it
all : $(exec) fgame

Game : $(OTHER_OBJECTS) $(CHARACTER_OBJECTS) $(ITEM_OBJECTS)
	g++ -o $(exec)

input_management.o : input_management.cpp input_management.h
	g++ $(CFLAGS) input_management.cpp

map_management.o : map_management.cpp map_management.h
	g++ $(CFLAGS) map_management.cpp

display_management.o : display_management.cpp display_management.h
	g++ $(CFLAGS) display_management.cpp

datetime.o : datetime.cpp datetime.h
	g++ $(CFLAGS) datetime.cpp

item_management.o : item_management.cpp item_management.h
	g++ $(CFLAGS) item_management.cpp

item.o : item.cpp item.h
	g++ $(CFLAGS) item.cpp

weapon.o : weapon.cpp weapon.h
	g++ $(CFLAGS) weapon.cpp

armour.o : armour.cpp armour.h
	g++ $(CFLAGS) armour.cpp

shield.o : shield.cpp shield.h
	g++ $(CFLAGS) shield.cpp

ring.o : ring.cpp ring.h
	g++ $(CFLAGS) ring.cpp

chars_management.o : chars_management.cpp chars_management.h
	g++ $(CFLAGS) chars_management.cpp

observer.o : observer.cpp observer.h
	g++ $(CFLAGS) observer.cpp

character.o : character.cpp character.h
	g++ $(CFLAGS) character.cpp

player.o : player.cpp player.h
	g++ $(CFLAGS) player.cpp

human.o : human.cpp human.h
	g++ $(CFLAGS) human.cpp

elf.o : elf.cpp elf.h
	g++ $(CFLAGS) elf.cpp

dwarf.o : dwarf.cpp dwarf.h
	g++ $(CFLAGS) dwarf.cpp

hobbit.o : hobbit.cpp hobbit.h
	g++ $(CFLAGS) hobbit.cpp

orc.o : orc.cpp orc.h
	g++ $(CFLAGS) orc.cpp

main.o : main.cpp
	g++ $(CFLAGS) main.cpp

fgame : Game
	./Game

clean :
	rm Game *.o *~ \#*

# offer a function of tar source code
zip:
	tar cvf FantasticGame_Group8.tar ../src/*.cpp ../src/*.h ../src/Makefile ../EE6411_Group8_STL_explanation.pdf

# list the headers and sources of the game
dir:
	echo "Headers: \n" $(HEADERS) "\nSources:\n" $(SOURCES)
