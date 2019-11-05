#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct SegmentTree {
private:
	int N;
	int sign;
	ll* offset;
	ll* step;

	void update(int node, int begin, int end, int i, int j, int val) {
		// current segment outside search range
		if (end< i || j < begin) {
			return;
		}
		// current segment overlaps with search range
		if (i <= begin && end<= j) {
			step[node]++; // number of queries
			offset[node] += val + sign * (begin-i);
		} 
		// current segment covers the search range
		else{
			update(2*node, begin, (begin+end)/2, i, j, val);
			update(2*node+1, (begin+end)/2+1, end, i, j, val);
		}
	}

	ll query(int node, int begin, int end, int i) {
		if (end< i || i < begin) {
			return 0;
		}
		if (begin == end) {
			return offset[node];
		}
		step[2*node] += step[node];
		step[2*node+1] += step[node];

		int mid = (begin+end)/2;
		offset[2*node] += offset[node];
		offset[2*node+1] += offset[node] + sign * step[node] * (mid +1 - begin);
		offset[node] = 0;
		step[node] = 0;

		return query(2*node, begin, (begin+end)/2, i) + query(2*node+1, (begin+end)/2+1, end, i);
	}

public:
	SegmentTree(int N, int sign) {
		this->N = N;
		this->sign = sign;
		this->offset = new ll[4*N+42];
		this->step = new ll[4*N+42];

		for (int i = 0; i < 4*N + 42; i++) {
			offset[i] = step[i] = 0;
		}
	}

	~SegmentTree() {
		delete[] offset;
		delete[] step;
	}

	void update(int i, int j, int val) {
		update(1, 1, N, i, j, val);
	}

	ll query(int i) {
		return query(1, 1, N, i);
	}
};

int T;
int N, M;

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d %d", &N, &M);

		SegmentTree pos(N, 1), neg(N, -1); // ???

		for (int i = 0; i < M; i++){
			int position, val;
			scanf("%d %d", &position, &val);

			int endIdx = position;
			int startIdx = max(1, position-val+1);
			int startVal = max(1, val-position+1);
			pos.update(startIdx, endIdx, startVal);

			if (val > 1) {
				endIdx = min(N, position+val-1);
				startIdx = position+1;
				neg.update(startIdx, endIdx, val-1);
			}

		}

		for (int i = 1; i <= N; i++) {
			printf("%lld", pos.query(i) + neg.query(i));
			printf("%c", i == N ? '\n' : ' ');
		}
	}
}
