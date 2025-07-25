CXX = g++-14
CXXFLAGS = -std=c++20 -Wall -MMD -Werror=vla
EXEC = sorcery
OBJECTS = subject.o ability.o abilitymanager.o card.o minion.o spell.o enchantment.o ritual.o ascii_graphics.o collection.o activeminions.o graveyard.o info.o deck.o hand.o display.o text.o graphics.o player.o game.o input.o main.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} # Comment out for Q3
	#${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} -lX11 # Uncomment for Q3

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
