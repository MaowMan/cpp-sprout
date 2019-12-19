#include <iostream>
#include <cmath>
#include <vector>

long long min(long long a,long long b){
    if(a>=b){
        return b;
    }
    else{
        return a;
    }
}
inline long long cal(long long a,long long b,long long c,long long k){
    return a*(k*k)+b*(k)+c;
}
int main(){
    long long a,b,c;
    std::cin>>a>>b>>c;
    int n;
    std::cin>>n;
    std::vector<long long> data;
    for(int k=-50;k<51;k++){
            long long cache=cal(a,b,c,k);
            //std::cout<<cache<<std::endl;
            data.push_back(cache);
    }
    for(int i=0;i<n;i++){
        long long l,r,result=9999999999;
        std::cin>>l>>r;
        for(int k=0;k<data.size();k++){
            if(data[k]>=l&&data[k]<=r){
                result=0;
                break;
            }
            else{
                long long cache=min(std::abs(data[k]-l),std::abs(data[k]-r));
                //std::cout<<"cache:"<<cache<<"result:"<<result<<std::endl;
                if (cache<=result){
                    result=cache;
                }
            }
        }
        std::cout<<result<<std::endl;
    }
}
