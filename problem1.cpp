#include <iostream>
#include <stdio.h>     
#include <stdlib.h>  
#include <time.h>  
#include <math.h>

using namespace std;

int main() {
  double UniformDistribution[1000];
  double UniformDistribution2[1000];

  double InterArrivalTimes[1000];
  double ServiceTimes[1000];
  double ArrivalTimes[1000];
  double ArrivalTime = 0;
  double TotalServiceTimes = 0;

  srand(time(NULL));
  for (int i = 0; i < 1000; i++){
    UniformDistribution[i] = (double) rand()/ RAND_MAX;
  }
    for (int i = 0; i < 1000; i++){
    UniformDistribution2[i] = (double) rand()/ RAND_MAX;
  }

  for (int i = 0; i < 1000; i++){
    InterArrivalTimes[i] = (-.5)*log(UniformDistribution[i]);
    ServiceTimes[i] = (-1)*log(UniformDistribution2[i]);
    TotalServiceTimes+= ServiceTimes[i];

  }

  double ActualAvgServiceTime = TotalServiceTimes / 1000;

  for (int i = 0; i < 1000; i++){
    ArrivalTime+= InterArrivalTimes[i];
    ArrivalTimes[i] = ArrivalTime;
  } 

  double ActualAvgAT = ArrivalTime / 1000;

  for (int i = 0; i < 1000; i++){
    cout << "<process ID: " << i+1 << ", arrival time: " << ArrivalTimes[i] <<", requested service time: "  << ServiceTimes[i] << ">" << endl;
  }
  cout << "Actual Average Arrival Rate: 1 process per " << ActualAvgAT << " seconds" << endl;
    cout << "Actual Average Service Time: " << ActualAvgServiceTime << " seconds" << endl;

}