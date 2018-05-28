int binser(vi arr, int val){
	int l = 0, r = arr.size()-1,mid;
	while(l<=r){
		mid = (l+r)/2;
		if(arr[mid] == val) return mid;
		else if(val > arr[mid]) l = mid+1;
		else r = mid-1;
	}
	return mid;
}
