#include <bits/stdc++.h>
using namespace std;
long long arr[100005], N,  M;

// f(t) = true/false : can we do N problems in <= M days where the maximum value of each partition is t
bool f(int t){
	int partition = 1;
	long long sum = 0; // dont forget to zero this shit faosjdoasjdsakdlaksd
	for(int i = 0; i < N; i++){
		if(arr[i] > t) return false; // berarti ada nilai individual yang ngelebihin kuota latihan kita, skip.
		if(sum + arr[i] <= t) sum += arr[i];  // kalau kita jumlahin masih dalam batas kuota, berarti kita masih bisa ngerjain.
		else{    // kalau udah lebih, berarti satu hari telah terlewati
			partition++;
			sum = arr[i];
		} 
	}
	return partition <= M; // apakah hari yang kita gunakan kurang dari batas
}

int main(){
    cin>>N>>M;
    long long sum = 0;
    for(int i = 0; i < N; i++){
		 cin>>arr[i]; sum += arr[i];
	}
    long long l = 1, r = sum, mid = (l+r)/2;
    while(l<=r){
		// cout<<mid<<endl;
		if(f(mid)) r = mid - 1; // kalau kuota sekarang memenuhi, berarti keatasnya memenuhi semua, kurangin r.
		else l = mid + 1;
		mid = (l+r)/2;
	}
	
	cout<<l<<endl; // print l, karena setelah loop kelar l pasti >= mid
}
