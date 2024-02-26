#include <bits/stdc++.h>
using namespace std;
//knight move takes 3
//it must move the answer path, ex) DDR anyway
//any other move must be reset(offset)
//so the key point is insert answer moves into the chaos routes that reset the move

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  stack<pair<int, int>> stack;//row+col, previous movement
  int rows, cols, k;
  int start, end;
  cin >> rows; cin >> cols; cin >> k;
  int maze[rows][cols];
  for(int i=0; i<rows; i++){
    for(int j=0; j<cols; j++){
      char tmp;
      int tmp2C;
      cin >> tmp;
      if(tmp=='S'){
        tmp2C = 0;//S==2;
        start = i*cols + j;
      }
      else if(tmp=='E'){
        tmp2C = 3;//E==3
        end = i*cols + j;
      }
      else  tmp2C = (int)  tmp - 48;//INTEGERIZE
      maze[i][j] = tmp2C; 
    }
  }//save maze in 2D array
  int currY = start/cols;
  int currX = start%cols;
  int ans=0, prev=0, dist=0;
  stack.push({0, 0});
  while(!stack.empty()){
    if(prev>-1 && currY>0 && ((maze[currY-1][currX]==0) || (dist==9 && maze[currY-1][currX]==3))){//UP
      stack.push({currY*cols + currX, 1});
      currY-=1;
      dist+=1;
    }
    else if(prev>-2 && currY<rows-1 && ((maze[currY+1][currX]==0) || (dist==9 && maze[currY+1][currX]==3))){//DOWN
      stack.push({currY*cols + currX, 2});
      currY+=1;
      dist+=1;
    }
    else if(prev>-3 && currX>0 && ((maze[currY][currX-1]==0) || (dist==9 && maze[currY][currX-1]==3))){//LEFT
      stack.push({currY*cols + currX, 3});
      currX-=1;
      dist+=1;
    }
    else if (prev>-4 && currX<cols-1 && ((maze[currY][currX+1]==0) || (dist==9 && maze[currY][currX+1]==3))){//RIGHT
      stack.push({currY*cols + currX, 4});
      currX+=1;
      dist+=1;
    }
    else{
      currY = stack.top().first/cols;
      currX = stack.top().first%cols;
      prev = stack.top().second;
      if(prev==1 || prev==2 || prev==3 || prev==4)  dist-=1;
      stack.pop();  
    }
    if(dist==10) ans+=1;
  }
  cout << "ans: " << ans << '\n';
}