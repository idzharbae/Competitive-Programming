void updateBIT(int BIT[], int n, int index, int val){
	while(index <= n){
		BIT[index] += val;
		index += index & (-index);
	}
}
int getSum(int BIT[], int n, int index){
	int sum = 0;
	while(index > 0){
		sum += BIT[index];
		index += index & (-index);
	}
	return sum;
}