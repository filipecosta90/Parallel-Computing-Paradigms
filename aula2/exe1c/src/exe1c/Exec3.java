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
public class Exec3 {
    /*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

    public static void main(String[] args) {

    new Thread(new Cont3( 0, 4)).start();
    new Thread(new Cont3( 1, 4 )).start();
    new Thread(new Cont3( 2, 4 )).start();
    new Thread(new Cont3( 3, 4 )).start();

  }
}