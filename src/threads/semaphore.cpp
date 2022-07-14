#include <cassert>

#include "semaphore.hpp"
#include "semaphore_error.hpp"


Semaphore::Semaphore(int a_numSemaphores)
{   
    int r = sem_init(&m_semaphore, 0, a_numSemaphores);
    if(r != 0)
    {
        throw SemaphoreError("Semaphore ctor", "construction failed.");
    }
}

Semaphore::~Semaphore()
{    
    int r = sem_destroy(&m_semaphore);
    assert(r == 0);
}

bool Semaphore::try_wait()
{
    if(sem_trywait(&m_semaphore) == 0)
    {
        return true;
    }

    if(errno != EAGAIN)
    {
        throw SemaphoreError("Semaphore try_wait", "Error while TryAcquire.");
    }

    return false;
}

void Semaphore::wait()
{   
    int r; 
    do 
    {
        r = sem_wait(&m_semaphore);
    } 
    while(r != 0 and errno == EINTR );

    if(r == 0)
    {
        return;
    }

    switch(errno)
    {
        case EINVAL: assert(!"Cant be due to ctor failure that will throw");
        break;        
    }
}

int Semaphore::release()
{    
    int r = sem_post(&m_semaphore);
    if(r != 0)
    {
        if(errno == EINVAL)
        {
            assert(!"can't be due to to ctuor failure that will throw.");
        }
        if(errno == EOVERFLOW)
        {
            throw SemaphoreError("Semaphore release", "overflow releasing.");
        }
    }

    return r;
}