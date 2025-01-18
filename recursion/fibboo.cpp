#include <bits/stdc++.h> 
using namespace std; 
int fuctio(int n) {
    if((n==0) or (n ==1) ) {
        return 1 ;
    }
 return n * fuctio(n-1);
}

int fibo(int n) {
if(n==0) {
    return 0 ;
}
else if(n==1) {
    return 1 ;
}
else {
    return fibo(n-1) + fibo(n-2);
}
}

int  main() {
    int n ; 
    cin >> n ;
    int a = fibo(n);
    int b = fuctio(n) ;
    cout << "fibonaccci  :"  << a  << endl;
    cout << "factorial :" << b << endl;
      for(int i = 0;i<n;i++) {
      printf("%d ",fibo(i));            
   }


}