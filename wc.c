#include <stdlib.h>
#include <stdio.h>

int wordcount(char *str) {
	int words = 0;
	while (*str++ != '\0') {
		if (*str++ == ' ') {
			words++;
		}
	}
	// we count the gaps between words so add one to the count
	return words+1;
}

int main() {
	char *sentences[] = {
		"this is a first sentence",
		"this is another sentence",
		"why does it work so randomly?",
		"should I use GDB to debug this?",
		"it  must have something to do with whitespace   ",
		"word",
		"a couple words",
		"way   too many    spaces between\nwords"
		};
	int i;
	for (i = 0; i < sizeof(sentences)/sizeof(char*); i++) {
		printf("%s: %d\n", sentences[i], wordcount(sentences[i]));
	}
	return 0;
}
