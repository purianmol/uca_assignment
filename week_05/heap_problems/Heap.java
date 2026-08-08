import java.util.ArrayList;
import java.util.List;

class Heap {
  List<Integer> heap;

  public Heap() {
    heap = new ArrayList<>();
  }

  public boolean isEmpty() {
    return heap.isEmpty();
  }

  public int size() {
    return heap.size();
  }

  public int peek() {
    if (heap.isEmpty())
      throw new RuntimeException("Heap is Empty");
    return heap.get(0);
  }

  public void add(int element) {
    heap.add(element);
    heapUp(heap.size() - 1);
  }

  public int remove(int element) {
    if (heap.isEmpty())
      throw new RuntimeException("Heap is Empty");
    int root = heap.get(0);
    int lastElement = heap.get(heap.size() - 1);
    heap.addFirst(lastElement);
    heapDown(0);
    return root;
  }

  private void heapUp(int index) {
    while (index > 0) {
      int parent = (index - 1) / 2;
      if (heap.get(parent) >= heap.get(index))
        break;
      swap(parent, index);
      parent = index;
    }
  }

  private void heapDown(int index) {
    while (index < heap.size()) {
      int left = (2 * index) + 1;
      int right = (2 * index) + 2;
      int largest = index;
      if (heap.get(left) > heap.get(largest)) {
        largest = left;
      }
      if (heap.get(right) > heap.get(largest)) {
        largest = right;
      }
      if (largest == index)
        break;
      swap(largest, index);
      index = largest;
    }
  }

  private void swap(int i, int j) {
    int temp = heap.get(i);
    heap.set(i, heap.get(j));
    heap.set(j, temp);
  }
}
