#include<bits/stdc++.h>
using namespace std;

template <typename T>
T mymax (T a,T b){return (a>b)?a:b;}
template <typename T>
T mymin (T a,T b){return (a<b)?a:b;}

template <typename T>
T myabs (T a){return (a<0)?(-1*a):a;}

template <class T>
void bubble_sort(T A[],int n){
    for (int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(A[j]>A[j+1])swap(A[j],A[j+1]);
        }
    }
}

int main (){

    int a,b;
    int A[10];

    cin>>a;

    cout<<myabs(-2.905)<<endl;

//    for(int i=0;i<a;i++){
//        cin>>A[i];
//    }
//
//    bubble_sort(A,a);
//
//    for(int i=0;i<a;i++){
//        cout<<A[i]<<endl;
//    }
//
//    cout<<mymax(A[0],a)<<endl;
//    cout<<mymin(A[0],a)<<endl;

    return 0;
}
