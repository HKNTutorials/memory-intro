#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct sponsorships {
    char * day;
    char letter;
    int number;
} sponsorships;

sponsorships * init_day(void);
void print_struct(sponsorships * cur_spons);
void copy_struct(sponsorships * source, sponsorships * dest);
void destroy(sponsorships * source);

/**
 * Print out Sesame Street letters and numbers of the day, making
 * sure to delete your memory when you're done with it.
 *
 * this code is OK
 */
int main() {
    sponsorships *temp_day, *today;
    temp_day = init_day();
    today = init_day();

    printf("day letter number: ");
    scanf("%s %c %d", temp_day->day, &(temp_day->letter), &(temp_day->number));

    copy_struct(today, temp_day);
    destroy(temp_day);

    print_struct(today);
    destroy(today);

    return 0;
}

sponsorships * init_day() {
    sponsorships * retval;
    retval = malloc( sizeof(sponsorships) );
    retval->day = malloc( sizeof(char)*15 );
    return retval;
}

void copy_struct(sponsorships * dest, sponsorships * source) {
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
