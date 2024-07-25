import java.util.*;

class MyNode{
	int data;
	MyNode next;
	
	MyNode(){}
	
	MyNode(int item){
		this.data=item;
		this.next=null;
	}
}

class MySinglyLinkedList{
	MyNode start;

	MySinglyLinkedList(){
		this.start=null;
	}

	void insertBeginSLL(int item){
		if(start==null){
			this.start=new MyNode(item);
		}
		else{
			MyNode nNode=new MyNode(item);

			nNode.next=start;
			this.start=nNode;
		}
	}

	void insertEndSLL(int item){
		if(start==null){
			this.start=new MyNode(item);
		}
		else{
			MyNode nNode=new MyNode(item);

			MyNode ptr=start;

			while(ptr.next!=null)
				ptr=ptr.next;

			ptr.next=nNode;

		}
	}
	
	void displaySLL(){
		MyNode ptr=this.start;

		while(ptr!=null){
			System.out.print(ptr.data+" ");
			ptr=ptr.next;
		}

		System.out.println("");
	}
}

class Main{
	public static void main(String[] args){
		MySinglyLinkedList ll=new MyLinkedList();
		Scanner sc=new Scanner(System.in);
		int ch,val;

		while(1){
			System.out.println("1. Insert Begin SLL");
			System.out.println("2. Insert End SLL");
			System.out.println("3. display SLL");
			System.out.println("4. Exit program");
			System.out.println("---------------------------------------");
			System.out.println("Enter choice");
			ch=sc.nextInt();
			System.out.println("---------------------------------------");

			switch(ch){
				case 1:
					System.out.println("Enter the node value");
					val=sc.nextInt();

					ll.insertBeginSLL()
			}
		}
	}
}
