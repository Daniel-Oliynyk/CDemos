#include <stdio.h>
#include <string.h>

int min(int a, int b, int c) {
    if (a < b && a < c) return a;
    else if (b < c) return b;
    else return c;
}

int levenshteinDistance(const char* s1, const char* s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    if (len1 == 0) return len2;
    if (len2 == 0) return len1;
    int dist[len1 + 1][len2 + 1];
    for (int i = 0; i <= len1; i++) dist[i][0] = i;
    for (int i = 0; i <= len2; i++) dist[0][i] = i;
    for (int x = 1; x <= len1; x++) {
        for (int y = 1; y <= len2; y++) {
            int cost = (x - 1 < len2 && y - 1 < len1 && s1[x - 1] == s2[y - 1])? 0 : 1;
            dist[x][y] = min(dist[x - 1][y] + 1, dist[x][y - 1] + 1, dist[x - 1][y - 1] + cost);
        }
    }
    return dist[len1][len2];
}

int main(void) {
    char s1[] = "GAMBOL";
    char s2[] = "GUMBO";
    printf("Result: %d\n", levenshteinDistance(s1, s2));
}
