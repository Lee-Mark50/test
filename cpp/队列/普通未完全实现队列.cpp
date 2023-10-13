#define MAXSIZE 200
typedef struct{
	int a[MAXSIZE];
	int top,bottom;
	int size;
}*circleLine; 
//局限于：只能从一段入，另一端出队列。 
void in(circleLine &a,int i){
	//插入操作
}
void out(circleLine &a){
	//队列出元素 
} 
bool Isempty(){
	if(circleLine->top=circleLine->bottom){
		return true;
	}
	else return false;
} 