#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#define OFFSETOF(type, member) (size_t)&(((type*)0)->member)
struct S1
{
	char c1;
	int i;
	char c2;
};

int main()
{
	printf("%d\n", OFFSETOF(struct S1, c1));
	printf("%d\n", OFFSETOF(struct S1, i));
	printf("%d\n", OFFSETOF(struct S1, c2));
	return 0;
}