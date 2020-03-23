#연결리스트는 기본 중의 기본. 기본적인 규칙 및 원리 잊지 말자. 
#두 개의 클래스 설정. 개별적인 노드들에 대한 클래스인 Class Node, 전체 연결리스트에 대한 Class linkedList

class sNode:
    def __init__(self,item):
        self.item=item #data field
        self.next=None #link field  (처음에 등장하는 노드는 다음 연결자가 없는 하나짜리)
    def set_item(self,new_item):
        self.item=new_item
    def set_next(self,new_next):
        self.next=new_next
    def get_item(self):
        return self.item
    def get_next(self):
        return self.next

class LinkedList:
    def __init__(self):
        self.head=None  #전체 리스트에 대해서 초기화해주기
    def is_empty(self):
        return self.head==None
    def add(self,item):  #리스트의 첫번째 자리로 item 배치
        #잊지말고 노드화
        temp=sNode(item)  #내용물 item을 담은 노드, temp
        temp.set_next(self.head)
        self.head=temp
    def size(self): #리스트 traversal
        current=self.head #직관적인 이름짓기. 현재의 위치를 current라 명명
        count=0
        while current!=None:
            count+=1
            current=current.get_next()
        return count
    def search(self,item):  #또 traversal? 찾고자 하는 item이 있는지 없는지 여부 체크
        current=self.head
        found=False #직관적인 이름짓기
        while current!=None and found!=True:
            if (current.get_item()==item):
                found=True
            else:
                current=current.get_next()
        return found
    def delete(self,item):  #역시 traversal 해야겠지?
        current=self.head
        found=False
        previous=None  #delete 대상의 이전 노드가 delete 대상 다음 노드와 연결되어야 하므로
        while not found:
            if (current.get_item()==item):
                found=True
            else:
                previous=current
                current=current.get_next()
        if previous==None: #맨 첫번째 노드의 삭제, 삭제하고자 하는 item이 첫번째 노드였음
            self.head=current.get_next()
        else:
            previous.set_next(current.get_next())
    def append(self,item): #연결리스트의 가장 끝부분에 추가, traversal 고려
        #노드화 잊지말기
        temp=sNode(item)
        current=self.head
        while current.get_next()!=None:
            current=current.get_next()
        #이 지점에 왔으면 마지막 노드겠지?
        current.set_next(temp)
    def printElement(self):
        current=self.head
        while current:
            if current.get_next()!=None:
                print(current.get_item(),'->',end=' ')
            else:
                print(current.get_item())
            current=current.get_next()

""" #main 함수-singly linked list 직접 확인해보기
s=LinkedList()
print(s.is_empty())
print(s.size())
s.add(1)
s.printElement() #1
s.add(2)
s.append(3)
s.printElement() #2->1->3
s.delete(3)
s.printElement() #2->1
print(s.search(4))  #False
 """

class dNode: #이중연결리스트 Nodes, 두 개의 link field 있다는 것만 기억!
    def __init__(self,item):
        self.item=item
        self.previous=None  #previous link field
        self.next=None #next link field
    def get_item(self): return self.item
    def get_previous(self): return self.previous
    def get_next(self): return self.next
    def set_item(self,new_item):
        self.item=new_item
    def set_previous(self,new_previous):
        self.previous=new_previous
    def set_next(self,new_next):
        self.next=new_next
    
class DoubleList:
    def __init__(self):
        self.head=None
    def is_empty(self):
        return self.head==None
    def add(self,item): #처음 위치에 item 삽입
        temp=dNode(item)
        if self.head==None:
            self.head=temp
        else:
            temp.set_next(self.head)
            self.head.set_previous(temp) #set_previous 놓치지마!
            self.head=temp
    def append(self,item): #마지막 위치에 item 삽입
        temp=dNode(item)
        if self.head==None:
            self.head=temp
        else:
            current=self.head
            while current.get_next()!=None:
                current=current.get_next()
            current.set_next(temp)
            temp.set_previous(current)
    def insert_after(self,item,x): #특정 항목 x를 저장하고 있는 노드 다음 위치에
                              #item 삽입
        temp=dNode(item)
        #비어 있는 리스트는 아니라고 가정.
        #x를 찾기 위해 traversal 해야겠지?
        current=self.head
        found=False #못 찾을 수도 있으니까
        #찾기 먼저, 삽입 나중에
        while current!=None and not found:
            if (current.get_item()==x):
                found=True
            else:
                current=current.get_next()
        #이제, current 다음에 넣기(찾았다면)
        if found==False:
            print("x 찾을 수 없음")
        else:
            temp.set_next(current.get_next())
            temp.set_previous(current)
            if (current.get_next()!=None):
                current.get_next().set_next(temp)
            current.set_next(temp)
    def insert_before(self,item,x): #특정 항목 x를 저장하고 있는 노드 이전 위치에
                               #item 삽입
        temp=dNode(item)
        if self.head==None:
            self.head=temp
        else:
            current=self.head
            found=False
            while current!=None and not found:
                if (current.get_item()==x):
                    found=True
                else:
                    current=current.get_next()
        #순회 마치고, found 또는 not found
        if found!=True:
            print("x 찾을 수 없음")
        else:
            temp.set_next(current)
            temp.set_previous(current.get_previous())
            if current.get_previous()!=None:
                current.get_previous().set_next(temp)
            current.set_previous(temp)
    def pop_first(self):
        if self.is_empty():
            print("Nothing to pop!")
        else:
            if self.head.get_next()==None:
                self.head=None
            else:
                self.head=self.head.get_next()
                self.head.set_previous(None)  #None 설정 잊지 말기. 원칙은 쌍방향
    def pop_last(self): #traversal 고려하자
        if self.is_empty():
            print("Nothing to pop!")
        else:
            #원소 하나짜리
            if (self.head.get_next==None):
                self.head=None
            else: #traversal
                current=self.head
                while current.get_next()!=None:
                    current=current.get_next()
                current.get_previous().set_next(None)
    def delete(self,item): #특정 item을 저장하고 있는 기존 노드 삭제
        #탐색을 위한 traversal과 delete
        if self.is_empty():
            print("Nothing to delete!")
        else:
            current=self.head
            found=False
            while current!=None and not found:
                if (current.get_item()==item):
                    found=True
                else:
                    current=current.get_next()
        #찾았다는 가정 하에 delete 작업 수행
        if current.get_previous()==None:
            current.get_next().set_previous(None)
            self.head=current.get_next()
        elif current.get_next()!=None:
            current.get_previous().set_next(current.get_next())
            current.get_next().set_previous(current.get_previous())
        elif current.get_next()==None:
            current.get_previous().set_next(None)
    def printElement(self):
        current=self.head
        while current:
            if current.get_next()!=None:
                print(current.get_item(),'->',end=' ')
            else:
                print(current.get_item())
            current=current.get_next()
'''#main 함수-doubly linked list 직접 확인해보기
d=DoubleList()
print(d.is_empty()) #True
d.add(1)
d.printElement() #1
d.add(2)
d.append(3)
d.printElement() #2->1->3
d.delete(3)
d.printElement() #2->1
d.pop_last()  
d.printElement() #2
d.append(5)
d.printElement() #2->5
d.pop_first()
d.printElement() #5'''

#환형연결리스트->sNode class의 형태 취해
#주의: 마지막 노드가 첫 노드를 참조, 따라서 next 필드 값이 None인 노드가
#  존재하지 않는다
#주의2:주로 head가 마지막 노드를 참조하게 함으로써 첫노드와 마지막 노드를
#  O(1) 시간에 접근할 수 있도록 함. 
class CircularList:
    def __init__(self):
        self.head=None
    def is_empty(self):
        return self.head==None
    def add(self,item): #연결리스트의 첫 위치에 item 삽입, O(1) 이라는거
        temp=sNode(item)
        if self.is_empty():
            temp.set_next(temp) #제자리돌기
            self.head=temp
        else:
            temp.set_next(self.head.get_next())
            self.head.set_next(temp)
    def append(self,item): #가장 끝 자리에 삽입, O(1) 이라는거
        temp=sNode(item)
        if self.is_empty():
            temp.set_next(temp)
            self.head=temp
        else:
            temp.set_next(self.head.get_next())
            self.head.set_next(temp)
            self.head=temp
    def pop_first(self):
        if self.is_empty():
            print("Nothing to pop!")
        else:
            temp=self.head.get_next()
            #하나짜리라면
            if (temp==temp.get_next()):
                self.head=None
            else:
                self.head.set_next(temp.get_next())
    def search(self,item):
        temp=self.head.get_next() #다른 list에서 self.head였던 것이.
        found=False
        current=temp  #current와 temp를 둘 다 가지고 있기:
        #temp는 첫 노드, current는 말 그대로 현재 진행형인 노드
        #중요: 무한루프 방지
        while current.get_next()!=temp and not found:
            if (current.get_item()==item):
                found=True
            else:
                current=current.get_next()
        return found
    def printElement(self):
        temp=self.head.get_next()
        current=temp
        while True:
            if current==self.head:
                print(current.get_item())
            else:
                print(current.get_item(),'->',end=' ')
            current=current.get_next()
            if current!=temp:
                continue
            else:
                break
#main 함수-circular linked list 직접 확인해보기
c=CircularList()
print(c.is_empty()) #True
c.add(1)
c.printElement() #1
c.add(2)
c.append(3)
c.printElement() #2->1->3
c.append(5)
c.printElement() #2->1->3->5
c.pop_first()
c.printElement() #1->3->5
print(c.search(4)) #False
        
