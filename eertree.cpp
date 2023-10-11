//Palindrome Tree
struct eertree{
    struct node{
        vector<int> downward;
        int suffixlink, len, occurrences;
        node(int link, int ln){
            suffixlink = link; len = ln;
            downward = vector<int>(26,-1);
            occurrences = 0;
        }
    };
    vector<node> tree;
    eertree(string &s){
        int cur = 0, t = 0;
        tree = {node(0,-1),node(0,0)};
        for(int i = 0; i < s.size(); i++){
            char c = s[i]; int chr = (c-'a');
            while(t<=0 || s[t-1] != c){
                cur = tree[cur].suffixlink;
                t = i - tree[cur].len;
            }
            int added;
            if(tree[cur].downward[chr] == -1){
                tree[cur].downward[chr] = tree.size();
                added = tree.size();
                int newlength = tree[cur].len+2;
                tree.emplace_back(-1,newlength);
                if(tree.back().len > 1){
                    do t = i - tree[cur = tree[cur].suffixlink].len;
                    while(t<=0 || s[t-1] != c);
                    tree[added].suffixlink = tree[cur].downward[chr];
                } else tree[added].suffixlink = 1;
                cur = tree.size()-1;
            } else cur = tree[cur].downward[chr];
            tree[cur].occurences++;
            t = i - tree[cur].len+1;
        }

        for(int i = tree.size()-1; i > 1; i--){
            tree[tree[i].suffixlink].occurences += tree[i].occurences;
        }
    }
};
