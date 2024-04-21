#include<bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

int tt = 1;

int numberOfSubWithSum(int ind, int s, int sum, int arr[], int n) {
	if(ind == n) {
		if(sum == s) return 1;
		return 0;
	}
	s += arr[ind];
	int left = numberOfSubWithSum(ind+1, s, sum, arr, n);
	
	s -= arr[ind];
    int right = numberOfSubWithSum(ind+1, s, sum, arr, n);
    
	return left + right;
}

bool singleSubsequence(int ind, vector<int> &ds, int s, int sum, int arr[], int n) {
	if(ind == n) {
		if(s == sum) {
			for(auto it : ds) cout<<it<<" ";
		    cout<<endl;
		    return true;
		}
		return false;
	}
	
	ds.push_back(arr[ind]);
	s += arr[ind];
	if(singleSubsequence(ind+1, ds, s, sum, arr, n) == true) return true;
	
	ds.pop_back();
	s -= arr[ind];
	if(singleSubsequence(ind+1, ds, s, sum, arr, n) == true) return true;
}

void subsequenceSumK(int ind, vector<int> &ds,int s, int sum, int arr[], int n) {
	if(ind == n) {
		if(s == sum){
			for(auto it : ds) cout<<it<<" ";
			cout<<endl;	
		}
		return;
	}
	
	ds.push_back(arr[ind]);
	s += arr[ind];
	subsequenceSumK(ind+1, ds, s, sum, arr, n);
	
	s -= arr[ind];
    ds.pop_back();
    subsequenceSumK(ind+1, ds, s, sum, arr, n);
}

void subsequence(int ind, vector<int> &ds, int arr[], int n){
	if(ind == n) {
		for(auto it : ds) cout<<it<<" ";
		cout<<endl;
		return;	
	}
	
	//pick condition
	ds.push_back(arr[ind]);
	subsequence(ind+1, ds, arr, n);
	
	//not pick condition
	ds.pop_back();
	subsequence(ind+1, ds, arr, n);
}

int32_t main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif		

	int arr[] = {1,2,1};
	int sum = 2;
	int n = 3;
	vector<int> ds;
	cout<<"Possible subsequence"<<endl;
	subsequence(0, ds, arr, n);
	cout<<"subsequence with sum k"<<endl;
	subsequenceSumK(0, ds, 0, sum, arr, n);
	cout<<"subsequence which print only one "<<endl;
	singleSubsequence(0, ds, 0, sum, arr, n);
	cout<<"Total number of subsequence"<<endl;
	cout<<numberOfSubWithSum(0, 0, sum, arr, n);
	return 0;
}