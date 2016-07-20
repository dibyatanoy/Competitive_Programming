#include <iostream>
#include<cstdio> 
#include<stack> 
using namespace std; 
int main() 
{  int n, val;  while (1) {   scanf("%d", &n);   if (n == 0) break;   while (1) {    scanf("%d", &val); int i;   if (val == 0) {     printf("\n");     break;    }    stack<int> A, B;    A.push(val);    for (i = 1; i < n; i++) {     scanf("%d", &val);     A.push(val);    }    i = n;    for (; i >= 1;) {     if (!B.empty() && B.top() == i) {      B.pop();      i--;      continue;     }     if (A.empty()) break;     if (A.top() != i) B.push(A.top());     else i--;     A.pop();          }    if (A.empty() && B.empty()) puts("Yes");    else puts("No");   }  }  return 0; } 
