//空结点后还有结点，直接return false

void Q1(){
    enqueue(sq,p,maxsize)
    while(!empty()){
        deQueue(sq,r);
        if(r){
            enQueue(r->lchild);
            enQueue(r->rchild);
        }
        else
            while(!isEmpty(sq)){
                dequeue(sq,r);//取出队首元素，如后面还有，即r，那就return false，非完全二叉树
                if(r)
                return false;
            }
    }
}