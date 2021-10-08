#include <iostream>
#include <stdio.h>     
#include <stdlib.h>  
#include <time.h>  
#include <math.h>

using namespace std;

double GenerateServers(int seed) {
  double UniformDistribution;
  double UniformDistribution2;
  double HourCounter = 0.00;
  double HourCounter2 = 0.00;
  double MTBF;
  double MTBF2;


  srand(seed);
  cout << "System: " << seed << endl;
  while (HourCounter < 175200 && HourCounter2 < 175200){
    UniformDistribution = (double) rand()/ RAND_MAX;
    UniformDistribution2 = (double) rand()/ RAND_MAX;
    MTBF = (-500)*log(UniformDistribution);
    MTBF2 = (-500)*log(UniformDistribution2);
    HourCounter+= MTBF;
    HourCounter2+= MTBF2;

    if ( (HourCounter <= HourCounter2) && (HourCounter2 <= HourCounter+10)){
      return HourCounter;
    }

    cout << "Server 1 failed at hour: " << HourCounter << " after " << MTBF << " hours. Restored at hour " << HourCounter + 10 << " ." << endl;

    cout << "Server 2 failed at hour: " << HourCounter2 << " after " << MTBF2 << " hours. Restored at hour " << HourCounter2 + 10 << " ." << endl;

    HourCounter+= 10;  
    HourCounter2+= 10; 
  }
  return HourCounter;
}

int main(){
  int seed1 = 1;
  int seed2 = 2;
  int seed3 = 4;

  double Total1 = GenerateServers(seed1);
  double Total2 = GenerateServers(seed2);
  double Total3 = GenerateServers(seed3);

  double AverageSystemFailureTime = (Total1 + Total2 + Total3) / 3;
  
  cout << "Average time until whole computing system fails: " << AverageSystemFailureTime << " hours" << endl;

}