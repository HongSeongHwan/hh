#include<iostream>
using namespace std;
void main(){
int c,p,p2,n;
cin>>n;
c=p=2;
p2=1;
for (int i=3;i<= n;i++){
c=p+p2;
c=c%10007;
p2=p;
p=c;
}
if (n == 1) {
cout << "1";
return;
}
cout<<c;
}