#include <iostream>
using namespace std;

struct Point{
  int r;
  int c;
};

bool solve(Point b, string maze[]){

  if(maze[b.r][b.c+1] == 'E' || maze[b.r][b.c-1] == 'E' ||
     maze[b.r+1][b.c] == 'E' || maze[b.r-1][b.c] == 'E' )
     return true;

  if(maze[b.r][b.c+1] == ' '){
    b.c += 1;
    maze[b.r][b.c] = '.';

    if(solve(b, maze))
      return true;
    else{
      maze[b.r][b.c]  = ' ';
      b.c -= 1;
    }
  }

  if(maze[b.r+1][b.c] == ' '){
    b.r += 1;
    maze[b.r][b.c] = '.';

    if(solve(b, maze))
      return true;
    else{
      maze[b.r][b.c] = ' ';
      b.r -= 1;
    }
  }


    if(maze[b.r][b.c-1] == ' '){
      b.c -= 1;
      maze[b.r][b.c] = '.';

      if(solve(b, maze))
        return true;
      else{
        maze[b.r][b.c] = ' ';
        b.c += 1;
      }
    }

    if(maze[b.r-1][b.c] == ' '){
      b.r -= 1;
      maze[b.r][b.c] = '.';

      if(solve(b, maze))
        return true;
      else{
        maze[b.r][b.c] = ' ';
        b.r += 1;;
      }
    }

    return false;
  }
  void read(const int row, string maze[]){
    for(int i = 0; i < row; i++){
      getline(cin, maze[i]);
    }
  }

  void print(const int row, const string maze[]){
    for(int i = 0; i < row; i++){
      cout << maze[i] << endl;
    }
    cout << endl;
  }

  int main(){
    int row, col;
    string* maze;
    Point bender;
    int map = 0;

    cin >> row >> col;

    while(row != 0 && col != 0){
      cin.ignore();
      maze = new string[row];
      read(row, maze);
      bender = find(row, col, maze);
      if(solve(bender, maze)){
        cout << "Map : " << map << endl;
        print(row, maze);
        map++;
      }

      delete[] maze;
      cin >> row >> col;
    }
    return 0;
  }
