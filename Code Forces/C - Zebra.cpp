#include <bits/stdc++.h>
using namespace std;

//menggunakan semacam linked list berbentuk array untuk solve
//jadi idenya kita mencatat setiap index itu loncat kemana aja supaya rangkaiannya jadi string 0101010...

int main(){
	string input;
	cin>>input;
	int len = input.length();
	if(input[0] != '0' || input[len-1] != '0'){ cout<<"-1\n"; return 0; }
	
	int satu_ujung=0, jumlah[200005]={0}, k=0, head[200005], tail[200005], next[200005];
	
	for(int i =0; i<len; i++){
		if(input[i] == '0'){
			if(satu_ujung == 0){
				head[k] = i;
				tail[k] = i;
				jumlah[k]++;
				k++;
			}else{
				satu_ujung--;
				next[tail[satu_ujung]] = i;
				tail[satu_ujung] = i;
				jumlah[satu_ujung]++;
			}
		}else{ //input '1'
			jumlah[satu_ujung]++;
			next[tail[satu_ujung]] = i;
			tail[satu_ujung] = i;
			satu_ujung++;
		}
		if(satu_ujung > k){ cout<<"-1\n"; return 0; }
	}
	
	if(satu_ujung){ cout<<"-1\n"; return 0; }
	cout<<k<<endl;
	for(int i=0; i<k; i++){
		cout<<jumlah[i];
		for(int j=head[i]; ; j=next[j]){
			cout<<" "<<j+1;
			if(tail[i] == j) break;
		}
		cout<<endl;
	}
	
return 0;
}
