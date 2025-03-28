#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Activity {
    int start, end;

    Activity(int start, int end) : start(start), end(end) {}
};

// Comparator function to sort activties (Similar to our greedy knapsack)

bool activityCompare(Activity s1, Activity s2)
{
    return s1.end < s2.end;
}

// Function to find maximum number of activities that can be done.
void doActivities(vector<Activity> activities)
{
    vector<Activity> sortedActivities = activities;

    // Sort based on the ending time

    sort(sortedActivities.begin(), sortedActivities.end(), activityCompare);
    // We can always perform the first activity (Since sorted)
    int i = 0;
    cout << "(" << sortedActivities[i].start << "," << sortedActivities[i].end << ")";

    // Consider all activities other than the first activity
    for (int j = 1; j < sortedActivities.size(); j++)
    {
        if (sortedActivities[j].start >= sortedActivities[i].end)
        {
            cout << ",(" << sortedActivities[j].start << "," << sortedActivities[j].end << ")";
            i = j; // I'm doing the next activity, so I adhere to the next activity's time.
        }
    }
}

int main()
{
    vector<Activity> activities;

    activities.emplace_back(1, 2);
    activities.emplace_back(3, 4);
    activities.emplace_back(0, 6);
    activities.emplace_back(8, 9);
    activities.emplace_back(5, 7);
    activities.emplace_back(5, 9);
    doActivities(activities);

}
