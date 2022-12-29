#include <iostream>
#include <vector>
using namespace std;
 
// Pre Computing the factorial
void factorial(long dummy[], long size)
{
    dummy[0] = 1;
    for (long long int i = 1; i < size; i++) {
        dummy[i] = dummy[i - 1] * i;
    }
}
 
 
// Function to tell total possible ways to fix root that is ncr ways
long combinations(long dummy[], long size, long temp)
{
    if (temp > size)
        return 0;
 
    // nCr= factorial(n)/(factorial(r)*factorial(n-r))
    long ans = dummy[size] / dummy[temp];
    ans /= dummy[size - temp];
 
    return ans;
}
 
// Count permutations that generates same BST
long countPerm(vector<long>& perm, long dummy[])
{

    // Store the size of the array
    long N = perm.size();
 
    // Base case
    if (N <= 2) {
        return 1;
    }
 
    vector<long> leftSubTree,rightSubTree;
 
    // Store the root node
    long root = perm[0];
 
    for (long i = 1; i < N; i++) {

        // Pushing elements in left and right subtree accordingly
        perm[i] < root?leftSubTree.push_back(perm[i]):rightSubTree.push_back(perm[i]);
    }
 
    // Store the size of leftSubTree and right subtree
    long N1 = leftSubTree.size();
    long N2 = rightSubTree.size();
 
    // Recurring on left and right subtree to calculate answers from left and right subtrees
    return combinations(dummy, N - 1, N1)*countPerm(leftSubTree,dummy)*countPerm(rightSubTree,dummy);

}
 
int main()
{
 long arraysize;
 while(arraysize != 0){
    cin >> arraysize;
        vector<long> arr;
         long arrval;
        for(long i =0; i < arraysize; i++){
            cin >> arrval;
            arr.push_back(arrval);
        }

        long dummy[arraysize];

    // Filling dummy array with factorial upto size
    factorial(dummy, arraysize);
   
    // Count permutations
    cout << countPerm(arr, dummy) <<endl;;
 }


    
 
    return 0;
}