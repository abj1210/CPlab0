parser: lex.yy.c parser.tab.c syntax_tree.c syntax_check_update.c hash.c ir.c stack.c main.c
	gcc parser.tab.c syntax_tree.c syntax_check_update.c hash.c ir.c stack.c obj.c reg.c main.c  -lfl -ly  -o parser

test: 
	make parser
	./parser ../test.c ../out.s

lex.yy.c: lex.l
	flex --header-file=flex.h  lex.l

	
parser.tab.c: parser.y
	bison -d -v parser.y

clean:
	rm -f *.out *.o flex.h lex.yy.c parser.tab.c parser.tab.h parser scanner 