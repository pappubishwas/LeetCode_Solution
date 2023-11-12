#include <iostream>
#using namespace std;
class Solution {
public:
    #define ll long long
const ll p = 1e9 + 7;
    
ll pow(ll x,ll y){
    ll res=1;
    while(y>0){
        if(y%2==1)
            res=(res%p*x%p)%p;
        y=y>>1;
        
        x=(x%p*x%p)%p;
    }
    return res%p;
}
    
    int stringCount(int n) {
        long long ans,sub;

        if(n<4)
            return 0;
        
        ans=pow(26,n);
        //l=0
        sub=pow(25,n);
        // t=0
        sub+=pow(25,n);
        // e=0 ,1 
        sub+=(pow(25,n)+n*pow(25,n-1))%p;
        // l=0,t=0
        sub-=pow(24,n);
        // t=0, e<2
        sub-=(pow(24,n)+n*pow(24,n-1))%p;
        // l=0 , e<2
        sub-=(pow(24,n)+n*pow(24,n-1))%p;
        // l=0,t=0,t<2
        sub+=(pow(23,n)+n*pow(23,n-1))%p;
            
        return (ans%p - sub%p+p+p)%p;
    }
};
int main() {
    Solution solution;
    
    // Example usage:
    int n = 4; // Change the value of n as needed
    int result = solution.stringCount(n);
    
    std::cout << "Result for n=" << n << ": " << result << std::endl;

    return 0;
}
