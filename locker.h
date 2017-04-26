#ifndef LOCKER_H
#define LOCKER_H

#include <pthread.h>
#include <semaphore.h>
#include <iostream>

class sem
{
public:
	sem()
	{
		if(sem_init(&m_sem, 0, 0) != 0)
		{
			cout << "�ź�����ʼ������" << endl;
			exit(-1);
		}
	}
	~sem()
	{
		sem_destroy(&m_sem);
	}
	bool wait()
	{
		return sem_wait(&m_sem) == 0;
	}
	bool post()
	{
		return sem_post(&m_sem) == 0;
	}
private:
	sem_t m_sem;
};
