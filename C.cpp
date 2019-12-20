#include <vector>
#include <algorithm>
#include <iostream>
#include <string>

void print(std::vector<int> &data){
    std::cout<<data.size();
    for(int i=0;i<data.size();i++){
        std::cout<<' '<<data[i];
    }
    std::cout<<std::endl;
}
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

int main(){
    int na,nb;
    std::cin>>na>>nb;
    if (na==0||nb==0){
        for(int i=0;i<3;i++){
            std::cout<<0<<std::endl;
        }
        return 0;
    }
    std::vector<int> a(na),b(nb);
    for(int i=0;i<na;i++){
        std::cin>>a[i];
    }
    for(int i=0;i<nb;i++){
        std::cin>>b[i];
    }
    int limit;
    int turn=-1;
    std::vector<std::vector<int>> res;
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
        if (a.size()==0||b.size()==0){
            turn=i+1;
            res.push_back(a);
            res.push_back(b);
            break;
        }
        std::vector<int>::iterator ptr_rb=find(a.begin(),a.end(),rb);
        if(ptr_rb!=a.end()){
            a.erase(ptr_rb);
            b.push_back(rb);
            b=match(b);
        }
        //print(a);
        //print(b);
        res.push_back(a);
        res.push_back(b);
        if (a.size()==0||b.size()==0){
            turn=i+1;
            break;
        }
    }
    if (turn==-1){
        turn=limit;
    }
    std::cout<<turn<<std::endl;
    for (int i=0;i<res.size();i++){
        std::cout<<res[i].size();
        for(int k=0;k<res[i].size();k++){
            std::cout<<' '<<res[i][k];
        }
        std::cout<<'\n';
    }
    return 0;
}
