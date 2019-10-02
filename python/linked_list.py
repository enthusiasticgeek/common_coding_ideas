#!/usr/bin/env python3

import time
import signal
import sys
import time
import random

def signal_handler(sig, frame):
        print('You pressed Ctrl+C!')
        sys.exit(0)

class LinkedList(object):

    def __init__(self, head=None):
        self.head = head

    def insert(self, data):
        new_node = Node(data)
        new_node.set_next(self.head)
        self.head = new_node

    def size(self):
        current = self.head
        count = 0
        while current:
            count += 1
            current = current.get_next()
        return count

    def search(self, data):
        current = self.head
        found = False
        count = 0
        while current and found is False:
            if current.get_data() == data:
                found = True
                print('found at position ' + str(count))
            else:
                current = current.get_next()
                count += 1
        if current is None:
            raise ValueError("Data not in list")
        return current

    def delete(self, data):
        current = self.head
        previous = None
        found = False
        while current and found is False:
            if current.get_data() == data:
                found = True
            else:
                previous = current
                current = current.get_next()
        if current is None:
            raise ValueError("Data not in list")
        if previous is None:
            self.head = current.get_next()
        else:
            previous.set_next(current.get_next())

class Node(object):

    def __init__(self, data=None, next_node=None):
        self.data = data
        self.next_node = next_node

    def get_data(self):
        return self.data

    def get_next(self):
        return self.next_node

    def set_next(self, new_next):
        self.next_node = new_next

ll = LinkedList();
ll.insert(11)
ll.insert(22)
ll.insert(33)

print(str(ll.size()))

print(str(ll.search(22).get_data()))
