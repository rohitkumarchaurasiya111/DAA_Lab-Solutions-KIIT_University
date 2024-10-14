// Write a program to find the maximum profit nearest to but not exceeding the given knapsack capacity using the Fractional Knapsack algorithm.
//  Notes# Declare a structure ITEM having data members item_id, item_profit, item_weight and profit_weight_ratio. Apply heap sort technique to sort the items in non-increasing order, according to their profit /weight.
//  Input:
//  Enter the number of items: 3
//  Enter the profit and weight of item no 1: 27  16
//  Enter the profit and weight of item no 2: 14  12
//  Enter the profit and weight of item no 3: 26  13
//  Enter the capacity of knapsack:18

// Output:
// Item No   	profit	  	Weight    		Amount to be taken
// 3           	 26.000000 	13.000000		1.000000
// 1    	 27.000000   	16.000000   		0.312500
// 2            	14.000000   	12.000000   		0.000000
// Maximum profit: 34.437500

#include <stdio.h>

int main()
{
    int n;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    float arr[n][4];
    for (int i = 0; i < n; i++)
    {
        printf("Enter the profit and weight of item no %d: ", (i));
        arr[i][0] = (float)i;                     
        scanf("%f", &arr[i][1]);                  
        scanf("%f", &arr[i][2]);                  
        arr[i][4] = (float)arr[i][1] / arr[i][2]; 
    }
    int capacity;
    printf("Enter the capacity of Knapsack: ");
    scanf("%d", &capacity);


    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][4] > arr[i + 1][4])
            {
                for (int k = 0; k < 4; k++)
                {
                    float temp = arr[i][k];
                    arr[i][k] = arr[i + 1][k];
                    arr[i + 1][k] = temp;
                }
            }
        }
    }

    float total_profit = 0;
    int i = 0;
    printf("ItemNo\tProfit\tWeight\tAmount to be taken\n");
    for (; i < n; i++)
    {
        if (arr[i][2] <= capacity)
        {
            total_profit += arr[i][1];
            capacity = capacity - arr[i][2];
            printf("%.2f \t %.2f \t %.2f \t %.2f\n", arr[i][0], arr[i][1], arr[i][2], arr[i][2]);
        }
        else
        {
            break;
        }
    }
    if (capacity > 0)
    {
        total_profit += (float)arr[i][1] * capacity / arr[i][2];
        printf("%.2f \t %.2f \t %.2f \t %.2f\n", arr[i][0], arr[i][1], arr[i][2], capacity);
        capacity = 0;
    }
    printf("Maximum Profit: %f", total_profit);
}