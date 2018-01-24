SRC_CXX=\
	Piece.cxx \
	Joueur.cxx \
	Echiquier.cxx\
	JoueurBlanc.cxx\
	JoueurNoir.cxx\
	pion.cxx\
	fou.cxx\
	Tour.cxx\
	Roi.cxx\
	reine.cxx\
	Cavalier.cxx\

OBJ=${SRC_CXX:.cxx=.o}

all: testPiece

testPiece: $(OBJ) testPiece.o
	g++ $(OBJ) testPiece.o -o testPiece -lm

%.o: %.cxx
	g++ -c $<

clean:
	@rm -f $(OBJ) testPiece.o testPiece *~

