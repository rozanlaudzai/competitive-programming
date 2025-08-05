/*
--- rozanlaudzai 2025 ---
only need a Trie <3
be mindful of the memory limit!
you can reduce the memory usage by avoiding raw pointers or fixed-size (26) adjacency arrays
*/
#include <bits/stdc++.h>
using namespace std;

vector<char> ans;

struct Node {
    bool isEnd = false;
    int depth = 0;
    map<char, Node *> adj;
};

struct Trie {
    int mx = 0;
    Node *root;
    Trie() {
        root = new Node();
    }
    void add(string const &s) {
        int len = s.size();
        Node *u = root;
        mx = max(mx, len);
        u->depth = max(u->depth, len);
        for (char const &i : s) {
            if (u->adj[i] == nullptr) {
                u->adj[i] = new Node();
            }
            u = u->adj[i];
            u->depth = max(u->depth, len);
        }
        u->isEnd = true;
    }
    void dfs(Node *u) {
        if (u->isEnd) {
            ans.push_back('P');
        }
        char mxChar;
        Node *deep = nullptr;
        for (pair<char, Node *> const &i : u->adj) {
            char c = i.first;
            Node *v = i.second;
            if (deep == nullptr && v->depth == mx) {
                deep = v;
                mxChar = c;
                continue;
            }
            ans.push_back(c);
            dfs(v);
        }
        if (deep != nullptr) {
            ans.push_back(mxChar);
            dfs(deep);
        }
        ans.push_back('-');
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string s;
    Trie t;
    cin >> n;
    while (n-- > 0) {
        cin >> s;
        t.add(s);
    }

    t.dfs(t.root);

    while (ans.back() == '-') {
        ans.pop_back();
    }
    cout << ans.size() << '\n';
    for (char const &i : ans) {
        cout << i << '\n';
    }

    return 0;
}
