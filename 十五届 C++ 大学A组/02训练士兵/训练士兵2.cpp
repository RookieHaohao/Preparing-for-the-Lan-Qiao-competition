#include<iostream>
#include<algorithm>
typedef long long ll; 

using namespace std;

struct pos{
  ll p;
  ll c;
};

ll s[100005];

bool cmp(pos &p1, pos &p2){
	return p1.c > p2.c;
}


int main(){
	int n; //士兵的数量 
	ll m; //组团训练的金兵数量
	cin >> n >> m;  
	pos* a = new pos[n + 5];   //动态分配内存 
	for(int i = 1; i <= n; i++)
		cin >> a[i].p >> a[i].c; 
	sort(a+1, a+1+n,cmp);
	for(int i = 1; i <= n; i++)
		s[i] = s[i-1] + a[i].p;
	int i = 1;
	while(m >= s[i])
	 i++;
	int cnt = a[i].c;
	ll ans = cnt * m;
	for(int j = 1; j <= i; j++){
		ans += a[j].p * (a[j].c - cnt);
	}
	cout << ans << endl; 
	
	
}


