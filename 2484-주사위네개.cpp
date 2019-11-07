#include <bits/stdc++.h>
using namespace std;

// vector로 사용해도 가능
int arr[4];


// 조건문으로 모든 케이스 처리
int money(int arr[]){
    sort(arr,arr+4); // 정렬, arr에서는 +size로 정렬하는 크기 조정

    if(arr[0]==arr[1]&&arr[1]==arr[2]&&arr[2]==arr[3]){
        return 50000+arr[0]*5000;
    }
    else if((arr[0]==arr[1]&&arr[1]==arr[2])||(arr[1]==arr[2]&&arr[2]==arr[3])){
        return 10000+arr[1]*1000;
    }
    else if(arr[0]==arr[1]&&arr[2]==arr[3]){
        return 2000+arr[0]*500+arr[2]*500;
    }
    else if((arr[0]==arr[1])||(arr[1]==arr[2])){
        return 1000+arr[1]*100;
    }
    else if(arr[2]==arr[3]){
        return 1000+arr[2]*100;
    }
    else{
        return arr[3]*100;
    }
}

int main(void) {
    int n, maxi = 0; cin >> n;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < 4 ; j++){
            cin >> arr[i];
        }
        maxi = max(maxi,money(arr));
    }

    cout << maxi;
}