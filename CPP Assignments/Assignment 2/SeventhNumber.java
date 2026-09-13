package LoopForNumbers;

public class SeventhNumber {
	
	public static void main(String[] args) {
		for(int i = 1; i <= 200; i++) {
			if(i % 7 == 0) {
				System.out.print(i + " ");
			}
		}
	}

}
