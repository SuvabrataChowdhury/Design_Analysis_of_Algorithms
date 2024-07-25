//Implementation of a binary search tree in java

import java.util.*;

class MyNode{
	int data;
	MyNode left;
	MyNode right;

	MyNode(){}

	MyNode(int item){
		this.data=item;
		this.left=null;
		this.right=null;
	}
}

class MyBST{
	MyNode root;

	MyBST(){
		this.root=null;
	}

	MyNode insertBST(MyNode cNode,int item){
		if(cNode==null){
			return new MyNode(item);
		}
		else{
			if(item<cNode.data){
				cNode.left=insertBST(cNode.left,item);
			}

			if(item>cNode.data){
				cNode.right=insertBST(cNode.right,item);
			}
		}

		return cNode;
	}

	boolean insertBST(int item){
		if(!this.isPresent(item)){
			this.root=this.insertBST(this.root,item);
			return true;
		}
		else
			return false;
	}

	MyNode minNode(MyNode cNode){
		if(cNode.left==null)
			return cNode;
		return minNode(cNode.left);
	}

	MyNode deleteNode(MyNode cNode,int item){
		if(cNode==null)
			return null;
		else{
			if(item<cNode.data)
				cNode.left=deleteNode(cNode.left,item);
			else if(item>cNode.data)
				cNode.right=deleteNode(cNode.right,item);
			else{
				//**Item Found**//

				if(cNode.left!=null&&cNode.right!=null){
					MyNode temp=this.minNode(cNode.right);

					cNode.data=temp.data;
					cNode.right=deleteNode(cNode.right,temp.data);
				}
				else{
					MyNode temp=null;

					if(cNode.left==null)
						temp=cNode.right;
					else
						temp=cNode.left;

					cNode=null;//current node gets deleted
					return temp;
				}
			}
		}

		return cNode;
	}

	boolean deleteNode(int item){
		if(root==null||!this.isPresent(item))
			return false;
		else{
			this.root=this.deleteNode(this.root,item);
			return true;
		}
	}

	boolean isPresent(int item){
		return this.searchBST(this.root,item);
	}

	boolean searchBST(MyNode cNode,int item){
		if(cNode==null)
			return false;
		else if(cNode.data==item)
			return true;
		else if(item<cNode.data)
			return searchBST(cNode.left,item);
		else
			return searchBST(cNode.right,item);
	}

	void preorderBST(MyNode cNode){
		if(cNode==null)
			return ;
		
		System.out.print(cNode.data+" ");
		preorderBST(cNode.left);
		preorderBST(cNode.right);
	}

	void inorderBST(MyNode cNode){
		if(cNode==null)
			return ;
		
		inorderBST(cNode.left);
		System.out.print(cNode.data+" ");
		inorderBST(cNode.right);
	}

	void postorderBST(MyNode cNode){
		if(cNode==null)
			return ;
		
		postorderBST(cNode.left);
		postorderBST(cNode.right);
		System.out.print(cNode.data+" ");
	}

	void display(){
		int ch;

		Scanner sc=new Scanner(System.in);
		while(true){
			System.out.println("1. Preorder Traversal");
			System.out.println("2. Inorder Traversal");
			System.out.println("3. Postorder Traversal");
			System.out.println("4. Exit");
			System.out.println("------------------------------------");
			System.out.println("Enter choice");
			ch=sc.nextInt();
			System.out.println("------------------------------------");
			
			switch(ch){
				case 1:
					this.preorderBST(this.root);
					break;
				case 2:
					this.inorderBST(this.root);
					break;
				case 3:
					this.postorderBST(this.root);
					break;
				case 4:
					return;
				default:
					System.out.println("Wrong Input");
			}

			System.out.println("");

		}
	}
}

class BST{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		MyBST t1=new MyBST();

		int ch;
		int val;
		while(true){	
			System.out.println("1. Insert Element in BST");
			System.out.println("2. Delete Element from BST");
			System.out.println("3. Search an Element in the BST");
			System.out.println("4. Display the BST");
			System.out.println("5. Exit");
			System.out.println("------------------------------------");
			System.out.println("Enter choice");
			ch=sc.nextInt();
			System.out.println("------------------------------------");

			switch(ch){
				case 1:
					System.out.println("Enter the item to be inserted");
					val=sc.nextInt();

					if(t1.insertBST(val))
						System.out.println(val+" inserted successfully");
					else
						System.out.println(val+" already exists");
					
					break;
				case 2:
					System.out.println("Enter the item to be deleted");
					val=sc.nextInt();

					if(t1.deleteNode(val))
						System.out.println(val+" has been deleted");
					else
						System.out.println(val+" is not present in BST");
					break;
				case 3:	
					System.out.println("Enter the item to be searched");
					val=sc.nextInt();

					if(t1.isPresent(val))
						System.out.println(val+" is present");
					else
						System.out.println(val+" is not present");
					break;
				case 4:
					t1.display();
					break;
				case 5:
					System.exit(0);
				default:
					System.out.println("Wrong Input");
			}
		}
	}
}
