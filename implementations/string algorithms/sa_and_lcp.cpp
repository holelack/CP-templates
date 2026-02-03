void getSA() {
    for (int i = 0; i < N; i++) {
        sa[i] = i;
        isa[i] = S[i];
    }
    for (int d = 1; d < N; d<<=1) {
        auto cmp = [&](int i, int j) {
            if (isa[i] != isa[j]) return isa[i] < isa[j];
            return isa[i+d] < isa[j+d];
        };

        for (int i = 0; i < M; i++) cnt[i] = 0;
        for (int i = 0; i < N; i++) cnt[isa[i+d]]++;
        for (int i = 1; i < M; i++) cnt[i] += cnt[i-1];
        for (int i = N-1; i >= 0; i--) idx[--cnt[isa[i+d]]] = i;
        
        for (int i = 0; i < M; i++) cnt[i] = 0;
        for (int i = 0; i < N; i++) cnt[isa[i]]++;
        for (int i = 1; i < M; i++) cnt[i] += cnt[i-1];
        for (int i = N-1; i >= 0; i--) sa[--cnt[isa[idx[i]]]] = idx[i];

        nisa[sa[0]] = 0;
        for (int i = 1; i < N; i++) {
            nisa[sa[i]] = nisa[sa[i-1]] + cmp(sa[i-1], sa[i]);
        }
        isa = nisa;
        if (isa[sa[N-1]]==N) break;
    }
}

void getLCP() {
    for (int i = 0; i < N; i++) isa[sa[i]] = i;
    int r = 0;
    for (int i = 0; i < N; i++) {
        if (isa[i]) {
            while (r < N && S[sa[isa[i]-1]+r] == S[i+r]) r++;
            lcp[isa[i]] = r ? r--: 0;
        }
    }
}
