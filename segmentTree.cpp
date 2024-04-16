#include<bits/stdc++.h>
using namespace std;

#ifdef itzzYathishh
#include "algo/debug.h"
#else
#define dbg(...) ;
#define debug(...) ;
#define crndl ;
#define mod ((int)1e9+7)
#endif

void build(int ind, int low, int high, int arr[], int seg[]) {
	if(low == high) {
		seg[ind] = arr[low];
		return;
	}
	int mid = (low + high) >> 1;
	build(2*ind+1, low, mid, arr, seg);
	build(2*ind+2, mid+1, high, arr, seg);
	seg[ind] = min(seg[2*ind+1], seg[2*ind+2]);	
}

int query(int ind, int low, int high, int l, int r, int seg[]) {
	if(low >= l && high <= r) {
		return seg[ind];
	}
	if(high < l || low > r){
		return INT_MAX;
	}
	int mid = (low + high) >> 1;
	int left = query(2*ind+1, low, mid , l, r, seg);
	int right = query(2*ind+2, mid+1, high, l, r, seg);
	return min(left, right);
}

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int n, q;
	cin>>n>>q;
		
	int arr[n], seg[4*n];	
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
		
	build(0, 0, n-1, arr, seg);
	
	while(q--){
		int l,r;
		cin>>l>>r;
		l--, r--;
		cout<<query(0, 0, n-1, l, r, seg)<<"\n";
	}
	
	return 0;
}