/* Generated by Nim Compiler v0.11.2 */
/*   (c) 2015 Andreas Rumpf */
/* The generated code is subject to the original license. */
/* Compiled for: Linux, amd64, gcc */
/* Command for C compiler:
   gcc -c  -w  -I/usr/lib/nim -o /home/hacked/dotfiles/nimcache/main.o /home/hacked/dotfiles/nimcache/main.c */
#define NIM_INTBITS 64
#include "nimbase.h"

#include <stdio.h>
typedef struct TGenericSeq TGenericSeq;
typedef struct NimStringDesc NimStringDesc;
struct  TGenericSeq  {
NI len;
NI reserved;
};
struct  NimStringDesc  {
  TGenericSeq Sup;
NIM_CHAR data[SEQ_DECL_SIZE];
};
static N_INLINE(void, initStackBottomWith)(void* locals);
N_NOINLINE(void, setStackBottom)(void* thestackbottom);
static N_INLINE(void, nimFrame)(TFrame* s);
N_NOINLINE(void, stackoverflow_20001)(void);
static N_INLINE(void, popFrame)(void);
NIM_EXTERNC N_NOINLINE(void, systemInit)(void);
NIM_EXTERNC N_NOINLINE(void, systemDatInit)(void);
NIM_EXTERNC N_NOINLINE(void, mainInit)(void);
NIM_EXTERNC N_NOINLINE(void, mainDatInit)(void);
STRING_LITERAL(TMP139, "\033[1;31m test", 12);
extern TFrame* frameptr_17042;

static N_INLINE(void, initStackBottomWith)(void* locals) {
	setStackBottom(locals);
}
void PreMainInner() {
	systemInit();
	mainDatInit();
}

void PreMain() {
	void (*volatile inner)();
	systemDatInit();
	inner = PreMainInner;
	initStackBottomWith((void *)&inner);
	(*inner)();
}

int cmdCount;
char** cmdLine;
char** gEnv;
N_CDECL(void, NimMainInner)(void) {
	mainInit();
}

N_CDECL(void, NimMain)(void) {
	void (*volatile inner)();
	PreMain();
	inner = NimMainInner;
	initStackBottomWith((void *)&inner);
	(*inner)();
}

int main(int argc, char** args, char** env) {
	cmdLine = args;
	cmdCount = argc;
	gEnv = env;
	NimMain();
	return nim_program_result;
}


static N_INLINE(void, nimFrame)(TFrame* s) {
	NI LOC1;
	LOC1 = 0;
	{
		if (!(frameptr_17042 == NIM_NIL)) goto LA4;
		LOC1 = ((NI) 0);
	}
	goto LA2;
	LA4: ;
	{
		LOC1 = ((NI) ((NI16)((*frameptr_17042).calldepth + ((NI16) 1))));
	}
	LA2: ;
	(*s).calldepth = ((NI16) (LOC1));
	(*s).prev = frameptr_17042;
	frameptr_17042 = s;
	{
		if (!((*s).calldepth == ((NI16) 2000))) goto LA9;
		stackoverflow_20001();
	}
	LA9: ;
}

static N_INLINE(void, popFrame)(void) {
	frameptr_17042 = (*frameptr_17042).prev;
}
NIM_EXTERNC N_NOINLINE(void, mainInit)(void) {
	nimfr("main", "main.nim")
	nimln(5, "main.nim");
	printf("%s\012", ((NimStringDesc*) &TMP139)? (((NimStringDesc*) &TMP139))->data:"nil");
	popFrame();
}

NIM_EXTERNC N_NOINLINE(void, mainDatInit)(void) {
}

