#include <stdio.h>
#include <setjmp.h>


/* `setjmp(env)' : return 2 values; the first time that invoke it, it returns 0 */ 
/* `longjmp(env, ret)' : make `setjmp' return a new value */
#define Try do {jmp_buf env; if (!setjmp(env)) {
#define Catch }else {
#define End } }while(0)


// i must greate than 0
#define Throw(i) longjmp(env, i)


int main(int argc, char *argv[]) {
	jmp_buf env;
	if (!setjmp(env)) {
		printf("first call, ret = 0.\n");
		longjmp(env, 10);	// exception occured.
		printf("not reachable.\n");
	}else {
		printf("Exception catch.\n");
	}

//	Try
//	Catch
//	End;

	return 0;
}
