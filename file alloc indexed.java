import java.util.*;

class block{
	String file_name;
	String state;
	String type;
	int indices[] = new int[10];
	int file_size;   //Only for index blocks.
}

class file_alloc{
	static int[] find_blocks(block b[], int num_blocks, int fsize){
		//Finds the blocks needed by the file.

		int count = 0;
		int indices[] = new int[fsize];
		for(int i=0; i < num_blocks; i++){
			if(b[i].state.equals("free")){
				indices[count++] = i;
				if(count == fsize)
					return indices;
			}
		}
		indices[0] = -1;   //If required number of blocks not available signal it by giving 1st element of index array as -1.
		return indices;
	}

	static void linked(block b[], int mem_size){
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

				int indices[] = new int[fsize];
				indices = find_blocks(b, num_blocks, fsize+1);



				if(indices[0] != -1){
					b[indices[0]].type = "I";
					b[indices[0]].file_name = fname;
					b[indices[0]].state = "used";
					b[indices[0]].file_size = fsize;
					for(int i=0; i < fsize; i++){
						b[indices[0]].indices[i] = indices[i+1];
					}
					for(int i=1; i <= fsize; i++){
						b[indices[i]].type = "D";
						b[indices[i]].file_name = fname;
						b[indices[i]].state = "used";
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

				for(int i=0; i < num_blocks; i++){
					if(b[i].type == "I"){
						System.out.print(i + "\t" + b[i].type + "\t");
						for(int j=0; j < b[i].file_size; j++)
							System.out.print(b[i].indices[j] + " ");

						System.out.println();
					
					}
					else
						System.out.println(i + "\t" + b[i].type + "\t" +  b[i].file_name);
				}


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
		linked(b, size);

	}
}
