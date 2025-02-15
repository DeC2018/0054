#include <iostream>
#include <vector>

class Solution {
 public:
  std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) {
    if (matrix.empty())
      return {};

    const int m = matrix.size();
    const int n = matrix[0].size();
    std::vector<int> ans;
    int r1 = 0;
    int c1 = 0;
    int r2 = m - 1;
    int c2 = n - 1;

    // Repeatedly add matrix[r1..r2][c1..c2] to ans
    while (ans.size() < m * n) {
      for (int j = c1; j <= c2 && ans.size() < m * n; ++j)
        ans.push_back(matrix[r1][j]);
      for (int i = r1 + 1; i <= r2 - 1 && ans.size() < m * n; ++i)
        ans.push_back(matrix[i][c2]);
      for (int j = c2; j >= c1 && ans.size() < m * n; --j)
        ans.push_back(matrix[r2][j]);
      for (int i = r2 - 1; i >= r1 + 1 && ans.size() < m * n; --i)
        ans.push_back(matrix[i][c1]);
      ++r1, ++c1, --r2, --c2;
    }

    return ans;
  }
};

// Function to print the output
void printOutput(const std::vector<int>& output) {
  std::cout << "[";
  for (size_t i = 0; i < output.size(); ++i) {
    std::cout << output[i];
    if (i != output.size() - 1) {
      std::cout << ",";
    }
  }
  std::cout << "]" << std::endl;
}

int main() {
  Solution solution;

  // Example 1
  std::vector<std::vector<int>> matrix1 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  std::vector<int> output1 = solution.spiralOrder(matrix1);
  std::cout << "Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]" << std::endl;
  std::cout << "Output: ";
  printOutput(output1);

  // Example 2
  std::vector<std::vector<int>> matrix2 = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
  std::vector<int> output2 = solution.spiralOrder(matrix2);
  std::cout << "Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]" << std::endl;
  std::cout << "Output: ";
  printOutput(output2);

  return 0;
}
