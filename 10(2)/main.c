#include <stdio.h>

#define NODES 9
#define START 0  /*探索開始ノード*/

struct edge {
    int start_node;
    int end_node;
};

int matrix[NODES][NODES]; /*隣接行列*/
int df_flag[NODES]; /*探索状況フラグ*/
struct edge df_tree[NODES-1]; /*探索木*/
int edge_cnt;

void df_search(int);

int main()
{
    int u, v, i;
    FILE *fp;
    
    for (u = 0; u < NODES; u++)
    for (v = 0; v < NODES; v++)
    matrix[u][v] = 0; /*隣接行列をゼリクリアする*/
    
    fp = fopen("/Users/labd/Documents/隣接行列/graph1.dat", "r");
    while(fscanf(fp, "%d %d", &u, &v) != EOF) { /*データを読み込む*/
        matrix[u][v] = 1; /*データを登録する*/
        matrix[u][v] = 1;
    }
    fclose(fp);
    edge_cnt = 0;
    for (u = 0; u < NODES; u++)
    df_flag[u] = 0; /*探索状況フラグをゼロクリアする*/
    df_search(START); /*ノードSTARTから探索を開始する*/
    
    for (i = 0; i < NODES - 1; i++) /*探索木を表示する*/
    printf("(%d %d)", df_tree[i].start_node, df_tree[i].end_node);
    printf("\n");
    
    return 0;
}

void df_search(int u)
{
    int v;
    df_flag[u] = 1; /*ノードuを探索済みに設定する*/
    
    for (v = 0; v < NODES; v++) /*探索されていないノードvを調査する*/
    if (matrix[u][v] == 1 && df_flag[v] == 0) {
        df_tree[edge_cnt].start_node  = u; /*ノードu,v間の辺を探索木に登録する*/
        df_tree[edge_cnt].end_node = v;
        edge_cnt++;
        df_search(v); /*ノードvを探索する*/
    }
}
