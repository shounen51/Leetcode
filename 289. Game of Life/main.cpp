#include <iostream>
#include <vector>

using namespace std;
    void gameOfLife(vector<vector<int>>& board) {
        int h=board.size();
        int w=board[0].size();
        vector<vector<int>> dir = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                int neighbor=0;
                for(vector<int> di : dir){
                    int dy = di[0];
                    int dx = di[1];
                    if(i+dy>=0 && i+dy<h && j+dx>=0 && j+dx<w){
                        if(board[i+dy][j+dx]>0){
                            neighbor++;
                        }
                    }
                }
                if(board[i][j]==1 && (neighbor!=2 && neighbor!=3)){
                    board[i][j]=2;
                }
                else if(board[i][j]==0 && neighbor==3){
                    board[i][j]=-1;
                }
            }
        }
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                if(board[i][j]==-1){
                    board[i][j]=1;
                }
                else if(board[i][j]==2){
                    board[i][j]=0;
                }
            }
        }
    }
    int main(){
        vector<vector<int>> board = {{0,1,0},{0,0,1},{1,1,1},{0,0,0}};
        gameOfLife(board);
        return 0;
    }