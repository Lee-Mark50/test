//. 已知数组A[n,n]是对称的，完成下列任务：
//（1）设计算法将A[n,n]中的下三角中的各元素按行优先
//          次序存储到一维数组B中。
//（2）对任意输入的A数组中的元素的下标i, j，求解出该
//          元素在B中的存储位置。
#include<iostream>
using namespace std;
int main(){
	int n,l;
	cin>>n>>l>>endl;
	int A[n,n];
	int B[l];
	if(A[n,n]==0)return Null;
	for(int i=1;i<n;i++){
		for(int m=1;m<n;m++){
			B[m-1]=A[(i-1)*n];//将A数组元素存储在B数组中 
		}
	}
	cin>>i>>j;//输入下标i,j查找位置
	cout<<i<<"行"<<j<<"个"<<endl; 
} 
//3. 对两个以三元组形式存储的同阶稀疏矩阵A、B，设计算法求C=A+B。
#include<iostream>
#include<stdlib.h>
 
typedef struct node{
    int row;
	int col;
	int num;
}node;
 
typedef struct{
	int cnt1,cnt2;
	node matrix1[101];
	node matrix2[101];
}juzhen;
 
void init(juzhen *p){
    int n,m,t1,t2,i=0;
	int x,y,z,tmp;
	scanf("%d%d%d%d",&n,&m,&t1,&t2);
	p->cnt1=t1;
	p->cnt2=t2;
	while(1){
		scanf("%d%d%d",&x,&y,&z);
	    p->matrix1[i].row = x;
        p->matrix1[i].col = y;
        p->matrix1[i].num = z;
        i++;
        if(i==t1) break;
	}
	i=0;
	while(1){
		scanf("%d%d%d",&x,&y,&z);
	    p->matrix2[i].row = x;
        p->matrix2[i].col = y;
        p->matrix2[i].num = z;
        i++;
        if(i==t2) break;
	}
}
 
void add(juzhen *p){
    int i,j,k,flag;
	int tmp;
	k=p->cnt1-1;
	for(i=0;i < p->cnt2;i++){
		flag=1;
		for(j=0;j < p->cnt1;j++){
			if(p->matrix1[j].row == p->matrix2[i].row && p->matrix1[j].col == p->matrix2[i].col){
			    p->matrix1[j].num +=p->matrix2[i].num;
			    flag=0;
			    break;
			}	
		}
		if(flag){
			p->matrix1[++k].row = p->matrix2[i].row;
			p->matrix1[k].col = p->matrix2[i].col;
			p->matrix1[k].num = p->matrix2[i].num;
		}
	}
	p->cnt1 = k+1;
	
	for(i=0;i < k;i++){
		for(j=i;j<k+1;j++){
			if(p->matrix1[i].row > p->matrix1[j].row){  
                tmp = p->matrix1[i].row;  
                p->matrix1[i].row = p->matrix1[j].row;  
                p->matrix1[j].row = tmp;  
                tmp =p ->matrix1[i].col;  
                p->matrix1[i].col = p->matrix1[j].col;  
                p->matrix1[j].col = tmp;  
                tmp = p->matrix1[i].num;  
                p->matrix1[i].num = p->matrix1[j].num;  
                p->matrix1[j].num = tmp;  
            } 
		}
	}
	for(i=0;i<k;i++){  
        for(j=i;j<k+1;j++){  
            if(p->matrix1[i].row == p->matrix1[j].row && p->matrix1[i].col > p->matrix1[j].col){  
                tmp = p->matrix1[i].col;  
                p->matrix1[i].col = p->matrix1[j].col;  
                p->matrix1[j].col = tmp;  
                tmp = p->matrix1[i].num;  
                p->matrix1[i].num = p->matrix1[j].num;  
                p->matrix1[j].num = tmp;  
            }  
        }  
   } 
}  
 
void output(juzhen *p){
	int tmp=0;
	while((p->cnt1)--){
		printf("%d %d %d\n",p->matrix1[tmp].row,p->matrix1[tmp].col,p->matrix1[tmp].num);
		tmp++;
	}
}
 
int main(){
     juzhen *p=(juzhen *)malloc(sizeof(juzhen));
	 init(p);
	 add(p);
	 output(p);
	 return 0;
}
//4. 对下列广义表，请分别构造求出其中的原子c的复合函数。
//     A=(a,b,c) 
//     A=(a, (b, c) )
//     A=(a, b, (c,d) )
//
//answer:tail{A}，tail{A};即可得到c 
//answer:首先tail{A}取出里面的（b，c），得到（b，c）；然后tail{A}即可得到c
//answer: tail{A}，tail{A};即可得到(c,d);然后取表头 head{A}即可得到c

//5. 给出广义表的相关运算和相应的描述，并设计存储结构及
//    其运算实现。 
//6. 在有多个广义表需要存储的背景下，给出广义表的相关运
//    算和相应的描述，并设计存储结构及其运算实现。注意特
//    别要能对广义表标识符进行引用、指示等。 
//7，设计算法，对以字符串形式表示的广义表，构造出其相应
//  的链表存储结构。
代码实现： 
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
 //广义表的相关运算和描述
 typedef struct Inode{
 	int tag;
 	union {
 		char data;
 		struct Inode*sublist;
	 }val;
	 struct lnode*link;
 }GLnode;
 int GLLength(GLNode *g){//广义表长度 
 	int n=0;
 	GLNode *g1;
 	g1=g->val.sublist;
	 while(g1.!=NULL){
	 	n++;
	 	g1=g1->link; 
	 } return 0;
 } 
 int GLDepth(GLNode*g){//深度 
 	GLNode *g1;
 	int maxd=0,dep;
 	if(g->tag==0){
 		return 0;
	 }
	 g1=g->val.sublist;
	 if(g1==NULL){
	 	return 1;
	 } 
	 while(g1!=NULL){
	 	if(g1->tag==1){
	 		dep=GLDepth(g1);
	 		if(dep>maxd)maxd=dep;
		 }g1=g1->link;
	 }
	 return (maxd+1);
 }
 
 void DispGL(GLNode *g)//输出广义表 
{
	if(g!=NULL)
	{
		if(g->tag==0)
		{
			printf("%c",g->val.data);
		}
		else
		{
			printf("(");
			if(g->val.sublist==NULL)
			{
				printf("#");
			}
			else
			{
				DispGL(g->val.sublist);
			}
			printf(")");
		}
		if(g->link!=NULL)
		{
			printf(",");
			DispGL(g->link); 
		}
	}
}
GLNode *CreatGL(char *&s)//广义表的具体创设表现 
{
	GLNode *g;
	char ch=*s++;
	if(ch!='\0') 
	{
		g=(GLNode *)malloc(sizeof(GLNode));
		if(ch=='(')
		{
			g->tag=1;
			g->val.sublist=CreatGL(s);
		}
		else if(ch==')')
		{
			g=NULL;
		}
		else if(ch=='#')
		{
			g=NULL;
		}
		else
		{
			g->tag=0;
			g->val.data=ch;
		}
	}
	else
	{
		g=NULL;
	}
	ch=*s++;
	if(g!=NULL)
	{
		if(ch==',')
		{
			g->link=CreatGL(s);
		}
		else
		{
			g->link=NULL;
		}
	}
	return g;
}
void DestroyGL(GLNode *& g)//递归释放广义表 
{
	GLNode *g1,*g2;
	g1=g->val.sublist;
	while(g1!=NULL)
	{
		if(g1->tag==0)
		{
			g2=g1->link;
			free(g1);
			g1=g2;
		}
		else
		{
			g2=g1->link;
			DestroyGL(g1);
			g1=g2;
		}
	}
	free(g);
}
char Max(GLNode *g) 
{ 
 char max,maxx; 
 if (g!=NULL) 
	{ if (g->tag==0) 
		{ 
		    max=Max(g->link); 
		    if(g->val.data>max)
		    {
		    	 return g->val.data; 
			}
			else
			{
				return max;
			}

		} else 
			{ max=Max(g->val.sublist);
			  maxx=Max(g->link); 
			  if(max>maxx)
			  {
			  	return max;
			  }
			  else
			  {
			  	return maxx;
			  }
			}
	} 
	else 
		return 0; 
}
int main()
{
    GLNode *s;
    char *g="(a,(b,c,(#),d),((a,b),c,d,((#))))";
    s=CreatGL(g);//创造广义表 
    cout<<"g:";//输出实现 
	DispGL(s);
    cout<<GLLength(s)<<endl;
    cout<<GLDepth(s)<<endl;
    cout<<Max(s)<<endl; 
    DestroyGL(s);
}
