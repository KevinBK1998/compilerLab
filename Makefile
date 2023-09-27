XSM_DIR = ~/compilerLab/xsm_expl
copy: a.xsm
	cp $< ${XSM_DIR}
compile: build
	./compiler.exe code.expl
build: y.tab.c lex.yy.c
	gcc y.tab.c lex.yy.c -o compiler.exe
lex.yy.c: tokens.l
	lex $<
y.tab.c: syntax.y
	yacc -d $<
clean:
	rm -f lex.yy.c y.tab.c y.tab.h