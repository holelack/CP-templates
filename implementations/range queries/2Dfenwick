vector<vector<int>> Y;
vector<vector<int>> BIT;

void reserve(int x, int y) {
    for (int i = x; i <= N; i += i & -i) {
        Y[i].push_back(y);
    }
}

void build() {
    for (int i = 1; i <= N; i++) {
        sort(Y[i].begin(), Y[i].end());
        Y[i].erase(unique(Y[i].begin(), Y[i].end()), Y[i].end());
        BIT[i].assign(Y[i].size()+1,0);
    }
}

int loyi(int y, int i) {
    return lower_bound(Y[i].begin(), Y[i].end(), y) - Y[i].begin() + 1;
}

int upyi(int y, int i) {
    return upper_bound(Y[i].begin(), Y[i].end(), y) - Y[i].begin();
}

void upd(int x, int y, int v) {
    for (int i = x; i <= N; i += i & -i) {
        for (int j = loyi(y,i); j < BIT[i].size(); j += j & -j) {
            BIT[i][j] = max(BIT[i][j], v);
        }
    }
}

int qry(int x, int y) {
    int res = 0;
    for (int i = x; i > 0; i -= i & -i) {
        for (int j = upyi(y,i); j > 0; j -= j & -j) {
            res = max(res, BIT[i][j]);
        }
    }
    return res;
}

void compress(int* seq, int L) {
    vector<int> cmp(seq,seq+L);
    sort(cmp.begin(), cmp.end());
    cmp.erase(unique(cmp.begin(), cmp.end()), cmp.end());
    for (int i = 0; i < L; i++) seq[i] = lower_bound(cmp.begin(), cmp.end(), seq[i]) - cmp.begin() + 1;
}
