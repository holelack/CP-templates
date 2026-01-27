vector<int>& manacher(string& S) {
    int r, p, j; // r = 이전 팰린드롬 끝 문자열, p = 이전 팰린드롬 중심, j = p를 기준으로 i에 대해 대칭
    vector<int> mana(S.size(), 0);
    for (int i = 0; i < S.size(); i++) {
        if (i > r) {
            r = p = i; // 처음부터 팰린드롬 계산
            while (r < S.size() && r <= 2 * p && S[r] == S[2*p-r]) r++; // 끝 문자 같으면 확장
            r--;
            mana[i] = r - p;
        } else {
            j = 2 * p - i;
            if (res[j] < r - i) res[i] = res[j]; // 전꺼 그대로 활용. 완전히 같은 구간이므로
            else if (res[j] > r - i) res[i] = r - i; // r-i까지만 같고 나머지는 다름
            else {
                p = i; // r은 그대로 유지
                while (r < S.size() && r <= 2 * p && S[r] == S[2*p-r]) r++; // 끝 문자 같으면 확장
                r--;
                mana[i] = r - p;
            }
        }
    }
}

