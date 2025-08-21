class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> stack;

        for (int asteroid : asteroids) {
            bool destroyed = false;

            while (!stack.empty() && asteroid < 0 && stack.back() > 0) {
                if (stack.back() < -asteroid) {
                    stack.pop_back(); // Right-moving asteroid is smaller, destroy it
                } else if (stack.back() == -asteroid) {
                    stack.pop_back(); // Both are equal, destroy both
                    destroyed = true;
                    break;
                } else {
                    // Right-moving asteroid is larger, destroy incoming left-moving one
                    destroyed = true;
                    break;
                }
            }

            if (!destroyed) {
                stack.push_back(asteroid);
            }
        }

        return stack;
    }
};