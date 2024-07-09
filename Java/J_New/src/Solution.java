import java.util.ArrayList;

class Solution {

    public int[][] modifiedMatrix(int[][] matrix) {
        // 获取矩阵的行数和列数
        int rows = matrix.length;
        int cols = matrix[0].length;

        // 创建一个新的矩阵，用于存储修改后的值
        int[][] resultMatrix = new int[rows][cols];

        // 这里仅是一个示例，将矩阵中的每个元素乘以2
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                resultMatrix[i][j] = matrix[i][j] * 2;
            }
        }

        // 返回修改后的矩阵
        return resultMatrix;
    }

    public static void main(String[] args) {
        int[][] inputMatrix = { {1, 2}, {3, 4} };
    
        Solution solution = new Solution();
        int[][] modified = solution.modifiedMatrix(inputMatrix);
    
        // 打印修改后的矩阵
        for (int[] row : modified) {
            for (int val : row) {
                System.out.print(val + " ");
            }
            System.out.println();
        }
    }
}