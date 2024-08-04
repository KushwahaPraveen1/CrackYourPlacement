#include <unordered_map>
#include <vector>
#include <random>

class RandomizedCollection {
private:
    std::vector<int> nums;
    std::unordered_map<int, std::vector<int>> indices;
    std::mt19937 rng;

public:
    RandomizedCollection() : rng(std::random_device{}()) {}

    bool insert(int val) {
        bool isNew = indices.count(val) == 0;
        indices[val].push_back(nums.size());
        nums.push_back(val);
        return isNew;
    }

    bool remove(int val) {
        auto it = indices.find(val);
        if (it == indices.end()) {
            return false;
        }
        int removeIndex = it->second.back();
        it->second.pop_back();
        if (it->second.empty()) {
            indices.erase(it);
        }
        if (removeIndex != nums.size() - 1) {
            int lastVal = nums.back();
            nums[removeIndex] = lastVal;
            auto& lastIndices = indices[lastVal];
            lastIndices[std::find(lastIndices.begin(), lastIndices.end(), nums.size() - 1) - lastIndices.begin()] = removeIndex;
        }
        nums.pop_back();
        return true;
    }

    int getRandom() {
        std::uniform_int_distribution<int> dist(0, nums.size() - 1);
        return nums[dist(rng)];
    }
};