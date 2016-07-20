#include <bits/stdc++.h>
#define pb push_back
#define CLR(x) memset(x,0,sizeof(x))
#define MP make_pair
#define MAXS 150000
#define MAXC 28

using namespace std;

int out[MAXS];
int f[MAXS],g[MAXS][MAXC]; // fail function and goto function
int nextMove[MAXS][MAXC];
int states;
vector <int> memo;

vector <string> words;
string text,result;

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
        if(out[currState]<keyword.size()) out[currState]=keyword.size();
        //out[currState]|=(1<<i);
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
                if(out[failure]>out[g[state][c]])
                    out[g[state][c]]|=out[failure];
                q.push(g[state][c]);
            }
        }
    }

    queue <int> q2;
    while(!q2.empty()) q2.pop();

    memset(nextMove, 0,sizeof(nextMove));

    for(int c=0;c<='z'-'a';c++){
        nextMove[0][c]=g[0][c];
        if(g[0][c]>0) q2.push(g[0][c]);
    }

    while(!q2.empty()){
        int nxt=q2.front();

        q2.pop();

        for(int c=0;c<='z'-'a';c++){
            if(g[nxt][c]!=-1){
                //printf("Here\n");
                q2.push(g[nxt][c]);
                nextMove[nxt][c]=g[nxt][c];
            }else{
               nextMove[nxt][c]=nextMove[f[nxt]][c];
            }
        }
    }
    //printf("Here\n");
    /*for(int i=0;i<states;i++){
        for(int c=0;c<='z'-'a';c++) nextMove[i][c]=findNextState(i,char(c+'a'));
        printf("%d");
    }*/
    return states;
}

int main(){

    int i,j,k;
    int numWords,currState;

    ios_base::sync_with_stdio(0); cin.tie(0);

    freopen("censor.in","r",stdin);
    freopen("censor.out","w",stdout);

    cin>>text;
    cin>>numWords;

    for(i=0;i<numWords;i++){
        string tmp;
        cin>>tmp;
        //cout<<tmp<<endl;
        words.pb(tmp);
    }

    result="";
    int resPos=0;

    buildMatch();
    currState=0;
    memo.pb(currState);

    for(i=0;i<text.size();i++){
        currState=nextMove[currState][text[i]-'a'];
        memo.pb(currState);
        //currState=findNextState(currState,text[i]);
        if(out[currState]<=0) {result.pb(text[i]);continue;}

        //printf("here\n");

        //otherwise, delete

        result.resize(result.size()-out[currState]+1);
        //printf("here 2\n");
        memo.resize(result.size()+1);
        //printf("memo size is %d\n", memo.size());
        currState=memo[memo.size()-1];

        //printf("curr state is %d\n",currState);

        /*for (j = 0; j < words.size(); ++j) {
           if (out[currState] & (1 << j)) { // Matched keywords[j]
               cout << "Keyword " << words[j] << " appears from "
                    << i - words[j].size() + 1 << " to " << i << endl;
           }
       }*/
    }
    //result.pb('\0');
    cout<<result<<endl;

    return 0;
}

/** AC!!! First Aho-Corasick AC! **/
