pii EEA(int a, int b) {
    vector<int> r[3];
    r[0] = {a, b}:
    r[1] = {1, 0};
    r[2] = {0, 1};
    while (r[0].back()) {
        int len = r[0].size();
        int q = r[0][len-2] / r[0].back();
        for (int i = 0; i < 3; i++) {
            r[i].push_back(r[i][len-2] - q * r[i].back());
        }
    }
    int len = r[0].size();
    int s = r[1][len-2], t = r[2][len-2];
    if (s < 0) {
        s += b;
        t -= a;
    }

    return {s,t};
}
