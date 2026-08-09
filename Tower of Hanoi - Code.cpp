// Tower of Hanoi

#include <iostream>
#include <string>
using namespace std;

int findIdx(int arr[5], int v) {
    for (int i=0; i<5; i++) {
        if (arr[i]==v)
            return i;
    }
    return -1;
}
void shift(int goal[5], int bases[3][5], int move, int from, int to ){
    int piece = goal[move-1];
    int placed = 0;
    while(placed<3 && bases[to][placed] ==0){
        placed++;
    }
    if(bases[to][placed-1]==0 && bases[to][placed]==4){
        bases[from][findIdx(bases[from], piece)]=0;
        bases[to][placed-1]=piece;
    }
    else{
        if( bases[to][placed-1]==0 && findIdx(goal, bases[to][placed] )> findIdx(goal, piece)){
            bases[from][findIdx(bases[from], piece)]=0;
            bases[to][placed-1]=piece;
        }
    }
}

bool check(int x[5], int y[5]){
    for (int i=0;i<4;i++)
        if (x[i]!=y[i])
            return false;
    return true;
}
void display(string basic[5], int base[5]){
    for (int i =0; i<3; i++){
        int ii=base[i];
        cout<<string(7-ii*2,' ')<<basic[ii]<<endl;
    }
    cout<<basic[base[3]]<<endl;
    cout<<string(7,' ')<<char(base[4]+ 97)<<endl;
    cout<<endl;
}
int main() {
    string big = "[[[[[[3]]]]]]";
    string midium = "[[[[2]]]]";
    string small = "[[1]]";
    string all[5] = {"|", small, midium, big, "[/////////////]"};
    int base_a[5] = {1,2,3,4,0};
    int base_b[5] = {0,0,0,4,1};
    int base_c[5] = {0,0,0,4,2};
    int bb[3][5] = {{1,2,3,4,0}, {0,0,0,4,1},{0,0,0,4,2}};
    int goal[5] = {1,2,3,4,0};
    cout<<"Minimum Moves: 7"<<endl<<"Go!"<<endl;
    for (int i = 0; i < 3; i++){
        display(all, bb[i]);
    }
    int moves =0;
    while (!check(bb[2], goal)) {
        cout<<"Your_move!"<<endl;
        int pidx;
        char f,t;
        cout<<"Piece index: ";
        cin>>pidx;
        cout<<"From(a/b/c): ";
        cin>>f;
        int fidx = f-'a';
        cout<<"To(a/b/c): ";
        cin>>t;
        int tidx = t-'a';
        int old_bb[3][5];
        for(int i=0; i<3; i++)
            for(int j=0; j<5; j++)
                old_bb[i][j] = bb[i][j];
        shift(goal,bb,pidx,fidx,tidx);
        bool valid=false;
        for(int i=0; i<3; i++){
            if(!check(bb[i], old_bb[i])){
                valid=true;
                break;
            }
        }
        if(!valid){
            cout<<"Invalid Move!Try Again"<<endl;
        }
        else{
            for(int n=0; n<3; n++){
                display(all, bb[n]);
            }
            moves++;
            cout<<"move count: "<<moves<<endl;
        }
    }
    cout<<"solved!"<<endl;
    return 0;
}