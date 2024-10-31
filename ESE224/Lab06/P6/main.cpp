#include <vector>
#include <iostream>
using namespace std;

int maxWaterContainer(const vector<int>& height) {
    int left = 0;
    int right = height.size() - 1;
    int maxArea = 0;

    while (left < right) {
        // Calculate the area for the current container
        int width = right - left;
        int currentHeight = min(height[left], height[right]);
        int currentArea = width * currentHeight;

        // Update the maximum area found so far
        maxArea = max(maxArea, currentArea);

        // Move the pointer that has the shorter line
        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }

    return maxArea;
}

int main() {
    int n;
    cout << "Enter the number of lines: ";
    cin >> n;

    vector<int> height(n);
    cout << "Enter the heights of the lines: ";
    for (int i = 0; i < n; ++i) {
        cin >> height[i];
    }

    int result = maxWaterContainer(height);
    cout << "Output: " << result << endl;

    return 0;
}
