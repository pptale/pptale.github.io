//https://www.codechef.com/problems/AIRM?tab=submissions

#include <stdio.h>

int main(void) {
	// your code goes here
	int nr_test_cases;
	scanf("%d",&nr_test_cases);
	int nr_airplanes;
	int arrival_time, departure_time;
	int max_value_time = 1440;
	int freq_time_slot[max_value_time];
	while(nr_test_cases > 0){
	    nr_test_cases = nr_test_cases - 1;
	    
	    //Initialize freq_time_slot to zero
	    for (int i=0; i < max_value_time; i++){
	        freq_time_slot[i] = 0;
	    }
	    
	    scanf("%d",&nr_airplanes);
	
	    // Read arrival time
	    int arrival_time_slots[nr_airplanes];
	    for (int i = 0; i < nr_airplanes; i++){
	        scanf("%d",&arrival_time);
	        //cout<< arrival_time <<" ";
	        freq_time_slot[arrival_time] = freq_time_slot[arrival_time] + 1; 
	    }
	    
	    // Read arrival time
	    int departure_time_slots[nr_airplanes];
	    for (int i=0; i < nr_airplanes; i++){
	        scanf("%d",&departure_time);
	        //cout<< departure_time <<" ";
	        freq_time_slot[departure_time] = freq_time_slot[departure_time] + 1;
	    }
	    //cout<<endl;
	    int max_element_in_freq_time_slot = 0;
	    for (int i=0; i < max_value_time; i++){
	        if (max_element_in_freq_time_slot < freq_time_slot[i]){
	            //cout<<max_element_in_freq_time_slot<<" ";
	            max_element_in_freq_time_slot = freq_time_slot[i];
	        }
	    }
	    printf("%d\n", max_element_in_freq_time_slot);
	}
}

