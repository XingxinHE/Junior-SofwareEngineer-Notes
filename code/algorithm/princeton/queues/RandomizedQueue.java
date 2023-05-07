import edu.princeton.cs.algs4.StdRandom;

import java.util.Iterator;
import java.util.NoSuchElementException;


public class RandomizedQueue<Item> implements Iterable<Item> {
    private static final int INITIAL_CAPACITY = 10;

    private Item[] array = null;
    private int count = 0;

    // construct an empty randomized queue
    public RandomizedQueue() {
        array = (Item[]) new Object[RandomizedQueue.INITIAL_CAPACITY];
    }

    // is the randomized queue empty?
    public boolean isEmpty() {
        return 0 == size();
    }

    // return the number of items on the randomized queue
    public int size() {
        return count;
    }

    private int capacity() {
        return array.length;
    }

    private void resize(int size) {
        if (size < 1) return;

        Item[] oldArray = array;
        array = (Item[]) new Object[size];

        for (int ii = 0; ii < size(); ++ii) {
            array[ii] = oldArray[ii];
            oldArray[ii] = null;
        }
    }

    // add the item
    public void enqueue(Item item) {
        if (null == item) throw new IllegalArgumentException("item is null.");

        if (capacity() == size()) {
            resize(capacity() * 2);
        }
        array[count++] = item;
    }

    // remove and return a random item
    public Item dequeue() {
        if (isEmpty()) throw new NoSuchElementException("No item in queue.");
        int index = StdRandom.uniformInt(0, size());

        Item result = array[index];

        // swap the random item and the last item
        array[index] = array[size() - 1];
        array[size() - 1] = null;
        --count;

        if (size() <= (capacity() / 4)) {
            resize(capacity() / 2);
        }

        return result;
    }

    // return a random item (but do not remove it)
    public Item sample() {
        if (isEmpty()) throw new NoSuchElementException("the queue is empty");
        int index = StdRandom.uniformInt(0, size());
        return array[index];
    }

    private class RandomizedQueueIterator implements Iterator<Item> {
        private int currentIndex = 0;
        private int[] randomOrder = null;

        public RandomizedQueueIterator() {
            if (isEmpty()) return;

            randomOrder = new int[size()];
            for (int ii = 0; ii < size(); ++ii) {
                randomOrder[ii] = ii;
            }

            /*
             * if using the library `import java.util.stream.IntStream;`
             * the code above can be simplified as
             * randomOrder = IntStream.range(0, size()).toArray();
             */

            StdRandom.shuffle(randomOrder, 0, size());
        }

        public boolean hasNext() {
            return currentIndex < size();
        }

        public void remove() {
            throw new UnsupportedOperationException();
        }

        public Item next() {
            if (currentIndex >= size())
                throw new NoSuchElementException("out of bound.");
            Item item = (Item) array[randomOrder[currentIndex++]];
            return item;
        }
    }

    // return an independent iterator over items in random order
    public Iterator<Item> iterator() {
        return new RandomizedQueueIterator();
    }

    // unit testing (required)
    public static void main(String[] args) {
        RandomizedQueue<Integer> randomizedQueue = new RandomizedQueue<Integer>();
        for (int ii = 0; ii < 13; ++ii) {
            randomizedQueue.enqueue(ii);
        }
        for (int item : randomizedQueue) {
            System.out.println(item);
        }
    }
}
