import java.util.*;

class disk{
	static void sort(int arr[], int n){
		for(int i=0; i < n-1; i++)
			for(int j=0; j < n-1; j++)
				if(arr[j] > arr[j+1]){
					int t = arr[j];
					arr[j] = arr[j+1];
					arr[j+1] = t;
				}
	}

	static int find_first_to_left(int cyl[], int initial, int n){
		int pos = -1;
		for(int i=0; i < n; i++){
			if(cyl[i] < initial)
				pos = i;
		}
		return pos;
	}

	static int[] _clook(int cyl[], int initial, int range, int n){
		sort(cyl, n);
		int distance = 0;
		int movement[] = new int[n];
		if(initial < Math.abs(cyl[n-1] - initial)){
			//Go left to 0 first
			int t = 0;
			int pos = find_first_to_left(cyl, initial, n);

			for(int i=pos; i >= 0; i--)
				movement[t++] = cyl[i];
			distance += initial - cyl[0];  //Dont go till end, go till first cylinder request

			for(int i=n-1; i >= pos+1; i--)
				movement[t++] = cyl[i];	
			distance += cyl[n-1] - cyl[pos+1];


		}

		else{
			int t = 0;
			int pos = find_first_to_left(cyl, initial, n);

			for(int i=n-1; i >= pos+1; i--)
				movement[t++] = cyl[i];	
			distance += cyl[n-1] - cyl[pos+1];  ///Dont go till end, go till last cylinder request

			for(int i=pos; i >= 0; i--)
				movement[t++] = cyl[i];
			distance += initial - cyl[0]; 
		}
		System.out.println("Total movement = " + distance);
		return movement;
	}

	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);

		System.out.println("Enter the number of cylinders and initial head position");
		int n = sc.nextInt();
		int initial = sc.nextInt();

		System.out.println("Enter the disk range");
		int range = sc.nextInt();
		int cyl[] = new int[n];

		System.out.println("Enter the cylinder positions");
		for(int i=0; i < n; i++)
			cyl[i] = sc.nextInt();	

		int movement[] = _clook(cyl, initial, range, n);

		for(int i=0; i < n; i++)
			System.out.print(movement[i] + " ");
		
	}	
}

/*

Enter the number of cylinders and initial head position
8 50
Enter the disk range
199
Enter the cylinder positions
11 34 62 64 95 119 123 180
Total movement = 157
34 11 180 123 119 95 64 62

*/
