#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <deque>
#include <set>
#include <map>
#include <utility>
#define eps 1e-9

using namespace std;

struct node{
    int item;
    node* left;
    node* right;
};

int main(){

    node *root=new node;

    node *tmp=new node;
    root->left=tmp;
    tmp->item=1;

    printf("%d\n",root->left->item);

    return 0;
}
