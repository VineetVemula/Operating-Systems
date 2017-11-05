import java.util.*;

class block{
	String file_name;
	String state;
	String type;
	int index[] = new int[10];
	int file_size;
}

class test{
	static boolean is_hit(int q[], int n, int page){
		for(int i=0; i < n; i++)
			if(q[i] == page)
				return true;

		return false;
	}
	
	
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);

		System.out.println("Enter the number of pages");
		int n = sc.nextInt();


		System.out.println("Enter the number of frames");
		int n_frames = sc.nextInt();

		int pages[] = new int[n];
		int q[] = new int[n_frames];

		for(int i=0; i < n_frames; i++)
			q[i] = -1;

		for(int i=0; i < n; i++)
			pages[i] = sc.nextInt();

		int f = 0;
		int r = -1;

		int count = 0;
		for(int i=0; i < n; i++){
			if(is_hit(q, n_frames, pages[i])){
				System.out.print("Hit ");
			}
			else{
				if(r == f-1){
					q[++r] = pages[i];
					count++;
				}
				else{
					if(r - f < n_frames - 1){
						q[++r] = pages[i];
						count++;
					}
					else{
						int page_ = q[f];
						f = (f + 1) % n_frames;
						//System.out.print("index = "+ (r + 1) % n_frames);
						q[(r + 1) % n_frames] = pages[i];
						r++;
					}
				}
			}	
			for(int j=0; j < count; j++)
				System.out.print(q[j] + " ");

			// int j = f;
			// do{
			// 	System.out.print(q[j] + " ");
			// 	j = (j + 1) % n_frames;
			// }while(j != f);

			System.out.println();
		}


	}
}
