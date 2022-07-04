#include <bits/stdc++.h>
using namespace std;

// Check all the valid options using this helper function
void helper(vector<int> input, int n, bool* temp, int selected, bool* res, int* mini, int sum, int curr_sum, int cur_Index)
{
   // Edge case
   if (cur_Index == n)
       return;

   // Check the size
   if ((n/2 - selected) > (n - cur_Index))
       return;

   // Case when current element is not considered in the result
   helper(input, n, temp, selected, res, mini, sum, curr_sum, cur_Index + 1);

   selected++;
   curr_sum = curr_sum + input[cur_Index];
   temp[cur_Index] = true;

   // checks if a solution is formed
   if (selected == n / 2)
   {
       // check for the best solution
       if (abs(sum / 2 - curr_sum) < *mini)
       {
           *mini = abs(sum/2 - curr_sum);
           for (int i = 0; i<n; i++)
               res[i] = temp[i];
       }
   }
   else
   {
       // Case when current element is considered in the result
       helper(input, n, temp, selected, res, mini, sum, curr_sum, cur_Index + 1);
   }

   temp[cur_Index] = false;
}

// main function that generate an arr
void getResult(vector<int> input, int n)
{
   bool* temp = new bool[n];

   bool* res = new bool[n];

   int mini = INT_MAX;

   int sum = 0;

   // Compute sum
   for (int i = 0; i < n; i++)
   {
       sum += input[i];
       temp[i] = res[i] = false;
   }

   // Recursive call to helper
   helper(input, n, temp, 0, res, &mini, sum, 0, 0);

   // Print both the subsequence
   cout << ": ";
   for (int i = 0; i<n; i++)
   {
       if (res[i] == true)
           cout << input[i] << ", ";
   }
   cout << endl;
   cout << ": ";
   for (int i = 0; i < n; i++)
   {
       if (res[i] == false)
           cout << input[i] << ", ";
   }
}

int main()
{
   // Input array
   vector<int> input = {1, 3, 100, 90, 200};
   int n = input.size();
   getResult(input, n);
   return 0;
}

