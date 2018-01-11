#include "config.h"
#include <stdio.h>
#include <errno.h>

#ifdef HAVE_STRING_H
#include <string.h>
#endif

#ifdef HAVE_SYS_TIME_H
#include <sys/time.h>
#endif

void checkIfFunctionsDoExist()
{
#ifndef HAVE_GETTIMEOFDAY
    printf("getTimeOfDay not supported");
    exit(1);
#endif
#ifndef HAVE_STRERROR
    printf("strerr not supported");
    exit(2);
#endif
}

int main()
{
    FILE *fd;
    int charactersWritten = 0;
    int returnCode = 0xff;
    struct timeval first, second;
    checkIfFunctionsDoExist();

    fd = fopen("test.txt", "w");
    charactersWritten = fprintf(fd, "Hello World!\n");

    gettimeofday(&first, NULL);
    returnCode = fclose(fd);
    gettimeofday(&second, NULL);
    printf("First close took %d \n", second.tv_usec - first.tv_usec);
    if (returnCode == 0)
    {
        printf("First close was successfull\n");
    }
    else
    {
        printf("First close was *NOT* ok \n");
    }

    gettimeofday(&first, NULL);
    returnCode = fclose(fd);
    gettimeofday(&second, NULL);
    printf("Second close took %d \n", second.tv_usec - first.tv_usec);
    if (returnCode == 0)
    {
        printf("Second close was successfull\n");
    }
    else
    {
        printf("Second close was *NOT* ok with %d \n", returnCode);
        printf("Errno is %d\n", errno);
        char *text = strerror((int)errno);
        printf("Error string is %s \n", text);
    }

    return 0;
}