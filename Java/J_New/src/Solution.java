import java.util.ArrayList;

class Solution {

    public int[][] modifiedMatrix(int[][] matrix) {
        // ��ȡ���������������
        int rows = matrix.length;
        int cols = matrix[0].length;

        // ����һ���µľ������ڴ洢�޸ĺ��ֵ
        int[][] resultMatrix = new int[rows][cols];

        // �������һ��ʾ�����������е�ÿ��Ԫ�س���2
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                resultMatrix[i][j] = matrix[i][j] * 2;
            }
        }

        // �����޸ĺ�ľ���
        return resultMatrix;
    }

    public static void main(String[] args) {
        int[][] inputMatrix = { {1, 2}, {3, 4} };
    
        Solution solution = new Solution();
        int[][] modified = solution.modifiedMatrix(inputMatrix);
    
        // ��ӡ�޸ĺ�ľ���
        for (int[] row : modified) {
            for (int val : row) {
                System.out.print(val + " ");
            }
            System.out.println();
        }
    }
}