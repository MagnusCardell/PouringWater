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
        //cout<<"SO FAR SO GOOD1"<<endl;
        for(int i=0; i<3; ++i){
            currState[i] = new int[2];
        }
        //cout<<"SO FAR SO GOOD2"<<endl;
        currState[0][0]=ten;
        currState[0][1]=10;
        currState[1][0]=seven;
        currState[1][1]=7;
        currState[2][0]=four;
        currState[2][1]=4;
        //cout<<"SO FAR SO GOOD3"<<endl;
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
        //cout << "here1"<<endl;
        int i = 0;
        while(i < 6){
            for(int m = 0; m < 3; m++){
                for(int n = 0; n < 2; n++)
                    temp[m][n]=currState[m][n];
                //cout << "hi"<<endl;
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
                cout << endl;
                printIt(temp);

                //print here
                //create a child where that much has been poured. Do that for all possible situations.
            }
            i++;
        }
        return neighbours;
    }

    int getState(int i){
        return currState[i][0];
    }

    //bool operator==(Cups b){
    //    return b.currState.A==currState.A; // add in checks for B and C
    //}
    void printIt(int **t) {
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 2; j++) {
                cout << t[i][j]<<" ";
            }
            cout <<'\n';
        }
    }

    void printIt() {
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 2; j++) {
                cout << currState[i][j]<<" ";
            }
            cout <<'\n';
        }
    }
};

void print_queue(queue<Node> q){
    while(!q.empty()){
        q.front().printIt();
        q.pop();
        cout << endl;
    }
    cout << endl;

}

string breadthFirstSearch(Node root){
    queue<Node> FIFO_stack; //for saving stack order
    queue<Node> copy;
    //map<Cups, int> control; // for checking visited Cups
    vector<int**> children; //for saving neighbours
    string path = ""; //saving path? 
    int ctr = 0;

    FIFO_stack.push(root);

    while(!FIFO_stack.empty() && ctr < 2){
        Node temp = FIFO_stack.front(); //Queue specific op
        //path += temp.n(); 
        copy = FIFO_stack;
        FIFO_stack.pop();
        cout << "queue " << ctr << endl;
        print_queue(copy);

        if(temp.getState(1) == 2 or temp.getState(2) == 2){
            return "found it";
        }
        children = temp.genState();

        cout << "children.size: " << children.size() << endl;
        for(unsigned int i=0; i< children.size(); ++i){
            //cout << "here2" << endl;
            Node t(children[i]);
            //cout << "here1" << endl;
            FIFO_stack.push(t);
            //cout << "here" << endl;
        }
        ctr++;
    }
    return path;
}
int main(){
    Node root(0,7,4);
   
    breadthFirstSearch(root);
    

    return 0;
}