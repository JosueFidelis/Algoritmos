#include <iostream>
#include<limits.h>
#include<algorithm>
using namespace std;

int main(){
    int tests, coin, cents, value, money[2];
    cin >> tests;
    while (tests --) {
        money[0] = money[1] = INT_MAX - 1;
        cin >> value >> coin;
        int pocket[coin];
        for (int i = 0; i < coin; i ++) {
            cin >> cents;
            pocket[i] = cents;
        }
        int memo[coin][value + 1][2];
        for (int i = 0; i <= value; i ++) {
            memo[0][i][0] = INT_MAX;
        }
        sort(pocket, pocket + coin);
        for (int i = 0; i < coin; i ++) {
            for (int j = 1; j <= value; j ++) {
                if (i != 0) {
                    if(j <= pocket[i]) {
                        memo[i][j][0] = pocket[i] - j;
                        memo[i][j][1] = 1;
                    } else {                        
                        memo[i][j][0] = memo[i-1][j-pocket[i]][0];
                        memo[i][j][1] = memo[i-1][j-pocket[i]][1] + 1;
                    }
                    if(memo[i-1][j][0] < memo[i][j][0] || memo[i-1][j][0] == memo[i][j][0] && memo[i-1][j][1] < memo[i][j][1]) {
                        memo[i][j][0] = memo[i-1][j][0];
                        memo[i][j][1] = memo[i-1][j][1];
                    }
                    
                } else if (i == 0 && j <= pocket[i]) {
                    memo[i][j][0] = pocket[i] - j;
                    memo[i][j][1] = 1;
                    
                } else {
                    memo[i][j][0] = INT_MAX;
                }
            }
        }
        cout << memo[coin - 1][value][0] + value << " " << memo[coin-1][value][1] << endl;
    }
    return 0;
}
