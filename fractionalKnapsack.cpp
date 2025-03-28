#include <iostream>
using namespace std;

struct Item {

    int benefit, weight;

    Item(int benefit, int weight) : benefit(benefit), weight(weight) {}

};

bool compareItem(Item a, Item b)
{
    double r1 = (double)a.benefit / a.weight;
    double r2 = (double)b.benefit / b.weight;
    return r1 > r2;

}

double fractionKnapsack(int capacity, vector<Item> &items) {

    // fancy way to sort
    sort(items.begin(), items.end(), compareItem);
    double totalValue = 0;
    for (int i = 0; i < items.size(); i++)
    {
        // Do I have room for the weight?
        if (capacity >= items[i].weight)
        {
            capacity -= items[i].weight;
            totalValue += items[i].benefit;
            // I can't fit the whole item in my bag, so I take as much as I can.
        } else {
            double fraction = (double) capacity / items[i].weight;
            totalValue+= items[i].benefit*fraction; // This is the fraction of the item I will take.
            break; // choose to break because we filled our knapsack.
        }
    }
    return totalValue;

}

int main() {
    vector<Item> vec = {Item(12, 4), Item(32, 8), Item(40, 2), Item(30, 6), Item(50, 1)};
    int masonJarCapacity = 10;

    cout << "Maximum value of stuff in my mason jar is: " << fractionKnapsack(masonJarCapacity, vec);
}
