#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
inline long long cal(long long a,long long b,long long c,long k){
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
    std::sort(data.begin(),data.end());
    for(int i=0;i<n;i++){
        int l,r,ll,lr;
        std::cin>>l>>r;
        long long result=9223372036854775800;
        for(int k=0;k<data.size();k++){
            if (data[k]>=l){
                ll=k-1;
                break;
            }
        }
        for(int k=data.size()-1;k>=0;k--){
            if(data[k]<=r){
                lr=k+1;
                break;
            }
        }
        std::cout<<"ll:"<<ll<<"lr"<<lr<<std::endl;
        for(int k=l;k<r;k++){
            for(int p=ll;p<=lr;p++){
                long long cache=std::abs(data[p]-k);
                std::cout<<cache;
                if(cache<result){
                    result=cache;
                }
            }
        }
        std::cout<<result<<'\n';
    }
}
