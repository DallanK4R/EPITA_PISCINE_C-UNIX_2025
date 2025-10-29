
#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>

void freq_analysis(const char text[], const char table[])
{
    int freq[26] = { 0 };
    int present[26] = { 0 };
    int order[26];
    int n = 0;

    for (int i = 0; text[i] != '\0'; ++i)
    {
        int k = text[i] - 'A';
        if (!present[k])
        {
            present[k] = 1;
            order[n++] = k;
        }
        freq[k]++;
    }

    for (int i = 0; i < n; ++i)
    {
        int best = i;
        for (int j = i + 1; j < n; ++j)
        {
            if (freq[order[j]] > freq[order[best]]
                || (freq[order[j]] == freq[order[best]]
                    && order[j] < order[best]))
                best = j;
        }
        int t = order[i];
        order[i] = order[best];
        order[best] = t;
    }

    char map[26] = { 0 };
    for (int i = 0; i < n; ++i)
        map[order[i]] = table[i];

    for (int k = 0; k < 26; ++k)
        if (present[k])
            printf("%c %c\n", 'A' + k, map[k]);
}
