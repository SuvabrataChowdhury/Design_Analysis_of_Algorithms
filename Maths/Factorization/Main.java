import java.util.*;

class Factorize{
	void factorize1(int num){
		if(num!=1){
			int lim=(int )Math.sqrt(num);
			for(int i=2;i<=lim;i++){
				if(num%i==0){
					System.out.println(i);
					factorize1(num/i);
					return;
				}
			}

			System.out.println(num);
			return ;
		}
	}

	/*void factorize2(int num){
		int i=2;
		int lim=(int )Math.sqrt(num);

		while(num!=1){
			lim=(int )Math.sqrt(num);
			for(i=2;i<=lim;i++){
				if(num%i==0){
					System.out.println(i);
					num/=i;
					break;
				}
			}

			if(i==lim){
				System.out.println(num);
				break;
			}
		}
	}*/
}

class Main{
	public static void main(String[] args){
		Factorize ob=new Factorize();
		//Scanner sc=new Scanner(System.in);

		System.out.println("");
		ob.factorize1(Integer.parseInt(args[0]));
		
		/*System.out.println("");
		ob.factorize2(Integer.parseInt(args[0]));*/
	}
}
