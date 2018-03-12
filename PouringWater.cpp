#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;

void printNOde(vector<int**> p){
    for(int m=0; m<p.size(); ++m){
        for(int i = 0; i < 3; i++){
                for(int j = 0; j < 2; j++) {
                    cout << p[m][i][j]<<" ";
                }
                cout <<'\n';
            }
            cout<<"end of thing"<<endl;
            cout <<'\n';
        }
}
class Node{
    int n;
    int **currState;
    vector<string> path;

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

        path.push_back(this->getKey());
    }
    Node(int **curr, Node p){
        currState = new int*[3];
        for(int i=0; i<3; ++i){
            currState[i] = new int[2];
        }
        for(int i=0; i<3; ++i){
            for(int j=0; j<2; ++j){
                currState[i][j]=curr[i][j];
            }
        }
    path = p.path;
    path.push_back(this->getKey());
    }

    vector<int**> genState(){
        //Generate all valid neightbours
        vector<int**> neighbours;
        bool next[] = {true, true, true, true, true, true};
        int pos[6][2] = {{0,1},{0,2},{1,2},{1,0},{2,0},{2,1}};
        int j = 0;
        
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
            int **temp = new int*[3];
            for(int k=0; k<3; ++k){
                temp[k] = new int[2];
            }

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
                    //printIt(temp);
                    neighbours.push_back(temp);
                    //printNOde(neighbours);
                }
                else{
                    //new with with:
                    temp[pos[i][0]][0]=0;
                    temp[pos[i][1]][0]+=inAmount;
                    //printIt(temp);
                    neighbours.push_back(temp);
                    //printNOde(neighbours);
                }
            }
            i++;
        }
        //printNOde(neighbours);
        return neighbours;
    }


    int getState(int i){
        return currState[i][0];
    }

    string getKey(){
        string k = "";

        k += std::to_string(currState[0][0]);
        k += std::to_string(currState[1][0]);
        k += std::to_string(currState[2][0]);
        return k;
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

    void printPath(){
        for(int i=0; i<path.size(); ++i){
            cout<<path[i]<<endl;
        }
    }
};

void print_queue(queue<Node> q){
    while(!q.empty()){
        q.front().printIt();
        q.pop();
        cout << endl;
    }
    cout <<"end of queue" << endl;

}

void breadthFirstSearch(Node root){
    queue<Node> FIFO_stack;
    queue<Node> copy;
    map<string, int> control;
    vector<int**> children;
    string key = "";
    int ctr = 0;

    FIFO_stack.push(root);
    key = root.getKey();
    control[key] = 1;


    while(!FIFO_stack.empty()){
        Node temp = FIFO_stack.front();
        FIFO_stack.pop();
        cout << "queue " << ctr << endl;

        if(temp.getState(1) == 2 or temp.getState(2) == 2){
            temp.printPath();
            cout<< "found it"<<'\n'<<endl;;
        }
        children = temp.genState();
        //printNOde(children);
        //cout << "children.size: " << children.size() << endl;
        for(unsigned int i=0; i< children.size(); ++i){
            Node t(children[i], temp);
            key = t.getKey();
            if(control.count(key)){
                continue;
            }
            control[key] = 1;
            FIFO_stack.push(t);
        }
        //copy = FIFO_stack;
        //print_queue(copy);
        ctr++;
    }
    return;
}
int main(){
    Node root(0,7,4);
   
    breadthFirstSearch(root);
    

    return 0;
}