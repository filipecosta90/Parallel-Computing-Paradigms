
class PrimeServer {
  int *myPrimes;     // buffer to hold primes already calculated
  int nPrimes;      // number of primes calculated
  PrimeServer *myNext;   // next filter
  double timei;
  int contaPrimos;
  int divisoes;
  int maxprime;

  public:
  void minitFilter(int myMinP,int myMaxP,int SMaxP) {
    nPrimes=0;

    int pr[SMaxP];
    int nl = PrimeCalc::lowPrimes(SMaxP,pr);

    myPrimes = new int[nl];
    for(int i=0; i<nl; i++) 
      if (pr[i]>=myMinP && pr[i]<=myMaxP) myPrimes[nPrimes++]=pr[i];
    std::cout << nPrimes << " Primes " << myMinP << " ... " << myMaxP << "\n";

    contaPrimos=0;
    divisoes=0;
    maxprime=0;
    timei = MPI_Wtime();
  }

  void initFilter(int myMinP,int myMaxP,int SMaxP,PrimeServer *next)  {
    myNext = next;
    minitFilter(myMinP,myMaxP,SMaxP); 
  }

  void mprocess(int num[], int tam) {
    //cout << "Pack " << num[0] << " : " << num[tam-1] << "\n";
    int fim=0;

    if (num[tam-1]==-3) fim=1;
    for(int i=0; i<tam; i++) { 
      if (num[i]>2) {
        divisoes++;
        if (PrimeCalc::isPrime(num[i],myPrimes,nPrimes)) contaPrimos++;
        else num[i]=0;
      }
    }
    if (fim) { 
      num[tam-1]=-3;
      for(int i=0; i<tam; i++) if (num[i]>maxprime) maxprime=num[i];
      std::cout << divisoes << " testes - Max Prime " << maxprime << "\n";
    }
  }

  void process(int num[], int tam) {
    mprocess(num,tam);

    if (myNext!=0) myNext->process(num,tam);

    if (myNext==0 && num[tam-1]==-3)  { // fim do processamento
      end();
    }	
  }
  void end() {
    double timef = MPI_Wtime();
    std::cout << "Demorou " << (timef-timei)/1000 << "s " << contaPrimos << " primos\n";  
  }
};
