/*
    Knuth-Morris-Pratt string matching algorithm
    Akshay Anand
    10/12/2017
*/

#include <stdio.h>
#include <string.h>

void kmp_matcher(const char string[], const char patter[]);
void compute_prefix(const char patter[], int prefix[]);

int main(int argc, char *argv[])
{
    char string[] = "hellofooworld";
    char pattern[] = "oowo";
    kmp_matcher(string, pattern);
    return 0;
}

void kmp_matcher(const char string[], const char pattern[])
{
    int n = strlen(string), m = strlen(pattern);
    int prefix[m];
    compute_prefix(pattern, prefix);
    int q=-1, found=0;
    for(int i=0; i<n; i++)
    {
        while(q>0 && pattern[q+1]!=string[i])
            q = prefix[q];                 /* backtrack if match streak broken*/
        if(pattern[q+1] == string[i])
            q++;                            /* increment counter when match found*/
        if(q==m-1){     /*if whole pattern matched*/
            printf("Found match at %d\n", i-m+1);
            found=1;
            q=prefix[q];    /* to continue on to find more instances*/
        }
    }
    if(!(found)) printf("Not found\n");
}

void compute_prefix(const char pattern[], int prefix[])
{
    int m = strlen(pattern);
    int k=-1;
    prefix[0] = -1;
    for(int q=1; q<m; q++)
    {
        while(k>0 && pattern[k+1]!=pattern[q])
            k = prefix[k];          /* backtrack if match streak broken*/
        if(pattern[k+1] == pattern[q])
            k++;                /* increment counter when match found*/
        prefix[q] = k;
    }

}
