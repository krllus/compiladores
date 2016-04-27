# I am a comment, and I want to say that the variable CC will be
# the compiler to use.
FLEX = flex
CC = g++
MAIN = cafezinho

all: $(MAIN)
	$(CC) -o $(MAIN) lexico.cpp
	@echo "cafezinho pronto"

$(MAIN): lexico sintatico

lexico: cafezinho.lex
	$(FLEX) -o lexico.cpp cafezinho.lex
	@echo "lexico pronto"

sintatico:
	@echo "sintatico pronto"

clean:
	rm *.cpp $(MAIN)
