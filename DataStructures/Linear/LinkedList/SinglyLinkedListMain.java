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
	int delItem;

	MySinglyLinkedList(){
		this.start=null;
		this.delItem=0;
	}

	void insertBeginSLL(int item){
		if(this.start==null){
			this.start=new MyNode(item);
		}
		else{
			MyNode nNode=new MyNode(item);

			nNode.next=start;
			this.start=nNode;
		}
	}

	void insertEndSLL(int item){
		if(this.start==null){
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

	boolean insertAfterSLL(int item,int key){
		if(this.start==null)
			return false;
		else{
			MyNode ptr=start;

			while(ptr!=null){
				if(ptr.data==key)
					break;

				ptr=ptr.next;
			}

			if(ptr==null)
				return false;
			else{
				MyNode nNode=new MyNode(item);

				nNode.next=ptr.next;
				ptr.next=nNode;

				return true;
			}
		}
	}

	boolean deleteBeginSLL(){
		if(this.start==null)
			return false;
		else{
			MyNode temp=start;

			start=start.next;
			this.delItem=temp.data;
			temp=null;

			return true;
		}
	}

	
	boolean deleteEndSLL(){
		if(this.start==null)
			return false;
		else{
			MyNode temp=start;

			if(temp.next==null){
				this.delItem=temp.data;
				start=null;
				temp=null;
			}
			else{
				while(temp.next.next!=null)
					temp=temp.next;
				
				this.delItem=temp.next.data;

				temp.next=null;
			}

			return true;
		}
	}
	
	void displaySLL(){
		if(start==null)
			System.out.println("Empty List");
		else{
			MyNode ptr=this.start;

			while(ptr!=null){
				System.out.print(ptr.data+" ");
				ptr=ptr.next;
			}

			System.out.println("");
		}
	}
}

class SinglyLinkedListMain{
	public static void main(String[] args){
		MySinglyLinkedList ll=new MySinglyLinkedList();
		Scanner sc=new Scanner(System.in);
		int ch,val;

		while(true){
			System.out.println("1. Insert Begin SLL");
			System.out.println("2. Insert End SLL");
			System.out.println("3. Insert After SLL");
			System.out.println("4. Delete Begin SLL");
			System.out.println("5. Delete End SLL");
			System.out.println("6. Display SLL");
			System.out.println("7. Exit program");
			System.out.println("---------------------------------------");
			System.out.println("Enter choice");
			ch=sc.nextInt();
			System.out.println("---------------------------------------");

			switch(ch){
				case 1:
					System.out.println("Enter the node value");
					val=sc.nextInt();

					ll.insertBeginSLL(val);
					break;
				
				case 2:
					System.out.println("Enter the node value");
					val=sc.nextInt();

					ll.insertEndSLL(val);
					break;
				case 3:
					System.out.println("Enter the node value");
					val=sc.nextInt();
					System.out.println("Enter the key value");
					int key=sc.nextInt();

					ll.insertAfterSLL(val,key);
					break;
				case 4:
					if(ll.deleteBeginSLL())
						System.out.println(ll.delItem+" has been deleted");
					else
						System.out.println("UNDERFLOW");
					break;
				case 5:
					if(ll.deleteEndSLL())
						System.out.println(ll.delItem+" has been deleted");
					else
						System.out.println("UNDERFLOW");
					break;
				case 6:
					ll.displaySLL();
					break;
				case 7:
					System.exit(0);
				default:
					System.out.println("Wrong Input");
			}

			System.gc();
		}
	}
}
