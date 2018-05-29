int maze[100][100];
int mark[100][100];

bool solve(int xs,int ys, int xd, int yd, int step ){
  maze[xs][ys] = step;
  mark[xs][ys] = 1;
  if(xs == xd and ys == yd) return true;
  for(int i = -1; i <= 1; i++)
    for(int j = -1; j <= 1; j++){
      if(abs(i) == abs(j)) continue; // no diagonal moves or not moving
      if(maze[xs+i][ys+j] == 0 and mark[xs+i][ys+j] == 0)
        if(solve(xs+i,ys+j,xd,yd,step+1)) return true;
    }
    maze[xs][ys] = 0; // if taking this path leads to no solution, backtrack.
    return false;
}
