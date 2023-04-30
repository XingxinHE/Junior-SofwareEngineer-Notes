import java.util.Iterator;
import java.util.NoSuchElementException;

public class Deque<Item> implements Iterable<Item> {

    /* double-link list */
    private class Node {
        private Item item;
        private Node next = null;
        private Node prev = null;

        Node(Item item, Node prev, Node next) {
            this.item = item;
            this.prev = prev;
            this.next = next;
        }
    }

    private Node first = null;
    private Node last = null;

    private int count = 0;

    // construct an empty deque
    public Deque() {
    }

    // is the deque empty?
    public boolean isEmpty() {
        return 0 == this.count;
    }

    // return the number of items on the deque
    public int size() {
        return this.count;
    }

    // add the item to the front
    public void addFirst(Item item) {
        if (null == item) throw new IllegalArgumentException("item is null.");

        Node oldfirst = first;
        first = new Node(item, /* prev */null, /* next */oldfirst);

        // special care
        if (isEmpty()) last = first;
        else oldfirst.prev = first;

        ++count;
    }

    // add the item to the back
    public void addLast(Item item) {
        if (null == item) throw new IllegalArgumentException("item is null.");

        Node oldlast = last;
        last = new Node(item, /* prev */oldlast, /* next */null);

        // special care
        if (isEmpty()) first = last;
        else oldlast.next = last;

        ++count;
    }

    // remove and return the item from the front
    public Item removeFirst() {
        if (isEmpty()) throw new NoSuchElementException("no item in dequeue");

        Item item = first.item;
        first = first.next;
        --count;

        // special care
        if (isEmpty()) last = first;
        else first.prev = null;

        return item;
    }

    // remove and return the item from the back
    public Item removeLast() {
        if (isEmpty()) throw new java.util.NoSuchElementException("no item in dequeue");

        Item item = last.item;
        last = last.prev;
        --count;

        // special care
        if (isEmpty()) first = last;
        else last.next = null;

        return item;
    }

    // return an iterator over items in order from front to back
    public Iterator<Item> iterator() {
        return new DequeIterator();
    }

    private class DequeIterator implements Iterator<Item> {
        private Node current = first;

        public boolean hasNext() {
            return current != null;
        }

        // throw UnsupportedOperationException
        public void remove() {
            throw new UnsupportedOperationException("Not support remove function.");
        }

        // throw NoSuchElementException
        public Item next() {
            if (!hasNext()) {
                throw new NoSuchElementException("No more next element");
            }
            Item item = current.item;
            current = current.next;
            return item;
        }
    }

    public static void main(String[] args) {
        Deque<Integer> deq = new Deque<Integer>();

        System.out.println("size before init: " + deq.size());

        deq.addFirst(1);
        deq.addFirst(2);
        deq.addFirst(3);
        deq.addFirst(4);
        deq.addFirst(5);

        System.out.println("Loop the size after addFirst: " + deq.size());
        for (int num : deq) {
            System.out.println(num);
        }

        /* 5 4 3 2 1 */
        assert 5 == deq.removeFirst();
        assert 1 == deq.removeLast();
        assert 4 == deq.removeFirst();
        assert 2 == deq.removeLast();
        assert 3 == deq.removeFirst();

        assert 0 == deq.size() : "wrong";
        System.out.println("size: " + deq.size());

        deq.addLast(1);
        deq.addLast(2);
        deq.addLast(3);
        deq.addLast(4);
        deq.addLast(5);

        System.out.println("Loop the size after addLast: " + deq.size());
        for (int num : deq) {
            System.out.println(num);
        }

        /* 1 2 3 4 5 */
        assert 1 == deq.removeFirst();
        assert 5 == deq.removeLast();
        assert 2 == deq.removeFirst();
        assert 4 == deq.removeLast();
        assert 3 == deq.removeFirst();
    }
}
