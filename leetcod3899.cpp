/*
Problem: Angles of a Triangle

Approach:
1. Extract sides a, b, c from input.
2. Check triangle validity using triangle inequality:
   - a + b > c, b + c > a, c + a > b
   - If not valid → return empty vector.
3. Use Law of Cosines to compute angles:
   - A = acos((b² + c² - a²) / (2bc))
   - B = acos((a² + c² - b²) / (2ac))
   - C = acos((a² + b² - c²) / (2ab))
4. Convert angles from radians to degrees.
5. Store angles in vector and sort in ascending order.
6. Return the result.

Time Complexity: O(1)
Space Complexity: O(1)
*/

class Solution {
public:
    vector<double> internalAngles(vector<int>& sides) {
        double a = sides[0], b = sides[1], c = sides[2];
        // Check triangle validity
        if (a + b <= c || b + c <= a || c + a <= b) {
            return {};
        }
        double A = acos((b*b + c*c - a*a) / (2*b*c));
        double B = acos((a*a + c*c - b*b) / (2*a*c));
        double C = acos((a*a + b*b - c*c) / (2*a*b));

        double pi = acos(-1);
        A = A * 180.0 / pi;
        B = B * 180.0 / pi;
        C = C * 180.0 / pi;

        vector<double> res = {A, B, C};
        sort(res.begin(), res.end());

        return res;
    }
};
