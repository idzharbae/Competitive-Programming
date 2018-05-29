// x^y mod p
int modExp(int x, unsigned int y, int p)
{
    int ans = 1;
    x %= p;
    while(y>0){
      if(y&1)
        ans = (ans*x)%p;
      y = y>>1;
      x = (x*x)%p;
    }
    return ans;
}
