import java.util.Scanner;

class PalindromeString{

	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);

		System.out.print("Enter a word: ");
		String name = sc.nextLine();

		name = name.toLowerCase();

		String reverse = new StringBuffer(name).reverse().toString();
	
		System.out.println(reverse.equals(name) ? "It is Palindrome" : "Not a Palindrome");
	}
}