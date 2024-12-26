#include<bits/stdc++.h>
using namespace std;

void reverse(int arr[],int size){
    for(int start =0,end = size-1;start<end;start++,end--){
        swap(arr[start],arr[end]);
    }
}