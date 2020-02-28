#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n, k;
    cin >> n >> k;
    int n_y, n_x;
    cin >> n_y >> n_x;
    vector <int> queenAttack(8);
    int top         = n - n_y;
    int bottom      = n_y - 1;
    int left        = n_x - 1;
    int right       = n - n_x;
    int topRight    = (top < right)?top:right;
    int bottomRight = (right < bottom)?right:bottom;
    int topLeft     = (top < left)?top:left;
    int bottomLeft  = (left < bottom)?left:bottom;
    
    queenAttack[0] = top;    
    queenAttack[1] = bottom;    
    queenAttack[2] = left;    
    queenAttack[3] = right;    
    queenAttack[4] = topRight;    
    queenAttack[5] = bottomRight;    
    queenAttack[6] = topLeft;    
    queenAttack[7] = bottomLeft;
    
    for (int i = 0; i < k; i++){
        int k_y, k_x;
        cin >> k_y >> k_x;
        int position = 0;
        if (k_x == n_x){
            if(k_y > n_y){
                position = (k_y - n_y) - 1;
                queenAttack[0] = (position < queenAttack[0])
                    ?position:queenAttack[0];
            }
            else{
                position = (n_y - k_y) - 1;
                queenAttack[1] = (position < queenAttack[1])
                    ?position:queenAttack[1];
            }
        }
        else if(k_y == n_y){
            if(k_x < n_x){
                position = (n_x - k_x) - 1;
                queenAttack[2] = (position < queenAttack[2])
                    ?position:queenAttack[2];
            }
            else{
                position = (k_x - n_x) - 1;
                queenAttack[3] = (position < queenAttack[3])
                    ?position:queenAttack[3];
            }
        }
        else if((k_y > n_y) && (k_x > n_x)){
            position = ((k_y - n_y) == (k_x - n_x))
                ?(k_y - n_y - 1):queenAttack[4];
            queenAttack[4] = (position < queenAttack[4])
                ?position:queenAttack[4];
        }
        else if((k_y < n_y) && (k_x > n_x)){
            position = ((n_y - k_y) == (k_x - n_x))?
                (k_x - n_x - 1):queenAttack[5];
            queenAttack[5] = (position < queenAttack[5])
                ?position:queenAttack[5];
        }
        else if((k_y > n_y) && (k_x < n_x)){
            position = ((k_y - n_y) == (n_x - k_x))?
                (k_y - n_y - 1):queenAttack[6];
            queenAttack[6] = (position < queenAttack[6])?
                position:queenAttack[6];
        }
        else if((k_y < n_y) && (k_x < n_x)){
            position = ((n_y - k_y) == (n_x - k_x))?
                (n_y - k_y - 1):queenAttack[7];
            queenAttack[7] = (position < queenAttack[7])?
                position:queenAttack[7];
        }
    }
    int attacks = 0;
    for(int j = 0; j < 8; j++){
        attacks += queenAttack[j];        
    }
    cout << attacks;
    return 0;
}
