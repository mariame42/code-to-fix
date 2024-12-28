#include <stdio.h>
#include <string.h>

void ft_check_rest(char *file, char *wildcard, int *wc, int *i)
{
    int tmp;
    char close;
    int flag = 1;

    tmp = (*wc);
    // tmp++;
    // (*i)++;
    while (wildcard[tmp] != '*')
    {
        if ((flag == 1 && (wildcard[tmp] == '\'' || wildcard[tmp] == '\"'))
            || (flag == 2 && wildcard[tmp] == close))
        {
            if (flag == 1)
            {
                close = wildcard[tmp];
                tmp++;
                flag = 2;
            }
            else
            {
                close = '\0';
                tmp++;
                flag = 1;
            }
        }
        else
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
    int tmp = 0;
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
                else if (wildcard[wc] == '\'' || wildcard[wc] == '\"')
                {
                    tmp = wc + 1;
                    if (wildcard[tmp] && wildcard[tmp] == file[i])
                    {   
                        ft_check_rest(file, wildcard, &wc, &i);
                        break ;
                    }
                    else
                        i++;
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

int main(int ac, char **av)
{
    int res = ft_mid_with("minishell.c", "*mini*h*\"l\".\'c\'*", 0);
    if (res == 1)
        printf("it is fine");
    if (res == 0)
        printf("it is not fine");
}