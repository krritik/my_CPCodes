            //Trie
            // CodeForces Problem D
            // Good  Substrings

#include<bits/stdc++.h>
using namespace std;

#define int long long
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

struct trie {
    trie *child[26];

    trie() {
        for(int i=0; i<26; i++)
            child[i] = NULL;
    }
};

int n, k;
string s, good;

void insert_trie(trie *root, int i) {
    
    for(; i<n; i++) {
        int pos = s[i] - 'a';

        if(root->child[pos] == NULL){
            root->child[pos] = new trie;
        }     
        root = root->child[pos];    
    }

    return ; 
}

int count_trie(trie *t, int k) {
    if(k < 0)
        return 0;

    int ans = 1;
    for(int i=0; i<26; i++) {
        if(t->child[i] != NULL) {
            if(good[i] == '1')
                ans += count_trie(t->child[i], k);
            else
                ans += count_trie(t->child[i], k-1);    
        }    
    }    

    return ans;
}

int32_t main() {
    fast;
    cin >> s;
    cin >>good;
    cin >> k;

    trie *t = new trie;
    n = s.size();

    for(int i=0; i<s.size(); i++) {
        insert_trie(t, i);
    }

    int ans = count_trie(t, k);
    cout << ans-1 << endl;
    return 0;
}