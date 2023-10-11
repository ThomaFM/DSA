//Using the kmp prefix function compute the string automaton.
void compute_automaton(string s, vector<vector<int>>& aut) {    s += '#';
    int n = s.size();
    vector<int> pi = prefix_function(s); //kactle kmp; 
    aut.assign(n, vector<int>(26));
    for (int i = 0; i < n; i++) {
        for (int c = 0; c < 26; c++) {
            if (i > 0 && 'A' + c != s[i])
                aut[i][c] = aut[pi[i-1]][c];
            else
                aut[i][c] = i + ('A' + c == s[i]);
        }
    }
}
