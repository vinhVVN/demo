#include <bits/stdc++.h>

using namespace std;
int c=1;
void Print(int banco[100][100]){
    for (int i=0;i<8;i++){
        for (int j=0;j<8;j++){
            if (banco[i][j] == 1) cout<<"Q ";
            else cout<<"_ ";
        }
        cout<<endl;
    }
    cout<<endl;
}

bool Phuhop(int banco[100][100], int row, int col){
    for (int i=row-1;i>=0;i--){
        if (banco[i][col] == 1) return false; // kt hàng dọc xem có bị quân phía trên tấn công
    }
    for (int i=row-1, j=col-1; i>=0 && j>=0 ; i-- , j--){
        if (banco[i][j] == 1) return false; // kt đường chéo chính
    }
    for (int i=row-1, j=col+1; i>=0 && j<8; i--, j++){
        if (banco[i][j] == 1) return false; // kt đường chéo phụ
    }
    return true;
}

void Dat_hau(int banco[100][100], int row){
    if (row == 8){
        cout<<"Giai phap thu "<<c<<" : " <<endl;
        Print(banco);
        c++;
        return;
    }

    for (int col=0;col<8;col++){
        if (Phuhop(banco,row,col)){
            banco[row][col] = 1;
            Dat_hau(banco,row+1);
        }
        banco[row][col]=0;
    }
}

int main(){
    // freopen("Queen.inp","r",stdin);
    // freopen("Queen.out","w",stdout);
    int banco[100][100]; 
    Dat_hau(banco,0);

}