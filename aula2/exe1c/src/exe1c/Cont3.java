/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package exe1c;

/**
 *
 * @author filipeoliveira
 */
public class Cont3 extends Thread { 

    int thread_id;
    int n_threads;
    
  public Cont3( int tid, int nthreads ) { 
  thread_id = tid;
   n_threads = nthreads;
  }

  @Override
    public void run() {
      for (int i=thread_id; i<100; i+=n_threads) 
        System.out.println(Thread.currentThread() + " i= " + i);
    }
}
