

#include <stdio.h>
#include <stdlib.h>
#include <time.h>



// random string generator wrapper function
char* rand_string_alloc(size_t size) {
    char *s  = malloc(size + 1);
    if(s){
        rand_string(s, size);
    }
    return s;
}




void rand_string(char *s, size_t size){
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (size_t i = 0; i < size ; i++) {
        int key = rand() % (int) (sizeof(charset) -1);
        s[i] = charset[key];
        }
        s[size] = "\0";
    } 

     


int main() {
    char *str;
    size_t size = 10;  //specify a value for size of word

	/* seed the randomizer */
	srand( (unsigned)time(NULL) );

	printf("Today's random word: ");
    str = rand_string_alloc(size );
    if (str) {
        printf("%s",str);
        free (str);
    } else {
        printf("invalid.\n");
    }

	return(0);
}