package com.labs;

import java.util.ArrayList;
import java.util.Arrays;

public class Chapter6_2 {
    class StackEA<E> {
        private E[] data;
        private int pos;

        private final int blockSize = 32;

        public StackEA(int size) {
            if (size < 0 )
                throw new IllegalArgumentException("Stack size must be >= 0.");
            this.data = (E[])new Object[size];
        }

        public void push(E item) {
            if (pos == data.length) {
                this.data = Arrays.copyOf(this.data, this.data.length + blockSize);
            }
            this.data[pos++] = item;
        }

        public E pop() {
            if (this.pos == 0) {
                throw new IllegalStateException("Stack is empty.");
            }
            return this.data[--pos];
        }

        public boolean isEmpty() {
            return this.pos == 0;
        }
    }

    class StackOA<E> {
        private Object[] data;
        private int pos;

        private final int blockSize = 32;

        public StackOA(int size) {
            if (size < 0 )
                throw new IllegalArgumentException("Stack size must be >= 0.");
            this.data = new Object[size];
        }

        public void push(E item) {
            if (pos == data.length) {
                this.data = Arrays.copyOf(this.data, this.data.length + blockSize);
            }
            this.data[pos++] = item;
        }

        public E pop() {
            if (this.pos == 0) {
                throw new IllegalStateException("Stack is empty.");
            }
            return (E) this.data[--pos];
        }

        public boolean isEmpty() {
            return this.pos == 0;
        }
    }
}
