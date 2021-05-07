#include <iostream>
using namespace std;

#define V 6    //定义6个点
#define INFINITY 99999

int graph[V][V] = {
	{0, 6, 1, 5, 0, 0},
	{6, 0, 5, 0, 3, 0},
	{1, 5, 0, 5, 6, 4},
	{5, 0, 5, 0 ,0, 2},
	{0, 3, 6, 0, 0, 6},
	{0, 0, 4, 2, 6, 0},
};  //题目输入图


struct mst
{
	bool visited;
	int key;
	int near;
};

mst MST_Array[V];

void initilize()
{
	for (int i = 0; i < V; i++)
	{
		MST_Array[i].visited=false;
		MST_Array[i].key=INFINITY;		// considering INFINITY as inifinity
		MST_Array[i].near=i;
	}

	MST_Array[0].key=0;
}

void updateNear()
{
	for (int v = 0; v < V; v++)
	{
		int min=INFINITY;
		int minIndex=0;
		for (int i = 0; i < V; i++)
		{
			if (MST_Array[i].key<min && MST_Array[i].visited==false && MST_Array[i].key!=INFINITY)
			{
				min=MST_Array[i].key;
				minIndex=i;
			}
		}
	
		MST_Array[minIndex].visited=true;
	
		for (int i = 0; i < V; i++)
		{
			if (graph[minIndex][i]!=0 && graph[minIndex][i]<INFINITY)
			{
				if (graph[minIndex][i]<MST_Array[i].key)
				{
					MST_Array[i].key=graph[minIndex][i];
					MST_Array[i].near=minIndex;
				}
			}
		}
	}
}

void show()
{
	for (int i = 0; i < V; i++)
	{
		cout<<i<<"  -  "<<MST_Array[i].near<<"\t"<<graph[i][MST_Array[i].near]<<"\n";
	}
}


int main()
{
	initilize();
	updateNear();
	show();
	return 0;
}
