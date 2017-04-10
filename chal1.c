#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <time.h>

int main()
{
	char response[0xc0];
	memset(response, 0, sizeof(response));
	uint32_t year;
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	uint32_t bytes_read;
	setbuf(stdout, NULL);
	printf("Welcome to the NOP Certification Exam\n");
	printf("-------------------------------------\n");
	printf("%04d-%02d-%02d %02d:%02d:%02d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
	printf("-------------------------------------\n"
	       "The clock starts now, the rules are simple. You have 25m to root this box. If\n"
	       "you happen to have spare 0day on the linux kernel and are willing to spend it\n"
	       "here, I would be happy to broker it for a small fee. The total payout is much\n"
	       "larger than the prize for the fastest time. If instead you'd rather solve the\n"
	       "challenge as intended, note that this binary is running on port 9999 as root.\n"
	       "\n"
	       "-------------------------------------\n"
	       "Prove your pwnage by either a \"cat /flag\" or a \"rm -f /\", hackers choice.\n"
	       "-------------------------------------\n"
	       "\n"
	       "-------------------------------------\n"
	       "Binary Ninja has a built in shellcode compiler that can compile this payload:\n"
	       "-------------------------------------\n"
	       "int main (uint64_t a) {\n"
	       "   system(\"cat /flag\");\n"
	       "}\n"
	       "\n"
	       "-------------------------------------\n"
	       "The environment:\n"
	       " 1) kernel.randomize_va_space = 0\n"
	       " 2) kernel.yama.ptrace_scope = 0 \n"
	       " 3) compiled with execstack and no-stack-protector \n"
	       "-------------------------------------\n\n"
	       "Binary Ninja has a built in shellcode compiler that can compile this payload:\n"
	       "Prove yourself worthy. What year did the Daily Dave mail list first start up?\nYear: ");

	if (!scanf("%d", &year) || year != 2002)
	{
		printf("\033[31m\n"
		       " _____   ___  ___  ___ _____   _____  _   _ ___________ \n"
		       "|  __ \\ / _ \\ |  \\/  ||  ___| |  _  || | | |  ___| ___ \\\n"
		       "| |  \\// /_\\ \\| .  . || |__   | | | || | | | |__ | |_/ /\n"
		       "| | __ |  _  || |\\/| ||  __|  | | | || | | |  __||    / \n"
		       "| |_\\ \\| | | || |  | || |___  \\ \\_/ /\\ \\_/ / |___| |\\ \\ \n"
		       " \\____/\\_| |_/\\_|  |_/\\____/   \\___/  \\___/\\____/\\_| \\_|\n\n\033[0m");
		exit(0);
	}
	getc(stdin);
	printf("glhf: ");
	if (!fgets(response, 500, stdin))
		exit(0);

/*
	for (int i=0; i< 500; i++)
	{
		printf ("%02x", (uint8_t) response[i]);
	}
*/

	return 0;
}
