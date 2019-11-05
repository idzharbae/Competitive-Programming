#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<long long> vi;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int odd = 0;
	int n; cin>>n;
	int arr[n];
	int sum = 0;
	for(int i = 0; i < n; i++){
		cin>>arr[i];
		sum += arr[i]/2;
	}

	for(int i = 0; i < n; i++){
		if(arr[i] % 2 == 0)
			cout<<arr[i]/2<<endl;
		else{
			if(sum > 0 and arr[i] < 0){
					cout<<arr[i]/2 -1<<endl;
					sum--;
				
			}
			else if(sum < 0 and arr[i] > 0){
				cout<<arr[i]/2 + 1<<endl;
				sum++;
			}
			else{
				cout<<arr[i]/2<<endl;
			}
		}
	}	
	// cout<<sum<<endl;
	return 0;
}