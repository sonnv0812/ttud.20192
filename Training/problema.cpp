#include <stdio.h>
#include <string.h>

int main() {
    char s[21];
    fflush(stdin);
    gets(s);
    // printf("%d\n", strlen(s));
    
    for (int i = 0; i < strlen(s)-1; i++) {
        if (s[0] >= 'a' && s[0] <= 'z')
            s[0] = s[0] - 'a'+'A';
        while (s[i] == s[i+1] && s[i] == ' ') {
            for (int j = i; j < strlen(s); j++)
                s[j] = s[j+1];
        }
    }
    
    puts(s);

    return 0;
}