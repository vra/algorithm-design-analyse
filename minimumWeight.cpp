#include <fstream> 
#include <iostream> 

#define MAX_QUEUE_SIZE 1024

using namespace std;

struct Node   
{  
	int peer;  
    struct Node *parent;  
    int position;  
    double cw;  
    double cv;  
    double r;    
};  

struct Node *queues[MAX_QUEUE_SIZE];  //最小堆

void insert(struct Node *x, int oldlast)
 { 

	 //oldlast是目前堆的元素数目                                                
	int last = oldlast + 1;
    queues[last] = x;
    int i = last;                                                      
	while ((i > 1) && (queues[i]->r < queues[i/2]->r)) 
	{
		struct Node *temp;
        temp = queues[i];  
		queues[i] = queues[i/2];
        queues[i/2] = temp;
        i = i/2;
	}
}     

struct Node * deletemin(int last, struct Node *a[])
{       
	struct Node *temp;
    temp = a[1];
    a[1] = a[last];
	last --;                                                        
    int i = 1;  
	int j = 0;    

    while(i <= last/2)                                              
	{      
		if((a[2*i]->r < a[2*i+1]->r) || (2*i == last)) 
		{
			j = 2*i;
		}
		else
		{
			j = 2 * i + 1; 
		}                                                      
		if(a[i]->r > a[j]->r) 
		{                     

            struct Node *temp;  
            temp = a[i];  
            a[i] = a[j];  
            a[j] = temp;
            i = j;                                                  
        }                                                          
        else
		{
			return temp;                                         
		}
    }                                                              
       return temp;                                                  
}                                                                     

int main()  
{  
	
	ifstream fin("input.txt");  
    ofstream fout("output.txt");  
    int n,m,c;  
    fin >> n;
	fin >> m;
	fin >> c;  

    double **w = new  double*[n+1];  
    double **cc = new double*[n+1];  

    for(int i = 1; i <= n; i++)
	{  
		w[i] = new double[m+1];  
        cc[i] = new double[m+1];  
	}  

	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{  
            fin >> cc[i][j];  
		}
	}  

    for(int i=1;i<=n;i++)  
	{
		for(int j=1;j<=m;j++)  
		{
            fin >> w[i][j];  
		}
	}

    double *cmin = new double[n+1];  
    double *wmin = new double[n+1];  

    for(int i = 1; i <= n; i++)   
	{  
		cmin[i] = cc[i][1];  
		wmin[i] = w[i][1];  
        for(int j=2; j<=m; j++)     
		{  
			if(cmin[i] > cc[i][j])
			{
				cmin[i] = cc[i][j];  
			}
			if(wmin[i] > w[i][j])
			{
				wmin[i] = w[i][j];  
			}
		}  
   }  

    double *rc = new double[n+1];//剩余部件最小价格和  
    double *rw = new double[n+1];//剩余部件最小重量和  

    rc[n] = 0;
	rw[n] = 0;  
    for(int i = n-1; i>=1; i--)     
	{  
		rc[i] = rc[i+1]+cmin[i+1];  
		rw[i] = rw[i+1]+wmin[i+1];  
	}  

    struct Node *node = new struct Node;  
    node->peer = 0;  
    node->cv = 0;  
    node->cw = 0;  
    node->position = 0;  
    node->r = rw[1]+wmin[1];  

    insert(node,0);  
    int cpeer = 0;  
    int q_len = 1;  
    bool isend = false;   
    while(!isend&&q_len>0)  
    {   
		node = deletemin(q_len,queues);  
        q_len--;  
        if(node->peer == n)    
		{  

			isend = true;  
            fout << node->cw << endl; 
			int *x = new int[n+1];
            for(int k=n;k>=1;k--)  
			{  
                 x[k]=node->position;  
                 node=node->parent;  
            }  

            for(int k=1;k<=n;k++)   
			{
				fout<<x[k]<<" ";  
			}

            fout<<endl; 
			return 0; 
		}

        for(int j=1;j<=m;j++)
        { 
			if(node->cv+cc[node->peer+1][j]+rc[node->peer+1]<=c)  
			{  
				cpeer=node->peer+1;  
				struct Node *node_add=new struct Node ;  
				node_add->peer=cpeer;  
				node_add->cv=node->cv+cc[cpeer][j];  
				node_add->cw=node->cw+w[cpeer][j];   
				node_add->r=node_add->cw+rw[cpeer];  
				node_add->position=j;  
				node_add->parent=node;  
				insert(node_add,q_len);  
				q_len++;  
            }  
		}  
	}  

	if(q_len<=0) 
	{  
		cout<<"No Solution!"<<endl;
           return 0;
	}
}