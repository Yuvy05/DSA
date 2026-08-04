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

    // for deleting the root node
    // MAX HEAP
    void deleteNode(){
        int idx = size ;
        if(idx == 0){
            cout << "Nothing to delete" ;
            return ;
        }

        size -- ;
        // last element came to the root node
        arr[1] = arr[idx] ;

        // place last element to its correct positoin
        idx = 1 ;
        while(2*idx <= size){
            int left = 2*idx ;
            int right = 2*idx+1 ;
            int mxidx = left ;
            if(right <= size and arr[right] > arr[mxidx]){
                mxidx = right;
            }

            if(arr[idx] < arr[mxidx]){
                swap(arr[idx],arr[mxidx]) ;
                idx = mxidx ;
            }

            else{
                return ;
            }

        }
    }
    
};
int main() {
    heap h;
    // h.add(50) ;
    // h.add(55) ;
    // h.add(53) ;
    // h.add(52) ;
    // h.add(54) ;
    h.add(10) ;
    h.add(5) ;
    h.add(3) ;
    h.add(2) ;
    h.add(0) ;
    h.print() ;
    cout <<endl ;
    h.deleteNode() ;
    h.print() ;
}