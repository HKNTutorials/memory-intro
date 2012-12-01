#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct sponsorships {
    char * day;
    char letter;
    int number;
} sponsorships;

sponsorships * make_day(char * day, char letter, int number);
void print_struct(sponsorships * cur_spons);
void copy_struct(sponsorships * source, sponsorships * dest);
void destroy(sponsorships * source);

/**
 * Print out Sesame Street letters and numbers of the day, making
 * sure to delete your memory when you're done with it.
 */
int main() {
    sponsorships *mon, *tues, *wed, *thurs, *fri;

    mon = make_day("monday", 'g', 108);
    tues = malloc( sizeof(sponsorships) );  /* allocate space for tuesday */
    copy_struct(mon, tues);

    print_struct(mon);
    destroy(mon);

    print_struct(tues);
    destroy(tues);

    wed = make_day("wednesday", 'c', 6);
    thurs = make_day("thursday", 'z', 7);
    fri = make_day("friday", 'u', 300);

    print_struct(wed);
    print_struct(thurs);
    print_struct(fri);

    destroy(thurs);
    destroy(wed);
    destroy(fri);

    return 0;
}

/* allocates and populates a sponsorships structure and returns a pointer to it */
sponsorships * make_day(char * day, char letter, int number) {
    sponsorships * spons;
    spons = malloc( sizeof(sponsorships) );

    spons->day = malloc( sizeof(char) * (strlen(day)+1) );
    strcpy(spons->day, day);

    spons->letter = letter;
    spons->number = number;

    return spons;
}

/* copies the sponsorship data from one day into an empty string */
void copy_struct(sponsorships * source, sponsorships * dest) {
    dest->day = source->day;
    dest->letter = source->letter;
    dest->number = source->number;
}

/* deallocates sponsorship data */
void destroy(sponsorships * source) {
    free(source->day);
    free(source);
}

void print_struct(sponsorships * cur_spons) {
    printf("%s is brought to you by the letter %c and the number %d\n",
            cur_spons->day, cur_spons->letter, cur_spons->number);
}
