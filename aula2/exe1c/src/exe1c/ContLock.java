/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package exe1c;

import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

/**
 *
 * @author filipeoliveira
 */
public class ContLock extends Thread { 

    Lock lockFor;

  public ContLock( Lock lock ) { 
      lockFor = lock;
  }

  @Override
    public void run() {
      try{
        lockFor.lock();
        for (int i=0; i<100; i++) {
          System.out.println(Thread.currentThread() + " i= " + i);
        }
      }
      finally {
          lockFor.unlock();
      }
    }
}
