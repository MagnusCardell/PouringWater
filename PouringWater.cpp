#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;

class Node{
    int n;
    vector<vector<int>> currState; //for easy looping and checking

public:
    Node(){
        n = 0;
        currState.A = 0/10;
        currState.B;
        //waiting for logic...
    }

    void genState(Cups n){
        //Generate all valid neightbours
        bool [] next = {true, true, true, true, true, true};
        int [][] pos = {{0,1},{0,2},{1,2},{1,0},{2,0},{2,1}};
        int j = 0;
        while(j<3){
            /*if cup is full, all situations is is poured into
                are false*/
            if(currState[j][0]==currState[j][1]){
                for(int w = 0; w < 6; w++){
                    if(poss[w][1]==(j+1))
                        pos[w]=false;
                }
            }
            /*if cup is empty, all situations is is poured from
                are false*/
            if(currState[j][0]==0){
                for(int w = 0; w < 6; w++){
                    if(poss[w][0]==(j+1))
                        next[w]==false;
                }
            }
        }
        int i = 0;
        while(i < 6){
            if(next[i]){
                int maxFill = currState[pos[i][1]][1] - currState[pos[i][1]][0];
                //create a child where that much has been poured. Do that for all possible situations.
            }
        }
        children.push_back(n);
        return;
    }

    //void addChild(char n){ }

    vector<Cups> getChildren(){
        return children;
    }

    bool operator==(Cups b){
        return b.currState.A==currState.A; // add in checks for B and C
    }
};


//Stack implemented breadth first search
/* Create   - a std::stack of Nodes for LIFO (last in first out)
            - a vector children
            - a string path
    Add root to stack then start search until stack is empty
            - Get the top Node
            - add its value to path
            - pop it out from the stack
            - if Node is "goal" return path
            - else loop over all children and add them to queue in reverse order
            - while loop iterates
    Upon completion of search return path (no success)
*/
string breadthFirstSearch(Cups root, Cups goal){
    queue<Cups> FIFO_stack; //for saving stack order
    map<Cups, int> control; // for checking visited Cups
    vector<Cups> children; //for saving neighbours
    string path = ""; //saving path? 

    FIFO_stack.push(root);

    while(!FIFO_stack.empty()){
        Cups temp = FIFO_stack.front(); //Queue specific op
        path += temp.n(); 
        FIFO_stack.pop();

        if(temp == goal){
            return path;
        }
        children = temp.genNeighbours();

        for(int i=0; i< children.size(); ++i){
            FIFO_stack.push(children[i]);
        }
    }
    return path;
}
int main(){
    

    return 0;
}