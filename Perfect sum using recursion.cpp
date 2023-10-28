#include <iostream>
#include <vector>

void perfectSum(std::vector<int>& arr, int index, int target, std::vector<int>& subset) {
    if (target == 0) {
        // Base case: Target sum achieved, so print the subset
        for (int i = 0; i < subset.size(); ++i) {
            std::cout << subset[i] << " ";
        }
        std::cout << std::endl;
        return;
    }

    if (index >= arr.size()) {
        // Base case: Reached the end of array
        return;
    }

    // Include the current element
    subset.push_back(arr[index]);
    perfectSum(arr, index + 1, target - arr[index], subset);

    // Exclude the current element
    subset.pop_back();
    perfectSum(arr, index + 1, target, subset);
}

int main() {
    std::vector<int> arr = {2, 4, 6, 8, 10};
    int targetSum = 10;
    std::vector<int> subset;

    std::cout << "Subsets with perfect sum " << targetSum << " are:\n";
    perfectSum(arr, 0, targetSum, subset);

    return 0;
}
