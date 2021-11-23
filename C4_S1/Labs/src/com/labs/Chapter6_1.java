package com.labs;

import java.util.ArrayList;

public class Chapter6_1 {
    class Stack<E>{
        private ArrayList<E> data;

        public Stack(int size) {
            if (size < 0 )
                throw new IllegalArgumentException("Stack size must be >= 0.");
            this.data = new ArrayList<>(size);
        }

        public void push(E item) {
            this.data.add(item);
        }

        public E pop() {
            if (this.data.isEmpty()) {
                throw new IllegalStateException("stack is empty");
            }
            return this.data.remove(this.data.size() - 1);
        }

        public boolean isEmpty() {
            return this.data.isEmpty();
        }
    }
}
