/**
 * Author: Utkarsh Patel (18EC35034)
 *
 * Instructions to run:
 *  - pass number of iteration in the command-line
 *
 *    e.g. ./a.out 100 | python3 plot.py
 *    
 *    Here, number of iteration is 100
 */

#include <bits/stdc++.h>
#include "../debug.h"

using namespace std;

double genNextArrivalTime(double lambda) {
    // Generate a random variable following 
    // exponential distribution defined by lambda.
    // `U` is generated uniformally in [0, 1].
    // `E` follows exponential distribution.
    double U = (rand() % RAND_MAX + 1) / (1.0 * RAND_MAX);
    double E = (-1.0) * log(U) / lambda;
    return E;
}


int main(int argc, char *argv[]) {
    cout << setprecision(6);
    srand(time(NULL));
    int iter = stoi(argv[1]);
    
    for (double lambda : {1, 4, 10}) {
    
	    vector<int> nPackets(iter);
	    const double T = 1;

	    
	    for (int i = 0; i < iter; i++) {
		double sumArrivalTime = 0;
		while (sumArrivalTime < T) {
		    sumArrivalTime += genNextArrivalTime(lambda);
		    nPackets[i]++;
		}
	    }
	    

	    int maxPackets = 0;
	    for (int i = 0; i < iter; i++) {
		maxPackets = max(maxPackets, nPackets[i]);
	    }
	    
	    vector<double> prob(maxPackets + 1);
	    for (int i = 0; i < iter; i++) {
		prob[nPackets[i]]++;
	    }
	    
	    for (int i = 0; i < maxPackets + 1; i++) {
		prob[i] /= iter;
		cout << prob[i] << " ";
	    }
	    cout << '|';
    }	   
}                       
