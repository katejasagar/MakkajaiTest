#include <bits/stdc++.h>
#define int long long
using namespace std;

int getNeighbour(int i,int j,vector<vector<char>> cmatrix){
        int neighbour = 0;
       
        int dir[8][2] = {{1,-1},{1,1},{-1,-1},{-1,0},{1,0},{0,-1},{-1,1},{0,1}}; //8 Directions
       
        for(int k = 0;k < 8; k++){
            int row = i + dir[k][0];
            int col = j + dir[k][1];
         
            if(col >= 0 && col < cmatrix[row].size() && row >= 0 && row < cmatrix.size()  && cmatrix[row][col] == 'x'){
                neighbour++;
            }
        }
       
        return neighbour;
    }

int32_t main()
{
 vector<pair<int,int> > coords;  //For storing co-cordinates of alive matrix
 int a,b;
 int maxrow = INT_MIN;  //For storing dimension of square matrix
 
 //While input is given, breaks on ctrl+D
 while( cin >> a >> b){
  coords.push_back({a,b});
  maxrow = max(maxrow,a);
  maxrow = max(maxrow,b);
 }
 
 vector<vector<char> > matrix(maxrow+1, vector<char> (maxrow+1,'-')); //matrix
 vector<vector<char> > cmatrix(maxrow+1, vector<char> (maxrow+1,'-')); //Copy matrix so we retain old matrix
 
 for(int i=0;i<coords.size();i++){
  matrix[coords[i].first][coords[i].second] = 'x';
 }
 cmatrix = matrix;

 
  for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){  
                int num = getNeighbour(i,j,cmatrix);  //getting the number of alive neighbours
                if(cmatrix[i][j] == 'x' && (num < 2 || num > 3)){
                   
                    matrix[i][j] = '-';
                }
                if(cmatrix[i][j] == '-' && num == 3){
                   
                    matrix[i][j] = 'x';
                }
            }
        }
         
cout << "matrix after 1 tick is: \n";
 for(int i=0;i<matrix.size();i++){
  for(int j=0;j<matrix[0].size();j++){
  if(matrix[i][j]=='x'){
  cout << i << ", " << j << endl;
  }
  }
 }

}