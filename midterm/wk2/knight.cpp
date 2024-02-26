#include <bits/stdc++.h>
using namespace std;
//knight move takes 3
//it must move the answer path, ex) DDR anyway
//any other move must be reset(offset)
//so the key point is insert answer moves into the chaos routes that reset the move
/*
  PATCH NOTE
1. K LOOP CONDITION
2. MOVE CHECK FUNC
*/
int ryCal(int);
int rxCal(int);
int yCal(int);
int xCal(int);
int distCal(int);
int rdistCal(int);
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
for(int k=1; k<13; k++){
  // cout << "okay, new round!\n";
  int prev=0, dist=0;
  if(k==1){
    if(currY>0 && ((maze[currY-1][currX]==0) || (dist==total-1 && maze[currY-1][currX]==3))){//UP
      stack.push_back(1);
      currX += xCal(1);
      currY += yCal(1);
      dist += distCal(1);
      cout << "push 1" << endl;
      // cout << "push 1" << endl;
      prev=0;
    }
  }
  else if(k==2){
    if(currY<rows-1 && ((maze[currY+1][currX]==0) || (dist==total-1 && maze[currY+1][currX]==3))){//DOWN
      stack.push_back(2);
      currX += xCal(2);
      currY += yCal(2);
      dist += distCal(2);
      cout << "push 2" << endl;
      // cout << "push 2" << endl;
      prev=0;
    }
  }
  else if(k==3){
    if(currX>0 && ((maze[currY][currX-1]==0) || (dist==total-1 && maze[currY][currX-1]==3))){//LEFT
      stack.push_back(3);
      currX += xCal(3);
      currY += yCal(3);
      dist+=distCal(3);
      cout << "push 3" << endl;
      // cout << "push 3" << endl;
      prev=0;
    }
  }
  else if(k==4){
    if (currX<cols-1 && ((maze[currY][currX+1]==0) || (dist==total-1 && maze[currY][currX+1]==3))){//RIGHT
      stack.push_back(4);
      currX += xCal(4);
      currY += yCal(4);
      dist+=distCal(4);
      cout << "push 4" << endl;
      // cout << "push 4" << endl;
      prev=0;
    }
  }
  else if(k==5){
      if(dist<total-2 && currX<cols-1 && currY>1 && ((maze[currY-2][currX+1]==0) || (dist==total-3 && maze[currY-2][currX+1]==3))){
      stack.push_back(5);
      currX+=xCal(5);
      currY+=yCal(5);
      dist+=distCal(5);
      prev=0;
      cout << "push 5" << endl;
    }
  }
  else if(k==6){
    if(dist<total-2 && currX<cols-2 && currY>0 && ((maze[currY-1][currX+2]==0) || (dist==total-3 && maze[currY-1][currX+2]==3))){
      stack.push_back(6);
      currX+=xCal(6);
      currY+=yCal(6);
      dist+=distCal(6);
      prev=0;
      cout << "push 6" << endl;
    }
  }
  else if(k==7){
    if(dist<total-2 && currX<cols-2 && currY<rows-1 && ((maze[currY+1][currX+2]==0) || (dist==total-3 && maze[currY+1][currX+2]==3))){
      stack.push_back(7);
      currX+=xCal(7);
      currY+=yCal(7);
      dist+=distCal(7);
      prev=0;
      cout << "push 7" << endl;
    }
  }
  else if(k==8){
    if(dist<total-2 && currX<cols-1 && currY<rows-2 && ((maze[currY+2][currX+1]==0) || (dist==total-3 && maze[currY+2][currX+1]==3))){
      stack.push_back(8);
      currX+=xCal(8);
      currY+=yCal(8);
      dist+=distCal(8);
      prev=0;
      cout << "push 8" << endl;
    }
  }
  else if(k==9){
    if(dist<total-2 && currX>0 && currY<rows-2 && ((maze[currY+2][currX-1]==0) || (dist==total-3 && maze[currY+2][currX-1]==3))){
      stack.push_back(9);
      currX+=xCal(9);
      currY+=yCal(9);
      dist+=distCal(9);
      prev=0;
      cout << "push 9" << endl;
    }
  }
  else if(k==10){
    if(dist<total-2 && currX>1 && currY<rows-1 && ((maze[currY+1][currX-2]==0) || (dist==total-3 && maze[currY+1][currX-2]==3))){
      stack.push_back(10);
      currX+=xCal(10);
      currY+=yCal(10);
      dist+=distCal(10);
      prev=0;
      cout << "push 10" << endl;
    }
  }
  else if(k==11){
    if(dist<total-2 && currX>1 && currY>0 && ((maze[currY-1][currX-2]==0) || (dist==total-3 && maze[currY-1][currX-2]==3))){
      stack.push_back(11);
      currX+=xCal(11);
      currY+=yCal(11);
      dist+=distCal(11);
      prev=0;
      cout << "push 11" << endl;
    }
  }
  else if(k==12){
    if(dist<total-2 && currX>0 && currY>1 && ((maze[currY-2][currX-1]==0) || (dist==total-3 && maze[currY-2][currX-1]==3))){
      stack.push_back(12);
      currX+=xCal(12);
      currY+=yCal(12);
      dist+=distCal(12);
      prev=0;
      cout << "push 12" << endl;
    }
  }

  while(!stack.empty()){
    if(prev<1 && currY>0 && ((maze[currY-1][currX]==0) || (dist==total-1 && maze[currY-1][currX]==3))){//UP
      stack.push_back(1);
      currY += yCal(1);
      dist+=distCal(1);
      cout << "push 1" << endl;
      // cout << "push 1" << endl;
      prev=0;
    }
    else if(prev<2 && currY<rows-1 && ((maze[currY+1][currX]==0) || (dist==total-1 && maze[currY+1][currX]==3))){//DOWN
      stack.push_back(2);
      currY+=yCal(2);
      dist+=distCal(2);
      cout << "push 2" << endl;
      // cout << "push 2" << endl;
      prev=0;
    }
    else if(prev<3 && currX>0 && ((maze[currY][currX-1]==0) || (dist==total-1 && maze[currY][currX-1]==3))){//LEFT
      stack.push_back(3);
      currX+=xCal(3);
      dist+=distCal(3);
      // cout << "push 3" << endl;
      prev=0;
      cout << "push 3" << endl;
    }
    else if (prev<4 && currX<cols-1 && ((maze[currY][currX+1]==0) || (dist==total-1 && maze[currY][currX+1]==3))){//RIGHT
      stack.push_back(4);
      currX+=xCal(4);
      dist+=distCal(4);
      prev=0;
      cout << "push 4" << endl;
    }
    else if(dist<total-2 && prev<5 && currX<cols-1 && currY>1 && ((maze[currY-2][currX+1]==0) || (dist==total-3 && maze[currY-2][currX+1]==3))){
      stack.push_back(5);
      currX+=xCal(5);
      currY+=yCal(5);
      dist+=distCal(5);
      prev=0;
      cout << "push 5" << endl;
    }
    else if(dist<total-2 && prev<6 && currX<cols-2 && currY>0 && ((maze[currY-1][currX+2]==0) || (dist==total-3 && maze[currY-1][currX+2]==3))){
      stack.push_back(6);
      currX+=xCal(6);
      currY+=yCal(6);
      dist+=distCal(6);
      prev=0;
      cout << "push 6" << endl;
    }
    else if(dist<total-2 && prev<7 && currX<cols-2 && currY<rows-1 && ((maze[currY+1][currX+2]==0) || (dist==total-3 && maze[currY+1][currX+2]==3))){
      stack.push_back(7);
      currX+=xCal(7);
      currY+=yCal(7);
      dist+=distCal(7);
      prev=0;
      cout << "push 7" << endl;
    }
    else if(dist<total-2 && prev<8 && currX<cols-1 && currY<rows-2 && ((maze[currY+2][currX+1]==0) || (dist==total-3 && maze[currY+2][currX+1]==3))){
      stack.push_back(8);
      currX+=xCal(8);
      currY+=yCal(8);
      dist+=distCal(8);
      prev=0;
      cout << "push 8" << endl;
    }
    else if(dist<total-2 && prev<9 && currX>0 && currY<rows-2 && ((maze[currY+2][currX-1]==0) || (dist==total-3 && maze[currY+2][currX-1]==3))){
      stack.push_back(9);
      currX+=xCal(9);
      currY+=yCal(9);
      dist+=distCal(9);
      prev=0;
      cout << "push 9" << endl;
    }
    else if(dist<total-2 && prev<10 && currX>1 && currY<rows-1 && ((maze[currY+1][currX-2]==0) || (dist==total-3 && maze[currY+1][currX-2]==3))){
      stack.push_back(10);
      currX+=xCal(10);
      currY+=yCal(10);
      dist+=distCal(10);
      prev=0;
      cout << "push 10" << endl;
    }
    else if(dist<total-2 && prev<11 && currX>1 && currY>0 && ((maze[currY-1][currX-2]==0) || (dist==total-3 && maze[currY-1][currX-2]==3))){
      stack.push_back(11);
      currX+=xCal(11);
      currY+=yCal(11);
      dist+=distCal(11);
      prev=0;
      cout << "push 11" << endl;
    }
    else if(dist<total-2 && prev<12 && currX>0 && currY>1 && ((maze[currY-2][currX-1]==0) || (dist==total-3 && maze[currY-2][currX-1]==3))){
      stack.push_back(12);
      currX+=xCal(12);
      currY+=yCal(12);
      dist+=distCal(12);
      prev=0;
      cout << "push 12" << endl;
    }
    else{
      prev = stack.back();
      currY += ryCal(prev);
      currX += rxCal(prev);
      if(prev<5)  dist+=rdistCal(prev);
      else  dist+=rdistCal(prev);
      cout << "pop " << prev << '\n';
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
      if(prev<5)  dist+=rdistCal(prev);
      else  dist+=rdistCal(prev);
      cout << "pop " << prev << '\n';
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
  case 5: 
    return +2;
  case 6:
    return +1;
  case 7:
    return -1;
  case 8:
    return -2;
  case 9:
    return -2;
  case 10:
    return -1;
  case 11:
    return +1;
  case 12:
    return +2;
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
    case 5:
      return -1;
    case 6:
      return -2;
    case 7:
      return -2;
    case 8:
      return -1;
    case 9:
      return +1;
    case 10:
      return +2;
    case 11:
      return +2;
    case 12:
      return +1;
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
  case 5:
    return -2;
  case 6:
    return -1;
  case 7:
    return +1;
  case 8:
    return +2;
  case 9:
    return +2;
  case 10:
    return +1;
  case 11:
    return -1;
  case 12:
    return -2;
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
  case 5:
    return +1;
  case 6:
    return +2;
  case 7:
    return +2;
  case 8:
    return +1;
  case 9:
    return -1;
  case 10:
    return -2;
  case 11:
    return -2;
  case 12:
    return -1;
  default:
    return 0;
  }
}

int distCal(int traj)
{
  switch (traj){
    case 1:
    case 2:
    case 3:
    case 4: return +1;
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12: return +3; 
    default: return 0;
  }
}

int rdistCal(int traj)
{
  switch (traj){
    case 1:
    case 2:
    case 3:
    case 4: return -1;
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12: return -3;
    default: return 0;
  }
}