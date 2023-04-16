// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T, int size>
class TPQueue {
 private:
    T arr[size];
    char head, tail, length;
 public:
    TPQueue() : head(0), tail(0), length(0){}
    bool isEmpty() const {
        return 0 == length;
    }
    bool isFull() const {
        return size == length;
    }
    void push(const T& value) {
        if (isFull()) {
            throw std::string("Queue is full!");
        } else {
            int promej = head;
            arr[head % size] = value;
            T promejArrVal = arr[promej % size];
            while (arr[(promej - 1) % size].prior < arr[promej % size].prior \
                && tail < promej) {
                promejArrVal = arr[promej % size];
                arr[promej % size] = arr[(promej - 1) % size];
                arr[(promej - 1) % size] = promejArrVal;
                promej--;
            }
            length++;
            head++;
        }
    }
    const T& pop() {
        if (isEmpty()) {
            throw std::string("Queue is empty");
        } else {
            length--;
            return arr[tail++ % size];
        }
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
