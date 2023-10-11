const int K = 26;
const char fir = 'a';
struct Vertex {
    int next[K];
    bool output = false;
    int p = -1;
    char pch;
    int link = -1;
    int go[K];
    int id = -1;
    Vertex(int p=-1, char ch='$') : p(p), pch(ch) {
        fill(begin(next), end(next), -1);
        fill(begin(go), end(go), -1);
    }
};

vector<Vertex> t(1);
void add_string(string const& s, int ind) {
    int v = 0;
    for (char ch : s) {
        int c = ch - fir;
        if (t[v].next[c] == -1) {
            t[v].next[c] = t.size();
            t.emplace_back(v, ch);
        }
        v = t[v].next[c];
    }
    t[v].id = ind;
    t[v].output = true;
}

int go(int v, char ch);
int get_link(int v) {
    if(t[v].link != -1) return t[v].link;
    if (v == 0 || t[v].p == 0) t[v].link = 0;
    else t[v].link = go(get_link(t[v].p), t[v].pch);
    return t[v].link;
}

int go(int v, char ch) {
    int c = ch - fir;
    if (t[v].go[c] != -1) return t[v].go[c];
    if (t[v].next[c] != -1) t[v].go[c] = t[v].next[c];
    else t[v].go[c] = v == 0 ? 0 : go(get_link(v), ch);
    return t[v].go[c];
}
