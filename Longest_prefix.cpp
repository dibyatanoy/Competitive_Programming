#include <bits/stdc++.h>
#define MAXX 1000005

using namespace std;

struct node{
    bool endmark;
    node *next[26+1];

    node(){
        endmark=false;
        for(int i=0;i<27;i++) next[i]=NULL;
    }
}*root;

void insrt(char *str,int len){
    node *curr=root;

    for(int i=0;i<len;i++){
        int id=str[i]-'a';
        if(curr->next[id]==NULL) curr->next[id]=new node();
        curr=curr->next[id];
    }

    curr->endmark=1;

    return;
}

bool srch(char *str,int len){
    node *curr=root;

    for(int i=0;i<len;i++){
        int id=str[i]-'a';
        if(curr->next[id]==NULL) return false;
        curr=curr->next[id];
    }

    return curr->endmark;
}

void del(node *curr){
    for(int i=0;i<26;i++){

        if(curr->next[i]) del(curr->next[i]);
    }
    delete(curr);
}

int main(){

    root=new node();
    int i,j;

    char tmp[12];

    while(scanf("%s",tmp) && tmp[0]!='.'){
        insrt(tmp,strlen(tmp));
    }

    scanf

    return 0;
}
