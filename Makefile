CXX=g++
XXFLAGS=-Wall -MMD
EXEC=main
OBJECTS=main.o gamepiece.o gameboard.o emptyspace.o king.o queen.o knight.o bishop.o pawn.o rook.o player.o
DEPENDS=${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${XXFLAGS} ${OBJECTS} -o ${EXEC}
-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${EXEC}
