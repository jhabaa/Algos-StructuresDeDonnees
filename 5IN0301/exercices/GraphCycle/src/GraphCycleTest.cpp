# include <iostream>
# include <iomanip>
#include "graph.h"
//---------------------------------------------------------------------------
using namespace std;
//---------------------------------------------------------------------------
TGraph* GenerateGraph(int dim,double prEdge);
TGraph* CreateGraph();
void ShowGraph(const TGraph& graph);
void ShowPath(const TGraph& graph, const TPath& path, double length);
bool FindNewPath(void);
void TestCyclicGraph(const TGraph& graph);
void TestAllRecurCyclicGraph(TGraph& graph,int i, int j);
void MakeAcyclicGraph(TGraph& graph);
//---------------------------------------------------------------------------
int main(int argc, char* argv[])
{
    TGraph graph0(0,0);  // first 0 is pointer NULL
    TestCyclicGraph(graph0);
    double t1[1][1] = {{0.0}};
    TGraph graph1((double *)t1,1);  // or TGraph graph1(t1[0],1);
    TestCyclicGraph(graph1);
    double t2_0[2][2] = {{0.0,INFINITY},{INFINITY,0.0}};
    TGraph graph2_0(t2_0[0],2);
    TestCyclicGraph(graph2_0);
    double t2_1[2][2] = {{0.0,1.0},{INFINITY,0.0}};
    TGraph graph2_1(t2_1[0],2);
    TestCyclicGraph(graph2_1);
    double t2_2[2][2] = {{0.0,INFINITY},{1.0,0.0}};
    TGraph graph2_2(t2_2[0],2);
    TestCyclicGraph(graph2_2);
    double t2_3[2][2] = {{0.0,1.0},{1.0,0.0}};
    TGraph graph2_3(t2_3[0],2);
    TestCyclicGraph(graph2_3);
    double t5[5][5] = {{     0.0,INFINITY,     1.0,INFINITY,INFINITY},
        {INFINITY,     0.0,INFINITY,INFINITY,     1.0},
        {INFINITY,INFINITY,     0.0,     1.0,INFINITY},
        {INFINITY,     1.0,INFINITY,     0.0,INFINITY},
        {INFINITY,INFINITY,     1.0,INFINITY,     0.0}
    };
    TGraph graph5((double *)t5,5);
    TestCyclicGraph(graph5);
    graph5[4][2] = INFINITY;
    TestCyclicGraph(graph5);
    TGraph graph3(3);
    TestAllRecurCyclicGraph(graph3,0,0);
    TGraph graph4(4);
    TestAllRecurCyclicGraph(graph4,0,0);
    TGraph* pGraph = GenerateGraph(15000,0.0001);
    TestCyclicGraph(*pGraph);
    delete pGraph;
    pGraph = GenerateGraph(10000,0.00001);
    TestCyclicGraph(*pGraph);
    delete pGraph;
    pGraph = GenerateGraph(400,1.0);
    MakeAcyclicGraph(*pGraph);
    delete pGraph;
    return 0;
}
//---------------------------------------------------------------------------
TGraph* CreateGraph()
{
    int dim;
    cout << "Nombre de sommets dans le graphe? ";
    cin >> dim;
    TGraph* pGraph = new TGraph(dim);
    int n1, n2;
    double d;
    do {
        cout
                << "Sommet de départ, sommet d'arrivée et longueur (<-1> pour finir): ";
        cin >> n1;
        if (n1 == -1)
            break;
        cin >> n2;
        if (n2 == -1)
            break;
        cin >> d;
        (*pGraph)[n1][n2] = d;
    } while (true);
    return pGraph;
}
//---------------------------------------------------------------------------
TGraph* GenerateGraph(int dim,double prEdge)
{
    srand(0);
    TGraph* pGraph = new TGraph(dim);
    for (int vs=0; vs<dim; ++vs) {
        for (int ve=0; ve<dim; ++ve) {
            if (vs!=ve && ((double) rand() / RAND_MAX)<prEdge)
                (*pGraph)[vs][ve] = ((double) rand() / (RAND_MAX))*10.0;
        }
    }
    return pGraph;
}
//---------------------------------------------------------------------------
void ShowGraph(const TGraph& graph)
{

    cout << "   |";
    for (int i = 0; i < graph.Dim(); ++i) {
        cout << "    " << "s" << i;
    }

    cout << endl << "---+";
    for (int i = 0; i < graph.Dim(); ++i) {
        cout << "------";
    }
    cout << endl;

    for (int i = 0; i < graph.Dim(); ++i) {
        cout << "s" << setw(1) << i << " |";
        for (int j = 0; j < graph.Dim(); ++j)
            if (graph[i][j] < INFINITY)
                cout << setw(6) << graph[i][j];
            else
                cout << setw(6) << ".";
        cout << endl;
    }
}
//---------------------------------------------------------------------------
void ShowPath(const TGraph& graph, const TPath& path, double length)
{
    if (length == INFINITY)
        cout << "Aucun chemin n'a été trouvé!" << endl;
    else {
        cout << "Un chemin de longueur " << length << " a été trouvé: ";
        int s = 0;
        double len = 0.0;
        for (int i = 0, sPrec = path[0]; i < path.Length(); ++i) {
            s = path[i];
            len += graph[sPrec][s];
            if (i != 0)
                cout << " ,";
            cout << " " << s << " (" << len << ")";
            sPrec = s;
        }
        cout << endl;
    }
}
//---------------------------------------------------------------------------
bool FindNewPath(void)
{
    char findAnother;
    do {
        cout << endl
             << "Voulez-vous rechercher un autre chemin (<O>ui/<N>on) ? ";
        cin >> findAnother;
        findAnother = (char) toupper(findAnother);
    } while ((findAnother != 'O') && (findAnother != 'N'));
    return (findAnother == 'O');
}
//---------------------------------------------------------------------------


void TestCyclicGraph(const TGraph& graph)
{
    TPath path(graph.Dim()+1);
    if (graph.Dim()<=20)
        ShowGraph(graph);
    else cout << "Graphe trop grand pour etre affiche !" << endl;
    clock_t ct1, ct2;
    ct1 = clock();
    bool isCyclic = IsCyclic(graph, path);
    ct2 = clock();
    if (isCyclic) {
        cout << "Un cyle a ete trouve (" << ((double)(ct2 - ct1) / CLOCKS_PER_SEC) << "s) :";
        for (int i=0; i<path.Length(); ++i)
            cout << " " << path[i];
        cout << endl;
    } else {
        cout << "Pas de cycle a trouve (" << ((double)(ct2 - ct1) / CLOCKS_PER_SEC) << "s) !" << endl;
    }
}
//---------------------------------------------------------------------------
void TestAllRecurCyclicGraph(TGraph& graph,int i, int j)
{
    // take next vertex
    if (i-1==j) j+=2;
    else ++j;
    if (j>=graph.Dim()) {
        ++i;
        j=0;
    }
    // full graph generated -> test cyclic
    if (i>=graph.Dim()) {
        TestCyclicGraph(graph);
        return;
    }
    // generate graph with and without edge ij
    else {
        double temp = graph[i][j];
        graph[i][j]=1.0;
        TestAllRecurCyclicGraph(graph, i, j);
        graph[i][j]=INFINITY;
        TestAllRecurCyclicGraph(graph, i, j);
        graph[i][j]=temp;
    }
}
//---------------------------------------------------------------------------
void MakeAcyclicGraph(TGraph& graph)
{
    TPath path(graph.Dim()+1);
    clock_t ct1, ct2;
    ct1 = clock();
    bool isCyclic;
    while ((isCyclic = IsCyclic(graph, path)))  {
        graph[path[0]][path[1]]=INFINITY;
    }
    ct2 = clock();
    cout << "Temps pour rendre acyclique le graphe (dimension " << graph.Dim() << ") : " << ((double)(ct2 - ct1) / CLOCKS_PER_SEC) << "s !" << endl;
}
//---------------------------------------------------------------------------
