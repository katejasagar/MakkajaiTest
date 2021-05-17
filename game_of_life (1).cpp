#include <bits/stdc++.h>
#define int long long
using namespace std;

class GameOfLife{
    private:
        vector<pair<int,int> > coords;  //For storing Alive cell's co-ordinates
        vector<vector<char> > matrix;   //Original Matrix
        vector<vector<char> > cmatrix;  //Copied Matrix

        int getNeighbour(int i,int j){
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

    public:
        void getInput(){
            int a,b;
            int maxrow = INT_MIN;  //For storing dimension of square matrix
            while( cin >> a >> b){
            coords.push_back({a,b});
            maxrow = max(maxrow,a);
            maxrow = max(maxrow,b);
            }
            //Initialise Vector Size
            vector<char> init;
            for(int i=0;i<maxrow+1;i++){
                init.push_back('-');
            }
            for(int i=0;i<maxrow+1;i++){
                matrix.push_back(init);
                cmatrix.push_back(init);
            }
            //Setting alive Cells
             for(int i=0;i<coords.size();i++){
            matrix[coords[i].first][coords[i].second] = 'x';
            }
            cmatrix = matrix;
        }

        void performOneTick(){

            for(int i = 0; i < matrix.size(); i++){
                for(int j = 0; j < matrix[0].size(); j++){  
                    int num = getNeighbour(i,j);  //getting the number of alive neighbours
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


};


int32_t main()
{
    GameOfLife g1;
    g1.getInput();
    g1.performOneTick();
}