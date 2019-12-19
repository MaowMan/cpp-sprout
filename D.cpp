#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


int cal(std::string n){
    int res=0;
    for (int i=0;i<n.size();i++){
        res+=(n[i]-'a');
    }
    return res;
}
struct node{
    std::string name;
    std::vector<int> child;
    int score;
    int parent;
};
int main(){
    int n;
    std::cin>>n;
    struct node base;
    base.name="base";
    base.score=0;
    base.parent=-1;
    std::vector<struct node> nodes;
    nodes.push_back(base);
    int now=0;
    for (int i=0;i<n;i++){
        int command;
        std::cin>>command;
        if (command==0){
            if (nodes[now].parent==-1){
                continue;
            }
            else{
                now=nodes[now].parent;
            }
        }
        else if(command==1){
            std::string arg;
            std::cin>>arg;
            bool flag=true;
            for(int k=0;k<nodes[now].child.size();k++){
                if(nodes[nodes[now].child[k]].name==arg){
                    now=nodes[now].child[k];
                    flag=false;
                    break;
                }
            }
            if(flag){
                struct node blank;
                nodes.push_back(blank);
                nodes[nodes.size()-1].name=std::string(arg);
                nodes[nodes.size()-1].parent=now;
                nodes[nodes.size()-1].score=nodes[now].score+cal(arg);
                //std::cout<<nodes[nodes.size()-1].name<<std::endl;
                nodes[now].child.push_back(nodes.size()-1);
                now=nodes.size()-1;
            }
        }
        else if(command==2){
            std::string arg;
            std::cin>>arg;
            bool flag=true;
            for(int k=0;k<nodes[now].child.size();k++){
                if(nodes[nodes[now].child[k]].name==arg){
                    flag=false;
                    break;
                }
            }
            if(flag){
                struct node blank;
                nodes.push_back(blank);
                nodes[nodes.size()-1].name=arg;
                nodes[nodes.size()-1].parent=now;
                nodes[nodes.size()-1].score=nodes[now].score+cal(arg);
                //std::cout<<nodes[nodes.size()-1].name<<std::endl;
                nodes[now].child.push_back(nodes.size()-1);
            }
        }
        else if(command==3){
            std::cout<<nodes[now].score<<std::endl;
        }
        else if(command==4){
            std::cout<<"name:"<<nodes[now].name<<std::endl;
            std::cout<<"parent:"<<nodes[now].parent<<std::endl;
            std::cout<<"score:"<<nodes[now].score<<std::endl;
            std::cout<<"child_length:"<<nodes[now].child.size()<<std::endl;
            if(nodes[now].child.size()>0){
                for(int k=0;k<nodes[now].child.size();k++){
                    std::cout<<nodes[nodes[now].child[k]].name<<' ';
                }
                std::cout<<std::endl;
            }
            else{
                std::cout<<"No child"<<std::endl;
            }
        }
    }
}
