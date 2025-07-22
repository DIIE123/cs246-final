CXX = g++-14
CXXFLAGS = -std=c++20 -Wall -MMD -Werror=vla
EXEC = sorcery
OBJECTS = ability.o ascii_graphics.o card.o collection.o deck.o display.o game.o graphics.o hand.o input.o main.o minion.o player.o spell.o subject.o text.o # add more later
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} # Comment out for Q3
	#${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} -lX11 # Uncomment for Q3

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
