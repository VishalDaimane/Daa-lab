#include <stdio.h>
#include <stdbool.h>
#define N 4
bool prefers(int preferences[N][N], int w, int m, int m1) {
    for (int i = 0; i < N; i++) {
        if (preferences[w][i] == m1) return true;
        if (preferences[w][i] == m) return false;
    }
    return false;
}
void stableMarriage(int preferences[N][N]) {
    int wPartner[N]; 
    bool mFree[N];   
    for (int i = 0; i < N; i++) {
        wPartner[i] = -1;
        mFree[i] = true;
    }

    int freeCount = N; 
    while (freeCount > 0) {
        int m;
        for (m = 0; m < N; m++) {
            if (mFree[m]) break;
        }
        for (int i = 0; i < N && mFree[m]; i++) {
            int w = preferences[m][i]; 
            if (wPartner[w - N] == -1) {
                wPartner[w - N] = m;
                mFree[m] = false;
                freeCount--;
            } else {
                int m1 = wPartner[w - N];
                if (prefers(preferences, w - N, m, m1)) {
                    wPartner[w - N] = m;
                    mFree[m] = false;
                    mFree[m1] = true;
                }
            }
        }
    }
    printf("Woman   Man\n");
    for (int i = 0; i < N; i++) {
        printf(" %d \t  %d\n", i + N, wPartner[i]);
    }
}
int main() {
    int preferences[N][N] = {
        {7, 5, 6, 4}, 
        {5, 4, 6, 7},  
        {4, 5, 6, 7},  
        {4, 5, 6, 7}   
    };
    stableMarriage(preferences);
return 0;
}
