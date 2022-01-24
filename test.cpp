#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        set<int> s;
        s.insert(1);
        int sq, cu;
        int i = 2;
        while (i <= n) {
            sq = pow(i, 2);
            if (sq > n) break;
            s.insert(sq);
            cu = pow(i, 3);
            if (cu <= n) s.insert(cu);
            i++;
        }
        return s.size();
    }
    
	return 0;
}
