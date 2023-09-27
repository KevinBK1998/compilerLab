XSM_DIR = ~/compilerLab/xsm_expl
copy: a.xsm
	cp $< ${XSM_DIR}
link: linker.exe x.xobj
	./linker.exe
compile: compiler.exe code.expl
	./compiler.exe code.expl
compiler.exe: y.tab.c lex.yy.c
	gcc y.tab.c lex.yy.c -o compiler.exe
linker.exe: link.l
	lex link.l
	gcc lex.yy.c -o linker.exe
lex.yy.c: tokens.l
	lex $<
y.tab.c: syntax.y
	yacc -d $<
clean:
	rm -f lex.yy.c y.tab.c y.tab.h compiler.exe linker.exe