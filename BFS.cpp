#include<iostream>
using namespace std;
#include "graph.cpp"
#include "queue.cpp"
void BFS(graph *g , vertex *s)
{
    int i , j , k;
    vertex *temp,*q;
    adjvertex *ad;
    for(i = 0 ; i < g->noofvertex ; i++)
    {
        g->v[i]->d = 1000000;
        g->v[i]->color = 0;
        g->v[i]->parent = NULL;
    }
    s->d = 0;
    s->color = 1;
    InitializeQ(g->noofvertex);
    vertex **t = new vertex*[g->noofvertex];
    Enqueue(t,s);
    while(!IsEmptyQ())
    {
        temp = Dequeue(t);
        ad = temp->adj;
        while(ad != NULL)
        {
            q = ad->v;
            if(q->color == 0)
            {
                q->color = 1;
                q->d = temp->d + 1;
                q->parent = temp;
                Enqueue(t,q);
            }
            q->color = 2;
            ad = ad->next;
        }
    }

}
int main()
{
    int i , j , k;
    cout<<"Enter no. of vertex you want in graph:- "<<endl;
    cin>>i;
    cout<<"Enter no. of edges you want in graph"<<endl;
    cin>>j;
    graph *g;
    g = makeGraph(i,j);
    cout<<"Enter the Source vertex:-- "<<endl;
    cin>>k;
    BFS(g , g->v[k]);
    cout<<"Printing the results:-- "<<endl;
    for(i = 0 ; i < g -> noofvertex ; i++ )
    {
        cout<<"vertex no.-- "<<i<<" Distance from "<<k<<" "<<" is --->>> "<<g->v[i]->d<<endl;
    }
    return 0;
}
