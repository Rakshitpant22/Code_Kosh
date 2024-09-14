#include<iostream>
#include<thread>
#include<unistd.h>

using namespace std;
void task_a(){
    for(int i=0;i<5;i++){
        sleep(1);
        cout<<"task a"<<i<<endl;
        fflush(stdout);
    }
}
void task_b(){
    for(int i=0;i<5;i++){
        sleep(1);
        cout<<"task b"<<i<<endl;
        fflush(stdout);
    }
}
int main()
{
    thread t1(task_a);
    thread t2(task_b); 
    //here main threads exits so for that:
    //we join the all threads and wait to combine & then return
    t1.join();
    t2.join();
    return 0;
}