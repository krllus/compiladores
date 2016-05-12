# I am a comment, and I want to say that the variable CC will be
# the compiler to use.
FLEX = flex
BISON = bison
CC = g++
MAIN = cafezinho

all: sintatico lexico
	$(CC) -o $(MAIN) sintatico.cpp lexico.cpp	
	@echo "cafezinho pronto"

simple: cafezinho.lex cafezinho.yac	
	$(BISON) -d -o sintatico.cpp cafezinho.yac
	$(FLEX) -o lexico.cpp cafezinho.lex
	$(CC) -o $(MAIN) sintatico.cpp lexico.cpp
	@echo "cafezinho pronto"

lexico: cafezinho.lex
	$(FLEX) -o lexico.cpp cafezinho.lex
	@echo "lexico pronto"

sintatico: cafezinho.yac
	$(BISON) -d -o sintatico.cpp cafezinho.yac
	@echo "sintatico pronto"

clean:
	rm *.cpp *.hpp $(MAIN)
	@echo "clean pronto"
