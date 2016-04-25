# I am a comment, and I want to say that the variable CC will be
# the compiler to use.
FLEX=flex
CC=cc

all: cafezinho
	$(CC) -o teste lexico.cpp
	@echo "cafezinho pronto"	

cafezinho: lexico sintatico

lexico:
	$(FLEX) -o lexico.cpp cafezinho.lex
	@echo "lexico pronto"

sintatico:
	@echo "sintatico pronto"

clean:
	rm *.cpp
