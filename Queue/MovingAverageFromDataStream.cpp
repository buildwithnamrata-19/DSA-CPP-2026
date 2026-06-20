class MovingAverage {
private:
    queue<int> q;
    int size;
    double sum;

public:

    MovingAverage(int size) {
        this->size = size;
        sum = 0;
    }

    double next(int val) {

        q.push(val);
        sum += val;

        if(q.size() > size) {

            sum -= q.front();
            q.pop();
        }

        return sum / q.size();
    }
};
