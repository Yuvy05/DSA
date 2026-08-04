// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std ;

// max heap
class heap{
    public : 
    int arr[100] ;
    int size = 0 ;
    void add(int val){
        size = size+1 ;
        int index = size ;
        arr[index] = val ;
        
        while(index > 1){
            int parent = index/2 ;
            if(arr[index] > arr[parent]){
                swap(arr[index],arr[parent]) ;
                index = parent ;
            }
            else break ;
        }
    }
    void print(){
        for(int i = 1 ; i <= size ;i++){
            cout << arr[i]<< " " ;
        }
    }
    
};
int main() {
    heap h;
    h.add(50) ;
    h.add(55) ;
    h.add(53) ;
    h.add(52) ;
    h.add(54) ;
    h.print() ;
}