// https://leetcode.com/problems/my-calendar-i

class MyCalendar {
public:
    vector<pair<int, int>> v;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        bool check = false; end--;
        for(int i = 0; i < v.size(); i++){
            if(v[i].first <= start and v[i].second >= end)check = true;
            if(v[i].first <= start and v[i].second >= start) check = true;
            if(v[i].first <= end and v[i].second >= end) true;
        }
        if(check) return false;
        else{
            v.push_back({start, end});
            return true;
        }
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */