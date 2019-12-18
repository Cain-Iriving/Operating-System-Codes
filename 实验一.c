//#include <stdio.h>
//#include <stdlib.h>
//#define f 5
//struct PCB{
//    int id;
//    int priority;
//    int cputime;
//    int alltime;
//    char state;
//    int next;
//}pcb[f-1];
//
//int procnum;
//int rand();
//int algo;
//int run,head,tail,j;
//
//void print(){ //print the running process ,waiting queue and pcb sequence list 
//	int k,p;
//	for(k = 1;k<=40;++k){
//		printf("=");
//		printf("\nrunning proc\n");
//		printf("waiting queue");
//		printf("\n %d ",pcb[run].id);
//		p = head;
//		while(p!=0){
//			printf("%5d",p);
//			p = pcb[p].next;
//		}
//		printf("\n");
//		for(k = 1;k<=40;++k){
//			printf("=");
//			printf("\n");
//			printf(" id ");
//			for(k = 1;k<f+1;++k){
//				printf("%5d",pcb[k].id);
//				printf("\n");
//				printf(" priority ");
//				for(k = 1;k<f+1;++k){ 
//					printf("%5d",pcb[k].priority);
//					printf("\n");
//					printf("alltime ");
//					for(k = 1;k<f+1;++k){
//						printf("%5d",pcb[k].alltime);
//						printf("\n");
//						printf("state ");
//						for(k = 1;k<f+1;++k){
//							printf("%5c",pcb[k].state);
//							printf("\n");
//							printf("next ");
//							for(k=1;k<f+1;++k){
//								printf("%5d",pcb[k].next);
//								printf("\n");
//							}
//						}
//					} 
//			}
//			
//		}
//	}
//}
//} 
//
//void insert(int q){ //insert a process
//    int p,s;
//    p = head;
//    s = pcb[head].next;
//    while((pcb[q].priority<pcb[s].priority)&&(s!=0)){
//        p = s;
//        s = pcb[s].next;
//}
//        pcb[p].next = q;
//        pcb[q].next = s;
//}
//void insert2(){ //put a process onto the tail of the queue
//    pcb[tail].next = run;
//    tail = run;
//    pcb[run].next = 0;
//}
//
//void init(){ //create a waiting queue
//    int i;
//    head = 0;
//    if(algo==2){
//        for(i = 1;i<f+1;++i){
//            pcb[i].id = i;
//            pcb[i].priority = (rand()+11)%41;//0-40;
//            pcb[i].cputime  = 0;
//            pcb[i].alltime  = (rand()+1)%7; //0-7
//            pcb[i].state = 'W';
//            pcb[i].next = 0;
//            if((pcb[i].priority<pcb[head].priority)&&(head!=0)){
//                insert(pcb[i].id);
//            }else{
//                pcb[i].next = head;
//                head = pcb[i].id;
//            }
//        }
//    }else{
//            for(i=1;i<f+1;++i){
//                pcb[i].id = i;
//                pcb[i].priority = (rand()+1)%3+1; //1-4
//                pcb[i].cputime = 0;
//                pcb[i].alltime = (rand()+1)%7;
//                pcb[i].state = 'W';
//                pcb[i].next = (i+1)%(f+1);
//            }
//            head = 1;
//            tail = f;
//            pcb[f].next = 0;
//        }
//    run =  head;
//    pcb[run].state = 'R';
//    head = pcb[head].next;
//    pcb[run].next = 0;
//    print();
//}
//
// //Priority algorithm
//void prisch(){ //the process with prio algorithm
//    while(run!=0){
//        pcb[run].cputime += 1;
//        pcb[run].priority -= 3;
//        pcb[run].alltime -= 1;
//        if(pcb[run].alltime==0){
//            pcb[run].state = 'F';
//            pcb[run].next = 0;
//            if(head!=0){
//                run = head;
//                pcb[f].state = 'R';
//                head = pcb[head].next;
//            }else{
//                pcb[0].id = pcb[run].id;
//                run = 0;
//            }
//        }else if((pcb[run].priority < pcb[head].priority)&&(head!=0)){
//            pcb[run].state = 'W';
//            insert(run);
//            run = head;
//            pcb[run].state = 'R';
//            head = pcb[head].next;
//        }
//        print();
//     }
//}
//
//void timesch(){ //the process with RR algorithm
//    while(run!=0){
//        pcb[run].alltime -= 1;
//        pcb[run].cputime += 1;
//        if(pcb[run].alltime==0){
//            pcb[run].state = 'F';
//            pcb[run].next = 0;
//            if(head!=0){
//                run = head;
//                pcb[run].state = 'R';
//                head = pcb[head].next;
//            }else{
//                pcb[0].id = pcb[run].id;
//                run = 0;
//            }
//        }else if((pcb[run].cputime==pcb[run].priority)&&(head!=0)){
//            pcb[run].state = 'W';
//            pcb[run].cputime = 0;
//            insert2();
//            run = head;
//            pcb[run].state = 'R';
//            head = pcb[head].next;
//        }
//        print();
//    }
//}
//
//int main()
//{
//    agan:printf("Type the algorithm is (1:时间片轮转算法 2:优先级调度算法):");
//    scanf("%d",&algo);
//    if(algo==2){
//        printf("Output of priority.\n");
//        init();
//        prisch();
//    }
//    else if(algo==1){
//
//            printf("Output of round robin.\n");
//            init();
//            timesch();
//
//    }
//    else{
//        printf("Try again,please.\n");
//        goto agan;
//    }
//    for(j=1;j<=40;++j){
//        printf("=");
//    }
//    printf("\n\n");
//    for(j=1;j<=40;++j){
//        printf("=");
//    }
//    printf("\n\n");
//    printf("system finished\n");
//    getch();
//    return 0;
//}
//
#include <stdio.h>    
#include <stdlib.h>    
    
struct node    
{    
    int pid;//进程id号     
    int prio;//进程优先级     
    int runtime;//进程运行的时间     
    int alltime;//进程还需运行的时间     
    char state;//进程的状态 运行r，就绪j，阻塞b。     
    struct node *next;    
};    
    
     
typedef struct node Node;    
typedef Node * Link;    
    
void init(Link *head);    
void create(Link head);    
void menu(Link head);    
void RR(Link head);    
void FCFS(Link head);     
Link gethighprio(Link head);    
void PRIORITY(Link head);    
void error();    
void quit();    
void save();    
int num = 0;//进程的id号     
     
 void create(Link head)    
{    
    Link p = head;    
    Link newnode;    
    //char ch;    
    newnode = (Link)malloc(sizeof(Node));       
        
    newnode->runtime = 0;    
    newnode->state = 'j';    
    newnode->pid = ++num;    
    newnode->prio = 2;    
    newnode->alltime = 2;    
    p = head;     
    while(p->next != NULL)    
    {    
        p = p->next;    
    }    
    newnode->next = p->next;    
    p->next = newnode;    
        
    newnode = (Link)malloc(sizeof(Node));       
        
    newnode->runtime = 0;    
    newnode->state = 'j';    
    newnode->pid = ++num;    
    newnode->prio = 3;    
    newnode->alltime = 3;    
    p = head;     
    while(p->next != NULL)    
    {    
        p = p->next;    
    }    
    newnode->next = p->next;    
    p->next = newnode;    
        
    newnode = (Link)malloc(sizeof(Node));       
        
    newnode->runtime = 0;    
    newnode->state = 'j';    
    newnode->pid = ++num;    
    newnode->prio = 4;    
    newnode->alltime = 4;    
    p = head;     
    while(p->next != NULL)    
    {    
        p = p->next;    
    }    
    newnode->next = p->next;    
    p->next = newnode;    
        
    newnode = (Link)malloc(sizeof(Node));       
        
    newnode->runtime = 0;    
    newnode->state = 'j';    
    newnode->pid = ++num;    
    newnode->prio = 5;    
    newnode->alltime = 5;    
    p = head;     
    while(p->next != NULL)    
    {    
        p = p->next;    
    }    
    newnode->next = p->next;    
    p->next = newnode;    
  //printf("请输入进程的优先级：");    
//  scanf("%d",&(newnode->prio));    
//  printf("请输入进程的总共需要运行的时间：") ;    
//  scanf("%d",&(newnode->alltime));     
//  getchar();    
//  printf("\n");    
    /*  
printf("是否要继续创建进程：");  
    scanf("%c",&ch);  
    if(ch == 'y')  
    {  
        create(head);  
    }  
    else if(ch == 'n')  
    {  
        menu(head);  
    }  
    else  
    {  
        printf("您的输入有误！\n");  
    }*/    
}     
    
    
/*尾插入的形式调度算法*/     
//void create(Link head)    
//{    
//  Link p = head;    
//  Link newnode;    
//  char ch;    
//  newnode = (Link)malloc(sizeof(Node));    
//      
//  printf("请输入进程的优先级：");    
//  scanf("%d",&(newnode->prio));    
//  printf("请输入进程的总共需要运行的时间：") ;    
//  scanf("%d",&(newnode->alltime));    
//      
//  newnode->runtime = 0;    
//  newnode->state = 'j';    
//  newnode->pid = ++num;    
//    
//  while(p->next != NULL)    
//  {    
//      p = p->next;    
//  }    
//  newnode->next = p->next;    
//  p->next = newnode;       
//  getchar();    
//  printf("\n");    
//  printf("是否要继续创建进程：");    
//    scanf("%c",&ch);    
//    if(ch == 'y')    
//    {    
//      create(head);    
//    }    
//    else if(ch == 'n')    
//    {    
//        menu(head);    
//    }    
//    else    
//    {    
//      printf("您的输入有误！\n");    
//    }    
//}     
//    
//void save()    
//{    
//        
//}    
    
/*先来先服务调度算法*/     
void FCFS(Link head)    
{    
    Link old;    
    Link p = head->next;    
    if(p == NULL)    
    {    
        printf("队列里面没有进程，返回啦！\n");    
        menu(head);    
    }    
    
    p->state = 'r';    
        
    while(p != NULL && ((p->alltime) > 0))    
    {    
        p->runtime++;    
        p->alltime--;    
        printf("运行进程id号： %d 优先级：%d  进程运行时间： %d  进程还需运行时间 %d  进程状态：%c\n",p->pid,p->prio,p->runtime,p->alltime,p->state);     
                
    }    
    old = p;    
    head->next = p->next;    
    p = p->next;    
    free(old);    
}    
    
/*查找获得链表中优先级最高的进程，返回指向该进程的指针*/     
Link gethighprio(Link head)     
{    
    Link p = head->next;    
    Link q = p->next;    
       
    while(q != NULL)    
    {    
        if(p->prio < q->prio)    
        {    
            p = q;      
        }    
        q=q->next;    
    }    
    return p;    
}    
    
/*动态优先级调度算法*/     
void PRIORITY(Link head)    
{    
    Link q = head;    
    Link front = head;    
    Link old;    
    if(q->next == NULL)    
    {    
        printf("队列里面没有进程，返回啦！\n");    
        menu(head);     
    }    
    q = gethighprio(head);    
    q->state = 'r';    
          
    if(q->alltime > 0)    
    {    
        q->runtime++;    
        q->alltime--;    
        q->prio = (q->prio) - 1;    
        printf("运行的进程pid：%d  优先级：%d   进程运行时间： %d  进程还需运行时间 %d  进程状态：%c\n",q->pid,q->prio,q->runtime,q->alltime,q->state);    
        if(q->alltime == 0)    
        {    
            old = q;    
            if(q->next != NULL)    
            {    
                while(front->next != q)    
                {    
                    front = front->next;    
                }    
                front->next = q->next;    
                q = NULL;    
                free(old);    
            }    
            else              /*一开始程序问题出在这里，删除结点末尾没有=NULL，以后要注意*/    
            {    
                while(front->next != q)    
                {    
                    front = front->next;    
                }    
                front->next = NULL;    
                q = NULL;    
                free(old);          
            }       
        }    
        PRIORITY(head);    
    }    
}    
    
/*时间片轮转调度算法*/     
void RR(Link head)    
{    
    Link p = head->next;    
    Link front = head;    
    Link old;    
        
    if(p == NULL)    
    {    
        printf("队列里面没有进程，返回啦！\n");    
        menu(head);     
    }    
    while(head->next != NULL)    
    {    
        front = head;    
        p->runtime++;    
        p->alltime--;    
        p->state = 'r';    
            
        printf("运行的进程pid：%d  优先级：%d   进程运行时间： %d  进程还需运行时间 %d  进程状态：%c\n",p->pid,p->prio,p->runtime,p->alltime,p->state);    
            
        if(p->alltime <= 0)    
        {    
            old = p;    
            if(p->next != NULL)    
            {    
                while(front->next != p)    
                {    
                    front = front->next;    
                }    
                front->next = p->next;    
                p = p->next;    
                free(old);     
            }    
            else{    
                while(front->next != p)    
                {    
                    front = front->next;    
                }    
                front->next = NULL;    
                p = NULL;    
                free(old);    
                old = NULL;    
            }    
        }    
            
        if((p != NULL) && (p->next != NULL))    
        {    
            p = p->next;    
        }    
        else{    
            p = head->next;    
        }    
            
            
    }    
        
}    
    
/*输入有误*/    
void error()    
{    
    printf("您的输入有误，退出啦！\n");    
    exit(1);     
}    
    
/*退出*/    
void quit()    
{    
    printf("Thank you for your using!\n");    
    printf("        白白             \n");    
    exit(1);    
}    
    
void menu(Link head)    
{    
    int choice;    
    while(1)    
    {    
        printf("\n");    
        printf("********************************************\n");    
        printf("***************进程调度*********************\n");    
        printf("*    1.创建进程       2.先来先服务算法     *\n");    
        printf("*    3.时间片轮转算法 4.优先级调度算法     *\n");    
        printf("*    5.退出                                *\n");    
        
        printf("请输入您的选项（1~6）：");    
        scanf("%d",&choice);    
            
        switch(choice)    
        {    
            case 1:{    
                create(head);    
                break;    
            }    
                
            case 2:{    
                FCFS(head);    
                break;    
            }    
                
            case 3:{    
                RR(head);    
                break;    
            }    
            case 4:{    
                PRIORITY(head);    
                break;    
            }    
            case 5:{    
                quit();    
                exit(1);    
            }    
                
            default:{    
                error();    
                break;    
            }    
        }    
            
    }    
         
}    
    
void init(Link *head)    
{    
    *head = (Link)malloc(sizeof(Node));    
    (*head)->next = NULL;    
}    
    
int main()    
{    
    Link head;    
    //Link newnode;    
        
    
        
    init(&head);    
        
    menu(head);    
            
}    


