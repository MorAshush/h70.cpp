#ifndef SEMAPHORE_HPP
#define SEMAPHORE_HPP

#include <semaphore.h> 



class Semaphore
{ 

public:
  Semaphore(int a_numSemaphores);

  ~Semaphore();

  Semaphore(const Semaphore &a_other) = delete;     
  Semaphore& operator=(const Semaphore &a_other) = delete; 

  bool try_wait();
  void wait();    
  int release();

private:   
  sem_t m_semaphore;

};


 #endif //SEMAPHORE_HPP