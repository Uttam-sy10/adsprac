#include<bits/stdc++.h>
using namespace std;
class graph{
    private:
    vector<vector<int>> adjMatrix;
    int vertices ;

    public:
    graph(int vertices ) {
        this->vertices = vertices;
        
        for(int i=0;i<vertices;i++){
            vector<int> row(vertices,0);
            adjMatrix.push_back(row);
        }    
     }

     void addEdge(int v1 ,int v2){
        adjMatrix[v1][v2] = 1;
        adjMatrix[v2][v1] = 1;
     }

     void display()
     {
        for (int i = 0; i < vertices; i++)
        {
            for (int j = 0; j < vertices; j++)
            {
               cout<<adjMatrix[i][j]<<" ";

            }
            cout<<endl;
            
        }
        

     }
     
};

int main(){
    graph gr(4);
    gr.addEdge(0,1);
    gr.addEdge(0,2);
    gr.addEdge(1,2);
    gr.addEdge(1,3);
    gr.addEdge(2,3);

    cout<<"displaying matrix: "<<endl;
    gr.display();
}