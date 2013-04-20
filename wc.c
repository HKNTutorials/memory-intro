#include <stdlib.h>
#include <stdio.h>

// Count the number of words in a null-terminated string. Intended to handle
// only the space character as whitespace and only a single whitespace
// character between words.
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
		"never gonna give you up",
		"why does it work so randomly?",
		"never gonna let you done",
		"never gonna run around",
		"and desert you.",
		"should I use GDB to debug this? never gonna make you cry",
		"it must have something to do with whitespace",
		"word",
		"a couple words",
		"On a bright summer day Princess starburst walked over to Storybelle to show her her pink star-shaped medallion with a yellow jewel and said \"never gonna say goodbye, never gonna tell a lie and hurt you\"",
		};
	int i;
	// This sizeof only works because sentences is a static array. This for loop
	// construct is not buggy and correctly iterates over the sentences using
	// sentences[i].
	for (i = 0; i < sizeof(sentences)/sizeof(char*); i++) {
		printf("%s: %d\n", sentences[i], wordcount(sentences[i]));
	}
	return 0;
}
