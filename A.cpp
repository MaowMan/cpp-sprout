#include <iostream>
#include <vector>
#include <cstdio>

int main(){
    int n;
    std::cin>>n;
    if (n==2){
        int nxt;
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
        int a,b;
        std::cin>>a>>b;
        if (a-(b-a)>0){
                std::cout<<a-(b-a)<<std::endl;
        }
        else{
            if((a+b)%2==0){
                std::cout<<(a+b)/2<<std::endl;
            }
            else{
                std::cout<<b+(b-a)<<std::endl;
            }
        }
    }
}
