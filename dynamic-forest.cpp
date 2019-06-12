#include <iostream>
using namespace std;

void treecut(int *forest, int*f, int i){
    if(i==10)
        return;
    f[i]=max(max(f[i-1], f[i-2]+forest[i]),f[i-3]+forest[i-1]+forest[i]);
    cout<<f[i]<<endl;
    treecut(forest,f,i+1);

}

int main(){
    int forest[11]={5,3,7,8,4,3,1,4,8,2};
    int f[10]={0}; //przesuwam drzewa o 1 zeby nie wyjsc poza tablice
    f[0]=forest[0];
    f[1]=forest[1]+forest[0];
    f[2]=max(max(f[1], f[0]+forest[2]),forest[1]+forest[2]);

    treecut(forest,f, 3);
    cout<<f[9];



}
