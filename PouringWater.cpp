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
string depthFirstSearch(Cups root, Cups goal){
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