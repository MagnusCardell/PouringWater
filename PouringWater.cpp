#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;

class Node{
    int n;
    int **currState;

public:
    Node(int ten, int seven, int four){
        currState = new int*[3];
        for(int i=0; i<3; ++i){
            currState[i] = new int[2];
        }
        currState[0][0]=ten;
        currState[0][1]=10;
        currState[1][0]=seven;
        currState[1][1]=7;
        currState[2][0]=four;
        currState[2][1]=4;
    }
    Node(int **curr){
        currState = new int*[3];
        for(int i=0; i<3; ++i){
            currState[i] = new int[2];
        }
        for(int i=0; i<3; ++i){
            for(int j=0; j<2; ++j){
                currState[i][j]=curr[i][j];
            }
        }
    }
    
    vector<int**> genState(){
        //Generate all valid neightbours
        vector<int**> neighbours;
        bool next[] = {true, true, true, true, true, true};
        int pos[6][2] = {{0,1},{0,2},{1,2},{1,0},{2,0},{2,1}};
        int j = 0;
        int **temp = new int*[3];
        for(int i=0; i<3; ++i){
            temp[i] = new int[2];
        }
        while(j<3){
            /*if cup is full, all situations is is poured into
                are false*/
            if(currState[j][0]==currState[j][1]){
                for(int w = 0; w < 6; w++){
                    if(pos[w][1]==(j))
                        next[w]=false;
                }
            }
            /*if cup is empty, all situations is is poured from
                are false*/
            if(currState[j][0]==0){
                for(int w = 0; w < 6; w++){
                    if(pos[w][0]==(j))
                        next[w]=false;
                }
            }
            ++j;
        }
        int i = 0;
        while(i < 6){
            //copy( &currState[0][0], &currState[0][0]+3*2, &temp[0][0]);
            for(int m=0; m<3; ++m){
                for(int n=0; n<2; ++n){
                    temp[m][n]=currState[m][n];
                }
            }
            if(next[i]){
                int maxFill = currState[pos[i][1]][1] - currState[pos[i][1]][0];
                int inAmount = currState[pos[i][0]][0];
                if(maxFill <= inAmount){
                    
                    //create a child node with: 
                    temp[pos[i][0]][0]-=maxFill;
                    temp[pos[i][1]][0]+=maxFill;
                    neighbours.push_back(temp);
                }
                else{
                    //new with with:
                    temp[pos[i][0]][0]=0;
                    temp[pos[i][1]][0]+=inAmount;
                    neighbours.push_back(temp);
                }
                printIt(temp);
                cout<<'\n'<<endl;
                //create a child where that much has been poured. Do that for all possible situations.
            }
            ++i;
        }
        return neighbours;
    }

    int getState(int i){
        return currState[i][0];
    }
    string getKey(){
        string t="";
        for(int i=0; i<3; ++i){
            t += "hi";//std::to_string(currState[i][0]);
        }
    }

    void printIt(){
        for(int i=0; i<3; ++i){
            for(int j=0; j<2; ++j){
                cout<<currState[i][j]<<" ";
            }
            cout<<'\n';
        }
    }
    void printIt(int **t){
        for(int i=0; i<3; ++i){
            for(int j=0; j<2; ++j){
                cout<<t[i][j]<<" ";
            }
            cout<<'\n';
        }
    }
    //bool operator==(Cups b){
    //    return b.currState.A==currState.A; // add in checks for B and C
    //}
};

string breadthFirstSearch(Node root){
    queue<Node> FIFO_stack; //for saving stack order
    map<string, int> control; // for checking visited Cups
    vector<int**> children; //for saving neighbours
    string path = ""; //saving path? 
    string key = "";
    
    FIFO_stack.push(root);

    while(!FIFO_stack.empty()){
        //cout<<FIFO_stack.size()<<endl;
        Node temp = FIFO_stack.front(); //Queue specific op
        //key = temp.getKey();
        control[key] = 1;
        //path += temp.n(); 
        FIFO_stack.pop();

        if(temp.getState(1) == 2 or temp.getState(2) == 2){
            return "found it";
        }
        children = temp.genState();
        //cout<<FIFO_stack.size()<<endl;
        cout<<children.size()<<endl;
        for(int i=0; i< children.size(); ++i){
            cout<<FIFO_stack.size()<<endl;
            Node t(children[i]);
            
            //t.printIt();
            //cout<<"\n";
            
            //if(control[t.getKey()] <= 0){
            //    control[t.getKey()] = 1;
                FIFO_stack.push(t);
            //}
        }
        //delete &temp;
    }
    return path;
}
int main(){
    Node root(0,7,4);
    breadthFirstSearch(root);
    

    return 0;
}