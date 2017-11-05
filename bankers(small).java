package x;

import java.util.*;


class x{
	static void accept_matrix(int mat[][], int p, int r, Scanner sc){
		System.out.println("Enter the matrix");
		for(int i=0; i < p; i++)
			for(int j=0; j < r; j++)
				mat[i][j] = sc.nextInt();
	}
	
	static void print_matrix(int mat[][], int p, int r){
		for(int i=0; i < p; i++){
			for(int j=0; j < r; j++)
				System.out.print(mat[i][j] + " ");
			
			System.out.println();
		}
	}

	static boolean check(int x[], int y[], int len){
		for(int i=0; i < len; i++)
			if(x[i] < y[i])
				return false;
		return true;
	}
	public static void main(String args[]){
		int p, r;
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the number of processes and resources");
		p = sc.nextInt();
		r = sc.nextInt();
		
		int alloc[][] = new int[p][r];
		int max[][] = new int[p][r];
		int need[][] = new int[p][r];
		int avail[] = new int[r];
		int schedule[] = new int[p];
		int work[] = new int[r];
		int completed = 0;
		
		boolean finish[] = new boolean[p];
		for(int i=0; i < p; i++)
			finish[i] = false;
		
		x.accept_matrix(alloc, p, r, sc);
		x.accept_matrix(max, p, r, sc);
		
		
		System.out.println("Enter the available matrix");
		for(int i=0; i < r; i++)
			avail[i] = sc.nextInt();
		
		System.arraycopy(avail, 0, work, 0, r);
		
		for(int i=0; i < p; i++)
			for(int j=0; j < r; j++)
				need[i][j] = max[i][j] - alloc[i][j];
				
		int i=0;
		boolean safe = true;
		boolean flag = false;
		while(completed < p){
			if(i == 0)
				flag = false;
			if(!finish[i]){
				if(x.check(work, need[i], r)){
					finish[i] = true;
					flag = true;
					schedule[completed++] = i;
					for(int j=0; j < r; j++)
						work[j] += alloc[i][j];
				}
					
			}
			i = (i + 1) % p;
			if(i == 0 && !flag){
				safe = false;
				break;
			}
		}
		if(safe){
			System.out.println("System is safe and process order is");
			for(int w=0; w < p; w++)
				System.out.print(schedule[w] + " ");
		}
		
		else
			System.out.println("System is not safe");
		
		
	}
}
