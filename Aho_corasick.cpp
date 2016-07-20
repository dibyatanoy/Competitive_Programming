#include <bits/stdc++.h>
#define pb push_back
#define CLR(x) memset(x,0,sizeof(x))
#define MP make_pair
#define MAXS 1000
#define MAXC 30

using namespace std;

long long int out[MAXS];
int f[MAXS], g[MAXS][MAXC]; // fail function and goto function
int nextMove[MAXS][MAXC];
int states;

vector <string> words;
string text;

int findNextState(int currState, char nextChar){
    int answer=currState;
    int c=nextChar-'a';

    while(g[answer][c]==-1) answer=f[answer];
    return g[answer][c];
}

int buildMatch(){
    CLR(out);
    memset(f,-1,sizeof(f));
    memset(g,-1,sizeof(g));

    states=1;

    for(int i=0;i<words.size();i++){

        string keyword=words[i];
        int currState=0;
        for(int j=0;j<keyword.size();j++){
            int c=keyword[j]-'a';

            if(g[currState][c]==-1) g[currState][c]=states++;

            currState=g[currState][c];
        }
        out[currState]|=(1<<i);
    }

    for(int c=0;c<MAXC;c++){
        if(g[0][c]==-1) g[0][c]=0;
    }

    queue <int> q;

    for(int c=0;c<='z'-'a';c++){
        if(g[0][c]>0){
            f[g[0][c]]=0;
            q.push(g[0][c]);
        }
    }

    while(!q.empty()){

        int state = q.front();
        q.pop();

        for(int c=0;c<='z'-'a';c++){
            if(g[state][c]!=-1){
                int failure=f[state];
                while(g[failure][c]==-1){
                    failure=f[failure];
                }
                failure=g[failure][c];
                f[g[state][c]]=failure;
                out[g[state][c]]|=out[failure];
                q.push(g[state][c]);
            }
        }
    }

    for(int i=0;i<states;i++){
        for(int c=0;c<='z'-'a';c++) nextMove[i][c]=findNextState(i,(char)c+'a');
    }

    return states;
}

int main(){

    int i,j,k;
    int numWords,currState;

    scanf("%d",&numWords);

    for(i=0;i<numWords;i++){
        string tmp;
        cin>>tmp;
        words.pb(tmp);
    }

    cin>>text;

    buildMatch();
    currState=0;

    for(i=0;i<text.size();i++){
        currState=nextMove[currState][text[i]-'a'];
        //currState=findNextState(currState,text[i]);
        if(out[currState]==0) continue;

        for (j = 0; j < words.size(); ++j) {
           if (out[currState] & (1 << j)) { // Matched keywords[j]
               cout << "Keyword " << words[j] << " appears from "
                    << i - words[j].size() + 1 << " to " << i << endl;
           }
       }
    }

    return 0;
}
