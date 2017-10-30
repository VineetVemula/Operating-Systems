import java.util.*;

class pt{
	int page_no;
	int frame;
}

class paging{
	static int find_bits(int size){
		int count = 0;
		while(size > 0){
			size /= 2;
			count++;
		}
		return (count + 9);
	}

	static int[] to_binary(int num, int size){
		int bin[] = new int[size];
		for(int i=size-1; i >= 0; i--){
			bin[i] = num % 2;
			num = num / 2;
		}	
		return bin;
	}

	static int to_int(int bin[], int size){
		int num = 0;
		int pow_index = 0;
		for(int i=size-1; i >= 0; i--){
			num += bin[i] * Math.pow(2, pow_index);
			pow_index++;
		}

		return num;
	}

	static void print_arr(int arr[], int len){
		for(int i=0; i < len; i++)
			System.out.print(arr[i]);

	}

	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);

		System.out.println("Enter the logical address size");
		int log_size = sc.nextInt();
		System.out.println("Enter the physical address size");
		int phy_size = sc.nextInt();
		System.out.println("Enter the page size");
		int page_size = sc.nextInt();
		System.out.println("Enter the number of page table entries");
		int num = sc.nextInt();

		pt p[] = new pt[num];
		for(int i=0; i < num; i++){
			p[i] = new pt();
			p[i].page_no = sc.nextInt();
			p[i].frame = sc.nextInt();
		}

		System.out.println("Page table is");

		for(int i=0; i < num; i++){
			int frame[] = to_binary(p[i].frame, 16);
			System.out.print(p[i].page_no + " "); print_arr(frame, 16); System.out.println();
		}

		int log_len = find_bits(log_size); int phy_len = find_bits(phy_size); int page_len = find_bits(page_size);

		System.out.println("Logical addr length = " + log_len + " Physical address length = " + phy_len + " Page length = " + page_len);

		System.out.println("Enter the logical address");
		int log_addr = sc.nextInt();

		int log_addr_bin[] = to_binary(log_addr, log_len);
		for(int i=0; i < log_len; i++)
			System.out.print(log_addr_bin[i]);


		int page_bits = log_len - page_len;
		int page_bin[] = new int[page_bits];

		for(int i=0; i < page_bits; i++)
			page_bin[i] = log_addr_bin[i];

		System.out.print("\nPage number in binary = "); print_arr(page_bin, page_bits); System.out.println();
		int page_int = to_int(page_bin, page_bits);
		System.out.println("Page number in decimal = " + page_int);

		int page_frame = -1;
		for(int i=0; i < num; i++){
			if(p[i].page_no == page_int)
				page_frame = p[i].frame;
		}



		System.out.print("Frame in binary = "); print_arr(to_binary(page_frame, 16), 16); System.out.println();

		int page_frame_bin[] = to_binary(page_frame, 16);

		int phy_addr_bin[] = new int[phy_len];
		for(int i=0; i < phy_len; i++)
			phy_addr_bin[i] = 0;




		int j = log_len-1;
		int index = phy_len - 1;

		for(int i=0; i < (log_len - page_bits); i++)
			phy_addr_bin[index--] = log_addr_bin[j--];



		j = log_len-1;
		int t = index;
		for(int i=0; i < t; i++){
			phy_addr_bin[index--] = page_frame_bin[j--];
		}

		System.out.print("Physical address in binary = "); print_arr(phy_addr_bin, phy_len);
		System.out.println("\nPhysical address in decinal =  " + to_int(phy_addr_bin, phy_len));
	 }
}
