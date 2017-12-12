// threadtest.cc 
//	Simple test case for the threads assignment.
//
//	Create two threads, and have them context switch
//	back and forth between themselves by calling Thread::Yield, 
//	to illustratethe inner workings of the thread system.
//
// Copyright (c) 1992-1993 The Regents of the University of California.
// All rights reserved.  See copyright.h for copyright notice and limitation 
// of liability and disclaimer of warranty provisions.

#include "copyright.h"
#include "system.h"
// testnum is set in main.cc
int testnum = 1;

//----------------------------------------------------------------------
// SimpleThread
// 	Loop 5 times, yielding the CPU to another ready thread 
//	each iteration.
//
//	"which" is simply a number identifying the thread, for debugging
//	purposes.
//----------------------------------------------------------------------
#include <iostream>
#include <unistd.h>

using namespace std;

//void funArray[10];


void SimpleThread1(int which)
{
    int num;
    for (num = 0; num < 5; num++)
		{
		sleep(1);
		printf("*** thread %d looped %d times\n", which, num);
        currentThread->Yield();
		}
}
void
SimpleThread2(int which)
{
	int num;
	for (num = 0; num < 5; num++)
		{
		sleep(2);
		printf("*** thread %d looped %d times\n", which, num);
		currentThread->Yield();
		}
}
void
SimpleThread3(int which)
{
    int num;
    
    for (num = 0; num < 5; num++) 
		{
		sleep(3);
		printf("*** thread %d looped %d times\n", which, num);
		currentThread->Yield();
		}
}

void
SimpleThread4(int which)
{
    int num;
    
    for (num = 0; num < 5; num++) 
		{
		sleep(4);
		printf("*** thread %d looped %d times\n", which, num);
		currentThread->Yield();
		}
}

//----------------------------------------------------------------------
// ThreadTest1
// 	Set up a ping-pong between two threads, by forking a thread 
//	to call SimpleThread, and then calling SimpleThread ourselves.
//----------------------------------------------------------------------


#include "synch.h"




void ThreadTest1()
{
	Thread * t1[5];
	
	
		t1[0] = new Thread("1");
		t1[1] = new Thread("2");
		t1[2] = new Thread("3");	
		t1[3] = new Thread("4");	
		t1[4] = new Thread("5");
		
	std::cout<<"threadtest1\n";
    DEBUG('t', "Entering ThreadTest1");
    
    
    
    
	
		
	t1[0]->Fork( SimpleThread1, 1,1);
	t1[1]->Fork( SimpleThread2, 2,4);
	t1[2]->Fork( SimpleThread3, 3,3);
	t1[3]->Fork( SimpleThread4, 4,2);
	t1[4]->Fork( SimpleThread1, 5,5);
	
	

	

}

//----------------------------------------------------------------------
// ThreadTest
// 	Invoke a test routine.
//----------------------------------------------------------------------

void
ThreadTest()
{
	 
    switch (testnum) {
    case 1:
	ThreadTest1();
    break;
	default:
	printf("No test specified.\n");
	break;
    }
}

