#include <stdio.h>
#include <string.h>

void ft_check_rest(char *file, char *wildcard, int *wc, int *i)
{
    int tmp;

    tmp = (*wc);
    tmp++;
    (*i)++;
    while (wildcard[tmp] != '*')
    {
        if (file[(*i)] && wildcard[tmp] != file[(*i)])
            break ;
        if (file[(*i)] == '\0' || wildcard[tmp] == '\0')
            break ;
        if (file[(*i)] && wildcard[tmp] == file[(*i)])
        {
            tmp++;
            (*i)++;
        }
    }
    if (wildcard[tmp] != '*')
    {
        (*wc)--;
        return ;
    }
    (*wc) = tmp;
}

int ft_mid_with(char *file, char *wildcard, int wc)
{
    int i = 0;
    int flag = 0;
    if (file[i])
    {
        while (wildcard[wc] == '*')
        {
            wc++;
            if (!wildcard[wc])
                break ;
            while (file[i])
            {
                if (wildcard[wc] && wildcard[wc] == file[i])
                {
                    ft_check_rest(file, wildcard, &wc, &i);
                    break ;
                }
                else
                    i++;
            }
        }
    }
    if (wildcard[wc] == '\0')
        return (1);
    return (0);
}

int main(void)
{
    int res = ft_mid_with("minishell.c", "*mini*h*l.c*", 0);
    if (res == 1)
        printf("it is fine");
    if (res == 0)
        printf("it is not fine");
}