#include <vector>
#include <algorithm>
#include <iostream>
#include <string>

std::vector<int> match(std::vector<int> &data){
    std::vector<int> res;
    for(int i=0;i<data.size();i++){
        std::vector<int>::iterator ptr;
        ptr=find(res.begin(),res.end(),data[i]);
        if(ptr==res.end()){
            res.push_back(data[i]);
        }
        else{
            res.erase(ptr);
        }
    }
    return res;
}

std::string print(std::vector<int> &data){
    std::string res;
    res+=std::to_string(data.size());
    for(int i=0;i<data.size();i++){
        res+=" ";
        res+=std::to_string(data[i]);
    }
    res+="\n";
    return res;
}
int main(){
    int na,nb;
    std::cin>>na>>nb;
    std::vector<int> a(na),b(nb);
    for(int i=0;i<na;i++){
        std::cin>>a[i];
    }
    for(int i=0;i<nb;i++){
        std::cin>>b[i];
    }
    int limit;
    int turn;
    std::string res;
    std::cin>>limit;
    for(int i=0;i<limit;i++){
        int ra,rb;
        std::cin>>ra>>rb;
        std::vector<int>::iterator ptr_ra=find(b.begin(),b.end(),ra);
        if(ptr_ra!=b.end()){
            b.erase(ptr_ra);
            a.push_back(ra);
            a=match(a);
        }
        std::cout<<print(a);
        res+=print(a);
        if (a.size()==0){
            turn=i+1;
            break;
        }
        std::vector<int>::iterator ptr_rb=find(a.begin(),a.end(),rb);
        if(ptr_rb!=a.end()){
            a.erase(ptr_rb);
            b.push_back(rb);
            b=match(b);
        }
        std::cout<<print(a);
        res+=print(b);
        if (b.size()==0){
            turn=i+1;
            break;
        }
    }
    std::cout<<turn<<std::endl;
    std::cout<<res<<std::endl;
}
