#!/usr/bin/env python3

from threading import Thread, Lock
from threading import Condition

from queue import Queue


import _thread
import time
import signal
import sys
import time
import random

def signal_handler(sig, frame):
        print('You pressed Ctrl+C!')
        sys.exit(0)


queue = []
lock = Lock()
condition = Condition()

class ProducerThread(Thread):
    def run(self):
        nums = range(5) #Will create the list [0, 1, 2, 3, 4]
        global queue
        while True:
            num = random.choice(nums) #Selects a random number from list [0, 1, 2, 3, 4]
            lock.acquire()
            queue.append(num)
            print("Produced"+ str(num))
            lock.release()
            time.sleep(random.random())


class ConsumerThread(Thread):
    def run(self):
        global queue
        while True:
            lock.acquire()
            if not queue:
                print("Nothing in queue, but consumer will try to consume")
            num = queue.pop(0)
            print ("Consumed"+str(num))
            lock.release()
            time.sleep(random.random())


class ConsumerThreadI(Thread):

    def __init__(self):
        Thread.__init__(self)
    die = False
    def run(self):
        global queue
        while not self.die:
            condition.acquire()
            if not queue:
                print("Nothing in queue, consumer is waiting")
                condition.wait()
                print("Producer added something to queue and notified the consumer")
            num = queue.pop(0)
            print("Consumed" + str(num))
            condition.release()
            time.sleep(random.random())
    def join(self):
        self.die = True
        super().join()


class ProducerThreadI(Thread):
    def __init__(self):
        Thread.__init__(self)
    def run(self):
        nums = range(5)
        global queue
        while not self.die:
            condition.acquire()
            num = random.choice(nums)
            queue.append(num)
            print("Produced"+str(num))
            condition.notify()
            condition.release()
            time.sleep(random.random())
    def join(self):
        self.die = True
        super().join()

queue1 = Queue(10)

class ProducerThreadII(Thread):
    def __init__(self):
        Thread.__init__(self)
    die = False
    def run(self):
        nums = range(5)
        global queue1
        while not self.die:
            num = random.choice(nums)
            queue1.put(num)
            print ("Produced"+str(num))
            time.sleep(random.random())
    def join(self):
        self.die = True
        super().join()



class ConsumerThreadII(Thread):
    def __init__(self):
        Thread.__init__(self)
    die = False
    def run(self):
        global queue1
        while not self.die:
            num = queue1.get()
            queue1.task_done()
            print("Consumed"+str(num))
            time.sleep(random.random())
    def join(self):
        self.die = True
        super().join()



if __name__ == '__main__':

    signal.signal(signal.SIGINT, signal_handler)
    p = ProducerThreadII()
    c = ConsumerThreadII()
    p.start()
    c.start()

    try:
        while True:
            time.sleep(2)
    except KeyboardInterrupt:
        p.join()
        c.join()

