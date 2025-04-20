#include <string.h>

void myreverse (char s[]) {
        char tmp;
        int l;

        l = strlen(s);
        for (int i = 0; i < l/2; ++i) {
                tmp = s[l-1-i];
                s[l-1-i] = s[i];
                s[i] = tmp;
        }
}
