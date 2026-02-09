#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;
#define fastio() {ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
using pii = pair<int,int>;
using pll = pair<ll, ll>;

// 1. 차원(Rank) 계산기: 이 타입이 몇 차원 벡터인지 컴파일 타임에 계산
template<typename T>
struct get_rank { static constexpr int value = 0; };
template<typename T>
struct get_rank<vector<T>> { static constexpr int value = 1 + get_rank<T>::value; };

// 2. 문자열 변환 도우미
template<typename T>
string to_str(const T& x) {
    if constexpr (is_arithmetic_v<T>) return to_string(x);
    else { ostringstream oss; oss << x; return oss.str(); }
}

// 3. 2차원 행렬을 문자열 줄(lines)들로 변환 (4D 그리드용)
template<typename T>
vector<string> get_matrix_lines(const vector<vector<T>>& mat, int& total_w) {
    if (mat.empty()) return {"[Empty]"};
    int r = mat.size(), c = 0;
    for(const auto& row : mat) c = max(c, (int)row.size());
    
    vector<int> col_w(c, 0);
    for(int i=0; i<r; ++i) 
        for(int j=0; j<(int)mat[i].size(); ++j) 
            col_w[j] = max(col_w[j], (int)to_str(mat[i][j]).size());

    vector<string> lines;
    total_w = 0;
    for(int i=0; i<r; ++i) {
        string line = "| ";
        for(int j=0; j<c; ++j) {
            if (j < (int)mat[i].size()) {
                ostringstream oss;
                oss << setw(col_w[j]) << mat[i][j] << (j == (int)mat[i].size()-1 ? "" : " ");
                line += oss.str();
            } else {
                line += string(col_w[j] + (j == c-1 ? 0 : 1), ' ');
            }
        }
        line += " |";
        lines.push_back(line);
        total_w = max(total_w, (int)line.size());
    }
    return lines;
}

// 4. 메인 재귀 로직
template<typename T>
void printND_recursive(const T& v, int depth) {
    constexpr int rank = get_rank<T>::value;

    if constexpr (rank == 4) {
        // --- 4D 특수 그리드 레이아웃 ---
        int big_R = v.size();
        for (int i = 0; i < big_R; i++) {
            int big_C = v[i].size();
            vector<vector<string>> row_matrices;
            int max_h = 0;
            for (int j = 0; j < big_C; j++) {
                int dummy_w;
                auto lines = get_matrix_lines(v[i][j], dummy_w);
                max_h = max(max_h, (int)lines.size());
                row_matrices.push_back(lines);
            }
            for (int h = 0; h < max_h; h++) {
                for (int j = 0; j < big_C; j++) {
                    if (h < (int)row_matrices[j].size()) cout << row_matrices[j][h] << "   ";
                    else cout << string(row_matrices[j][0].size(), ' ') << "   ";
                }
                cout << "\n";
            }
            cout << "\n";
        }
    } 
    else if constexpr (rank >= 1) {
        // 1D, 2D, 3D, 5D+ 일반 재귀 및 출력
        if (v.empty()) { cout << "[]\n"; return; }
        
        if constexpr (rank == 1) {
            cout << "[ ";
            for(int i=0; i<(int)v.size(); i++) cout << v[i] << (i==(int)v.size()-1?"":" ");
            cout << " ]\n";
        } 
        else if constexpr (rank == 2) {
            int dummy;
            auto lines = get_matrix_lines(v, dummy);
            for(const auto& l : lines) cout << l << "\n";
        }
        else {
            for (int i = 0; i < (int)v.size(); i++) {
                cout << "[Depth " << depth << " / Index " << i << "]\n";
                printND_recursive(v[i], depth + 1);
                if (depth == 0) cout << string(50, '=') << "\n";
                else cout << "\n";
            }
        }
    } 
    else {
        cout << to_str(v) << "\n";
    }
}

// 5. 진입점 및 매크로
template<typename T>
void dbgND_entry(const T& x, string name) {
    cout << "--- ND Debug: " << name << " (Rank " << get_rank<T>::value << ") ---\n";
    printND_recursive(x, 0);
    cout << "--------------------------------------------" << endl;
}

#define dbgND(x) dbgND_entry(x, #x)

// N차원 벡터 생성기
template<typename T> auto makeND(int n, const T& val) { return vector<T>(n, val); }
template<typename T, typename... Args> auto makeND(int n, Args... args) {
    auto inner = makeND<T>(args...);
    return vector<decltype(inner)>(n, inner);
}

int main() {
    fastio();
    
    auto v = makeND<int>(2, 2, 3, 3, 3, 3, 0);
    int cnt = 0;
    for(auto& a : v) for(auto& b : a) for (auto& c: b) for (auto& d: c) for (auto& e: d) for (auto& f: e) f = cnt++;
    
    dbgND(v);

    return 0;
}
