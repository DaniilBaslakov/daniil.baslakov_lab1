#include <stdio.h>
#include <stdlib.h>

struct          s_unical
{
    char        symb[256];
    int         freq[256];
}               s_symbol;

void    bubble_sort(int *un)
{
    int     i;
    int     temp;
    int     j;
    char    temp2;

    i = 0;
    while (i < *un)
    {
        j = 0;
        while (j < *un)
        {
            
            if (s_symbol.freq[j + 1] && (s_symbol.freq[j + 1] > s_symbol.freq[j]))
            {
                temp = s_symbol.freq[j];
                s_symbol.freq[j] = s_symbol.freq[j + 1];
                s_symbol.freq[j + 1] = temp;
                temp2 = s_symbol.symb[j];
                s_symbol.symb[j] = s_symbol.symb[j + 1];
                s_symbol.symb[j + 1] = temp2;
            }
            j++;
        }
        i++;
    }
}

void    increase_freq(char str)
{
    int i;

    i = 0;
    while (i < 256)
    {
        if (s_symbol.symb[i] == str)
            break;
        i++;
    }
    s_symbol.freq[i] += 1;
}

int    check_symb(char str)
{
    int i;

    i = 0;
    while (i < 256)
    {
        if (s_symbol.symb[i++] == str)
            return (1);
    }
    return (0);    
}

void    fill_arr(char *str, int *un)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while (str[count])
    {
        if (check_symb(str[count]))
            increase_freq(str[count]);  
        else
        {
            s_symbol.symb[i] = str[count];
            s_symbol.freq[i] = 1;
            *un += 1;
            i++;
        }
        count++;
    }
    s_symbol.symb[i + 1] = '\0';
}

int     main(int argc, char **argv)
{
    char    *str;
    int     i;
    int     un;

    un = 0;
    str = "Hello, world!";
    if (argc == 2)
        str = argv[1];
    fill_arr(str, &un);
    bubble_sort(&un);
    i = 0;
    while (s_symbol.symb[i])
    {
        printf("%c ", s_symbol.symb[i]);
        i++;
    } 
    putchar('\n');
    i = 0;
    while (s_symbol.symb[i])
    {
        printf("%d ", s_symbol.freq[i]);
        i++;
    } 
    return (0);
}