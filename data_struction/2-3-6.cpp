//生产者消费者问题伪码概述
#include<iostream>
using namespace std;

void P(Semephore s){
    s.value--;//对应的生产者要生产，占据空间减一
    if(s.value<=0){
        //没有空间了
        sleep(s.queue);
        //因此阻塞，停止生产
    }
}

void V(Sqmephore s){
    s.value++;//对应的消费者要消费，占据空间加一
    if(s.value<=0){
        //如果没有产品来供给消费，即占据队列空
        wake_up(s.queue);
        //唤醒队列，进行生产

    }
}


//对于简单的生产者消费者问题，选择伪码实现，
//要观察题目中出现的生产者和消费者具体涉及几个关系（并发和互斥）几个信号量

int Semephere_empty = n;
int Semephere_full = 0;
bool Semephere_mutex=1;

void Producer(){
    while(1){
        
        void ProduceItem();//这里生产者生产不用放置在PV进程里，是因为这里生产与队列空间无关，即源源不断生产消费进程来，处理关系与之后有关

        P(Semephere_empty);//如果初始empty为满就沉默，加锁

        P(Semephere_mutex);//互斥访问缓冲区资源，加锁

        void AddInToBuffer();

        V(Semephere_mutex);//先解huan'chon

        V(Semephere);
    }
}

void Customer(){
    while(1){
        P(Semephere);

        void CostFromBuffer();



        void BuyItem();


    }
}