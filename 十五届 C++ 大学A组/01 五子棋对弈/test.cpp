#include<iostream>
using namespace std;
int mp[5][5];
long long sum=0;
void check(){
    int a=0;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(mp[i][j]==1) a++;
        }
    }
    if(a!=13) return;
    //此时满足13-12 
    int count=0;
    count+=mp[0][0]+mp[1][1]+mp[2][2]+mp[3][3]+mp[4][4];if(count%5==0) return; count=0;
    count+=mp[0][4]+mp[1][3]+mp[2][2]+mp[3][1]+mp[4][0];if(count%5==0) return; count=0;
    for(int i=0;i<5;i++){
        count+=mp[i][0]+mp[i][1]+mp[i][2]+mp[i][3]+mp[i][4];if(count%5==0) return; count=0;
        count+=mp[0][i]+mp[1][i]+mp[2][i]+mp[3][i]+mp[4][i];if(count%5==0) return; count=0;
    }
    //满足平局 
    sum++;
}
void dfs(int num){//依次由从左往右，再到从上往下的顺序遍历
    if(num==25){//棋盘下满 
        check();
        return;
    }
    int x=num/5,y=num%5;//换算成坐标
    mp[x][y]=0;
    dfs(num+1);
    mp[x][y]=1;
    dfs(num+1);
}
int main(){
    dfs(0);//从0开始，遍历所有结果
    cout<<sum;//3126376
    return 0;
}
