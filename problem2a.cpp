#include <iostream>
#include <stdio.h>     
#include <stdlib.h>  
#include <time.h>  
#include <math.h>

using namespace std;

int main() {
  double UniformDistribution;
  double UniformDistribution2;
  double HourCounter = 0.00;
  double HourCounter2 = 0.00;
  double MTBF;
  double MTBF2;


  srand(time(NULL));

  cout << "Server 1 Info:" << endl;
  while (HourCounter < 175200){
    UniformDistribution = (double) rand()/ RAND_MAX;
    MTBF = (-500)*log(UniformDistribution);
    HourCounter+= MTBF;
    cout << "Server 1 failed at hour: " << HourCounter << " after " << MTBF << " hours. Restored at hour " << HourCounter + 10 << " ." << endl;
    HourCounter+= 10;  
  }
  
  cout << "Server 2 Info:" << endl;
  while (HourCounter2 < 175200){
    UniformDistribution2 = (double) rand()/ RAND_MAX;
    MTBF2 = (-500)*log(UniformDistribution2);
    HourCounter2+= MTBF2;
    cout << "Server 2 failed at hour: " << HourCounter2 << " after " << MTBF2 << " hours. Restored at hour " << HourCounter2 + 10 << " ." << endl;
    HourCounter2+= 10; 
  }

}