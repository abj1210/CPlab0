
test: 
	make parser
	./parser test.c

parser: parser.tab.c lex.yy.c syntax_tree.c main.c
	gcc parser.tab.c syntax_tree.c main.c  -lfl -ly  -o parser

lex.yy.c: lex.l
	flex --header-file=flex.h  lex.l

	
parser.tab.c: parser.y
	bison -d parser.y

clean:
	rm -rf *.out *.o lex.yy.c parser.tab.c parser.tab.h