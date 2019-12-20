#include <vector>
#include <algorithm>
#include <iostream>

int main(){
    int n;
    std::cin>>n;
    std::vector<long long> data(n);
    for(int i=0;i<n;i++){
        std::cin>>data[n];
    }
    std::sort(data.begin(),data.end());
    if(data.size()==1){
        if(data[0]==1){
            std::cout<<2<<std::endl;
        }
        else{
            std::cout<<1<<std::endl;
        }
    }
    else if(data.size()==2){
        if (data[0]-(data[1]-data[0])>0){
            std::cout<<data[0]-(data[1]-data[0])<<std::endl;
        }
        else{
            if((data[1]-data[0])%2==0){
                std::cout<<(data[0]+data[1])/2<<std::endl;
            }
            else{
                std::cout<<data[1]+data[1]-data[0]<<std::endl;
            }
        }
    }
    else if(data.size()==3){
        if((data[2]-data[1])==(data[1]-data[0])){
            if(data[0]-(data[1]-data[0])>0){
                std::cout<<data[0]-(data[1]-data[0])<<std::endl;
            }
            else{
                std::cout<<data[2]+data[2]-data[1]<<std::endl;
            }
        }
        else{
            if((data[1]-data[0])>(data[2]-data[1])){
                std::cout<<(data[0]+data[1])/2<<std::endl;
            }
            else{
                std::cout<<(data[1]+data[2])/2<<std::endl;
            }
        }
    }
    else{
        if((data[1]-data[0])==())
    }

}
