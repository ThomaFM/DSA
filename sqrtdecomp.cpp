//Template for sqrt decomp blocking technique
struct Sqrt{
    int INF = INT_MAX;
    const int block_size = 450; //sqrt 2e5 ~ 450
    vector<int> nums, blocks;
    Sqrt(vector<int> &arr){
        nums = arr;
        blocks = vector<int>((arr.size()/block_size)+1,INF);
        for(int i = 0; i < nums.size(); i++){
            blocks[i/block_size] = min(blocks[i/block_size],nums[i]);
        }
    }

    void update(int ind, int v){
        nums[ind] = v;
        int b_num = ind/block_size; 
        blocks[b_num] = INF;
        for(int i = b_num*block_size; i < (b_num+1)*(block_size); i++){
            blocks[i/block_size] = min(blocks[i/block_size],nums[i]);
        }
    }

    int query(int l, int r){
        int ans = INF; //default starting value
        while(l<r && (l%block_size) && l) ans = min(ans,nums[l++]);
        while(l+block_size<=r) {
            ans = min(ans,blocks[l/block_size]); 
            l += block_size;
        }
        while(l<=r) ans = min(ans,nums[l++]); //other partial
        return ans;
    }
};
