//Dynamic _median
//Priority_queue // Heaps
//CodeChef /// RRATING

#include<bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define ll long long
#define fi(a, b) for(ll i=a; i<b; i++)
#define fj(a, b) for(ll j=a; j<b; j++)
#define mp make_pair
#define X first
#define Y second

#define N 250006

     
int32_t main() {
    fast;
    int n; 
    priority_queue<int> max , min;

    cin >> n;
    int cnt = 0;
    fi(0, n) {
        int y;
        cin >> y;

        if(y == 2) {
            if(min.empty())
                cout << "No reviews yet\n";
            else cout << -min.top() << endl;
        }
        else {
            cnt++;
            int x; cin >> x;
            int sz = min.size();

            if(cnt/3 > sz) {
                if(max.top() > x) {
                    min.push(-max.top());
                    max.pop();
                    max.push(x);
                }
                else {
                    min.push(-x);
                }
            }
            else {
                if(!min.empty()) {
                    if(-min.top() < x) {
                        max.push(-min.top());
                        min.pop();
                        min.push(-x);
                    }
                    else {
                        max.push(x);
                    }
                }
                else {
                    max.push(x);
                }
            } 
             
        }   
    }

    return 0;
}    