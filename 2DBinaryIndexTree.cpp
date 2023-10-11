//one based also maybe make long
struct BIT2D {
	vector<vector<int>> arr;
	int n, m; 
	BIT2D(int n, int m): n(n), m(m), arr(n+1, vector<int>(m+1)) {}
	void update(int x, int y, int a) {
		for (; x <= n; x += x&-x)
			for (int j = y; j <= n; j += j&-j) arr[x][j] += a;
	}
	int query(int x, int y) {
		int s = 0;
		for (; x > 0; x -= x&-x) 
			for (int j = y; j > 0; j -= j&-j ) s+= arr[x][j];
		return s;
	}

    int query(int x1, int y1, int x2, int y2){
        return query(x2, y2) - query(x1-1, y2) - query(x2, y1-1) + query(x1-1, y1-1);
    }
};
