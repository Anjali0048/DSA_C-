#include<iostream>
#include <climits>
using namespace std;


int reverse(int x) {
    int rev = 0;
    while(x!=0){
        if((rev > INT_MAX/10) || (rev < INT_MIN/10)){
            return 0;
        }
        int rem = x%10;
        rev = (rev*10)+rem;
        x /= 10;
    }
    return rev;
}


int main(){
    int a = 1245;
    cout<<reverse(a);
    return 0;
}
