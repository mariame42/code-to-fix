#include <stdio.h>
#include <string.h>

int ft_mid_with(char *file, char *wildcard, int wc, int end)
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
                    wc++;
                    i++;
                    break;
                }
                else
                    i++;
            }
            while (wildcard[wc] != '*')
            {
                if (file[i] && wildcard[wc] != file[i])
                    break ;
                if (file[i] == '\0' || wildcard[wc] == '\0')
                    break ;
                if (i == end)
                    break ;
                if (file[i] && wildcard[wc] == file[i])
                {
                    wc++;
                    i++;
                }
            }
        }
    }
    if (wildcard[wc] == '\0')
        return (1);
    return (0);
}

int main(void)
{
    int res = ft_mid_with("minishell.c", "*mini*h*l.c*", 0, strlen("minishell.c"));
    if (res == 1)
        printf("it is fine");
    if (res == 0)
        printf("it is not fine");
}