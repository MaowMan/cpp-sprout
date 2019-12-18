#include <iostream>
#include <vector>
#include <algorithm>

void print(std::vector<int> &vec){
    std::cout<<vec.size();
    for(int i=0;i<vec.size();i++){
        std::cout<<' '<<vec[i];
    }
    std::cout<<std::endl;
}

void match(std::vector<int> &vec){
    std::cout<<"matching"<<std::endl;
    print(vec);
    for(std::vector<int>::iterator i=vec.begin();i!=vec.end();++i){
        std::vector<int>::iterator ptr=find(vec.begin(),vec.end(),*i);
        if (ptr==vec.end()){
            std::cout<<"continue"<<std::endl;
            continue;
        }
        else{
            vec.erase(i);
            vec.erase(ptr);
            std::cout<<"erasing"<<std::endl;
            print(vec);
            break;
        }
    }
}

int main(){
    int a,b;
    std::cin>>a>>b;
    std::vector<int> A(a),B(b);
    int cache;
    for(int i=0;i<a;i++){
        std::cin>>cache;
        A[i]=cache;
    }
    for(int i=0;i<b;i++){
        std::cin>>cache;
        B[i]=cache;
    }
    int k,x,y;
    std::cin>>k;
    for (int i=0;i<k;i++){
        std::cin>>x>>y;
        std::vector<int>::iterator iB=find(B.begin(),B.end(),x);
        if (iB!=B.end()){
            A.push_back(x);
            B.erase(iB);
            match(A);
        }
        std::vector<int>::iterator iA=find(A.begin(),A.end(),y);
        if (iA!=B.end()){
            B.push_back(y);
            A.erase(iA);
            match(B);
        }
        print(A);
        print(B);
    }
}


