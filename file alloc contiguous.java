import java.util.*;

class block{
	String file_name;
	String state;
}

class file_alloc{
	static int find_start(block b[], int num_blocks, int fsize){
		//Finds the first partition which has continous number of required blocks free
		for(int i=0; i < num_blocks - fsize + 1; i++){
			int count = 0;
			for(int j=i; j < i + fsize; j++){
				if(b[j].state.equals("free")){
					count++;
					if(count >= fsize)
						return i;
				}
			
			}
		}
		System.out.println();
		return -1;
	}

	static void contigious(block b[], int mem_size){
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the size of each block");
		int b_size = sc.nextInt();
		int num_blocks = mem_size / b_size;


		while(true){
			System.out.println("1. Create 2. Delete 3. Display 4. Exit");
			int ch = sc.nextInt();
			

			if(ch == 1){
				System.out.println("Enter the filename");
				String fname = sc.next();
				System.out.println("Enter the filesize");
				int fsize = sc.nextInt();
				if(b_size > 1)
					fsize = fsize / b_size + fsize % b_size;


				int start = find_start(b, num_blocks, fsize);
				
				if(start != -1){
					for(int i=start; i < start + fsize; i++){
						b[i].file_name = fname;
						b[i].state = "used";
					}
				}
				
				else{
					System.out.println("File can't be allocated");
				}
					
			}	

			else if(ch == 2){
				System.out.println("Enter the filename to delete");
				String fname = sc.next();
				for(int i=0; i < num_blocks; i++){
					if(b[i].file_name.equals(fname)){
						b[i].file_name = "";
						b[i].state = "free";
					}
				}
			}

			else if(ch == 3){
				for(int i=0; i < num_blocks; i++)
					System.out.println(i + "\t" + b[i].file_name + "\t");


				System.out.println();
			}
			else if(ch == 4){
				return;
			}	
		}
			
	}


	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);

		System.out.println("Enter the size of memory");
		int size = sc.nextInt();

		block b[] = new block[size];

		for(int i=0; i < size; i++){
			b[i] = new block();
			b[i].file_name = "";
			b[i].state = "free";
		}
		contigious(b, size);

	}
}
