#include <assert.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *date_format(const char *format)
{
    time_t now = time(NULL);
    struct tm *utc = gmtime(&now);
    int jour = utc->tm_mday;
    int mois = utc->tm_mon + 1;
    int annee = utc->tm_year + 1900;
    int i = 0;
    char *res = malloc(sizeof(char) * 11);
    char *result = res;
    if (!res)
        return NULL;
    while (format[i])
    {
        if (format[i] == 'Y')
            res += sprintf(res, "%04d", annee);
        else if (format[i] == 'M')
            res += sprintf(res, "%02d", mois);
        else if (format[i] == 'D')
            res += sprintf(res, "%02d", jour);
        else
        {
            *res = format[i];
            res++;
        }
        i++;
    }
    if (i != 5)
    {
        free(result);
        return NULL;
    }
    result[10] = 0;
    return result;
}
