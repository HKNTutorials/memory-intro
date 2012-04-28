#include <stdlib.h>
#include <stdio.h>

typedef struct object {
    char * letter;
    int number;
} object;

void printobj(object * curobj);
void copy(object * source, object * dest);
void destroy(object * source);

int main() {
    // Create object
    object * mon = malloc( sizeof(object) );
    char * letter = "g";
    mon->letter = malloc( sizeof(char) );
    *(mon->letter) = *letter;
    mon->number = 108;
    printf("monday sponsored by: "); printobj(mon);
    
    // Copy into new object
    object * tues = malloc( sizeof(object) );
    copy(mon, tues);

    // Destroy old object
    destroy(mon);

    printf("tuesday sponsored by: "); printobj(tues);
    destroy(tues);

    object * wed = malloc( sizeof(object) );
    letter = "c";
    wed->letter = malloc( sizeof(char) );
    *(wed->letter) = *letter;
    wed->number = 6;

    object * thurs = malloc( sizeof(object) );
    letter = "z";
    thurs->letter = malloc( sizeof(char) );
    *(thurs->letter) = *letter;
    thurs->number = 7;

    printf("wednesday sponsored by: "); printobj(wed);
    printf("thursday sponsored by: "); printobj(thurs);

    destroy(wed); destroy(thurs);


    return 0;
}

void copy(object * source, object * dest) {
    dest->letter = source->letter;
    dest->number = source->number;
}

void destroy(object * source) {
    free(source->letter);
    free(source);
}

void printobj(object * curobj) {
    printf("the letter %c and the number %d\n", *(curobj->letter), curobj->number);
}
