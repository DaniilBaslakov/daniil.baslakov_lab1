#include <stdio.h>
#include <stdlib.h>

struct          s_unical
{
    char        symb[256];
    int         freq[256];
}               s_symbal;

void    bubble_sort(int *un)
{
    int i;
    int temp;
    int j;
    char temp2;

    i = 0;
    while (i < *un)
    {
        j = 0;
        while (j < *un)
        {
            
            if (s_symbal.freq[j + 1] && (s_symbal.freq[j + 1] > s_symbal.freq[j]))
            {
                temp = s_symbal.freq[j];
                s_symbal.freq[j] = s_symbal.freq[j + 1];
                s_symbal.freq[j + 1] = temp;
                temp2 = s_symbal.symb[j];
                s_symbal.symb[j] = s_symbal.symb[j + 1];
                s_symbal.symb[j + 1] = temp2;
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
        if (s_symbal.symb[i] == str)
            break;
        i++;
    }
    s_symbal.freq[i] += 1;
}

int    check_symb(char str)
{
    int i;

    i = 0;
    while (i < 256)
    {
        if (s_symbal.symb[i++] == str)
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
            s_symbal.symb[i] = str[count];
            s_symbal.freq[i] = 1;
            *un += 1;
            i++;
        }
        count++;
    }
    //s_symbal.symb[count] = '\0';
}
int     main(void)
{
    char            *str;
    int             i;
    int             un;

    un = 0;
    str = "Hello, world!";
    fill_arr(str, &un);
    bubble_sort(&un);
    i = 0;
    while (s_symbal.symb[i])
    {
        printf("s_symbal.symb %c | s_symbal.freq %d |  count %d\n", s_symbal.symb[i], s_symbal.freq[i], i + 1);
        i++;
    }  
    return (0);
}