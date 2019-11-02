/*************************************************************************
	> File Name: 4.Game.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年08月31日 星期六 11时48分16秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>
using namespace std;

int main() {
    long long hp, normalAttack, buffedAttack;
    cin >> hp >> normalAttack >> buffedAttack;
    long long flag = 0;
    long long ans = 0;
    if (buffedAttack > normalAttack * 2) flag = 1;
    if (!flag) {
        ans = hp / normalAttack;
        if (ans * normalAttack < hp) ans += 1;
        cout << ans << endl;
        return 0;
    }
    ans = 2 * (hp / buffedAttack);
    hp -= buffedAttack * (ans / 2);
    cout << "hp = " << hp << endl;
    while (hp > normalAttack) {
        hp -= buffedAttack;
        ans += 2;
        cout << "after " << ans << "attacked" << "hp : " << hp << endl;
    }
    if (hp > 0) ans += 1;
    cout << ans << endl;
    return 0;
}
