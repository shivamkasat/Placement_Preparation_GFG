class RandomizedSet {
public:
    /** Initialize your data structure here. */
    unordered_map < int, int > hmap;
    int lastIndex;
    vector < int > nums;

    RandomizedSet() {
      lastIndex = -1;

    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
     if (hmap.find(val) == hmap.end()) {
        lastIndex++;
        hmap[val] = lastIndex;
        nums.push_back(val);
     }
     return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
      if (hmap.find(val) == hmap.end()) {
        return false;
      }
      //index of the element;
      nums[hmap[val]] = nums[lastIndex];
      hmap[nums[lastIndex]] = hmap[val];
      hmap.erase(val);
      nums.pop_back();
      lastIndex--;
      return true;
    }

    /** Get a random element from the set. */
    int getRandom() {
      //random val = min + rand() % (max - min + 1);
      int randIndex = rand() % (lastIndex + 1);
      return nums[randIndex];

    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
