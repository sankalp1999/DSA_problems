bool compare(Item& a, Item& b)
    {
        double val_a = a.value * 1.0 / a.weight * 1.0;
        double val_b = b.value * 1.0 / b.weight * 1.0;
        return val_a > val_b;
    }
class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        sort(arr,arr+n,compare);
        double res = 0;
        for(int i = 0; i < n ; i++)
        {
            auto it = arr[i];
        }
        double W2 = (double)W;
        for(int i = 0; i < n; i++)
        {
            double weight = arr[i].weight;
            double val = arr[i].value;
            if(arr[i].weight <= W2)
            {
                res += arr[i].value;
                W2 -= weight;
            }
            else 
            {
                double temp =  ((val*1.0)/ (weight*1.0)) * W2;
                res += temp;
                W2 = 0;
            }
            if(W2 == 0)break;
        }
        return res;
    }
        
};
