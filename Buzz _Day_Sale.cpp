/*
Buzz Day Sale
Problem Description
Karan, who owns a shop at an exhibition, is planning to launch a promotion where customers receive free items with the purchase of specific items. He has chosen a few items for this special offer, which he's called the "Buzz Day Sale." Additionally, there are unlimited quantities available for each item type.
He assigned a unique ID to each item basis it's worth and put up a board that reads, "For every purchase of an item with ID K, all other items with IDs that are factors of K, will be free."
Veda visited Karan's shop on Buzz Day with the aim of acquiring as many items as possible while carrying a limited amount of money, A. If there are several ways to maximize the number of free items, she will strive to maximize the total worth of the items she receives freely.
Given the IDs of all the items offered in the sale and their costs, determine the maximum number of items Veda can receive for free and the maximum total worth of those items.

Constraints
1 <= N <= 500
1 <= ID of each item <= 1000
1 <= cost of each item <= 1000
1 <= Amount Veda holds <= 1000

Input
First lines consist of an integer N, denoting the number of items in the sale.
Second line consists of N space separated integers denoting the ID of items.
Third line consists of N space separated integers denoting the cost of each item.
Last line consists of a single integer A, denoting the amount Veda has.

Output
Print two space-separated integers indicating the maximum number of free items Veda can obtain and the maximum total worth of those items given the amount she has.
Maximize the number of free items first then maximize the total worth of free items.
Time Limit (secs)
1
Examples
Example 1

Input
7
4 9 11 13 15 5 25
1 4 2 6 3 7 8
10
Output
3 21

Explanation
There are 7 items with IDs {4, 9, 11, 13, 15, 5, 25} on sale. Their costs are {1, 4, 2, 6, 3, 7, 8}. Veda has 10 Rupees to spend on purchasing items in Buzz Day Sale.
If Veda buys the item with ID 15 in quantity of three, the total cost will be 3×3=9 (cost of ID 15 x quantity), which is less than 10. She will receive the item with ID 5 for free which is of worth 7. Thus, she will get the item with ID 5 with quantity three for free, resulting in a total worth of 7×3=21.
Since the quantity of free items is 3 and cost of free items is 21, print them as output.

Example 2
Input
5
11 24 3 12 7
7 11 15 9 4
17
Output
2 24
Explanation

There are 5 items with IDs {11, 24, 3, 12, 7} on sale. Their costs are {7 11 15 9 4}. Veda has 17 Rupees to spend on purchasing items in Buzz Day Sale.
If Veda buys item with ID 24, she will receive the items with ID 3 and ID 12 for free. No other purchase of combination will yield more free items. Therefore, she will get 2 free items, with a total worth of 24.
Since the quantity of free items is 2 and cost of free items is 24, print them as output.
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> ids(n), costs(n);
    for (int i = 0; i < n; i++) cin >> ids[i];
    for (int i = 0; i < n; i++) cin >> costs[i];

    int budget;
    cin >> budget;
    int mfi = 0, mfw = 0;

    for (int i = 0; i < n; i++) {
        int buyCost = costs[i];
        int maxQty = budget / buyCost;
        if (maxQty > 0) {
            int cfi = 0;
            int cfw = 0;

            for (int j = 0; j < n; j++) {
                if (i != j && ids[i] % ids[j] == 0) {
                    cfi += maxQty;
                    cfw += costs[j] * maxQty;
                }
            }
            if (cfi > mfi || 
               (cfi == mfi && cfw > mfw)) {
                mfi = cfi;
                mfw = cfw;
            }
        }
    }
    cout << mfi << " " << mfw ;
    return 0;
}
