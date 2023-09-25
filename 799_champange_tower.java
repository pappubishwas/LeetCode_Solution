public class Solution {
    public double champagneTower(int poured, int query_row, int query_glass) {
        if (poured == 0) return 0.0;
        List<Double> ans = new ArrayList<>();
        ans.add((double) poured);
        while (query_row-- > 0) {
            List<Double> temp = new ArrayList<>();
            temp.add(Math.max((ans.get(0) - 1) / 2, 0.0));
            for (int i = 1; i < ans.size(); i++) {
                temp.add(Math.max((ans.get(i - 1) - 1) / 2, 0.0) + Math.max((ans.get(i) - 1) / 2, 0.0));
            }
            temp.add(temp.get(0));
            ans = new ArrayList<>(temp);
        }
        
        return Math.min(1.0, ans.get(query_glass));
    }
    public static void main(String[] args) {
        Solution solution = new Solution();
        int poured = 25;
        int query_row = 6;
        int query_glass = 1;
        double result = solution.champagneTower(poured, query_row, query_glass);
        System.out.println("The amount of champagne in the glass (" + query_row + ", " + query_glass + ") is: " + result);
    }
}
