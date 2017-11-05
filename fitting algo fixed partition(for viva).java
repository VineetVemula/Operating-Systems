import java.util.*;

class block{
	int size;
	int t_size;
	int process;
	boolean flag;
}
class x{
	static void first_fit(block b[], int proc[], int np, int nb){
		for(int i=0; i < np; i++)
			for(int j=0; j < nb; j++){
				if(b[j].size >= proc[i] && b[j].flag){
					b[j].flag = false;
					b[j].process = i + 1;
					b[j].size -= proc[i];
					break;
				}
			}
	}
	static void best_fit(block b[], int proc[], int np, int nb){
		int j;
		for(int i=0; i < np; i++){
			int min = 999999;
			int pos = -1;
			for(j=0; j < nb; j++){
				if(b[j].size >= proc[i] && b[j].flag){
					if(b[j].size - proc[i] < min){
						min = b[j].size - proc[i];
						pos = j;
					}
				}
			}
			if(pos == -1){
				System.out.println("Process " + (i + 1) + "can't be scheduled");
				continue;
			}
			b[pos].flag = false;
			b[pos].process = i + 1;
			b[pos].size -= proc[i];
		}
	}
	static void worst_fit(block b[], int proc[], int np, int nb){
		int j;
		for(int i=0; i < np; i++){
			int max = 0;
			int pos = -1;
			for(j=0; j < nb; j++){
				if(b[j].size >= proc[i] && b[j].flag){
					if(b[j].size - proc[i] > max){
						max = b[j].size - proc[i];
						pos = j;
					}
				}
			}
			if(pos == -1){
				System.out.println("Process " + (i + 1) + "can't be scheduled");
				continue;
			}
			b[pos].flag = false;
			b[pos].process = i + 1;
			b[pos].size -= proc[i];
		}
	}
	static void print_table(block b[], int proc[], int nb){
		System.out.println("Block\t" + "Process\t" + "Remaining block size");

		for(int i=0; i < nb; i++)
			if(!b[i].flag)
				System.out.println((i+1) + "\t"  + b[i].process + "\t" + b[i].size);
	}
	public static void main(String[] args){
		int nb, np;
		System.out.println("Enter the number of blocks and process");
		Scanner sc = new Scanner(System.in);
		nb = sc.nextInt();
		np = sc.nextInt();
		block b[] = new block[nb];
		int proc[] = new int[np];
		System.out.println("Enter the size of each block");
		for(int i=0; i < nb; i++){
			b[i] = new block();
			b[i].size = sc.nextInt();
			b[i].t_size = b[i].size;
		}
		for(int i=0; i < nb; i++)
			b[i].flag = true;
		System.out.println("Enter the size of each process");
		for(int i=0; i < np; i++)
			proc[i] = sc.nextInt();
		System.out.println("FIRST FIT:");
		x.first_fit(b, proc, np, nb);
		x.print_table(b, proc, nb);
		for(int i=0; i < nb; i++){
			b[i].size = b[i].t_size;
			b[i].flag = true;
		}
		System.out.println("BEST FIT:");
		x.best_fit(b, proc, np, nb);
		x.print_table(b, proc, nb);
		for(int i=0; i < nb; i++){
			b[i].size = b[i].t_size;
			b[i].flag = true;
		}
		System.out.println("WORST FIT:");
		x.worst_fit(b, proc, np, nb);
		x.print_table(b, proc, nb);
	}
}
