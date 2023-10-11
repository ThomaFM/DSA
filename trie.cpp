const int ALPHASIZE = 26; //assumes alphabet is continues
struct node {
   bool isWord = false; //int ct for kth lex
   vector<node*> children;
   node() {
       children = vector<node*>(ALPHASIZE, nullptr);
   } //change -'a' to the first letter of the alphabet.
   void insert(string &s, int idx) { //ct++ at top for kth lex
       if(idx == s.size()) {isWord = true; return;}
       if(!children[s[idx]-'a'])
           children[s[idx]-'a'] = new node();
       children[s[idx]-'a'] -> insert(s, idx+1);
   }


   bool find(string &s, int idx) {
       if(idx == s.size()) return isWord;
       if(!children[s[idx]-'a']) return false;
       return children[s[idx]-'a'] -> find(s, idx+1);
   }
//stop here if don’t need find kth 
   void findkth(string &s, int k){
       int sum = 0;
       k-=isWord;
       if(!k) return;
       for(auto i: order){  //order of alphabet is 0,1,2-
           if(children[i] == nullptr) continue;
           if((sum+(children[i]->ct)) >= k){
               s.push_back(i+'a');
               children[i]->findkth(s,k-sum);
               return;
           }
           sum+=(children[i]->ct);
       }
   }
};
