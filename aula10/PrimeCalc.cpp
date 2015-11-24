class PrimeCalc {
  public:
    static int isPrime(int num, int *primes, int cont) {
      int j=0;
      while (j<cont && ((num%(primes[j]))!=0) ) j++; 
      return(j==cont);
    }

    static int lowPrimes(int max,int *primes) {
      int cur=1;
      primes[0]=3;

      for(int i=5; i<max; i+=2) 
        if (isPrime(i,primes,cur))  primes[cur++]=i;

      return(cur);
    }    

    static void seqPrimes(int min, int max, int *lprimes, int nlprimes) {
      int cur=0;
      int *primes = new int[max];

      printf("Calcular primos ate  %d - versao sequencial \n",max);

      double start = clock();;
      for(int i=min+1; i<max; i+=2) {
        if (isPrime(i,lprimes,nlprimes)) primes[cur++]=i; 
      }
      double end = clock();
      std::cout <<  cur << " primos, demorou " << (end - start)/1000 << "ms \n";

      //for (int i=0/*cur-3/*/; i<cur; i++) 
      //    /*if ((i+1)%100==0)*/ printf("primo %d = %d\n",i,primes[i]);
      delete(primes);
    }

};
