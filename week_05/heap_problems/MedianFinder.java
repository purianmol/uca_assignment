import java.util.PriorityQueue;
import java.util.Collections;

class MedianFinder {
  PriorityQueue<Integer> small;
  PriorityQueue<Integer> large;

  public MedianFinder() {
    small = new PriorityQueue<>(Collections.reverseOrder());
    large = new PriorityQueue<>();
  }

  public void addNum(int num) {
    if (small.isEmpty())
      small.offer(num);
    else if (num > small.peek())
      large.offer(num);
    else
      small.offer(num);
    divide();
  }

  public double findMedian() {
    if (small.size() == large.size())
      return (double) (small.peek() + large.peek()) / 2;
    return (double) small.peek();
  }

  void divide() {
    if (small.size() > large.size() + 1)
      large.offer(small.poll());
    if (large.size() > small.size())
      small.offer(large.poll());
  }
}
