class ProductOfNumbers {
public:
    vector<int> v;
    ProductOfNumbers() {
    }
    
    void add(int num) {
        v.push_back(num);
    }
    
    int getProduct(int k) {
        int n = v.size();
        long long ans = 1;

        for(int i=n-k; i<n; i++){
            ans = ans * v[i];
        }
        return ans;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */