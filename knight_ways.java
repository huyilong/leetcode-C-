import java.io.*;
import java.util.*;

/*
 * To execute Java, please define "static void main" on a class
 * named Solution.
 *
 * If you need more classes, simply define them inline.
 
 * 1  2  3 
 * 4  5  6
 * 7  8  9
 *    0

 * If a knight starts on 1,
 * and it takes exactly 10 moves,
 * how many different paths can it take to 9?
 */

class Solution {
  static int count = 0;
  public static void main(String[] args) {
    int[][] board = {{1,2,3},{4,5,6}, {7,8,9}, {-1, 0, -1} };
    for(int x =0 ; x<board.length; x++){
      for(int y=0; y<board[0].length; y++){
        System.out.print( board[x][y]);
      }
      System.out.println();
    }
    
    dfs(board, 0, 0, 10);
    System.out.println("the # of possible paths is:" + count );
    
    
  }
  
  private static void dfs(int[][] board, int x, int y, int move){
    if((x == 3 && y == 0) || (x == 3 && y==2)){
      return;
    }
    
    if(x<0 || y<0 || x>=board.length || y>= board[0].length){
      return;
    }
    
    if(board[x][y] == 9 && move == 0){
      count++;
      return;
    }
    if(board[x][y] != 9 && move == 0){
      return;
    }
 
    
    dfs(board, x+1, y+2, move-1);
    dfs(board, x+2, y+1, move-1);
    dfs(board, x-1, y-2, move-1);
    dfs(board, x-2, y-1, move-1);
    
    dfs(board, x-1, y+2, move-1);
    dfs(board, x-2, y+1, move-1);
    dfs(board, x+2, y-1, move-1);
    dfs(board, x+1, y-2, move-1);
    
    
  }
}
