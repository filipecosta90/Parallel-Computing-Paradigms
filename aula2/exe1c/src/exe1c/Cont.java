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
public class Cont extends Thread { 

  public Cont() { }

  @Override
    public void run() {
      for (int i=0; i<100; i++) 
        System.out.println(Thread.currentThread() + " i= " + i);
    }
}
