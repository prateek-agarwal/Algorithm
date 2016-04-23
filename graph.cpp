

typedef struct adjvertex{
  int weight;
  struct vertex *v;
  struct adjvertex *next;
}adjvertex;


typedef struct vertex{
 int d;
 int color;
 struct adjvertex *adj;
 struct vertex *parent;
 int rank;
}vertex;


typedef struct edge{
  struct vertex *s;
  struct vertex *d;
  int weight;
}edge;


typedef struct graph{

  int noofvertex;
  int noofedges;
  int isweighted;
  int d;//for BFS
  vertex** v;
  edge** e;
}graph;


vertex* makeVertex(int x){
  vertex *tmp = new vertex;
  tmp->d = x;
  tmp->color = 0;
  tmp->adj = NULL;

  return tmp;
}


edge* makeEdge(vertex *s1 , vertex *d1 , int x){

  edge *e = new edge;
  e->s = s1;
  e->d = d1;
  e->weight = x;

  return e;
}


adjvertex* makeAdj(vertex *s , int x){
  adjvertex *temp = new adjvertex;
  temp->v = s;
  temp->weight = x;
  temp->next = NULL;

  return temp;
}


int insertAdj(vertex *s , vertex *d , int x){
  adjvertex *t = NULL , *q = NULL;
  t = s->adj;
  while(t != NULL){
    q = t;
    t = t->next;
  }
  t = makeAdj(d,x);
  if(q != NULL)
    q->next = t;
  else
    s->adj = t;
  return 0;
}


graph* makeGraph(int v , int e){
  graph *temp = new graph;
  int i , j , k,sour , dest,wei,p;
  vertex *t;
  temp->noofedges = e;
  temp->noofvertex = v;
  temp->v = new vertex*[v];
  temp->e = new edge*[e];
  for(i = 0  ; i < v ; i ++){
    t = makeVertex(i);
    if(t == NULL){
      cout<<"Error Occured";

    }
    temp->v[i] = t;
  }
  cout<<"Enter 0 if weighted otherwise 1"<<endl;
  cin>>j;
  cout<<"Enter 0 if directed otherwise 1"<<endl;
  cin>>p;
  cout<<"Enter the source and destination of edges (between 0 and no. of the edge - 1):- "<<endl;
  for(i = 0 ; i < e; i++){
        cin>>sour>>dest;
        if(j)
          wei = 0;
        else
          cin>>wei;
        k = insertAdj(temp->v[sour] , temp->v[dest] , wei);
        if(p)
          k = insertAdj(temp->v[dest] , temp->v[sour] , wei);
        if(k)
            cout<<"Error in making adjacentylist  ";
        temp->e[i] = makeEdge(temp->v[sour] , temp->v[dest] , wei);

    }
	return temp;
  }
