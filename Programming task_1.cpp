
#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

int main() 
{
    // Week_days
    vector<string> days = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    
    // Corresponding temperatures
    vector<double> temperatures = {5.5, 12.0, 18.3, 21.5, 9.8, 25.0, 15.7};
    
    // Track warmest day using tuple
    tuple<string, double> warmestDay = make_tuple(days[0], temperatures[0]);
    
    cout << "Weather Report for the Week:\n";
    for (size_t i = 0; i < days.size(); i++) 
    {
        cout << days[i] << " - " << temperatures[i] << "°C : ";
        
        // Classification
        if (temperatures[i] < 10)
            cout << "Cold";
        else if (temperatures[i] <= 20)
            cout << "Ok";
        else
            cout << "Warm";
        
        cout << endl;
        
        // Update warmest day
        if (temperatures[i] > get<1>(warmestDay)) {
            warmestDay = make_tuple(days[i], temperatures[i]);
        }
    }
    
    cout << "\nWarmest Day: " << get<0>(warmestDay) 
         << " with " << get<1>(warmestDay) << "°C" << endl;
    
    return 0;
}
