#include <stdio.h>

#define CONCAT(__str1, __str2) __str1 ## __str2
#define STRINGIZE(__r) #__r

int main()
{
    int r = CONCAT(1, 3);
    char *p = STRINGIZE(1234);
    printf("%d %d %s\n", r, CONCAT(1,2), p);

    return 0;
}

