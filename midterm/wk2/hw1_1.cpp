#include <bits/stdc++.h>
using namespace std;
//knight move takes 3
//it must move the answer path, ex) DDR anyway
//any other move must be reset(offset)
//so the key point is insert answer moves into the chaos routes that reset the move
int ryCal(int);
int rxCal(int);
int yCal(int);
int xCal(int);
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  vector<int> stack;//previous movement
  vector<int>::iterator iter;
  int rows, cols, total;
  int start, end;
  cin >> rows; cin >> cols; cin >> total;
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
  cout << "X: " << currX << " Y: " << currY << endl;
  int ans=0;
for(int k=2; k<5; k++){
  // cout << "okay, new round!\n";
  int prev=0, dist=0;
  stack.push_back(k);//MUST UPDATE X, Y!!
  // cout << "push " << k << '\n';
  currX += xCal(k);
  currY += yCal(k);
  dist+=1;
  k++;
  prev=0;
  while(!stack.empty()){
    if(prev<1 && currY>0 && ((maze[currY-1][currX]==0) || (dist==total-1 && maze[currY-1][currX]==3))){//UP
      stack.push_back(1);
      currY += yCal(1);
      dist+=1;
      // cout << "push 1" << endl;
      prev=0;
    }
    else if(prev<2 && currY<rows-1 && ((maze[currY+1][currX]==0) || (dist==total-1 && maze[currY+1][currX]==3))){//DOWN
      stack.push_back(2);
      currY+=yCal(2);
      dist+=1;
      // cout << "push 2" << endl;
      prev=0;
    }
    else if(prev<3 && currX>0 && ((maze[currY][currX-1]==0) || (dist==total-1 && maze[currY][currX-1]==3))){//LEFT
      stack.push_back(3);
      currX+=xCal(3);
      dist+=1;
      // cout << "push 3" << endl;
      prev=0;
    }
    else if (prev<4 && currX<cols-1 && ((maze[currY][currX+1]==0) || (dist==total-1 && maze[currY][currX+1]==3))){//RIGHT
      stack.push_back(4);
      currX+=xCal(4);
      dist+=1;
      // cout << "push 4" << endl;
      prev=0;
    }
    else{
      prev = stack.back();
      currY += ryCal(prev);
      currX += rxCal(prev);
      if(prev==1 || prev==2 || prev==3 || prev==4)  dist-=1;
      // cout << "pop " << prev << '\n';
      stack.pop_back();  
    }
    if(dist==total){// it is not answer yet!!
      if(maze[currY][currX]==3){
          ans+=1;
         for(iter=stack.begin(); iter!=stack.end(); iter++)  cout << *(iter).base() << " ";
          cout << endl;
      }
      prev = stack.back();
      currY += ryCal(prev);
      currX += rxCal(prev);
      if(prev==1 || prev==2 || prev==3 || prev==4)  dist-=1;
      // cout << "pop " << prev << '\n';
      stack.pop_back();  
  }
}
}
  cout << "ans: " << ans << '\n';
}
//TRANS IT TO VECTOR FOR DEBUG
int ryCal(int traj)
{
  switch (traj)
  {
  case 1:
    return +1;
  case 2:
    return -1;
  default:
    return 0;
  }
}
int rxCal(int traj)
{
  switch (traj)
  {
    case 3:
      return +1;
    case 4:
      return -1;
    default:
      return 0;
  }
}

int yCal(int traj)
{
  switch (traj)
  {
  case 1:
    return -1;
  case 2:
    return +1;
  default:
    return 0;
  }
}

int xCal(int traj)
{
  switch (traj)
  {
  case 3:
    return -1;
  case 4:
    return +1;
  default:
    return 0;
  }
}