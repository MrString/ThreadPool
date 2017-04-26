#ifndef THREADPOOL_H
#define THREADPOOL_H

#include <list>
#include <cstdio>
#include <exception>
#include <pthread.h>

#include "locker.h"

template< typename T>
class threadpool
{
public:
	threadpool(int thread_number = 8, int max_requests = 10000);
	~threadpool();
	bool append(T* request);
	
private:
	static void* worker(void* arg)
	void run();
	
private:
	int m_thread_number;    //线程数
	int m_max_requests;     //最大请求数
	pthread_t* m_threads;   //线程id
	std::list<T* > m_workqueue; //请求队列
	locker m_queuelocker;
	sem m_queuestat;
	bool m_stop;
}1

#endif
