import java.util.Scanner;
import java.lang.StringBuffer;

class ReverseString{

	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter a word: ");
		String name = sc.nextLine();	
		String reverse = new StringBuffer(name).reverse().toString();
		System.out.println(reverse);
	}
}