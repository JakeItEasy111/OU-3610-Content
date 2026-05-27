#include <cmath> 
#include <vector>
using namespace std;

//Program responses to #6 on HW 1 

float find_mean(vector<float> nums){
    float avg = 0; 

    for (int i = 0; i < nums.size(); i++){
        avg += nums[i]; 
    }
    avg = avg / nums.size(); 
    return avg; 
}

float find_stdev(vector<float> nums){
    float s = 0.0; 
    float avg = find_mean(nums); 

    for (int i = 0; i < nums.size(); i++){
        float term = abs(nums[0] - avg);
        pow(term, 2);
        s += term; 
    }

    s = s / nums.size(); 
    s = sqrt(s); 
    return s;
}
