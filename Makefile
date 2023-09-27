compile: evaluator.exe
	./evaluator.exe
build: y.tab.c lex.yy.c
	gcc y.tab.c lex.yy.c -o evaluator.exe
lex.yy.c: exptree.l
	lex $<
y.tab.c: exptree.y
	yacc -d $<
clean:
	rm -f lex.yy.c y.tab.c y.tab.h