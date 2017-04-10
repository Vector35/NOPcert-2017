#include <stdio.h>
#include <sys/mman.h>

char shellCodeGoesHere[512];

int main()
{
	long what;
	long *where = (long *) 1;
	setbuf(stdout, NULL);
	mprotect(shellCodeGoesHere, 512, PROT_READ | PROT_WRITE | PROT_EXEC);
	while(where != 0)
	{
		puts("What?");
		scanf("%ld", &what);
		puts("Where?");
		scanf("%ld", (long int*) &where);
		if(where != 0)
			*where = what;
	}
}
