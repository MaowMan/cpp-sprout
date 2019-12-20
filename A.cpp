#include <iostream>
#include <vector>
#include <cstdio>
#include <set>

int main(){
    long long n;
    std::cin>>n;
    if (n==2){
        long long nxt;
        std::cin>>nxt;
        if (nxt==1){
            putchar('2');
            putchar('\n');
        }
        else{
            putchar('1');
            putchar('\n');
        }
    }
    else if (n==3){
        long long a,b;
        std::cin>>a>>b;
        if (a-(b-a)>0){
                std::cout<<a-(b-a)<<std::endl;
        }
        else{
            if((b-a)%2==0){
                std::cout<<a+(b-a)/2<<std::endl;
            }
            else{
                std::cout<<b+(b-a)<<std::endl;
            }
        }
    }
    else if(n==4){
        long long a,b,c;
        std::cin>>a>>b>>c;
        if((b-a)==(c-b)){
            if (a-(b-a)>0){
                std::cout<<a-(b-a)<<std::endl;
            }
            else{
                std::cout<<c+(b-a)<<std::endl;
            }
        }
        else{
            if((b-a)>(c-b)){
                std::cout<<a+(b-a)/2<<std::endl;
            }
            else{
                std::cout<<b+(c-b)/2<<std::endl;
            }
        }
    }
    else{
        long long a,b,c,d;
        std::cin>>a>>b>>c>>d;
        if(((b-a)==(c-b))&&((d-c)==(c-b))){
            long long log=(b-a);
            long long prev,next,cache;
            prev=c;
            next=d;
            while(std::cin>>cache){
                prev=next;
                next=cache;
                if ((next-prev)!=log){
                    std::cout<<prev+(next-prev)/2<<std::endl;
                    return 0;
                }
            }
            if ((a-log)>0){
                std::cout<<(a-log)<<std::endl;
            }
            else{
                std::cout<<(next+log)<<std::endl;
            }
        }
        else{
            if((b-a)==(c-b)){
                std::cout<<c+(d-c)/2<<std::endl;
            }
            else if((b-a)==(d-c)){
                std::cout<<b+(c-b)/2<<std::endl;
            }
            else{
                std::cout<<a+(b-a)/2<<std::endl;
            }
            return 0;
        }
    }
}
