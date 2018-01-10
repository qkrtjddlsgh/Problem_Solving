// Mini Fantasy War
#include <bits/stdc++.h>
using namespace std;

int a, b, c, d, e, f, g, h;
int hp, mp, attack, defense;

int main(int argc, char *argv[]){
    int tc;
    scanf("%d", &tc);
    
    while(tc--){
        scanf("%d %d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &g, &h);
        
        hp = a + e;
        mp = 5 * (b+f);
        attack = 2 * (c+g);
        defense = 2 * (d+h);
        
        if(hp < 1)
            hp = 1;
        if(mp < 1)
            mp = 5;
        if(attack < 0)
            attack = 0;
        
        cout << hp + mp + attack + defense << "\n";
    }
    
    return 0;
}
