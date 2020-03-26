#implementing circular queue
class CircularQueue:
	def __init__(self,maxSize): #사용자 지정하는 argument
		self.queue=list()
		self.maxSize=maxSize
		self.head=0
		self.tail=0
	def size(self):
		if self.tail>=self.head:
			size=self.tail-self.head
		else:
			size=maxSize-(self.head-self.tail)
		return size
	def enqueue(self,element):
		if self.size()==(self.maxSize-1):
			return "queue is full"
		else:
			self.queue.append(element)
			self.tail=(self.tail+1)%(self.maxSize)
	def dequeue(self):
		if self.size()==0:
			return "queue is empty"
		else:
		    self.head=(self.head+1)%(self.maxSize)
	def printElements(self):
		if self.size()==0:
			print("No elements to print!")
		else:
			for ele in self.queue:
				print(ele)

q=CircularQueue(5)
q.enqueue(1)
q.printElements() #1
q.enqueue(2)
q.enqueue(3)
q.printElements() #1 2 3
q.dequeue()
q.printElements() #1 2
q.size() #3
		