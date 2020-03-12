#include <iostream>
#include <vector>
#include <conio.h>
#include <iomanip>

using namespace std;

void swap(int &a , int &b)  {
	
	
	int temp= a ;
	
	a = b;
	
	b = temp;
	
}

int n ;

vector<int>Processed_pid ,Processed_at ,Processed_bt , Processed_ct;

vector<int> Processes;
vector<int>Burst;
vector<int>Arrival;
    
void NextShortestJob( int &maintime )  {
	
	
	

			
	int i = 0;
	int smallestburst = Burst.front();
	int pos=0;


	for (int l : Burst ) {
		
		
	if (smallestburst > l) {
		
	smallestburst= l;
	pos = i;
	
}
	++i;	
	
	}
	
	
	
	
	
	

	
	maintime = maintime + Burst.at(pos);  // 2 time unit for delay
	
	
	Processed_pid.push_back(Processes.at(pos));
	Processed_bt.push_back(Burst.at(pos));
	Processed_at.push_back(Arrival.at(pos));
	Processed_ct.push_back(maintime);

	
	

	
	

	
//	cout << 'P'<<list.at(pos) << '|';

	
 
	Processes.erase(Processes.begin() + pos );
	Burst.erase(Burst.begin() + pos );
	Arrival.erase(Arrival.begin() +pos);
	





}



int  main ()   {
	
	
	
	
	

	
	cin >> n;
	
	
    int pid[n] , sorted_pid[n];
    
    int at[n] , sorted_at[n];
    
    int bt[n] , sorted_bt[n] ,BT[n];
    
    	int ct[n];
	
    
   
    
    int limit =0;
    
    
    for (int i = 0 ; i < n ; ++i)   {
    	
    	cout << "\n\n\nEnter Pid : ";
    	
    	cin >> pid[i];
    	
    	cout << "\nEnter Arival time : ";
    	
    	cin >> at[i];
    	
    	cout << "\nEnter Burst time : ";
    	
    	cin >> bt[i];
    	
    	limit += bt[i];
    	
    	BT[i] = bt[i];
    	
    
    	
	}
    
    limit = limit + (2*(n-2));
    
    
    
    for (int  i = 0 ; i < n ; ++i)  {
    	
    	
    	for (int j = 0 ; j < n-1 ; ++j)  {
    		
    		
    		if (at[j] > at[j+1])   {
    			
    			
    			swap(pid[j] , pid[j+1]);
    			
    			swap(at[j] , at[j+1]);
    			
    			swap(bt[j] , bt[j+1]);
    			
    			
			}
    			
		}
    		
	}
    
    
    
    
    

    
    Processes.push_back(pid[0]);
    Arrival.push_back(at[0]);
	Burst.push_back(bt[0]);
	

    
    //  5 1 10 1 2 4 4 3 7 7 4 2 3 5 1 2
    
    
 
    
    int maintime = Arrival.front();
    
    int o =1;
    
    
    
    for ( ;maintime <= limit ; )   {
    	
    	if (!Processes.empty()) {
		
         NextShortestJob(maintime);
       
    
    
}

else {
	

	++maintime;
	
}
    	
    	for ( ; o < n ; ++o)  {
			
			if (maintime >= at[o])  {	
			
			Processes.push_back(pid[o]);
			
			Burst.push_back(bt[o]);
			
			Arrival.push_back(at[o]);
				
			}
			
			else break;
			
			
		} 
		
    	
    	maintime+=2;
    	
    	
    	
    	
	}
    
    
    cout << endl << endl;
    
    cout <<  "ID" << "\t\t" << "Arrival" << "\t\t"<< "Burst" << "\t\t" << "Completion" << "\t\t" << "Waiting" <<endl;

	for (int l = 0 ; l < Processed_pid.size() ; ++l)  {
		
		cout <<  Processed_pid.at(l) << "\t\t" << Processed_at.at(l) << "\t\t"<< Processed_bt.at(l) << "\t\t" << Processed_ct.at(l) << "\t\t\t" << (Processed_ct.at(l) - Processed_at.at(l))-Processed_bt.at(l) <<endl;
	}
	
	
}
